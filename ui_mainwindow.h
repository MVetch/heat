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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *callHelp;
    QAction *action_Qt;
    QAction *action_2;
    QAction *openSettings2;
    QAction *openSettings;
    QAction *loadSettings;
    QWidget *centralWidget;
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
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QPushButton *openSettingsButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1230, 740);
        MainWindow->setMinimumSize(QSize(1230, 740));
        MainWindow->setMaximumSize(QSize(1230, 740));
        MainWindow->setAutoFillBackground(false);
        callHelp = new QAction(MainWindow);
        callHelp->setObjectName(QStringLiteral("callHelp"));
        action_Qt = new QAction(MainWindow);
        action_Qt->setObjectName(QStringLiteral("action_Qt"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        openSettings2 = new QAction(MainWindow);
        openSettings2->setObjectName(QStringLiteral("openSettings2"));
        openSettings = new QAction(MainWindow);
        openSettings->setObjectName(QStringLiteral("openSettings"));
        loadSettings = new QAction(MainWindow);
        loadSettings->setObjectName(QStringLiteral("loadSettings"));
        loadSettings->setCheckable(false);
        loadSettings->setIconVisibleInMenu(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 360, 391, 351));
        widget_T = new QCustomPlot(groupBox);
        widget_T->setObjectName(QStringLiteral("widget_T"));
        widget_T->setGeometry(QRect(10, 20, 371, 321));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 391, 341));
        widget_q = new QCustomPlot(groupBox_2);
        widget_q->setObjectName(QStringLiteral("widget_q"));
        widget_q->setGeometry(QRect(10, 20, 371, 311));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(420, 10, 391, 341));
        widget_px = new QCustomPlot(groupBox_3);
        widget_px->setObjectName(QStringLiteral("widget_px"));
        widget_px->setGeometry(QRect(10, 20, 371, 311));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(420, 360, 391, 351));
        widget_KDef = new QCustomPlot(groupBox_4);
        widget_KDef->setObjectName(QStringLiteral("widget_KDef"));
        widget_KDef->setGeometry(QRect(10, 20, 371, 321));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(830, 360, 391, 351));
        widget_tauCont = new QCustomPlot(groupBox_5);
        widget_tauCont->setObjectName(QStringLiteral("widget_tauCont"));
        widget_tauCont->setGeometry(QRect(10, 20, 371, 321));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(830, 80, 391, 271));
        tableWidget->setMaximumSize(QSize(391, 16777215));
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(830, 10, 181, 31));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(830, 50, 391, 23));
        progressBar->setMaximum(1);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        progressBar->setFormat(QString::fromUtf8("%v \320\276\320\261\320\276\321\200\320\276\321\202\320\276\320\262 \320\270\320\267 %m"));
        openSettingsButton = new QPushButton(centralWidget);
        openSettingsButton->setObjectName(QStringLiteral("openSettingsButton"));
        openSettingsButton->setGeometry(QRect(1040, 10, 181, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1230, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(loadSettings);
        menu->addSeparator();
        menu->addAction(action_2);
        menu_2->addAction(callHelp);
        menu_2->addAction(action_Qt);

        retranslateUi(MainWindow);
        QObject::connect(action_2, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202 \321\202\320\265\320\277\320\273\320\276\320\262\320\276\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\260", Q_NULLPTR));
        callHelp->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\267\320\262\320\260\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\272\321\203", Q_NULLPTR));
        action_Qt->setText(QApplication::translate("MainWindow", "\320\236 Qt", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        openSettings2->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", Q_NULLPTR));
        openSettings->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        loadSettings->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\275\320\260 \320\262\321\213\321\205\320\276\320\264\320\265 \320\270\320\267 \320\276\321\207\320\260\320\263\320\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\277\320\273\320\276\320\262\320\276\320\271 \320\277\320\276\321\202\320\276\320\272", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\264\320\260\320\262\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\265\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260 \321\202\321\200\320\265\320\275\320\270\321\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\321\203", Q_NULLPTR));
        openSettingsButton->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
