#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_findImage.h"
#include <QThread>
#include <qvector.h>
#include <QFileInfo>
#include <QDirIterator>
#include <QStringList>
#include <QFileDialog>
#include "listAll.h"
#include <QImageReader>
#include <qlistwidget.h>
#include <qstring.h>
#include <qmessagebox.h>
#include <QClipboard>
#include <QDesktopServices>
#include <QProcess>
#include <QList>
#include <qscreen.h>

class findImage : public QMainWindow 
{
	Q_OBJECT

public:
	double DPI;
	findImage(QWidget *parent = nullptr);
	void exit(bool force);
	void initAll();
	//获取系统DPI
	
signals:
	void signalDoing(const QString& path);
	void signalBreak(bool breakFor);
public slots:
	void on_listAll_itemDoubleClicked();
	void on_listAll_customContextMenuRequested(const QPoint& pos);
	void on_listInfo_customContextMenuRequested(const QPoint& pos);
private:
	Ui::findImageClass ui;

	QFile *file;
	QFileInfo *fileInfo;

	QProcess proc;

	QAction* R_copyPath;
	QAction* R_copyFileName;
	QAction* R_openWithLocalImageViewer;
	QAction* R_openWithLocalExplorer;

	QAction* L_copyPath;
	QAction* L_copyFileName;
	QAction* L_openWithLocalImageViewer;
	QAction* L_openWithLocalExplorer;
};
