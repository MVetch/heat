/********************************************************************************
** Form generated from reading UI file 'mainwindowphone.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWPHONE_H
#define UI_MAINWINDOWPHONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QGroupBox *groupBox_5;
    QCustomPlot *widget_tauCont;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QCustomPlot *widget_KDef;
    QLineEdit *lambda_v_edit;
    QLabel *label_2;
    QLineEdit *c_v_edit;
    QLabel *label_12;
    QGroupBox *groupBox;
    QCustomPlot *widget_T;
    QLineEdit *hStep;
    QLineEdit *editH_a;
    QLineEdit *rho_p_edit;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *rho_v_edit;
    QLineEdit *lambda_p_edit;
    QLineEdit *lineRad;
    QLineEdit *c_p_edit;
    QLabel *label_10;
    QGroupBox *groupBox_3;
    QCustomPlot *widget_px;
    QLineEdit *thetaStep;
    QLabel *label_9;
    QTableWidget *tableWidget;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QCustomPlot *widget_q;
    QLineEdit *editH_b;
    QPushButton *pushButton;
    QLabel *label_11;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 540);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(480, 80, 151, 21));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(650, 320, 301, 211));
        widget_tauCont = new QCustomPlot(groupBox_5);
        widget_tauCont->setObjectName(QStringLiteral("widget_tauCont"));
        widget_tauCont->setGeometry(QRect(10, 20, 281, 181));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(790, 20, 61, 16));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(340, 320, 281, 211));
        widget_KDef = new QCustomPlot(groupBox_4);
        widget_KDef->setObjectName(QStringLiteral("widget_KDef"));
        widget_KDef->setGeometry(QRect(10, 20, 261, 181));
        lambda_v_edit = new QLineEdit(centralwidget);
        lambda_v_edit->setObjectName(QStringLiteral("lambda_v_edit"));
        lambda_v_edit->setGeometry(QRect(50, 60, 71, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 50, 131, 21));
        c_v_edit = new QLineEdit(centralwidget);
        c_v_edit->setObjectName(QStringLiteral("c_v_edit"));
        c_v_edit->setGeometry(QRect(190, 60, 61, 31));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(220, 40, 16, 21));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 320, 311, 211));
        widget_T = new QCustomPlot(groupBox);
        widget_T->setObjectName(QStringLiteral("widget_T"));
        widget_T->setGeometry(QRect(10, 20, 291, 181));
        hStep = new QLineEdit(centralwidget);
        hStep->setObjectName(QStringLiteral("hStep"));
        hStep->setGeometry(QRect(872, 50, 71, 31));
        editH_a = new QLineEdit(centralwidget);
        editH_a->setObjectName(QStringLiteral("editH_a"));
        editH_a->setGeometry(QRect(630, 70, 81, 31));
        rho_p_edit = new QLineEdit(centralwidget);
        rho_p_edit->setObjectName(QStringLiteral("rho_p_edit"));
        rho_p_edit->setGeometry(QRect(120, 10, 71, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(480, 10, 101, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(790, 60, 61, 16));
        rho_v_edit = new QLineEdit(centralwidget);
        rho_v_edit->setObjectName(QStringLiteral("rho_v_edit"));
        rho_v_edit->setGeometry(QRect(120, 60, 71, 31));
        lambda_p_edit = new QLineEdit(centralwidget);
        lambda_p_edit->setObjectName(QStringLiteral("lambda_p_edit"));
        lambda_p_edit->setGeometry(QRect(50, 10, 71, 31));
        lineRad = new QLineEdit(centralwidget);
        lineRad->setObjectName(QStringLiteral("lineRad"));
        lineRad->setGeometry(QRect(630, 10, 81, 31));
        c_p_edit = new QLineEdit(centralwidget);
        c_p_edit->setObjectName(QStringLiteral("c_p_edit"));
        c_p_edit->setGeometry(QRect(190, 10, 61, 31));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 40, 41, 21));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(340, 100, 281, 211));
        widget_px = new QCustomPlot(groupBox_3);
        widget_px->setObjectName(QStringLiteral("widget_px"));
        widget_px->setGeometry(QRect(10, 20, 261, 181));
        thetaStep = new QLineEdit(centralwidget);
        thetaStep->setObjectName(QStringLiteral("thetaStep"));
        thetaStep->setGeometry(QRect(870, 10, 71, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 31, 21));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(650, 110, 301, 191));
        tableWidget->setMaximumSize(QSize(391, 16777215));
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(false);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 41, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 311, 211));
        widget_q = new QCustomPlot(groupBox_2);
        widget_q->setObjectName(QStringLiteral("widget_q"));
        widget_q->setGeometry(QRect(10, 20, 291, 181));
        editH_b = new QLineEdit(centralwidget);
        editH_b->setObjectName(QStringLiteral("editH_b"));
        editH_b->setGeometry(QRect(630, 40, 81, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 30, 191, 51));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(150, 40, 16, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\320\276\321\201\320\273\320\265, \320\274\320\274", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260 \321\202\321\200\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 phi", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\265\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", nullptr));
        lambda_v_edit->setText(QApplication::translate("MainWindow", "17", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\264\320\276, \320\274\320\274", nullptr));
        c_v_edit->setText(QApplication::translate("MainWindow", "500", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "c", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\275\320\260 \320\262\321\213\321\205\320\276\320\264\320\265 \320\270\320\267 \320\276\321\207\320\260\320\263\320\260", nullptr));
        hStep->setText(QApplication::translate("MainWindow", "300", nullptr));
        editH_a->setText(QApplication::translate("MainWindow", "16", nullptr));
        rho_p_edit->setText(QApplication::translate("MainWindow", "7832", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\262\320\260\320\273\320\272\320\260, \320\274\320\274", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 r", nullptr));
        rho_v_edit->setText(QApplication::translate("MainWindow", "7800", nullptr));
        lambda_p_edit->setText(QApplication::translate("MainWindow", "58", nullptr));
        lineRad->setText(QApplication::translate("MainWindow", "450", nullptr));
        c_p_edit->setText(QApplication::translate("MainWindow", "481", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "lambda", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\264\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        thetaStep->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\222\320\260\320\273\320\276\320\272", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\321\201\320\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\277\320\273\320\276\320\262\320\276\320\271 \320\277\320\276\321\202\320\276\320\272", nullptr));
        editH_b->setText(QApplication::translate("MainWindow", "28", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "rho", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWPHONE_H
