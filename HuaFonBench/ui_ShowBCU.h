/********************************************************************************
** Form generated from reading UI file 'ShowBCU.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWBCU_H
#define UI_SHOWBCU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <src/shownetwork/gaugewidgets.h>
#include "src/public/SwitchControl.h"
#include "src/public/batteryitem.h"

QT_BEGIN_NAMESPACE

class Ui_ShowBCUClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    BatteryItem *wd_SOC;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    GaugeWidgets *wd_Current;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    GaugeWidgets *wd_Voltage;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbMOL_P;
    QLabel *lbMOL_T;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lbRSL_P;
    QLabel *lbRSL_T;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lbMSL_P;
    QLabel *lbMSL_T;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lbERROR_P;
    QLabel *lbMSL_T_7;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_12;
    SwitchControl *widget;
    QLabel *lbMOL_T_2;
    QHBoxLayout *horizontalLayout_22;
    SwitchControl *widget_2;
    QLabel *lbMOL_T_3;
    QHBoxLayout *horizontalLayout_23;
    SwitchControl *widget_3;
    QLabel *lbMOL_T_4;
    QHBoxLayout *horizontalLayout_24;
    SwitchControl *widget_4;
    QLabel *lbMOL_T_5;
    QHBoxLayout *horizontalLayout_26;
    SwitchControl *widget_5;
    QLabel *lbMOL_T_6;
    QGroupBox *groupBox_16;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_25;
    QLabel *lb_5V;
    QLabel *lbMOL_T_7;
    QHBoxLayout *horizontalLayout_27;
    QLabel *lb_24V;
    QLabel *lbMOL_T_8;
    QHBoxLayout *horizontalLayout_28;
    QLabel *lb_FTL1;
    QLabel *lbMOL_T_9;
    QHBoxLayout *horizontalLayout_29;
    QLabel *lb_FTL2;
    QLabel *lbMOL_T_10;
    QHBoxLayout *horizontalLayout_30;
    QLabel *lb_FTL3;
    QLabel *lbMOL_T_11;
    QHBoxLayout *horizontalLayout_31;
    QLabel *lb_FTL4;
    QLabel *lbMOL_T_12;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_32;
    QLabel *lb_BUTTON;
    QLabel *lbMOL_T_13;
    QHBoxLayout *horizontalLayout_33;
    QLabel *lb_Stop;
    QLabel *lbMOL_T_14;
    QHBoxLayout *horizontalLayout_34;
    QLabel *lb_Water;
    QLabel *lbMOL_T_15;
    QHBoxLayout *horizontalLayout_35;
    QLabel *lb_HuSuo;
    QLabel *lbMOL_T_16;
    QHBoxLayout *horizontalLayout_36;
    QLabel *lb_Smoke;
    QLabel *lbMOL_T_17;
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_18;
    QLabel *lbMSL_T_3;
    QLabel *lbDI_Status;
    QLabel *lbDIFbStatus;
    QHBoxLayout *horizontalLayout_19;
    QLabel *lbMSL_T_2;
    QLabel *lbDO_Status;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *lESOH;
    QLabel *label_2;
    QLineEdit *lESOE;
    QLabel *label_3;
    QLineEdit *lESOC;
    QLabel *label_17;
    QLineEdit *accDischargeCapacity;
    QLabel *label_16;
    QLineEdit *accChargeCapacity;
    QLabel *label_18;
    QLineEdit *factoryFullCapacity;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_6;
    QLineEdit *MAX_CHG_VOLT;
    QLabel *label_19;
    QLineEdit *MAX_M_VOLT;
    QLabel *label_4;
    QLineEdit *MAX_M_VOLT_ADDR;
    QLabel *label_21;
    QLineEdit *MAX_S_VOLT;
    QLabel *label_13;
    QLineEdit *MAX_S_VOLT_M_ADDR;
    QLabel *label_10;
    QLineEdit *MAX_S_VOLT_CELL_ADDR;
    QLabel *label_8;
    QLineEdit *AVERAGE_S_VOLT;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_9;
    QLineEdit *MIN_DHG_VOLT;
    QLabel *label_23;
    QLineEdit *MIN_M_VOLT;
    QLabel *label_5;
    QLineEdit *MIN_M_VOLT_ADDR;
    QLabel *label_25;
    QLineEdit *MIN_S_VOLT;
    QLabel *label_14;
    QLineEdit *MIN_S_VOLT_M_ADDR;
    QLabel *label_12;
    QLineEdit *MIN_S_VOLT_CELL_ADDR;
    QLabel *label_24;
    QLineEdit *VOLT_SUB;
    QHBoxLayout *horizontalLayout_21;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_7;
    QLineEdit *lErecommendedContinuousChargeCurrent;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_11;
    QLineEdit *lErecommendedContinuousDischargeCurrent;
    QLabel *label_28;
    QLineEdit *POSITIVE_BUS_RESISTANCE;
    QLabel *label_22;
    QLineEdit *NEGATIVE_BUS_RESISTANCE;
    QLabel *label_29;
    QLineEdit *NEGATIVE_BUS_RESISTANCE_2;
    QLabel *label_34;
    QLineEdit *NEGATIVE_BUS_RESISTANCE_3;
    QLabel *label_35;
    QLineEdit *NEGATIVE_BUS_RESISTANCE_4;
    QGroupBox *groupBox_13;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_20;
    QLineEdit *lEmaximumTemperature_ddegC;
    QLabel *label_31;
    QLineEdit *lEnrModuleMaximumTemperature;
    QLabel *label_33;
    QLineEdit *lEnrSensorMaximumTemperature;
    QLabel *label_27;
    QLineEdit *lEaverageTemperature_ddegC;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    QLineEdit *lEminimumTemperature_ddegC;
    QLabel *label_32;
    QLineEdit *lEnrModuleMinimumTemperature;
    QLabel *label_30;
    QLineEdit *lEnrSensorMinimumTemperature;
    QLabel *label_26;
    QLineEdit *TEMP_SUB;
    QTabWidget *tabWidget_DI;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_MSL;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableWidget_DO;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget_DI;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShowBCUClass)
    {
        if (ShowBCUClass->objectName().isEmpty())
            ShowBCUClass->setObjectName(QString::fromUtf8("ShowBCUClass"));
        ShowBCUClass->resize(1580, 1011);
        centralWidget = new QWidget(ShowBCUClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(16777215, 300));
        horizontalLayout_6 = new QHBoxLayout(groupBox_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(300, 0));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        wd_SOC = new BatteryItem(groupBox_4);
        wd_SOC->setObjectName(QString::fromUtf8("wd_SOC"));
        wd_SOC->setMinimumSize(QSize(0, 0));
        wd_SOC->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(wd_SOC);


        horizontalLayout_5->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd_Current = new GaugeWidgets(groupBox_2);
        wd_Current->setObjectName(QString::fromUtf8("wd_Current"));
        wd_Current->setMinimumSize(QSize(200, 200));
        wd_Current->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(wd_Current);


        horizontalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        wd_Voltage = new GaugeWidgets(groupBox_3);
        wd_Voltage->setObjectName(QString::fromUtf8("wd_Voltage"));
        wd_Voltage->setMinimumSize(QSize(200, 200));
        wd_Voltage->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(wd_Voltage);


        horizontalLayout_5->addWidget(groupBox_3);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(groupBox_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_9 = new QVBoxLayout(groupBox_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lbMOL_P = new QLabel(groupBox_7);
        lbMOL_P->setObjectName(QString::fromUtf8("lbMOL_P"));

        horizontalLayout_8->addWidget(lbMOL_P);

        lbMOL_T = new QLabel(groupBox_7);
        lbMOL_T->setObjectName(QString::fromUtf8("lbMOL_T"));

        horizontalLayout_8->addWidget(lbMOL_T);


        verticalLayout_9->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lbRSL_P = new QLabel(groupBox_7);
        lbRSL_P->setObjectName(QString::fromUtf8("lbRSL_P"));

        horizontalLayout_9->addWidget(lbRSL_P);

        lbRSL_T = new QLabel(groupBox_7);
        lbRSL_T->setObjectName(QString::fromUtf8("lbRSL_T"));

        horizontalLayout_9->addWidget(lbRSL_T);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lbMSL_P = new QLabel(groupBox_7);
        lbMSL_P->setObjectName(QString::fromUtf8("lbMSL_P"));

        horizontalLayout_10->addWidget(lbMSL_P);

        lbMSL_T = new QLabel(groupBox_7);
        lbMSL_T->setObjectName(QString::fromUtf8("lbMSL_T"));

        horizontalLayout_10->addWidget(lbMSL_T);


        verticalLayout_9->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lbERROR_P = new QLabel(groupBox_7);
        lbERROR_P->setObjectName(QString::fromUtf8("lbERROR_P"));

        horizontalLayout_11->addWidget(lbERROR_P);

        lbMSL_T_7 = new QLabel(groupBox_7);
        lbMSL_T_7->setObjectName(QString::fromUtf8("lbMSL_T_7"));

        horizontalLayout_11->addWidget(lbMSL_T_7);


        verticalLayout_9->addLayout(horizontalLayout_11);


        horizontalLayout_2->addWidget(groupBox_7);

        groupBox_9 = new QGroupBox(groupBox);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        verticalLayout_10 = new QVBoxLayout(groupBox_9);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        widget = new SwitchControl(groupBox_9);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout_12->addWidget(widget);

        lbMOL_T_2 = new QLabel(groupBox_9);
        lbMOL_T_2->setObjectName(QString::fromUtf8("lbMOL_T_2"));

        horizontalLayout_12->addWidget(lbMOL_T_2);


        verticalLayout_10->addLayout(horizontalLayout_12);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        widget_2 = new SwitchControl(groupBox_9);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        horizontalLayout_22->addWidget(widget_2);

        lbMOL_T_3 = new QLabel(groupBox_9);
        lbMOL_T_3->setObjectName(QString::fromUtf8("lbMOL_T_3"));

        horizontalLayout_22->addWidget(lbMOL_T_3);


        verticalLayout_10->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        widget_3 = new SwitchControl(groupBox_9);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        horizontalLayout_23->addWidget(widget_3);

        lbMOL_T_4 = new QLabel(groupBox_9);
        lbMOL_T_4->setObjectName(QString::fromUtf8("lbMOL_T_4"));

        horizontalLayout_23->addWidget(lbMOL_T_4);


        verticalLayout_10->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        widget_4 = new SwitchControl(groupBox_9);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        horizontalLayout_24->addWidget(widget_4);

        lbMOL_T_5 = new QLabel(groupBox_9);
        lbMOL_T_5->setObjectName(QString::fromUtf8("lbMOL_T_5"));

        horizontalLayout_24->addWidget(lbMOL_T_5);


        verticalLayout_10->addLayout(horizontalLayout_24);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        widget_5 = new SwitchControl(groupBox_9);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));

        horizontalLayout_26->addWidget(widget_5);

        lbMOL_T_6 = new QLabel(groupBox_9);
        lbMOL_T_6->setObjectName(QString::fromUtf8("lbMOL_T_6"));

        horizontalLayout_26->addWidget(lbMOL_T_6);


        verticalLayout_10->addLayout(horizontalLayout_26);


        horizontalLayout_2->addWidget(groupBox_9);

        groupBox_16 = new QGroupBox(groupBox);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        verticalLayout_11 = new QVBoxLayout(groupBox_16);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        lb_5V = new QLabel(groupBox_16);
        lb_5V->setObjectName(QString::fromUtf8("lb_5V"));

        horizontalLayout_25->addWidget(lb_5V);

        lbMOL_T_7 = new QLabel(groupBox_16);
        lbMOL_T_7->setObjectName(QString::fromUtf8("lbMOL_T_7"));

        horizontalLayout_25->addWidget(lbMOL_T_7);


        verticalLayout_11->addLayout(horizontalLayout_25);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        lb_24V = new QLabel(groupBox_16);
        lb_24V->setObjectName(QString::fromUtf8("lb_24V"));

        horizontalLayout_27->addWidget(lb_24V);

        lbMOL_T_8 = new QLabel(groupBox_16);
        lbMOL_T_8->setObjectName(QString::fromUtf8("lbMOL_T_8"));

        horizontalLayout_27->addWidget(lbMOL_T_8);


        verticalLayout_11->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        lb_FTL1 = new QLabel(groupBox_16);
        lb_FTL1->setObjectName(QString::fromUtf8("lb_FTL1"));

        horizontalLayout_28->addWidget(lb_FTL1);

        lbMOL_T_9 = new QLabel(groupBox_16);
        lbMOL_T_9->setObjectName(QString::fromUtf8("lbMOL_T_9"));

        horizontalLayout_28->addWidget(lbMOL_T_9);


        verticalLayout_11->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        lb_FTL2 = new QLabel(groupBox_16);
        lb_FTL2->setObjectName(QString::fromUtf8("lb_FTL2"));

        horizontalLayout_29->addWidget(lb_FTL2);

        lbMOL_T_10 = new QLabel(groupBox_16);
        lbMOL_T_10->setObjectName(QString::fromUtf8("lbMOL_T_10"));

        horizontalLayout_29->addWidget(lbMOL_T_10);


        verticalLayout_11->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        lb_FTL3 = new QLabel(groupBox_16);
        lb_FTL3->setObjectName(QString::fromUtf8("lb_FTL3"));

        horizontalLayout_30->addWidget(lb_FTL3);

        lbMOL_T_11 = new QLabel(groupBox_16);
        lbMOL_T_11->setObjectName(QString::fromUtf8("lbMOL_T_11"));

        horizontalLayout_30->addWidget(lbMOL_T_11);


        verticalLayout_11->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        lb_FTL4 = new QLabel(groupBox_16);
        lb_FTL4->setObjectName(QString::fromUtf8("lb_FTL4"));

        horizontalLayout_31->addWidget(lb_FTL4);

        lbMOL_T_12 = new QLabel(groupBox_16);
        lbMOL_T_12->setObjectName(QString::fromUtf8("lbMOL_T_12"));

        horizontalLayout_31->addWidget(lbMOL_T_12);


        verticalLayout_11->addLayout(horizontalLayout_31);


        horizontalLayout_2->addWidget(groupBox_16);

        groupBox_11 = new QGroupBox(groupBox);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        verticalLayout_13 = new QVBoxLayout(groupBox_11);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        lb_BUTTON = new QLabel(groupBox_11);
        lb_BUTTON->setObjectName(QString::fromUtf8("lb_BUTTON"));

        horizontalLayout_32->addWidget(lb_BUTTON);

        lbMOL_T_13 = new QLabel(groupBox_11);
        lbMOL_T_13->setObjectName(QString::fromUtf8("lbMOL_T_13"));

        horizontalLayout_32->addWidget(lbMOL_T_13);


        verticalLayout_13->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        lb_Stop = new QLabel(groupBox_11);
        lb_Stop->setObjectName(QString::fromUtf8("lb_Stop"));

        horizontalLayout_33->addWidget(lb_Stop);

        lbMOL_T_14 = new QLabel(groupBox_11);
        lbMOL_T_14->setObjectName(QString::fromUtf8("lbMOL_T_14"));

        horizontalLayout_33->addWidget(lbMOL_T_14);


        verticalLayout_13->addLayout(horizontalLayout_33);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        lb_Water = new QLabel(groupBox_11);
        lb_Water->setObjectName(QString::fromUtf8("lb_Water"));

        horizontalLayout_34->addWidget(lb_Water);

        lbMOL_T_15 = new QLabel(groupBox_11);
        lbMOL_T_15->setObjectName(QString::fromUtf8("lbMOL_T_15"));

        horizontalLayout_34->addWidget(lbMOL_T_15);


        verticalLayout_13->addLayout(horizontalLayout_34);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        lb_HuSuo = new QLabel(groupBox_11);
        lb_HuSuo->setObjectName(QString::fromUtf8("lb_HuSuo"));

        horizontalLayout_35->addWidget(lb_HuSuo);

        lbMOL_T_16 = new QLabel(groupBox_11);
        lbMOL_T_16->setObjectName(QString::fromUtf8("lbMOL_T_16"));

        horizontalLayout_35->addWidget(lbMOL_T_16);


        verticalLayout_13->addLayout(horizontalLayout_35);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        lb_Smoke = new QLabel(groupBox_11);
        lb_Smoke->setObjectName(QString::fromUtf8("lb_Smoke"));

        horizontalLayout_36->addWidget(lb_Smoke);

        lbMOL_T_17 = new QLabel(groupBox_11);
        lbMOL_T_17->setObjectName(QString::fromUtf8("lbMOL_T_17"));

        horizontalLayout_36->addWidget(lbMOL_T_17);


        verticalLayout_13->addLayout(horizontalLayout_36);


        horizontalLayout_2->addWidget(groupBox_11);

        groupBox_15 = new QGroupBox(groupBox);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        verticalLayout_12 = new QVBoxLayout(groupBox_15);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        lbMSL_T_3 = new QLabel(groupBox_15);
        lbMSL_T_3->setObjectName(QString::fromUtf8("lbMSL_T_3"));

        horizontalLayout_18->addWidget(lbMSL_T_3);

        lbDI_Status = new QLabel(groupBox_15);
        lbDI_Status->setObjectName(QString::fromUtf8("lbDI_Status"));

        horizontalLayout_18->addWidget(lbDI_Status);


        verticalLayout_12->addLayout(horizontalLayout_18);

        lbDIFbStatus = new QLabel(groupBox_15);
        lbDIFbStatus->setObjectName(QString::fromUtf8("lbDIFbStatus"));

        verticalLayout_12->addWidget(lbDIFbStatus);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        lbMSL_T_2 = new QLabel(groupBox_15);
        lbMSL_T_2->setObjectName(QString::fromUtf8("lbMSL_T_2"));

        horizontalLayout_19->addWidget(lbMSL_T_2);

        lbDO_Status = new QLabel(groupBox_15);
        lbDO_Status->setObjectName(QString::fromUtf8("lbDO_Status"));

        horizontalLayout_19->addWidget(lbDO_Status);


        verticalLayout_12->addLayout(horizontalLayout_19);


        horizontalLayout_2->addWidget(groupBox_15);


        horizontalLayout_6->addWidget(groupBox);


        verticalLayout_5->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(16777215, 300));
        horizontalLayout_7 = new QHBoxLayout(groupBox_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(groupBox_6);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        lESOH = new QLineEdit(groupBox_6);
        lESOH->setObjectName(QString::fromUtf8("lESOH"));
        lESOH->setReadOnly(true);

        horizontalLayout_7->addWidget(lESOH);

        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        lESOE = new QLineEdit(groupBox_6);
        lESOE->setObjectName(QString::fromUtf8("lESOE"));
        lESOE->setReadOnly(true);

        horizontalLayout_7->addWidget(lESOE);

        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        lESOC = new QLineEdit(groupBox_6);
        lESOC->setObjectName(QString::fromUtf8("lESOC"));
        lESOC->setReadOnly(true);

        horizontalLayout_7->addWidget(lESOC);

        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_7->addWidget(label_17);

        accDischargeCapacity = new QLineEdit(groupBox_6);
        accDischargeCapacity->setObjectName(QString::fromUtf8("accDischargeCapacity"));
        accDischargeCapacity->setReadOnly(true);

        horizontalLayout_7->addWidget(accDischargeCapacity);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_7->addWidget(label_16);

        accChargeCapacity = new QLineEdit(groupBox_6);
        accChargeCapacity->setObjectName(QString::fromUtf8("accChargeCapacity"));
        accChargeCapacity->setReadOnly(true);

        horizontalLayout_7->addWidget(accChargeCapacity);

        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_7->addWidget(label_18);

        factoryFullCapacity = new QLineEdit(groupBox_6);
        factoryFullCapacity->setObjectName(QString::fromUtf8("factoryFullCapacity"));
        factoryFullCapacity->setReadOnly(true);

        horizontalLayout_7->addWidget(factoryFullCapacity);


        verticalLayout_5->addWidget(groupBox_6);

        groupBox_10 = new QGroupBox(centralWidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMaximumSize(QSize(16777215, 300));
        verticalLayout_6 = new QVBoxLayout(groupBox_10);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_12 = new QGroupBox(groupBox_10);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        verticalLayout_4 = new QVBoxLayout(groupBox_12);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_6 = new QLabel(groupBox_12);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_14->addWidget(label_6);

        MAX_CHG_VOLT = new QLineEdit(groupBox_12);
        MAX_CHG_VOLT->setObjectName(QString::fromUtf8("MAX_CHG_VOLT"));
        MAX_CHG_VOLT->setReadOnly(true);

        horizontalLayout_14->addWidget(MAX_CHG_VOLT);

        label_19 = new QLabel(groupBox_12);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_14->addWidget(label_19);

        MAX_M_VOLT = new QLineEdit(groupBox_12);
        MAX_M_VOLT->setObjectName(QString::fromUtf8("MAX_M_VOLT"));
        MAX_M_VOLT->setReadOnly(true);

        horizontalLayout_14->addWidget(MAX_M_VOLT);

        label_4 = new QLabel(groupBox_12);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_14->addWidget(label_4);

        MAX_M_VOLT_ADDR = new QLineEdit(groupBox_12);
        MAX_M_VOLT_ADDR->setObjectName(QString::fromUtf8("MAX_M_VOLT_ADDR"));
        MAX_M_VOLT_ADDR->setReadOnly(true);

        horizontalLayout_14->addWidget(MAX_M_VOLT_ADDR);

        label_21 = new QLabel(groupBox_12);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_14->addWidget(label_21);

        MAX_S_VOLT = new QLineEdit(groupBox_12);
        MAX_S_VOLT->setObjectName(QString::fromUtf8("MAX_S_VOLT"));
        MAX_S_VOLT->setReadOnly(true);

        horizontalLayout_14->addWidget(MAX_S_VOLT);

        label_13 = new QLabel(groupBox_12);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_14->addWidget(label_13);

        MAX_S_VOLT_M_ADDR = new QLineEdit(groupBox_12);
        MAX_S_VOLT_M_ADDR->setObjectName(QString::fromUtf8("MAX_S_VOLT_M_ADDR"));
        MAX_S_VOLT_M_ADDR->setReadOnly(true);

        horizontalLayout_14->addWidget(MAX_S_VOLT_M_ADDR);

        label_10 = new QLabel(groupBox_12);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_14->addWidget(label_10);

        MAX_S_VOLT_CELL_ADDR = new QLineEdit(groupBox_12);
        MAX_S_VOLT_CELL_ADDR->setObjectName(QString::fromUtf8("MAX_S_VOLT_CELL_ADDR"));
        MAX_S_VOLT_CELL_ADDR->setReadOnly(true);

        horizontalLayout_14->addWidget(MAX_S_VOLT_CELL_ADDR);

        label_8 = new QLabel(groupBox_12);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_14->addWidget(label_8);

        AVERAGE_S_VOLT = new QLineEdit(groupBox_12);
        AVERAGE_S_VOLT->setObjectName(QString::fromUtf8("AVERAGE_S_VOLT"));
        AVERAGE_S_VOLT->setReadOnly(true);

        horizontalLayout_14->addWidget(AVERAGE_S_VOLT);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_9 = new QLabel(groupBox_12);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_15->addWidget(label_9);

        MIN_DHG_VOLT = new QLineEdit(groupBox_12);
        MIN_DHG_VOLT->setObjectName(QString::fromUtf8("MIN_DHG_VOLT"));
        MIN_DHG_VOLT->setReadOnly(true);

        horizontalLayout_15->addWidget(MIN_DHG_VOLT);

        label_23 = new QLabel(groupBox_12);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_15->addWidget(label_23);

        MIN_M_VOLT = new QLineEdit(groupBox_12);
        MIN_M_VOLT->setObjectName(QString::fromUtf8("MIN_M_VOLT"));
        MIN_M_VOLT->setReadOnly(true);

        horizontalLayout_15->addWidget(MIN_M_VOLT);

        label_5 = new QLabel(groupBox_12);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_15->addWidget(label_5);

        MIN_M_VOLT_ADDR = new QLineEdit(groupBox_12);
        MIN_M_VOLT_ADDR->setObjectName(QString::fromUtf8("MIN_M_VOLT_ADDR"));
        MIN_M_VOLT_ADDR->setReadOnly(true);

        horizontalLayout_15->addWidget(MIN_M_VOLT_ADDR);

        label_25 = new QLabel(groupBox_12);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_15->addWidget(label_25);

        MIN_S_VOLT = new QLineEdit(groupBox_12);
        MIN_S_VOLT->setObjectName(QString::fromUtf8("MIN_S_VOLT"));
        MIN_S_VOLT->setReadOnly(true);

        horizontalLayout_15->addWidget(MIN_S_VOLT);

        label_14 = new QLabel(groupBox_12);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_15->addWidget(label_14);

        MIN_S_VOLT_M_ADDR = new QLineEdit(groupBox_12);
        MIN_S_VOLT_M_ADDR->setObjectName(QString::fromUtf8("MIN_S_VOLT_M_ADDR"));
        MIN_S_VOLT_M_ADDR->setReadOnly(true);

        horizontalLayout_15->addWidget(MIN_S_VOLT_M_ADDR);

        label_12 = new QLabel(groupBox_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_15->addWidget(label_12);

        MIN_S_VOLT_CELL_ADDR = new QLineEdit(groupBox_12);
        MIN_S_VOLT_CELL_ADDR->setObjectName(QString::fromUtf8("MIN_S_VOLT_CELL_ADDR"));
        MIN_S_VOLT_CELL_ADDR->setReadOnly(true);

        horizontalLayout_15->addWidget(MIN_S_VOLT_CELL_ADDR);

        label_24 = new QLabel(groupBox_12);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_15->addWidget(label_24);

        VOLT_SUB = new QLineEdit(groupBox_12);
        VOLT_SUB->setObjectName(QString::fromUtf8("VOLT_SUB"));
        VOLT_SUB->setReadOnly(true);

        horizontalLayout_15->addWidget(VOLT_SUB);


        verticalLayout_4->addLayout(horizontalLayout_15);


        verticalLayout_6->addWidget(groupBox_12);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        groupBox_14 = new QGroupBox(groupBox_10);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        verticalLayout_2 = new QVBoxLayout(groupBox_14);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_7 = new QLabel(groupBox_14);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_13->addWidget(label_7);

        lErecommendedContinuousChargeCurrent = new QLineEdit(groupBox_14);
        lErecommendedContinuousChargeCurrent->setObjectName(QString::fromUtf8("lErecommendedContinuousChargeCurrent"));
        lErecommendedContinuousChargeCurrent->setReadOnly(true);

        horizontalLayout_13->addWidget(lErecommendedContinuousChargeCurrent);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_11 = new QLabel(groupBox_14);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_20->addWidget(label_11);

        lErecommendedContinuousDischargeCurrent = new QLineEdit(groupBox_14);
        lErecommendedContinuousDischargeCurrent->setObjectName(QString::fromUtf8("lErecommendedContinuousDischargeCurrent"));
        lErecommendedContinuousDischargeCurrent->setReadOnly(true);

        horizontalLayout_20->addWidget(lErecommendedContinuousDischargeCurrent);


        verticalLayout_2->addLayout(horizontalLayout_20);


        horizontalLayout_21->addWidget(groupBox_14);

        label_28 = new QLabel(groupBox_10);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_21->addWidget(label_28);

        POSITIVE_BUS_RESISTANCE = new QLineEdit(groupBox_10);
        POSITIVE_BUS_RESISTANCE->setObjectName(QString::fromUtf8("POSITIVE_BUS_RESISTANCE"));
        POSITIVE_BUS_RESISTANCE->setReadOnly(true);

        horizontalLayout_21->addWidget(POSITIVE_BUS_RESISTANCE);

        label_22 = new QLabel(groupBox_10);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_21->addWidget(label_22);

        NEGATIVE_BUS_RESISTANCE = new QLineEdit(groupBox_10);
        NEGATIVE_BUS_RESISTANCE->setObjectName(QString::fromUtf8("NEGATIVE_BUS_RESISTANCE"));
        NEGATIVE_BUS_RESISTANCE->setReadOnly(true);

        horizontalLayout_21->addWidget(NEGATIVE_BUS_RESISTANCE);

        label_29 = new QLabel(groupBox_10);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_21->addWidget(label_29);

        NEGATIVE_BUS_RESISTANCE_2 = new QLineEdit(groupBox_10);
        NEGATIVE_BUS_RESISTANCE_2->setObjectName(QString::fromUtf8("NEGATIVE_BUS_RESISTANCE_2"));
        NEGATIVE_BUS_RESISTANCE_2->setReadOnly(true);

        horizontalLayout_21->addWidget(NEGATIVE_BUS_RESISTANCE_2);

        label_34 = new QLabel(groupBox_10);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_21->addWidget(label_34);

        NEGATIVE_BUS_RESISTANCE_3 = new QLineEdit(groupBox_10);
        NEGATIVE_BUS_RESISTANCE_3->setObjectName(QString::fromUtf8("NEGATIVE_BUS_RESISTANCE_3"));
        NEGATIVE_BUS_RESISTANCE_3->setReadOnly(true);

        horizontalLayout_21->addWidget(NEGATIVE_BUS_RESISTANCE_3);

        label_35 = new QLabel(groupBox_10);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_21->addWidget(label_35);

        NEGATIVE_BUS_RESISTANCE_4 = new QLineEdit(groupBox_10);
        NEGATIVE_BUS_RESISTANCE_4->setObjectName(QString::fromUtf8("NEGATIVE_BUS_RESISTANCE_4"));
        NEGATIVE_BUS_RESISTANCE_4->setReadOnly(true);

        horizontalLayout_21->addWidget(NEGATIVE_BUS_RESISTANCE_4);

        groupBox_13 = new QGroupBox(groupBox_10);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        verticalLayout = new QVBoxLayout(groupBox_13);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_20 = new QLabel(groupBox_13);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_16->addWidget(label_20);

        lEmaximumTemperature_ddegC = new QLineEdit(groupBox_13);
        lEmaximumTemperature_ddegC->setObjectName(QString::fromUtf8("lEmaximumTemperature_ddegC"));
        lEmaximumTemperature_ddegC->setReadOnly(true);

        horizontalLayout_16->addWidget(lEmaximumTemperature_ddegC);

        label_31 = new QLabel(groupBox_13);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_16->addWidget(label_31);

        lEnrModuleMaximumTemperature = new QLineEdit(groupBox_13);
        lEnrModuleMaximumTemperature->setObjectName(QString::fromUtf8("lEnrModuleMaximumTemperature"));
        lEnrModuleMaximumTemperature->setReadOnly(true);

        horizontalLayout_16->addWidget(lEnrModuleMaximumTemperature);

        label_33 = new QLabel(groupBox_13);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_16->addWidget(label_33);

        lEnrSensorMaximumTemperature = new QLineEdit(groupBox_13);
        lEnrSensorMaximumTemperature->setObjectName(QString::fromUtf8("lEnrSensorMaximumTemperature"));
        lEnrSensorMaximumTemperature->setReadOnly(true);

        horizontalLayout_16->addWidget(lEnrSensorMaximumTemperature);

        label_27 = new QLabel(groupBox_13);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_16->addWidget(label_27);

        lEaverageTemperature_ddegC = new QLineEdit(groupBox_13);
        lEaverageTemperature_ddegC->setObjectName(QString::fromUtf8("lEaverageTemperature_ddegC"));
        lEaverageTemperature_ddegC->setReadOnly(true);

        horizontalLayout_16->addWidget(lEaverageTemperature_ddegC);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_15 = new QLabel(groupBox_13);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_17->addWidget(label_15);

        lEminimumTemperature_ddegC = new QLineEdit(groupBox_13);
        lEminimumTemperature_ddegC->setObjectName(QString::fromUtf8("lEminimumTemperature_ddegC"));
        lEminimumTemperature_ddegC->setReadOnly(true);

        horizontalLayout_17->addWidget(lEminimumTemperature_ddegC);

        label_32 = new QLabel(groupBox_13);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_17->addWidget(label_32);

        lEnrModuleMinimumTemperature = new QLineEdit(groupBox_13);
        lEnrModuleMinimumTemperature->setObjectName(QString::fromUtf8("lEnrModuleMinimumTemperature"));
        lEnrModuleMinimumTemperature->setReadOnly(true);

        horizontalLayout_17->addWidget(lEnrModuleMinimumTemperature);

        label_30 = new QLabel(groupBox_13);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_17->addWidget(label_30);

        lEnrSensorMinimumTemperature = new QLineEdit(groupBox_13);
        lEnrSensorMinimumTemperature->setObjectName(QString::fromUtf8("lEnrSensorMinimumTemperature"));
        lEnrSensorMinimumTemperature->setReadOnly(true);

        horizontalLayout_17->addWidget(lEnrSensorMinimumTemperature);

        label_26 = new QLabel(groupBox_13);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_17->addWidget(label_26);

        TEMP_SUB = new QLineEdit(groupBox_13);
        TEMP_SUB->setObjectName(QString::fromUtf8("TEMP_SUB"));
        TEMP_SUB->setReadOnly(true);

        horizontalLayout_17->addWidget(TEMP_SUB);


        verticalLayout->addLayout(horizontalLayout_17);


        horizontalLayout_21->addWidget(groupBox_13);


        verticalLayout_6->addLayout(horizontalLayout_21);


        verticalLayout_5->addWidget(groupBox_10);

        tabWidget_DI = new QTabWidget(centralWidget);
        tabWidget_DI->setObjectName(QString::fromUtf8("tabWidget_DI"));
        tabWidget_DI->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget_MSL = new QTableWidget(tab);
        tableWidget_MSL->setObjectName(QString::fromUtf8("tableWidget_MSL"));
        tableWidget_MSL->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(tableWidget_MSL);

        tabWidget_DI->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_7 = new QVBoxLayout(tab_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tableWidget_DO = new QTableWidget(tab_2);
        tableWidget_DO->setObjectName(QString::fromUtf8("tableWidget_DO"));
        tableWidget_DO->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(tableWidget_DO);

        tabWidget_DI->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_8 = new QVBoxLayout(tab_3);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableWidget_DI = new QTableWidget(tab_3);
        if (tableWidget_DI->columnCount() < 10)
            tableWidget_DI->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_DI->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget_DI->setObjectName(QString::fromUtf8("tableWidget_DI"));
        tableWidget_DI->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_8->addWidget(tableWidget_DI);

        tabWidget_DI->addTab(tab_3, QString());

        verticalLayout_5->addWidget(tabWidget_DI);

        ShowBCUClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ShowBCUClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1580, 23));
        ShowBCUClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ShowBCUClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ShowBCUClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ShowBCUClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ShowBCUClass->setStatusBar(statusBar);

        retranslateUi(ShowBCUClass);

        tabWidget_DI->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ShowBCUClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShowBCUClass)
    {
        ShowBCUClass->setWindowTitle(QCoreApplication::translate("ShowBCUClass", "ShowBCU", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240\347\212\266\346\200\201", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240\346\200\273\346\265\201", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240\347\224\265\345\216\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ShowBCUClass", "\345\221\212\350\255\246\344\277\241\346\201\257", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("ShowBCUClass", "\345\221\212\350\255\246\346\214\207\347\244\272", nullptr));
        lbMOL_P->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T->setText(QCoreApplication::translate("ShowBCUClass", "\350\275\273\345\276\256\345\221\212\350\255\246", nullptr));
        lbRSL_P->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbRSL_T->setText(QCoreApplication::translate("ShowBCUClass", "\344\270\200\350\210\254\345\221\212\350\255\246", nullptr));
        lbMSL_P->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMSL_T->setText(QCoreApplication::translate("ShowBCUClass", "\344\270\245\351\207\215\345\221\212\350\255\246", nullptr));
        lbERROR_P->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMSL_T_7->setText(QCoreApplication::translate("ShowBCUClass", "\351\224\231\350\257\257\346\214\207\347\244\272", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("ShowBCUClass", "\346\216\245\350\247\246\345\231\250\347\212\266\346\200\201", nullptr));
        lbMOL_T_2->setText(QCoreApplication::translate("ShowBCUClass", "\350\264\237\346\216\245\350\247\246\345\231\250", nullptr));
        lbMOL_T_3->setText(QCoreApplication::translate("ShowBCUClass", "\351\242\204\345\205\205\346\216\245\350\247\246\345\231\250", nullptr));
        lbMOL_T_4->setText(QCoreApplication::translate("ShowBCUClass", "\346\255\243\346\216\245\350\247\246\345\231\250", nullptr));
        lbMOL_T_5->setText(QCoreApplication::translate("ShowBCUClass", "\345\205\205\347\224\265\346\216\245\350\247\246\345\231\250", nullptr));
        lbMOL_T_6->setText(QCoreApplication::translate("ShowBCUClass", "PWR\346\216\245\350\247\246\345\231\250", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("ShowBCUClass", "\350\276\223\345\205\245\344\277\241\345\217\267\347\212\266\346\200\201", nullptr));
        lb_5V->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_7->setText(QCoreApplication::translate("ShowBCUClass", "5V\344\277\241\345\217\267", nullptr));
        lb_24V->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_8->setText(QCoreApplication::translate("ShowBCUClass", "24V\344\277\241\345\217\267", nullptr));
        lb_FTL1->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_9->setText(QCoreApplication::translate("ShowBCUClass", "FTL1\344\277\241\345\217\267", nullptr));
        lb_FTL2->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_10->setText(QCoreApplication::translate("ShowBCUClass", "FTL2\344\277\241\345\217\267", nullptr));
        lb_FTL3->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_11->setText(QCoreApplication::translate("ShowBCUClass", "FTL3\344\277\241\345\217\267", nullptr));
        lb_FTL4->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_12->setText(QCoreApplication::translate("ShowBCUClass", "FTL4\344\277\241\345\217\267", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("ShowBCUClass", "\345\244\226\346\216\245\350\276\223\345\205\245\344\277\241\345\217\267\347\212\266\346\200\201", nullptr));
        lb_BUTTON->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_13->setText(QCoreApplication::translate("ShowBCUClass", "BUTTON\344\277\241\345\217\267", nullptr));
        lb_Stop->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_14->setText(QCoreApplication::translate("ShowBCUClass", "\346\200\245\345\201\234\344\277\241\345\217\267", nullptr));
        lb_Water->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_15->setText(QCoreApplication::translate("ShowBCUClass", "\346\260\264\346\265\270\344\277\241\345\217\267", nullptr));
        lb_HuSuo->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_16->setText(QCoreApplication::translate("ShowBCUClass", "\351\253\230\345\216\213\344\272\222\351\224\201\344\277\241\345\217\267", nullptr));
        lb_Smoke->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T_17->setText(QCoreApplication::translate("ShowBCUClass", "\347\203\237\346\204\237\344\277\241\345\217\267", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("ShowBCUClass", "DI/DO\347\212\266\346\200\201", nullptr));
        lbMSL_T_3->setText(QCoreApplication::translate("ShowBCUClass", "DI\344\270\200\350\207\264\346\200\247:", nullptr));
        lbDI_Status->setText(QCoreApplication::translate("ShowBCUClass", "DI\345\217\215\351\246\210\347\212\266\346\200\201:", nullptr));
        lbDIFbStatus->setText(QString());
        lbMSL_T_2->setText(QCoreApplication::translate("ShowBCUClass", "DO\344\270\200\350\207\264\346\200\247:", nullptr));
        lbDO_Status->setText(QCoreApplication::translate("ShowBCUClass", "DO\345\217\215\351\246\210\347\212\266\346\200\201:", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("ShowBCUClass", "SOH%", nullptr));
        label_2->setText(QCoreApplication::translate("ShowBCUClass", "SOE%", nullptr));
        label_3->setText(QCoreApplication::translate("ShowBCUClass", "SOC%", nullptr));
        label_17->setText(QCoreApplication::translate("ShowBCUClass", "\347\264\257\350\256\241\346\224\276\347\224\265\345\256\271\351\207\217(Ah)", nullptr));
        label_16->setText(QCoreApplication::translate("ShowBCUClass", "\347\264\257\350\256\241\345\205\205\347\224\265\345\256\271\351\207\217(Ah)", nullptr));
        label_18->setText(QCoreApplication::translate("ShowBCUClass", "\347\263\273\347\273\237\346\200\273\346\200\273\345\256\271\351\207\217(Ah)", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("ShowBCUClass", "\350\277\220\350\241\214\346\225\260\346\215\256\346\214\207\347\244\272", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\345\216\213", nullptr));
        label_6->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\345\205\201\350\256\270\345\205\205\347\224\265\347\224\265\345\216\213", nullptr));
        label_19->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\346\250\241\347\273\204\347\224\265\345\216\213", nullptr));
        label_4->setText(QCoreApplication::translate("ShowBCUClass", "->\346\250\241\347\273\204\344\275\215\347\275\256", nullptr));
        label_21->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\345\215\225\344\275\223\347\224\265\345\216\213", nullptr));
        label_13->setText(QCoreApplication::translate("ShowBCUClass", "->\346\250\241\347\273\204\347\274\226\345\217\267", nullptr));
        label_10->setText(QCoreApplication::translate("ShowBCUClass", "->\347\224\265\350\212\257\344\275\215\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("ShowBCUClass", "\345\271\263\345\235\207\345\215\225\344\275\223\347\224\265\345\216\213", nullptr));
        label_9->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\260\217\345\205\201\350\256\270\346\224\276\347\224\265\347\224\265\345\216\213", nullptr));
        label_23->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\260\217\346\250\241\347\273\204\347\224\265\345\216\213", nullptr));
        label_5->setText(QCoreApplication::translate("ShowBCUClass", "->\346\250\241\347\273\204\344\275\215\347\275\256", nullptr));
        label_25->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\260\217\345\215\225\344\275\223\347\224\265\345\216\213", nullptr));
        label_14->setText(QCoreApplication::translate("ShowBCUClass", "->\346\250\241\347\273\204\347\274\226\345\217\267", nullptr));
        label_12->setText(QCoreApplication::translate("ShowBCUClass", "->\347\224\265\350\212\257\344\275\215\347\275\256", nullptr));
        label_24->setText(QCoreApplication::translate("ShowBCUClass", "\345\215\225\344\275\223\347\224\265\345\216\213\345\216\213\345\267\256", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\265\201", nullptr));
        label_7->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\345\205\201\350\256\270\345\205\205\347\224\265\347\224\265\346\265\201", nullptr));
        label_11->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\260\217\345\205\201\350\256\270\346\224\276\347\224\265\347\224\265\346\265\201", nullptr));
        label_28->setText(QCoreApplication::translate("ShowBCUClass", "\346\255\243\346\257\215\347\272\277\347\224\265\351\230\273", nullptr));
        label_22->setText(QCoreApplication::translate("ShowBCUClass", "\350\264\237\346\257\215\347\272\277\347\224\265\351\230\273", nullptr));
        label_29->setText(QCoreApplication::translate("ShowBCUClass", "PCB\346\270\251\345\272\246", nullptr));
        label_34->setText(QCoreApplication::translate("ShowBCUClass", "PCB\346\270\251\345\272\246", nullptr));
        label_35->setText(QCoreApplication::translate("ShowBCUClass", "PCB\346\270\251\345\272\246", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("ShowBCUClass", "\346\270\251\345\272\246", nullptr));
        label_20->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\346\270\251\345\272\246", nullptr));
        label_31->setText(QCoreApplication::translate("ShowBCUClass", "->\346\250\241\347\273\204\344\275\215\347\275\256", nullptr));
        label_33->setText(QCoreApplication::translate("ShowBCUClass", "->\344\274\240\346\204\237\345\231\250\344\275\215\347\275\256", nullptr));
        label_27->setText(QCoreApplication::translate("ShowBCUClass", "\345\271\263\345\235\207\346\270\251\345\272\246", nullptr));
        label_15->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\260\217\346\270\251\345\272\246", nullptr));
        label_32->setText(QCoreApplication::translate("ShowBCUClass", "->\346\250\241\347\273\204\344\275\215\347\275\256", nullptr));
        label_30->setText(QCoreApplication::translate("ShowBCUClass", "->\344\274\240\346\204\237\345\231\250\344\275\215\347\275\256", nullptr));
        label_26->setText(QCoreApplication::translate("ShowBCUClass", "\346\270\251\345\267\256", nullptr));
        tabWidget_DI->setTabText(tabWidget_DI->indexOf(tab), QCoreApplication::translate("ShowBCUClass", "\345\221\212\350\255\246\346\214\207\347\244\272\350\241\250", nullptr));
        tabWidget_DI->setTabText(tabWidget_DI->indexOf(tab_2), QCoreApplication::translate("ShowBCUClass", "DO\347\212\266\346\200\201\350\241\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_DI->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_DI->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_DI->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_DI->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_DI->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_DI->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_DI->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_DI->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_DI->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_DI->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ShowBCUClass", "\346\226\260\345\273\272\345\210\227", nullptr));
        tabWidget_DI->setTabText(tabWidget_DI->indexOf(tab_3), QCoreApplication::translate("ShowBCUClass", "DI\347\212\266\346\200\201\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowBCUClass: public Ui_ShowBCUClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWBCU_H
