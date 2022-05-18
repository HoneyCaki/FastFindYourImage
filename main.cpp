#include "findImage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	findImage w;
	w.setWindowTitle("寻找文件");
	w.show();
	return a.exec();
}
