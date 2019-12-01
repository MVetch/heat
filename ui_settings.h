/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QDoubleSpinBox *lambda_p_edit;
    QLabel *label_9;
    QDoubleSpinBox *lambda_v_edit;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *rho_v_edit;
    QLabel *label_20;
    QDoubleSpinBox *rho_p_edit;
    QLabel *label_21;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *c_v_edit;
    QDoubleSpinBox *c_p_edit;
    QLabel *label_23;
    QLabel *label_22;
    QWidget *tab_2;
    QDoubleSpinBox *waterT;
    QLabel *label_7;
    QSpinBox *injectorsCount;
    QLabel *label;
    QTableWidget *injectorsInfo;
    QWidget *tab_5;
    QLabel *label_14;
    QLabel *label_6;
    QSpinBox *hStep;
    QSpinBox *timeToModel;
    QLabel *label_15;
    QSpinBox *thetaStep;
    QLabel *label_4;
    QLabel *label_13;
    QDoubleSpinBox *lineRad;
    QSpinBox *mmToHeat;
    QDoubleSpinBox *vSpin;
    QLabel *label_5;
    QDoubleSpinBox *editH_a;
    QLabel *label_3;
    QLabel *label_2;
    QDoubleSpinBox *editH_b;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(271, 422);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("../Khak2 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        pushButton = new QPushButton(Settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 380, 251, 31));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(Settings);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 340, 251, 31));
        pushButton_2->setAutoDefault(false);
        tabWidget = new QTabWidget(Settings);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 251, 321));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 81));
        lambda_p_edit = new QDoubleSpinBox(groupBox);
        lambda_p_edit->setObjectName(QStringLiteral("lambda_p_edit"));
        lambda_p_edit->setGeometry(QRect(100, 20, 121, 22));
        lambda_p_edit->setDecimals(1);
        lambda_p_edit->setMinimum(5);
        lambda_p_edit->setValue(27.7);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 50, 31, 21));
        lambda_v_edit = new QDoubleSpinBox(groupBox);
        lambda_v_edit->setObjectName(QStringLiteral("lambda_v_edit"));
        lambda_v_edit->setGeometry(QRect(100, 50, 121, 22));
        lambda_v_edit->setDecimals(1);
        lambda_v_edit->setMinimum(5);
        lambda_v_edit->setValue(17);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 20, 41, 21));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 110, 231, 81));
        rho_v_edit = new QDoubleSpinBox(groupBox_2);
        rho_v_edit->setObjectName(QStringLiteral("rho_v_edit"));
        rho_v_edit->setGeometry(QRect(100, 50, 121, 22));
        rho_v_edit->setDecimals(1);
        rho_v_edit->setMinimum(3000);
        rho_v_edit->setMaximum(10000);
        rho_v_edit->setSingleStep(10);
        rho_v_edit->setValue(7800);
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 50, 31, 21));
        rho_p_edit = new QDoubleSpinBox(groupBox_2);
        rho_p_edit->setObjectName(QStringLiteral("rho_p_edit"));
        rho_p_edit->setGeometry(QRect(100, 20, 121, 22));
        rho_p_edit->setDecimals(1);
        rho_p_edit->setMinimum(3000);
        rho_p_edit->setMaximum(10000);
        rho_p_edit->setSingleStep(10);
        rho_p_edit->setValue(7550);
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 20, 41, 21));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 210, 231, 81));
        c_v_edit = new QDoubleSpinBox(groupBox_3);
        c_v_edit->setObjectName(QStringLiteral("c_v_edit"));
        c_v_edit->setGeometry(QRect(100, 50, 121, 22));
        c_v_edit->setDecimals(1);
        c_v_edit->setMinimum(200);
        c_v_edit->setMaximum(700);
        c_v_edit->setSingleStep(10);
        c_v_edit->setValue(500);
        c_p_edit = new QDoubleSpinBox(groupBox_3);
        c_p_edit->setObjectName(QStringLiteral("c_p_edit"));
        c_p_edit->setGeometry(QRect(100, 20, 121, 22));
        c_p_edit->setDecimals(1);
        c_p_edit->setMinimum(200);
        c_p_edit->setMaximum(700);
        c_p_edit->setSingleStep(10);
        c_p_edit->setValue(669);
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(20, 20, 41, 21));
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 50, 31, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        waterT = new QDoubleSpinBox(tab_2);
        waterT->setObjectName(QStringLiteral("waterT"));
        waterT->setGeometry(QRect(170, 10, 71, 22));
        waterT->setMinimum(0);
        waterT->setValue(30);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 151, 21));
        injectorsCount = new QSpinBox(tab_2);
        injectorsCount->setObjectName(QStringLiteral("injectorsCount"));
        injectorsCount->setGeometry(QRect(170, 40, 71, 22));
        injectorsCount->setMinimum(1);
        injectorsCount->setMaximum(20);
        injectorsCount->setValue(6);
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 151, 21));
        injectorsInfo = new QTableWidget(tab_2);
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
        injectorsInfo->setGeometry(QRect(10, 70, 231, 221));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 180, 161, 20));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 30, 161, 21));
        hStep = new QSpinBox(tab_5);
        hStep->setObjectName(QStringLiteral("hStep"));
        hStep->setGeometry(QRect(180, 30, 51, 22));
        hStep->setMinimum(300);
        hStep->setMaximum(10000);
        hStep->setValue(300);
        timeToModel = new QSpinBox(tab_5);
        timeToModel->setObjectName(QStringLiteral("timeToModel"));
        timeToModel->setGeometry(QRect(180, 150, 51, 22));
        timeToModel->setMinimum(1);
        timeToModel->setMaximum(300);
        timeToModel->setValue(10);
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 120, 161, 21));
        thetaStep = new QSpinBox(tab_5);
        thetaStep->setObjectName(QStringLiteral("thetaStep"));
        thetaStep->setGeometry(QRect(180, 60, 51, 22));
        thetaStep->setMinimum(500);
        thetaStep->setMaximum(10000);
        thetaStep->setSingleStep(50);
        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 90, 161, 21));
        label_13 = new QLabel(tab_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 150, 161, 21));
        lineRad = new QDoubleSpinBox(tab_5);
        lineRad->setObjectName(QStringLiteral("lineRad"));
        lineRad->setGeometry(QRect(180, 90, 51, 22));
        lineRad->setDecimals(0);
        lineRad->setMinimum(100);
        lineRad->setMaximum(700);
        lineRad->setSingleStep(1);
        lineRad->setValue(450);
        mmToHeat = new QSpinBox(tab_5);
        mmToHeat->setObjectName(QStringLiteral("mmToHeat"));
        mmToHeat->setGeometry(QRect(180, 120, 51, 22));
        mmToHeat->setMinimum(10);
        mmToHeat->setMaximum(450);
        mmToHeat->setValue(40);
        vSpin = new QDoubleSpinBox(tab_5);
        vSpin->setObjectName(QStringLiteral("vSpin"));
        vSpin->setGeometry(QRect(180, 180, 51, 22));
        vSpin->setDecimals(1);
        vSpin->setMinimum(1);
        vSpin->setMaximum(30);
        vSpin->setValue(10);
        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 60, 161, 21));
        editH_a = new QDoubleSpinBox(tab_5);
        editH_a->setObjectName(QStringLiteral("editH_a"));
        editH_a->setGeometry(QRect(180, 240, 51, 22));
        editH_a->setMinimum(8);
        editH_a->setMaximum(27);
        editH_a->setValue(16);
        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 240, 151, 21));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 210, 131, 21));
        editH_b = new QDoubleSpinBox(tab_5);
        editH_b->setObjectName(QStringLiteral("editH_b"));
        editH_b->setGeometry(QRect(180, 210, 51, 22));
        editH_b->setMinimum(10);
        editH_b->setValue(28);
        tabWidget->addTab(tab_5, QString());

        retranslateUi(Settings);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        pushButton->setText(QApplication::translate("Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270 \320\277\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        pushButton_2->setText(QApplication::translate("Settings", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        groupBox->setTitle(QApplication::translate("Settings", "\320\242\320\265\320\277\320\273\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_9->setText(QApplication::translate("Settings", "\320\222\320\260\320\273\320\276\320\272", nullptr));
        label_8->setText(QApplication::translate("Settings", "\320\237\320\276\320\273\320\276\321\201\320\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("Settings", "\320\237\320\273\320\276\321\202\320\275\320\276\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", nullptr));
        label_20->setText(QApplication::translate("Settings", "\320\222\320\260\320\273\320\276\320\272", nullptr));
        label_21->setText(QApplication::translate("Settings", "\320\237\320\276\320\273\320\276\321\201\320\260", nullptr));
        groupBox_3->setTitle(QApplication::translate("Settings", "\320\242\320\265\320\277\320\273\320\276\320\265\320\274\320\272\320\276\321\201\321\202\321\214", nullptr));
        label_23->setText(QApplication::translate("Settings", "\320\237\320\276\320\273\320\276\321\201\320\260", nullptr));
        label_22->setText(QApplication::translate("Settings", "\320\222\320\260\320\273\320\276\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\265\321\202\320\260\320\273\320\273\320\260", nullptr));
        label_7->setText(QApplication::translate("Settings", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\262\320\276\320\264\321\213", nullptr));
        label->setText(QApplication::translate("Settings", "\320\232\320\276\320\273-\320\262\320\276 \321\204\320\276\321\200\321\201\321\203\320\275\320\272\320\276\320\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem = injectorsInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Settings", "\320\237\320\273\320\276\321\202\320\275\320\276\321\201\321\202\321\214, \320\273/(\320\274^2\302\267\321\201)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = injectorsInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Settings", "\320\243\320\263\320\276\320\273 \320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = injectorsInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Settings", "\320\222\320\265\320\273\320\270\321\207\320\270\320\275\320\260 \321\203\320\263\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = injectorsInfo->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Settings", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = injectorsInfo->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Settings", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = injectorsInfo->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Settings", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = injectorsInfo->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Settings", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = injectorsInfo->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("Settings", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = injectorsInfo->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("Settings", "6", nullptr));

        const bool __sortingEnabled = injectorsInfo->isSortingEnabled();
        injectorsInfo->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = injectorsInfo->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("Settings", "89,3", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = injectorsInfo->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("Settings", "72", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = injectorsInfo->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("Settings", "5,5", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = injectorsInfo->item(1, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("Settings", "89,3", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = injectorsInfo->item(1, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("Settings", "88,6", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = injectorsInfo->item(1, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("Settings", "5,5", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = injectorsInfo->item(2, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("Settings", "89,3", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = injectorsInfo->item(2, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("Settings", "108", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = injectorsInfo->item(2, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("Settings", "5,5", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = injectorsInfo->item(3, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("Settings", "89,3", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = injectorsInfo->item(3, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("Settings", "127,385", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = injectorsInfo->item(3, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("Settings", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = injectorsInfo->item(4, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("Settings", "206", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = injectorsInfo->item(4, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("Settings", "229,846", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = injectorsInfo->item(4, 2);
        ___qtablewidgetitem23->setText(QApplication::translate("Settings", "22,15", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = injectorsInfo->item(5, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("Settings", "206", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = injectorsInfo->item(5, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("Settings", "265,846", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = injectorsInfo->item(5, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("Settings", "11", nullptr));
        injectorsInfo->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Settings", "\320\236\321\205\320\273\320\260\320\266\320\264\320\265\320\275\320\270\320\265 \320\262\320\260\320\273\320\272\320\260", nullptr));
        label_14->setText(QApplication::translate("Settings", "\320\241\320\272-\321\202\321\214 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\321\217 \320\262\320\260\320\273\320\272\320\260, \320\276\320\261/\320\274\320\270\320\275", nullptr));
        label_6->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 \321\200\320\260\320\264\320\270\321\203\321\201\321\203", nullptr));
        label_15->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\200\320\260\320\261\320\276\321\207\320\265\320\263\320\276 \321\201\320\273\320\276\321\217, \320\274\320\274", nullptr));
        label_4->setText(QApplication::translate("Settings", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\262\320\260\320\273\320\272\320\260, \320\274\320\274", nullptr));
        label_13->setText(QApplication::translate("Settings", "\320\222\321\200\320\265\320\274\321\217 \320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217, \320\274\320\270\320\275", nullptr));
        label_5->setText(QApplication::translate("Settings", "\320\242\320\276\321\207\320\265\320\272 \320\277\320\276 \320\264\320\273\320\270\320\275\320\265 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_3->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\320\276\321\201\320\273\320\265, \320\274\320\274", nullptr));
        label_2->setText(QApplication::translate("Settings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\276\320\273\320\276\321\201\321\213 \320\264\320\276, \320\274\320\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Settings", "\320\236\320\261\321\211\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
