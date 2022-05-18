#include "listAll.h"
#include <qthread.h>
#include <qdebug.h>
#include "findImage.h"
#include <qdebug.h>
#include <qthread.h>
#include <QDebug>

QString dirPath; //文件夹路径
bool _breakFor;

listAll::listAll(QObject *parent)
	: QObject(parent)
{
}

listAll::~listAll()
{
}

//子线程
void listAll::listAll_Image()
{
	qDebug() << "当前线程对象地址：" << QThread::currentThread();
	QStringList pathList;
	int fileCount = 0;
	QStringList formats = QString("jpg;png;jpeg;gif;bmp").split(";"); //筛选
	
	qDebug() << dirPath;
	if (!pathList.isEmpty()) { pathList.clear(); }
	_breakFor = false;
	getImagePath(dirPath, pathList, formats , fileCount); //获取图片路径并存储到pathList
	emit imagePathList(pathList);
	for (int i = 0; i < pathList.count(); i++)
	{
		if (_breakFor)
		{
			break;
		}
		fileInfo = new QFileInfo(pathList[i]);
		QPixmap pixmap = loadImageFunction(pathList[i], QSize(150 * getScreenDPI(), 150 * getScreenDPI()));
		QListWidgetItem* item = new QListWidgetItem(QIcon(pixmap), fileInfo->fileName());
		emit imagePathItem(item , i+1 , fileCount);
	}
}

//图片压缩
QPixmap listAll::loadImageFunction(const QString& imagePath, const QSize& targetSize)
{
	QImageReader imageReader;
	imageReader.setFileName(imagePath);
	imageReader.setAutoTransform(true);

	auto imageSize = imageReader.size();
	auto targetScaledSize = imageSize.scaled(targetSize, Qt::KeepAspectRatio);
	

	imageReader.setScaledSize(targetScaledSize);
	QPixmap pixmap = QPixmap::fromImageReader(&imageReader);

	return pixmap;

}
//取得图片路径
void listAll::getImagePath(const QString& dirPath, QStringList& imagePath, const QStringList& formats, int &fileCount)
{
	QFileInfo fileInfo;
	imagePath.clear(); //每次执行都清空向量值
	QDirIterator it(dirPath, QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
	while (it.hasNext())
	{
		it.next();
		fileInfo = it.fileInfo();
		if (formats.contains(fileInfo.suffix()))
		{
			imagePath.push_back(fileInfo.absoluteFilePath());
		}
	}
	fileCount = imagePath.count();
}
//从主线程接收文件夹路径数据
void listAll::slotDoing(const QString& path)
{
	dirPath = path;
}

void listAll::slotBreak(bool breakFor)
{
	_breakFor = breakFor;
}

double listAll::getScreenDPI()
{
	double DPI;
	QScreen* screen = qApp->primaryScreen();
	qreal scrDPI = screen->logicalDotsPerInch();
	int systemDPI = (int)scrDPI;
	if (systemDPI == 96)
	{
		DPI = 1.0;
	}
	else if (systemDPI == 120)
	{
		DPI = 1.25;
	}
	else if (systemDPI == 144)
	{
		DPI = 1.5;
	}
	else if (systemDPI == 192)
	{
		DPI = 2.0;
	}
	else if (systemDPI > 192)
	{
		DPI = 2.5;
	}
	else
	{
		DPI = 1.0;
	}
	return DPI;
}