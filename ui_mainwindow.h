/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QCustomPlot *widget_T;
    QGroupBox *groupBox_2;
    QCustomPlot *widget_q;
    QGroupBox *groupBox_3;
    QCustomPlot *widget_px;
    QGroupBox *groupBox_4;
    QCustomPlot *widget_KDef;
    QGroupBox *groupBox_5;
    QCustomPlot *widget_tauCont;
    QPushButton *openSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1246, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 10, 271, 61));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(840, 90, 391, 291));
        tableWidget->setMaximumSize(QSize(391, 16777215));
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(false);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 400, 391, 311));
        widget_T = new QCustomPlot(groupBox);
        widget_T->setObjectName(QStringLiteral("widget_T"));
        widget_T->setGeometry(QRect(10, 20, 371, 281));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 80, 391, 301));
        widget_q = new QCustomPlot(groupBox_2);
        widget_q->setObjectName(QStringLiteral("widget_q"));
        widget_q->setGeometry(QRect(10, 20, 371, 271));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(420, 80, 391, 301));
        widget_px = new QCustomPlot(groupBox_3);
        widget_px->setObjectName(QStringLiteral("widget_px"));
        widget_px->setGeometry(QRect(10, 20, 371, 271));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(420, 400, 391, 311));
        widget_KDef = new QCustomPlot(groupBox_4);
        widget_KDef->setObjectName(QStringLiteral("widget_KDef"));
        widget_KDef->setGeometry(QRect(10, 20, 371, 281));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(840, 400, 391, 311));
        widget_tauCont = new QCustomPlot(groupBox_5);
        widget_tauCont->setObjectName(QStringLiteral("widget_tauCont"));
        widget_tauCont->setGeometry(QRect(10, 20, 371, 281));
        openSettings = new QPushButton(centralWidget);
        openSettings->setObjectName(QStringLiteral("openSettings"));
        openSettings->setGeometry(QRect(890, 52, 201, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\275\320\260 \320\262\321\213\321\205\320\276\320\264\320\265 \320\270\320\267 \320\276\321\207\320\260\320\263\320\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\277\320\273\320\276\320\262\320\276\320\271 \320\277\320\276\321\202\320\276\320\272", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\264\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\265\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260 \321\202\321\200\320\265\320\275\320\270\321\217", nullptr));
        openSettings->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
