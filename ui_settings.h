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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *groupBox;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_9;
    QDoubleSpinBox *lambda_v_edit;
    QDoubleSpinBox *lambda_p_edit;
    QDoubleSpinBox *rho_p_edit;
    QDoubleSpinBox *rho_v_edit;
    QDoubleSpinBox *c_p_edit;
    QDoubleSpinBox *c_v_edit;
    QGroupBox *groupBox_4;
    QLabel *label_3;
    QLabel *label_2;
    QDoubleSpinBox *editH_b;
    QDoubleSpinBox *editH_a;
    QGroupBox *groupBox_5;
    QLabel *label_7;
    QLabel *label;
    QDoubleSpinBox *airT;
    QDoubleSpinBox *waterT;
    QGroupBox *groupBox_8;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QSpinBox *thetaStep;
    QSpinBox *hStep;
    QDoubleSpinBox *lineRad;
    QLabel *label_13;
    QSpinBox *timeToModel;
    QDoubleSpinBox *vSpin;
    QLabel *label_14;
    QSpinBox *mmToHeat;
    QLabel *label_15;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(484, 364);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 461, 91));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 20, 41, 21));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(340, 40, 111, 21));
        label_12->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 40, 111, 21));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(200, 40, 111, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 60, 31, 21));
        lambda_v_edit = new QDoubleSpinBox(groupBox);
        lambda_v_edit->setObjectName(QStringLiteral("lambda_v_edit"));
        lambda_v_edit->setGeometry(QRect(60, 60, 111, 22));
        lambda_v_edit->setDecimals(1);
        lambda_v_edit->setMinimum(5);
        lambda_v_edit->setValue(17);
        lambda_p_edit = new QDoubleSpinBox(groupBox);
        lambda_p_edit->setObjectName(QStringLiteral("lambda_p_edit"));
        lambda_p_edit->setGeometry(QRect(60, 20, 111, 22));
        lambda_p_edit->setDecimals(1);
        lambda_p_edit->setMinimum(5);
        lambda_p_edit->setValue(58);
        rho_p_edit = new QDoubleSpinBox(groupBox);
        rho_p_edit->setObjectName(QStringLiteral("rho_p_edit"));
        rho_p_edit->setGeometry(QRect(200, 20, 111, 22));
        rho_p_edit->setDecimals(1);
        rho_p_edit->setMinimum(3000);
        rho_p_edit->setMaximum(10000);
        rho_p_edit->setSingleStep(10);
        rho_p_edit->setValue(7832);
        rho_v_edit = new QDoubleSpinBox(groupBox);
        rho_v_edit->setObjectName(QStringLiteral("rho_v_edit"));
        rho_v_edit->setGeometry(QRect(200, 60, 111, 22));
        rho_v_edit->setDecimals(1);
        rho_v_edit->setMinimum(3000);
        rho_v_edit->setMaximum(10000);
        rho_v_edit->setSingleStep(10);
        rho_v_edit->setValue(7800);
        c_p_edit = new QDoubleSpinBox(groupBox);
        c_p_edit->setObjectName(QStringLiteral("c_p_edit"));
        c_p_edit->setGeometry(QRect(340, 20, 111, 22));
        c_p_edit->setDecimals(1);
        c_p_edit->setMinimum(200);
        c_p_edit->setMaximum(700);
        c_p_edit->setSingleStep(10);
        c_p_edit->setValue(481);
        c_v_edit = new QDoubleSpinBox(groupBox);
        c_v_edit->setObjectName(QStringLiteral("c_v_edit"));
        c_v_edit->setGeometry(QRect(340, 60, 111, 22));
        c_v_edit->setDecimals(1);
        c_v_edit->setMinimum(200);
        c_v_edit->setMaximum(700);
        c_v_edit->setSingleStep(10);
        c_v_edit->setValue(500);
        groupBox_4 = new QGroupBox(Settings);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 230, 221, 81));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 151, 21));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 131, 21));
        editH_b = new QDoubleSpinBox(groupBox_4);
        editH_b->setObjectName(QStringLiteral("editH_b"));
        editH_b->setGeometry(QRect(160, 20, 51, 22));
        editH_b->setMinimum(10);
        editH_b->setValue(28);
        editH_a = new QDoubleSpinBox(groupBox_4);
        editH_a->setObjectName(QStringLiteral("editH_a"));
        editH_a->setGeometry(QRect(160, 50, 51, 22));
        editH_a->setMinimum(8);
        editH_a->setMaximum(27);
        editH_a->setValue(16);
        groupBox_5 = new QGroupBox(Settings);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(250, 230, 221, 81));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 50, 151, 21));
        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 141, 21));
        airT = new QDoubleSpinBox(groupBox_5);
        airT->setObjectName(QStringLiteral("airT"));
        airT->setGeometry(QRect(160, 20, 51, 22));
        airT->setValue(50);
        waterT = new QDoubleSpinBox(groupBox_5);
        waterT->setObjectName(QStringLiteral("waterT"));
        waterT->setGeometry(QRect(160, 50, 51, 22));
        waterT->setValue(30);
        groupBox_8 = new QGroupBox(Settings);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 110, 461, 111));
        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 101, 21));
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 20, 101, 21));
        label_5 = new QLabel(groupBox_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 20, 61, 21));
        thetaStep = new QSpinBox(groupBox_8);
        thetaStep->setObjectName(QStringLiteral("thetaStep"));
        thetaStep->setGeometry(QRect(400, 20, 51, 22));
        thetaStep->setMinimum(500);
        thetaStep->setMaximum(5000);
        thetaStep->setSingleStep(50);
        hStep = new QSpinBox(groupBox_8);
        hStep->setObjectName(QStringLiteral("hStep"));
        hStep->setGeometry(QRect(270, 20, 51, 22));
        hStep->setMinimum(30);
        hStep->setMaximum(1000);
        hStep->setValue(300);
        lineRad = new QDoubleSpinBox(groupBox_8);
        lineRad->setObjectName(QStringLiteral("lineRad"));
        lineRad->setGeometry(QRect(110, 20, 51, 22));
        lineRad->setDecimals(0);
        lineRad->setMinimum(100);
        lineRad->setMaximum(700);
        lineRad->setSingleStep(1);
        lineRad->setValue(450);
        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 50, 141, 21));
        timeToModel = new QSpinBox(groupBox_8);
        timeToModel->setObjectName(QStringLiteral("timeToModel"));
        timeToModel->setGeometry(QRect(160, 50, 51, 22));
        timeToModel->setMinimum(1);
        timeToModel->setMaximum(300);
        timeToModel->setValue(10);
        vSpin = new QDoubleSpinBox(groupBox_8);
        vSpin->setObjectName(QStringLiteral("vSpin"));
        vSpin->setGeometry(QRect(401, 50, 51, 22));
        vSpin->setDecimals(1);
        vSpin->setMinimum(1);
        vSpin->setMaximum(30);
        vSpin->setValue(10);
        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(220, 50, 181, 20));
        mmToHeat = new QSpinBox(groupBox_8);
        mmToHeat->setObjectName(QStringLiteral("mmToHeat"));
        mmToHeat->setGeometry(QRect(160, 80, 51, 22));
        mmToHeat->setMinimum(10);
        mmToHeat->setMaximum(450);
        mmToHeat->setValue(40);
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 80, 141, 21));
        pushButton = new QPushButton(Settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 320, 221, 31));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(Settings);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 320, 221, 31));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\265\321\202\320\260\320\273\320\273\320\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("Settings", "\320\237\320\276\320\273\320\276\321\201\320\260", Q_NULLPTR));
        label_12->setText(QApplication::translate("Settings", "\320\242\320\265\320\277\320\273\320\276\320\265\320\274\320\272\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_10->setText(QApplication::translate("Settings", "\320\242\320\265\320\277\320\273\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_11->setText(QApplication::translate("Settings", "\320\237\320\273\320\276\321\202\320\275\320\276\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("Settings", "\320\222\320\260\320\273\320\276\320\272", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Settings", "\320\236\321\207\320\260\320\263", Q_NULLPTR));
        label_3->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\320\276\321\201\320\273\320\265, \320\274\320\274", Q_NULLPTR));
        label_2->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\264\320\276, \320\274\320\274", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Settings", "\320\236\321\205\320\273\320\260\320\266\320\264\320\265\320\275\320\270\320\265 \320\262\320\260\320\273\320\272\320\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("Settings", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\262\320\276\320\264\321\213", Q_NULLPTR));
        label->setText(QApplication::translate("Settings", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\262\320\276\320\267\320\264\321\203\321\205\320\260", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Settings", "\320\236\320\261\321\211\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
        label_4->setText(QApplication::translate("Settings", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\262\320\260\320\273\320\272\320\260, \320\274\320\274", Q_NULLPTR));
        label_6->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 \321\200\320\260\320\264\320\270\321\203\321\201\321\203", Q_NULLPTR));
        label_5->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 phi", Q_NULLPTR));
        label_13->setText(QApplication::translate("Settings", "\320\222\321\200\320\265\320\274\321\217 \320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217, \320\274\320\270\320\275", Q_NULLPTR));
        label_14->setText(QApplication::translate("Settings", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\321\217 \320\262\320\260\320\273\320\272\320\260, \320\276\320\261/\320\274\320\270\320\275", Q_NULLPTR));
        label_15->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\200\320\260\320\261\320\276\321\207\320\265\320\263\320\276 \321\201\320\273\320\276\321\217, \320\274\320\274", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270 \320\277\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Settings", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
