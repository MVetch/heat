/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *groupBox;
    QLabel *label_8;
    QLineEdit *c_p_edit;
    QLabel *label_12;
    QLineEdit *lambda_p_edit;
    QLabel *label_10;
    QLineEdit *rho_v_edit;
    QLabel *label_11;
    QLabel *label_9;
    QLineEdit *lambda_v_edit;
    QLineEdit *rho_p_edit;
    QLineEdit *c_v_edit;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLineEdit *editH_b;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineRad;
    QLineEdit *editH_a;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLineEdit *thetaStep;
    QLineEdit *hStep;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(462, 270);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 441, 111));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 30, 41, 21));
        c_p_edit = new QLineEdit(groupBox);
        c_p_edit->setObjectName(QStringLiteral("c_p_edit"));
        c_p_edit->setGeometry(QRect(320, 30, 111, 21));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(340, 50, 71, 21));
        lambda_p_edit = new QLineEdit(groupBox);
        lambda_p_edit->setObjectName(QStringLiteral("lambda_p_edit"));
        lambda_p_edit->setGeometry(QRect(60, 30, 111, 21));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 50, 101, 21));
        rho_v_edit = new QLineEdit(groupBox);
        rho_v_edit->setObjectName(QStringLiteral("rho_v_edit"));
        rho_v_edit->setGeometry(QRect(190, 70, 111, 21));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(190, 50, 111, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 70, 31, 21));
        lambda_v_edit = new QLineEdit(groupBox);
        lambda_v_edit->setObjectName(QStringLiteral("lambda_v_edit"));
        lambda_v_edit->setGeometry(QRect(60, 70, 111, 21));
        rho_p_edit = new QLineEdit(groupBox);
        rho_p_edit->setObjectName(QStringLiteral("rho_p_edit"));
        rho_p_edit->setGeometry(QRect(190, 30, 111, 21));
        c_v_edit = new QLineEdit(groupBox);
        c_v_edit->setObjectName(QStringLiteral("c_v_edit"));
        c_v_edit->setGeometry(QRect(320, 70, 111, 21));
        groupBox_2 = new QGroupBox(Settings);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 231, 131));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 101, 21));
        editH_b = new QLineEdit(groupBox_2);
        editH_b->setObjectName(QStringLiteral("editH_b"));
        editH_b->setGeometry(QRect(170, 20, 51, 21));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 131, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 151, 21));
        lineRad = new QLineEdit(groupBox_2);
        lineRad->setObjectName(QStringLiteral("lineRad"));
        lineRad->setGeometry(QRect(170, 100, 51, 21));
        editH_a = new QLineEdit(groupBox_2);
        editH_a->setObjectName(QStringLiteral("editH_a"));
        editH_a->setGeometry(QRect(170, 60, 51, 21));
        groupBox_3 = new QGroupBox(Settings);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(250, 130, 201, 81));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 50, 61, 16));
        thetaStep = new QLineEdit(groupBox_3);
        thetaStep->setObjectName(QStringLiteral("thetaStep"));
        thetaStep->setGeometry(QRect(140, 20, 51, 21));
        hStep = new QLineEdit(groupBox_3);
        hStep->setObjectName(QStringLiteral("hStep"));
        hStep->setGeometry(QRect(140, 50, 51, 21));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 61, 16));
        pushButton = new QPushButton(Settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 220, 201, 41));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\265\321\202\320\260\320\273\320\273\320\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("Settings", "\320\237\320\276\320\273\320\276\321\201\320\260", Q_NULLPTR));
        c_p_edit->setText(QApplication::translate("Settings", "481", Q_NULLPTR));
        label_12->setText(QApplication::translate("Settings", "\320\242\320\265\320\277\320\273\320\276\320\265\320\274\320\272\320\276\321\201\321\202\321\214", Q_NULLPTR));
        lambda_p_edit->setText(QApplication::translate("Settings", "58", Q_NULLPTR));
        label_10->setText(QApplication::translate("Settings", "\320\242\320\265\320\277\320\273\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        rho_v_edit->setText(QApplication::translate("Settings", "7800", Q_NULLPTR));
        label_11->setText(QApplication::translate("Settings", "\320\237\320\273\320\276\321\202\320\275\320\276\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("Settings", "\320\222\320\260\320\273\320\276\320\272", Q_NULLPTR));
        lambda_v_edit->setText(QApplication::translate("Settings", "17", Q_NULLPTR));
        rho_p_edit->setText(QApplication::translate("Settings", "7832", Q_NULLPTR));
        c_v_edit->setText(QApplication::translate("Settings", "500", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\321\200\320\276\320\272\320\260\321\202\320\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("Settings", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\262\320\260\320\273\320\272\320\260, \320\274\320\274", Q_NULLPTR));
        editH_b->setText(QApplication::translate("Settings", "28", Q_NULLPTR));
        label_2->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\264\320\276, \320\274\320\274", Q_NULLPTR));
        label_3->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\320\276\321\201\320\273\320\265, \320\274\320\274", Q_NULLPTR));
        lineRad->setText(QApplication::translate("Settings", "450", Q_NULLPTR));
        editH_a->setText(QApplication::translate("Settings", "16", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\200\320\260\321\201\321\207\320\265\321\202\320\260", Q_NULLPTR));
        label_6->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 r", Q_NULLPTR));
        thetaStep->setText(QApplication::translate("Settings", "100", Q_NULLPTR));
        hStep->setText(QApplication::translate("Settings", "300", Q_NULLPTR));
        label_5->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 phi", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
