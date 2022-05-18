/********************************************************************************
** Form generated from reading UI file 'findImageIAMRSv.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FINDIMAGEIAMRSV_H
#define FINDIMAGEIAMRSV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findImageClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *dirPath;
    QPushButton *selectDir;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listInfo;
    QListWidget *listAll;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *progressBar;
    QLabel *lab_publicObject;
    QLabel *info_currentCount;
    QLabel *lab_gen;
    QLabel *lab_allObject;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *findImageClass)
    {
        if (findImageClass->objectName().isEmpty())
            findImageClass->setObjectName(QString::fromUtf8("findImageClass"));
        findImageClass->resize(1228, 830);
        centralWidget = new QWidget(findImageClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dirPath = new QLineEdit(widget);
        dirPath->setObjectName(QString::fromUtf8("dirPath"));

        horizontalLayout->addWidget(dirPath);

        selectDir = new QPushButton(widget);
        selectDir->setObjectName(QString::fromUtf8("selectDir"));

        horizontalLayout->addWidget(selectDir);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listInfo = new QListWidget(widget_2);
        listInfo->setObjectName(QString::fromUtf8("listInfo"));

        horizontalLayout_3->addWidget(listInfo);

        listAll = new QListWidget(widget_2);
        listAll->setObjectName(QString::fromUtf8("listAll"));

        horizontalLayout_3->addWidget(listAll);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        progressBar = new QProgressBar(widget_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_2->addWidget(progressBar);

        lab_publicObject = new QLabel(widget_3);
        lab_publicObject->setObjectName(QString::fromUtf8("lab_publicObject"));

        horizontalLayout_2->addWidget(lab_publicObject);

        info_currentCount = new QLabel(widget_3);
        info_currentCount->setObjectName(QString::fromUtf8("info_currentCount"));

        horizontalLayout_2->addWidget(info_currentCount);

        lab_gen = new QLabel(widget_3);
        lab_gen->setObjectName(QString::fromUtf8("lab_gen"));

        horizontalLayout_2->addWidget(lab_gen);

        lab_allObject = new QLabel(widget_3);
        lab_allObject->setObjectName(QString::fromUtf8("lab_allObject"));

        horizontalLayout_2->addWidget(lab_allObject);

        horizontalLayout_2->setStretch(0, 40);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout->addWidget(widget_3);

        findImageClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(findImageClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1228, 23));
        findImageClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(findImageClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        findImageClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(findImageClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        findImageClass->setStatusBar(statusBar);

        retranslateUi(findImageClass);

        QMetaObject::connectSlotsByName(findImageClass);
    } // setupUi

    void retranslateUi(QMainWindow *findImageClass)
    {
        findImageClass->setWindowTitle(QApplication::translate("findImageClass", "findImage", nullptr));
        label->setText(QApplication::translate("findImageClass", "\346\226\207\344\273\266\345\244\271\350\267\257\345\276\204", nullptr));
        selectDir->setText(QApplication::translate("findImageClass", "\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271", nullptr));
        lab_publicObject->setText(QApplication::translate("findImageClass", "\345\205\261\346\234\211\345\257\271\350\261\241\357\274\232", nullptr));
        info_currentCount->setText(QString());
        lab_gen->setText(QApplication::translate("findImageClass", "/", nullptr));
        lab_allObject->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class findImageClass: public Ui_findImageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FINDIMAGEIAMRSV_H
