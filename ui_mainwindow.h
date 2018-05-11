/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
        pushButton->setGeometry(QRect(840, 10, 221, 31));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(840, 50, 391, 291));
        tableWidget->setMaximumSize(QSize(391, 16777215));
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(false);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 350, 391, 361));
        widget_T = new QCustomPlot(groupBox);
        widget_T->setObjectName(QStringLiteral("widget_T"));
        widget_T->setGeometry(QRect(10, 20, 371, 331));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 391, 331));
        widget_q = new QCustomPlot(groupBox_2);
        widget_q->setObjectName(QStringLiteral("widget_q"));
        widget_q->setGeometry(QRect(10, 20, 371, 301));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(420, 10, 391, 331));
        widget_px = new QCustomPlot(groupBox_3);
        widget_px->setObjectName(QStringLiteral("widget_px"));
        widget_px->setGeometry(QRect(10, 20, 371, 301));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(420, 350, 391, 361));
        widget_KDef = new QCustomPlot(groupBox_4);
        widget_KDef->setObjectName(QStringLiteral("widget_KDef"));
        widget_KDef->setGeometry(QRect(10, 20, 371, 331));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(840, 350, 391, 361));
        widget_tauCont = new QCustomPlot(groupBox_5);
        widget_tauCont->setObjectName(QStringLiteral("widget_tauCont"));
        widget_tauCont->setGeometry(QRect(10, 20, 371, 331));
        openSettings = new QPushButton(centralWidget);
        openSettings->setObjectName(QStringLiteral("openSettings"));
        openSettings->setGeometry(QRect(1100, 10, 131, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202 \321\202\320\265\320\277\320\273\320\276\320\262\320\276\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\260", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\265\321\201\321\202\320\270 \321\200\320\260\321\201\321\207\320\265\321\202", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\275\320\260 \320\262\321\213\321\205\320\276\320\264\320\265 \320\270\320\267 \320\276\321\207\320\260\320\263\320\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\277\320\273\320\276\320\262\320\276\320\271 \320\277\320\276\321\202\320\276\320\272", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\264\320\260\320\262\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\265\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260 \321\202\321\200\320\265\320\275\320\270\321\217", Q_NULLPTR));
        openSettings->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
