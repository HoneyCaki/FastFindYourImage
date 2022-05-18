#pragma once

#include <QObject>
#include "findImage.h"

class listAll : public QObject
{
	Q_OBJECT

public:
	explicit listAll(QObject *parent = nullptr);
	~listAll();
	
	void listAll_Image();
	double getScreenDPI();
	void getImagePath(const QString& dirPath, QStringList& imagePath, const QStringList& formats, int &fileCount);
	QPixmap loadImageFunction(const QString& imagePath, const QSize& targetSize);
	
signals:
	//图片路径、压缩过的图片、加入item的图片
	void imagePathItem(QListWidgetItem* item , int currentFileCount , int fileCount);
	void imagePathList(QStringList imagePath);
	
public slots:
	void slotDoing(const QString &path);
	void slotBreak(bool breakFor);

private:
	QFile *file;
	QFileInfo *fileInfo;
};
