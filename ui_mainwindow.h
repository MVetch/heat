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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
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
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QPushButton *openSettingsButton;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QCustomPlot *widget_tauCont;
    QWidget *tab_3;
    QCustomPlot *widget_KDef;
    QWidget *tab_4;
    QCustomPlot *widget_q;
    QWidget *tab_5;
    QCustomPlot *widget_T;
    QWidget *tab_7;
    QCustomPlot *widget_TDeep;
    QSlider *sliderDeep;
    QLabel *label_deepStart;
    QLabel *label_deepMid;
    QLabel *label_deepEnd;
    QWidget *tab_6;
    QTableWidget *tableWidget;
    QPushButton *pushButton_stop;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1090, 650);
        MainWindow->setMinimumSize(QSize(1090, 650));
        MainWindow->setMaximumSize(QSize(1090, 650));
        QIcon icon;
        icon.addFile(QStringLiteral("../Khak2 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(920, 590, 161, 31));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 590, 731, 31));
        progressBar->setMaximum(1);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        progressBar->setFormat(QString::fromUtf8("%v \320\276\320\261\320\276\321\200\320\276\321\202\320\276\320\262 \320\270\320\267 %m"));
        openSettingsButton = new QPushButton(centralWidget);
        openSettingsButton->setObjectName(QStringLiteral("openSettingsButton"));
        openSettingsButton->setGeometry(QRect(750, 590, 161, 31));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1091, 581));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget_tauCont = new QCustomPlot(tab_2);
        widget_tauCont->setObjectName(QStringLiteral("widget_tauCont"));
        widget_tauCont->setGeometry(QRect(0, 0, 1081, 551));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        widget_KDef = new QCustomPlot(tab_3);
        widget_KDef->setObjectName(QStringLiteral("widget_KDef"));
        widget_KDef->setGeometry(QRect(0, 0, 1081, 551));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        widget_q = new QCustomPlot(tab_4);
        widget_q->setObjectName(QStringLiteral("widget_q"));
        widget_q->setGeometry(QRect(0, 0, 1081, 551));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        widget_T = new QCustomPlot(tab_5);
        widget_T->setObjectName(QStringLiteral("widget_T"));
        widget_T->setGeometry(QRect(0, 0, 1081, 551));
        tabWidget->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        widget_TDeep = new QCustomPlot(tab_7);
        widget_TDeep->setObjectName(QStringLiteral("widget_TDeep"));
        widget_TDeep->setGeometry(QRect(0, 70, 1081, 481));
        sliderDeep = new QSlider(tab_7);
        sliderDeep->setObjectName(QStringLiteral("sliderDeep"));
        sliderDeep->setGeometry(QRect(20, 30, 1041, 20));
        sliderDeep->setOrientation(Qt::Horizontal);
        label_deepStart = new QLabel(tab_7);
        label_deepStart->setObjectName(QStringLiteral("label_deepStart"));
        label_deepStart->setGeometry(QRect(20, 10, 51, 21));
        label_deepMid = new QLabel(tab_7);
        label_deepMid->setObjectName(QStringLiteral("label_deepMid"));
        label_deepMid->setGeometry(QRect(520, 40, 51, 21));
        label_deepEnd = new QLabel(tab_7);
        label_deepEnd->setObjectName(QStringLiteral("label_deepEnd"));
        label_deepEnd->setGeometry(QRect(1010, 10, 51, 21));
        tabWidget->addTab(tab_7, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tableWidget = new QTableWidget(tab_6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 1071, 541));
        tableWidget->setMaximumSize(QSize(10000, 16777215));
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(false);
        tabWidget->addTab(tab_6, QString());
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(920, 590, 161, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1090, 21));
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202 \321\202\320\265\320\277\320\273\320\276\320\262\320\276\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\260", nullptr));
        callHelp->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\267\320\262\320\260\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\272\321\203", nullptr));
        action_Qt->setText(QApplication::translate("MainWindow", "\320\236 Qt", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        openSettings2->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        openSettings->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        loadSettings->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\321\203", nullptr));
        openSettingsButton->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260 \321\202\321\200\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\265\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\320\242\320\265\320\277\320\273\320\276\320\262\320\276\320\271 \320\277\320\276\321\202\320\276\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\275\320\260 \320\262\321\213\321\205\320\276\320\264\320\265 \320\270\320\267 \320\276\321\207\320\260\320\263\320\260", nullptr));
        label_deepStart->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_deepMid->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_deepEnd->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\320\265 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\321\213 \320\262 \320\263\320\273\321\203\320\261\320\270\320\275\320\265 \320\262\320\260\320\273\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
