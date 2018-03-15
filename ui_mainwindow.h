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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *editH_a;
    QLineEdit *editH_b;
    QLineEdit *lineRad;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTableWidget *tableWidget;
    QLabel *labelforpicture;
    QLineEdit *thetaStep;
    QLineEdit *hStep;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *qValue;
    QLineEdit *fValue;
    QLabel *label;
    QLabel *label_7;
    QLineEdit *lambda_p_edit;
    QLineEdit *lambda_v_edit;
    QLineEdit *rho_v_edit;
    QLineEdit *rho_p_edit;
    QLineEdit *c_p_edit;
    QLineEdit *c_v_edit;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1158, 630);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(824, 50, 201, 23));
        editH_a = new QLineEdit(centralWidget);
        editH_a->setObjectName(QStringLiteral("editH_a"));
        editH_a->setGeometry(QRect(842, 20, 41, 20));
        editH_b = new QLineEdit(centralWidget);
        editH_b->setObjectName(QStringLiteral("editH_b"));
        editH_b->setGeometry(QRect(680, 20, 31, 20));
        lineRad = new QLineEdit(centralWidget);
        lineRad->setObjectName(QStringLiteral("lineRad"));
        lineRad->setGeometry(QRect(680, 50, 31, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(720, 20, 121, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(890, 20, 121, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(720, 50, 111, 21));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(530, 80, 621, 531));
        labelforpicture = new QLabel(centralWidget);
        labelforpicture->setObjectName(QStringLiteral("labelforpicture"));
        labelforpicture->setGeometry(QRect(10, 110, 500, 500));
        labelforpicture->setMinimumSize(QSize(0, 131));
        thetaStep = new QLineEdit(centralWidget);
        thetaStep->setObjectName(QStringLiteral("thetaStep"));
        thetaStep->setGeometry(QRect(1032, 20, 41, 20));
        hStep = new QLineEdit(centralWidget);
        hStep->setObjectName(QStringLiteral("hStep"));
        hStep->setGeometry(QRect(1032, 50, 41, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1080, 20, 61, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1080, 50, 47, 13));
        qValue = new QLineEdit(centralWidget);
        qValue->setObjectName(QStringLiteral("qValue"));
        qValue->setGeometry(QRect(612, 20, 41, 20));
        fValue = new QLineEdit(centralWidget);
        fValue->setObjectName(QStringLiteral("fValue"));
        fValue->setGeometry(QRect(612, 50, 41, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 20, 16, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(660, 50, 16, 21));
        lambda_p_edit = new QLineEdit(centralWidget);
        lambda_p_edit->setObjectName(QStringLiteral("lambda_p_edit"));
        lambda_p_edit->setGeometry(QRect(50, 10, 51, 20));
        lambda_v_edit = new QLineEdit(centralWidget);
        lambda_v_edit->setObjectName(QStringLiteral("lambda_v_edit"));
        lambda_v_edit->setGeometry(QRect(50, 50, 51, 20));
        rho_v_edit = new QLineEdit(centralWidget);
        rho_v_edit->setObjectName(QStringLiteral("rho_v_edit"));
        rho_v_edit->setGeometry(QRect(120, 50, 51, 20));
        rho_p_edit = new QLineEdit(centralWidget);
        rho_p_edit->setObjectName(QStringLiteral("rho_p_edit"));
        rho_p_edit->setGeometry(QRect(120, 10, 51, 20));
        c_p_edit = new QLineEdit(centralWidget);
        c_p_edit->setObjectName(QStringLiteral("c_p_edit"));
        c_p_edit->setGeometry(QRect(190, 10, 51, 20));
        c_v_edit = new QLineEdit(centralWidget);
        c_v_edit->setObjectName(QStringLiteral("c_v_edit"));
        c_v_edit->setGeometry(QRect(190, 50, 51, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 41, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 50, 31, 21));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 30, 41, 21));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(140, 30, 16, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(210, 30, 16, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", Q_NULLPTR));
        editH_a->setText(QApplication::translate("MainWindow", "0.5", Q_NULLPTR));
        editH_b->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        lineRad->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\264\320\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\320\276\321\201\320\273\320\265", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\262\320\260\320\273\320\272\320\260", Q_NULLPTR));
        labelforpicture->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        thetaStep->setText(QApplication::translate("MainWindow", "0.001", Q_NULLPTR));
        hStep->setText(QApplication::translate("MainWindow", "0.01", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263 \320\277\320\276 phi", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263 \320\277\320\276 r", Q_NULLPTR));
        qValue->setText(QApplication::translate("MainWindow", "1e7", Q_NULLPTR));
        fValue->setText(QApplication::translate("MainWindow", "1.3e3", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "q", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "f", Q_NULLPTR));
        lambda_p_edit->setText(QApplication::translate("MainWindow", "58", Q_NULLPTR));
        lambda_v_edit->setText(QApplication::translate("MainWindow", "17", Q_NULLPTR));
        rho_v_edit->setText(QApplication::translate("MainWindow", "7800", Q_NULLPTR));
        rho_p_edit->setText(QApplication::translate("MainWindow", "7832", Q_NULLPTR));
        c_p_edit->setText(QApplication::translate("MainWindow", "481", Q_NULLPTR));
        c_v_edit->setText(QApplication::translate("MainWindow", "500", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\321\201\320\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\222\320\260\320\273\320\276\320\272", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "lambda", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "rho", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "c", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
