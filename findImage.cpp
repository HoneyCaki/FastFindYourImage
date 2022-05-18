#include "findImage.h"
#include "listAll.h"
#include <qdebug.h>
#include <qstring.h>

QThread* sub = new QThread;
listAll* work = new listAll;
QStringList leftList;
listAll getDPI;
findImage::findImage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	QMenuBar* bar = menuBar();
	this->setMenuBar(bar);
	QMenu* fileMenu = bar->addMenu("菜单0");
	bar->setVisible(false); //隐藏菜单
	work->moveToThread(sub);
	
	//list all属性设置
	QSizePolicy sizePolicy = this->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
	ui.listAll->setViewMode(QListWidget::IconMode);
	ui.listAll->setIconSize(QSize(150 * getDPI.getScreenDPI() ,150 * getDPI.getScreenDPI()));
	ui.listAll->setSpacing(10);
	ui.listAll->setResizeMode(QListView::Adjust);
	ui.listAll->setMovement(QListView::Static);
	ui.listAll->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.listAll->setSizePolicy(sizePolicy);
	//list info属性设置
	ui.listInfo->setContextMenuPolicy(Qt::CustomContextMenu);

	ui.dirPath->setReadOnly(true);
	//设置右键选项
	R_copyFileName = fileMenu->addAction("复制文件名");
	R_copyPath = fileMenu->addAction("复制路径");
	R_openWithLocalImageViewer = fileMenu->addAction("用图片查看器打开");
	R_openWithLocalExplorer = fileMenu->addAction("打开文件位置");

	L_copyFileName = fileMenu->addAction("复制文件名");
	L_copyPath = fileMenu->addAction("复制路径");
	L_openWithLocalImageViewer = fileMenu->addAction("用图片查看器打开");
	L_openWithLocalExplorer = fileMenu->addAction("打开文件位置");
	//设置双击事件
	connect(ui.listAll, SIGNAL(itemDoubleClicked()) , this , SLOT(listAll_itemDoubleClicked()));

	//设置右键各个选项事件
	//【右列表右键菜单】复制文件名
	connect(R_copyFileName, &QAction::triggered, this, [=]() {
		QClipboard* clip = QApplication::clipboard();
		clip->setText(ui.listAll->currentItem()->text());
	});
	//【右列表右键菜单】复制文件路径
	connect(R_copyPath, &QAction::triggered, this, [=]() {
		QClipboard* clip = QApplication::clipboard();
		QString fileName = ui.listAll->currentItem()->text(); //文件名
		QString dirPath = ui.dirPath->text(); //文件所在地址
		QString fileAbsolutePath = dirPath.append("/").append(fileName);
		clip->setText(fileAbsolutePath);
		});
	//【右列表右键菜单】打开文件所在位置
	connect(R_openWithLocalExplorer, &QAction::triggered, this, [=]() {
		QString fileName = ui.listAll->currentItem()->text(); //文件名
		QString dirPath = ui.dirPath->text(); //文件所在地址
		QString fileAbsolutePath = QString("file:/").append(dirPath.append("/").append(fileName)); //file:/:/../...
		fileAbsolutePath.replace("/", "\\");
		QString cmd = QString("explorer.exe /select,\"%1\"").arg(fileAbsolutePath);
		proc.startDetached(cmd);
		});
	//【右列表右键菜单】用本地图片查看器打开
	connect(R_openWithLocalImageViewer, &QAction::triggered, this, [=](){
		QString fileName = ui.listAll->currentItem()->text(); //文件名
		QString dirPath = ui.dirPath->text();
		QString fileAbsolutePath = QString("file:/").append(dirPath.append("/").append(fileName));
		QDesktopServices::openUrl(QUrl(fileAbsolutePath, QUrl::TolerantMode()));
	});

	//【左列表右键菜单】复制文件名
	connect(L_copyFileName, &QAction::triggered, this, [=]() {
		QClipboard* clip = QApplication::clipboard();
		file = new QFile(ui.listInfo->currentItem()->text());
		clip->setText(file->fileName());
		});
	//【左列表右键菜单】复制文件路径
	connect(L_copyPath, &QAction::triggered, this, [=]() {
		QClipboard* clip = QApplication::clipboard();
		QString fileAbsolutePath = ui.dirPath->text();
		qDebug() << fileAbsolutePath;
		clip->setText(fileAbsolutePath);
		});
	//【左列表右键菜单】打开文件所在位置
	connect(L_openWithLocalExplorer, &QAction::triggered, this, [=]() {
		QString fileAbsolutePath = QString("file:///").append(ui.listInfo->currentItem()->text()); //文件名
		fileAbsolutePath.replace("/", "\\");
		QString cmd = QString("explorer.exe /select,\"%1\"").arg(fileAbsolutePath);
		proc.startDetached(cmd);
		});
	//【左列表右键菜单】用本地图片查看器打开
	connect(L_openWithLocalImageViewer, &QAction::triggered, this, [=]() {
		QString fileAbsolutePath = QString("file:///").append(ui.listInfo->currentItem()->text());
		QDesktopServices::openUrl(QUrl(fileAbsolutePath, QUrl::TolerantMode()));
		});

	//【按钮】当选择文件夹按钮被按下的事件
	connect(ui.dirPath, &QLineEdit::textChanged, work, &listAll::listAll_Image);
	connect(ui.selectDir, &QPushButton::clicked, this, [=]()
	{
		//重启线程
		if (sub->isRunning()) {	exit(true); } 
		sub->start();

		//让用户选择文件夹
		QString selectedDirPath = QFileDialog::getExistingDirectory(this, QStringLiteral("选择文件夹"), QStringLiteral("C:\\Users\\Administrator\\Desktop"));
		//重新选择文件夹时，如果列表有内容就清空
		if (ui.listAll->count() > 0)
		{
			initAll(); //全部初始化
		}
		if (!selectedDirPath.isEmpty())
		{
			ui.dirPath->setText(selectedDirPath);
		}
		//向子线程发送数据
		connect(this, &findImage::signalDoing, work, &listAll::slotDoing, Qt::DirectConnection);
		connect(this, &findImage::signalBreak, work, &listAll::slotBreak, Qt::DirectConnection);
		emit signalDoing(selectedDirPath); 
	});
	//接收来自子线程的item
	connect(work, &listAll::imagePathItem, this, [=](QListWidgetItem* item , int current , int all)
	{
		double _calcProc = (double)current / all;
		int calcProc = _calcProc * 100;
		QString currentFileCount = QString::number(current);
		QString allFileCount = QString::number(all);
		
		ui.listAll->addItem(item);
		item->setSizeHint(QSize(150 * getDPI.getScreenDPI(), 170 * getDPI.getScreenDPI()));
		ui.info_currentCount->setText(currentFileCount);
		ui.lab_allObject->setText(allFileCount);
		ui.progressBar->setValue(calcProc);	
	});
	//接收子线程的图片路径List，并添加到左侧列表
	connect(work, &listAll::imagePathList, this, [=](QStringList imagePath)	
	{
		ui.listInfo->addItems(imagePath);
		leftList = imagePath;
	});
}
//退出线程
void findImage::exit(bool force)
{
	if (force)
	{
		emit signalBreak(true);
		sub->quit();
		sub->wait();
	}
	//
}
//初始化所有控件状态
void findImage::initAll()
{
	leftList.clear();
	ui.listInfo->clear();
	ui.listAll->clear();
	ui.progressBar->setValue(0);
	ui.info_currentCount->setText(QString::number(0));
	ui.lab_allObject->setText(QString::number(0));
	ui.progressBar->setValue(0);
	ui.info_currentCount->setText(QString::number(0));
}
//右侧列表右键信息
void findImage::on_listAll_customContextMenuRequested(const QPoint& pos)
{
	Q_UNUSED(pos);
	QMenu* ptr = new QMenu(this);
	ptr->addAction(R_copyFileName);
	ptr->addAction(R_copyPath);
	ptr->addSeparator();
	ptr->addAction(R_openWithLocalImageViewer);
	ptr->addAction(R_openWithLocalExplorer);
	ptr->exec(QCursor::pos());
	delete ptr;
}
//左侧列表右键信息
void findImage::on_listInfo_customContextMenuRequested(const QPoint& pos)
{
	Q_UNUSED(pos);
	QMenu* ptr = new QMenu(this);
	ptr->addAction(L_copyFileName);
	ptr->addAction(L_copyPath);
	ptr->addSeparator();
	ptr->addAction(L_openWithLocalImageViewer);
	ptr->addAction(L_openWithLocalExplorer);
	ptr->exec(QCursor::pos());
	delete ptr;
}
//右侧列表双击事件（双击打开图片事件）
void findImage::on_listAll_itemDoubleClicked()
{
	int row = ui.listAll->currentRow();
	qDebug() << leftList[row];
	QString fileAbsolutePath = QString("file:///").append(leftList[row]);
	qDebug() << fileAbsolutePath;
	QDesktopServices::openUrl(QUrl(fileAbsolutePath, QUrl::TolerantMode()));
}