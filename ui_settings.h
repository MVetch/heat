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
#include <QtWidgets/QTableWidget>

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
    QGroupBox *groupBox_5;
    QLabel *label_7;
    QDoubleSpinBox *waterT;
    QLabel *label;
    QSpinBox *injectorsCount;
    QTableWidget *injectorsInfo;
    QGroupBox *groupBox_8;
    QLabel *label_4;
    QDoubleSpinBox *lineRad;
    QSpinBox *mmToHeat;
    QLabel *label_15;
    QLabel *label_14;
    QDoubleSpinBox *vSpin;
    QLabel *label_13;
    QSpinBox *timeToModel;
    QLabel *label_6;
    QSpinBox *hStep;
    QSpinBox *thetaStep;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_4;
    QLabel *label_3;
    QLabel *label_2;
    QDoubleSpinBox *editH_b;
    QDoubleSpinBox *editH_a;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(492, 451);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 471, 91));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 20, 41, 21));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(340, 40, 121, 21));
        label_12->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 40, 121, 21));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(190, 40, 121, 21));
        label_11->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 31, 21));
        lambda_v_edit = new QDoubleSpinBox(groupBox);
        lambda_v_edit->setObjectName(QStringLiteral("lambda_v_edit"));
        lambda_v_edit->setGeometry(QRect(50, 60, 121, 22));
        lambda_v_edit->setDecimals(1);
        lambda_v_edit->setMinimum(5);
        lambda_v_edit->setValue(17);
        lambda_p_edit = new QDoubleSpinBox(groupBox);
        lambda_p_edit->setObjectName(QStringLiteral("lambda_p_edit"));
        lambda_p_edit->setGeometry(QRect(50, 20, 121, 22));
        lambda_p_edit->setDecimals(1);
        lambda_p_edit->setMinimum(5);
        lambda_p_edit->setValue(27.7);
        rho_p_edit = new QDoubleSpinBox(groupBox);
        rho_p_edit->setObjectName(QStringLiteral("rho_p_edit"));
        rho_p_edit->setGeometry(QRect(190, 20, 121, 22));
        rho_p_edit->setDecimals(1);
        rho_p_edit->setMinimum(3000);
        rho_p_edit->setMaximum(10000);
        rho_p_edit->setSingleStep(10);
        rho_p_edit->setValue(7550);
        rho_v_edit = new QDoubleSpinBox(groupBox);
        rho_v_edit->setObjectName(QStringLiteral("rho_v_edit"));
        rho_v_edit->setGeometry(QRect(190, 60, 121, 22));
        rho_v_edit->setDecimals(1);
        rho_v_edit->setMinimum(3000);
        rho_v_edit->setMaximum(10000);
        rho_v_edit->setSingleStep(10);
        rho_v_edit->setValue(7800);
        c_p_edit = new QDoubleSpinBox(groupBox);
        c_p_edit->setObjectName(QStringLiteral("c_p_edit"));
        c_p_edit->setGeometry(QRect(340, 20, 121, 22));
        c_p_edit->setDecimals(1);
        c_p_edit->setMinimum(200);
        c_p_edit->setMaximum(700);
        c_p_edit->setSingleStep(10);
        c_p_edit->setValue(669);
        c_v_edit = new QDoubleSpinBox(groupBox);
        c_v_edit->setObjectName(QStringLiteral("c_v_edit"));
        c_v_edit->setGeometry(QRect(340, 60, 121, 22));
        c_v_edit->setDecimals(1);
        c_v_edit->setMinimum(200);
        c_v_edit->setMaximum(700);
        c_v_edit->setSingleStep(10);
        c_v_edit->setValue(500);
        groupBox_5 = new QGroupBox(Settings);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 110, 231, 291));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 20, 151, 21));
        waterT = new QDoubleSpinBox(groupBox_5);
        waterT->setObjectName(QStringLiteral("waterT"));
        waterT->setGeometry(QRect(170, 20, 51, 22));
        waterT->setMinimum(0);
        waterT->setValue(30);
        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 151, 21));
        injectorsCount = new QSpinBox(groupBox_5);
        injectorsCount->setObjectName(QStringLiteral("injectorsCount"));
        injectorsCount->setGeometry(QRect(171, 50, 51, 22));
        injectorsCount->setMinimum(1);
        injectorsCount->setMaximum(20);
        injectorsCount->setValue(6);
        injectorsInfo = new QTableWidget(groupBox_5);
        if (injectorsInfo->columnCount() < 3)
            injectorsInfo->setColumnCount(3);
        QFont font;
        font.setPointSize(8);
        font.setUnderline(false);
        font.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        injectorsInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font1);
        injectorsInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        injectorsInfo->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (injectorsInfo->rowCount() < 6)
            injectorsInfo->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        injectorsInfo->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        injectorsInfo->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        injectorsInfo->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        injectorsInfo->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        injectorsInfo->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        injectorsInfo->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        injectorsInfo->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        injectorsInfo->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        injectorsInfo->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        injectorsInfo->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        injectorsInfo->setItem(1, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        injectorsInfo->setItem(1, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        injectorsInfo->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        injectorsInfo->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        injectorsInfo->setItem(2, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        injectorsInfo->setItem(3, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        injectorsInfo->setItem(3, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        injectorsInfo->setItem(3, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        injectorsInfo->setItem(4, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        injectorsInfo->setItem(4, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        injectorsInfo->setItem(4, 2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        injectorsInfo->setItem(5, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        injectorsInfo->setItem(5, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        injectorsInfo->setItem(5, 2, __qtablewidgetitem26);
        injectorsInfo->setObjectName(QStringLiteral("injectorsInfo"));
        injectorsInfo->setGeometry(QRect(10, 80, 211, 201));
        groupBox_8 = new QGroupBox(Settings);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(250, 110, 231, 201));
        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 181, 21));
        lineRad = new QDoubleSpinBox(groupBox_8);
        lineRad->setObjectName(QStringLiteral("lineRad"));
        lineRad->setGeometry(QRect(170, 20, 51, 22));
        lineRad->setDecimals(0);
        lineRad->setMinimum(100);
        lineRad->setMaximum(700);
        lineRad->setSingleStep(1);
        lineRad->setValue(450);
        mmToHeat = new QSpinBox(groupBox_8);
        mmToHeat->setObjectName(QStringLiteral("mmToHeat"));
        mmToHeat->setGeometry(QRect(170, 50, 51, 22));
        mmToHeat->setMinimum(10);
        mmToHeat->setMaximum(450);
        mmToHeat->setValue(40);
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 50, 181, 21));
        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 170, 161, 20));
        vSpin = new QDoubleSpinBox(groupBox_8);
        vSpin->setObjectName(QStringLiteral("vSpin"));
        vSpin->setGeometry(QRect(170, 170, 51, 22));
        vSpin->setDecimals(1);
        vSpin->setMinimum(1);
        vSpin->setMaximum(30);
        vSpin->setValue(10);
        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 140, 181, 21));
        timeToModel = new QSpinBox(groupBox_8);
        timeToModel->setObjectName(QStringLiteral("timeToModel"));
        timeToModel->setGeometry(QRect(170, 140, 51, 22));
        timeToModel->setMinimum(1);
        timeToModel->setMaximum(300);
        timeToModel->setValue(10);
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 80, 181, 21));
        hStep = new QSpinBox(groupBox_8);
        hStep->setObjectName(QStringLiteral("hStep"));
        hStep->setGeometry(QRect(170, 80, 51, 22));
        hStep->setMinimum(300);
        hStep->setMaximum(10000);
        hStep->setValue(300);
        thetaStep = new QSpinBox(groupBox_8);
        thetaStep->setObjectName(QStringLiteral("thetaStep"));
        thetaStep->setGeometry(QRect(170, 110, 51, 22));
        thetaStep->setMinimum(500);
        thetaStep->setMaximum(10000);
        thetaStep->setSingleStep(50);
        label_5 = new QLabel(groupBox_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 110, 161, 21));
        pushButton = new QPushButton(Settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 410, 231, 31));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(Settings);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 410, 231, 31));
        pushButton_2->setAutoDefault(false);
        groupBox_4 = new QGroupBox(Settings);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(250, 320, 231, 81));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 151, 21));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 131, 21));
        editH_b = new QDoubleSpinBox(groupBox_4);
        editH_b->setObjectName(QStringLiteral("editH_b"));
        editH_b->setGeometry(QRect(170, 20, 51, 22));
        editH_b->setMinimum(10);
        editH_b->setValue(28);
        editH_a = new QDoubleSpinBox(groupBox_4);
        editH_a->setObjectName(QStringLiteral("editH_a"));
        editH_a->setGeometry(QRect(170, 50, 51, 22));
        editH_a->setMinimum(8);
        editH_a->setMaximum(27);
        editH_a->setValue(16);

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
        groupBox_5->setTitle(QApplication::translate("Settings", "\320\236\321\205\320\273\320\260\320\266\320\264\320\265\320\275\320\270\320\265 \320\262\320\260\320\273\320\272\320\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("Settings", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\262\320\276\320\264\321\213", Q_NULLPTR));
        label->setText(QApplication::translate("Settings", "\320\232\320\276\320\273-\320\262\320\276 \321\204\320\276\321\200\321\201\321\203\320\275\320\272\320\276\320\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = injectorsInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Settings", "\320\237\320\273\320\276\321\202\320\275\320\276\321\201\321\202\321\214, \320\273/(\320\274^2\302\267\321\201)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = injectorsInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Settings", "\320\243\320\263\320\276\320\273 \320\275\320\260\321\207\320\260\320\273\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = injectorsInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Settings", "\320\222\320\265\320\273\320\270\321\207\320\270\320\275\320\260 \321\203\320\263\320\273\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = injectorsInfo->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Settings", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = injectorsInfo->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Settings", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = injectorsInfo->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Settings", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = injectorsInfo->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Settings", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = injectorsInfo->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("Settings", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = injectorsInfo->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("Settings", "6", Q_NULLPTR));

        const bool __sortingEnabled = injectorsInfo->isSortingEnabled();
        injectorsInfo->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = injectorsInfo->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("Settings", "89,3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = injectorsInfo->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("Settings", "72", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = injectorsInfo->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("Settings", "5,5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = injectorsInfo->item(1, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("Settings", "89,3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = injectorsInfo->item(1, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("Settings", "88,6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = injectorsInfo->item(1, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("Settings", "5,5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = injectorsInfo->item(2, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("Settings", "89,3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = injectorsInfo->item(2, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("Settings", "108", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = injectorsInfo->item(2, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("Settings", "5,5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = injectorsInfo->item(3, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("Settings", "89,3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = injectorsInfo->item(3, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("Settings", "127,385", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = injectorsInfo->item(3, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("Settings", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = injectorsInfo->item(4, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("Settings", "206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = injectorsInfo->item(4, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("Settings", "229,846", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = injectorsInfo->item(4, 2);
        ___qtablewidgetitem23->setText(QApplication::translate("Settings", "22,15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = injectorsInfo->item(5, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("Settings", "206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = injectorsInfo->item(5, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("Settings", "265,846", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = injectorsInfo->item(5, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("Settings", "11", Q_NULLPTR));
        injectorsInfo->setSortingEnabled(__sortingEnabled);

        groupBox_8->setTitle(QApplication::translate("Settings", "\320\236\320\261\321\211\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
        label_4->setText(QApplication::translate("Settings", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\262\320\260\320\273\320\272\320\260, \320\274\320\274", Q_NULLPTR));
        label_15->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\200\320\260\320\261\320\276\321\207\320\265\320\263\320\276 \321\201\320\273\320\276\321\217, \320\274\320\274", Q_NULLPTR));
        label_14->setText(QApplication::translate("Settings", "\320\241\320\272-\321\202\321\214 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\321\217 \320\262\320\260\320\273\320\272\320\260, \320\276\320\261/\320\274\320\270\320\275", Q_NULLPTR));
        label_13->setText(QApplication::translate("Settings", "\320\222\321\200\320\265\320\274\321\217 \320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217, \320\274\320\270\320\275", Q_NULLPTR));
        label_6->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 \321\200\320\260\320\264\320\270\321\203\321\201\321\203", Q_NULLPTR));
        label_5->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 phi", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270 \320\277\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Settings", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Settings", "\320\236\321\207\320\260\320\263", Q_NULLPTR));
        label_3->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\320\276\321\201\320\273\320\265, \320\274\320\274", Q_NULLPTR));
        label_2->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\264\320\276, \320\274\320\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
