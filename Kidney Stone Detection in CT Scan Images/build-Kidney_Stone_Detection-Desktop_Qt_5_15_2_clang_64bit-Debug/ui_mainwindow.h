/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *display5;
    QLabel *display6;
    QLabel *display1;
    QLabel *display2;
    QLabel *display4;
    QLabel *display8;
    QLabel *display3;
    QLabel *display7;
    QPushButton *pushButton;
    QLabel *label_1;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1484, 799);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 1451, 641));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        display5 = new QLabel(gridLayoutWidget);
        display5->setObjectName(QString::fromUtf8("display5"));
        display5->setScaledContents(true);

        gridLayout->addWidget(display5, 2, 0, 1, 1);

        display6 = new QLabel(gridLayoutWidget);
        display6->setObjectName(QString::fromUtf8("display6"));
        display6->setScaledContents(true);

        gridLayout->addWidget(display6, 2, 1, 1, 1);

        display1 = new QLabel(gridLayoutWidget);
        display1->setObjectName(QString::fromUtf8("display1"));
        display1->setScaledContents(true);

        gridLayout->addWidget(display1, 0, 0, 1, 1);

        display2 = new QLabel(gridLayoutWidget);
        display2->setObjectName(QString::fromUtf8("display2"));
        display2->setScaledContents(true);

        gridLayout->addWidget(display2, 0, 1, 1, 1);

        display4 = new QLabel(gridLayoutWidget);
        display4->setObjectName(QString::fromUtf8("display4"));
        display4->setScaledContents(true);

        gridLayout->addWidget(display4, 0, 3, 1, 1);

        display8 = new QLabel(gridLayoutWidget);
        display8->setObjectName(QString::fromUtf8("display8"));
        display8->setScaledContents(true);

        gridLayout->addWidget(display8, 2, 3, 1, 1);

        display3 = new QLabel(gridLayoutWidget);
        display3->setObjectName(QString::fromUtf8("display3"));
        display3->setScaledContents(true);

        gridLayout->addWidget(display3, 0, 2, 1, 1);

        display7 = new QLabel(gridLayoutWidget);
        display7->setObjectName(QString::fromUtf8("display7"));
        display7->setScaledContents(true);

        gridLayout->addWidget(display7, 2, 2, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 690, 151, 41));
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(140, 10, 121, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 10, 101, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(850, 10, 161, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1240, 10, 101, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 680, 101, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 680, 101, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(860, 680, 161, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1240, 680, 101, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1484, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        display5->setText(QString());
        display6->setText(QString());
        display1->setText(QString());
        display2->setText(QString());
        display4->setText(QString());
        display8->setText(QString());
        display3->setText(QString());
        display7->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Upload Image", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">1. Original Image</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">2. Median Blur</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">3. K-Means Segmentation</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">4. Thresholding</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">5. Erosion</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">6. Dilation</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">7. Contouring Algorithm</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">8. Final Image</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
