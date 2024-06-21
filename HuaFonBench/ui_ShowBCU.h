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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
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
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_18;
    QLabel *lbMSL_T_3;
    QLabel *lbRunLed_Status;
    QLabel *lbDIFbStatus;
    QHBoxLayout *horizontalLayout_19;
    QLabel *lbMSL_T_2;
    QLabel *lbAlarmLed_Status;
    QGroupBox *groupBox_17;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_37;
    QLabel *lbMSL_T_4;
    QLabel *lbAC_Line;
    QHBoxLayout *horizontalLayout_39;
    QLabel *lbMSL_T_6;
    QLabel *lbAC_RUN;
    QLabel *lbDIFbStatus_2;
    QHBoxLayout *horizontalLayout_38;
    QLabel *lbMSL_T_5;
    QLabel *lbAC_Status;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *lESOH;
    QLabel *label_2;
    QLineEdit *lECYCLE;
    QLabel *label_3;
    QLineEdit *lESOC;
    QLabel *label_17;
    QLineEdit *accDischargeCapacity;
    QLabel *label_16;
    QLineEdit *accChargeCapacity;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_42;
    QLineEdit *LB_MAX_CHG_CUR;
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
    QLabel *label_34;
    QLineEdit *AVERAGE_S_VOLT_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_43;
    QLineEdit *LB_MAX_DHG_CUR;
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
    QLabel *label_41;
    QLineEdit *VOLT_PP;
    QHBoxLayout *horizontalLayout_21;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_28;
    QLineEdit *POSITIVE_BUS_RESISTANCE;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_22;
    QLineEdit *NEGATIVE_BUS_RESISTANCE;
    QGroupBox *groupBox_13;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_39;
    QLineEdit *PCB_PTemp;
    QLabel *label_37;
    QLineEdit *P_PTemp;
    QLabel *label_36;
    QLineEdit *B_PTemp;
    QLabel *label_20;
    QLineEdit *lEmaximumTemperature_ddegC;
    QLabel *label_31;
    QLineEdit *lEnrModuleMaximumTemperature;
    QLabel *label_33;
    QLineEdit *lEnrSensorMaximumTemperature;
    QLabel *label_27;
    QLineEdit *lEaverageTemperature_ddegC;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_40;
    QLineEdit *BAT_Temp;
    QLabel *label_38;
    QLineEdit *P_NTemp;
    QLabel *label_29;
    QLineEdit *B_NTemp;
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label_35;
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
        ShowBCUClass->resize(1634, 807);
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

        lbRunLed_Status = new QLabel(groupBox_15);
        lbRunLed_Status->setObjectName(QString::fromUtf8("lbRunLed_Status"));

        horizontalLayout_18->addWidget(lbRunLed_Status);


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

        lbAlarmLed_Status = new QLabel(groupBox_15);
        lbAlarmLed_Status->setObjectName(QString::fromUtf8("lbAlarmLed_Status"));

        horizontalLayout_19->addWidget(lbAlarmLed_Status);


        verticalLayout_12->addLayout(horizontalLayout_19);


        horizontalLayout_2->addWidget(groupBox_15);

        groupBox_17 = new QGroupBox(groupBox);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        verticalLayout_14 = new QVBoxLayout(groupBox_17);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        lbMSL_T_4 = new QLabel(groupBox_17);
        lbMSL_T_4->setObjectName(QString::fromUtf8("lbMSL_T_4"));

        horizontalLayout_37->addWidget(lbMSL_T_4);

        lbAC_Line = new QLabel(groupBox_17);
        lbAC_Line->setObjectName(QString::fromUtf8("lbAC_Line"));

        horizontalLayout_37->addWidget(lbAC_Line);


        verticalLayout_14->addLayout(horizontalLayout_37);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        lbMSL_T_6 = new QLabel(groupBox_17);
        lbMSL_T_6->setObjectName(QString::fromUtf8("lbMSL_T_6"));

        horizontalLayout_39->addWidget(lbMSL_T_6);

        lbAC_RUN = new QLabel(groupBox_17);
        lbAC_RUN->setObjectName(QString::fromUtf8("lbAC_RUN"));

        horizontalLayout_39->addWidget(lbAC_RUN);


        verticalLayout_14->addLayout(horizontalLayout_39);

        lbDIFbStatus_2 = new QLabel(groupBox_17);
        lbDIFbStatus_2->setObjectName(QString::fromUtf8("lbDIFbStatus_2"));

        verticalLayout_14->addWidget(lbDIFbStatus_2);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        lbMSL_T_5 = new QLabel(groupBox_17);
        lbMSL_T_5->setObjectName(QString::fromUtf8("lbMSL_T_5"));

        horizontalLayout_38->addWidget(lbMSL_T_5);

        lbAC_Status = new QLabel(groupBox_17);
        lbAC_Status->setObjectName(QString::fromUtf8("lbAC_Status"));

        horizontalLayout_38->addWidget(lbAC_Status);


        verticalLayout_14->addLayout(horizontalLayout_38);


        horizontalLayout_2->addWidget(groupBox_17);


        horizontalLayout_6->addWidget(groupBox);


        verticalLayout_5->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(16777215, 16777215));
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

        lECYCLE = new QLineEdit(groupBox_6);
        lECYCLE->setObjectName(QString::fromUtf8("lECYCLE"));
        lECYCLE->setReadOnly(true);

        horizontalLayout_7->addWidget(lECYCLE);

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


        verticalLayout_5->addWidget(groupBox_6);

        groupBox_10 = new QGroupBox(centralWidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMaximumSize(QSize(16777215, 16777215));
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
        label_42 = new QLabel(groupBox_12);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_14->addWidget(label_42);

        LB_MAX_CHG_CUR = new QLineEdit(groupBox_12);
        LB_MAX_CHG_CUR->setObjectName(QString::fromUtf8("LB_MAX_CHG_CUR"));
        LB_MAX_CHG_CUR->setReadOnly(true);

        horizontalLayout_14->addWidget(LB_MAX_CHG_CUR);

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

        label_34 = new QLabel(groupBox_12);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_14->addWidget(label_34);

        AVERAGE_S_VOLT_2 = new QLineEdit(groupBox_12);
        AVERAGE_S_VOLT_2->setObjectName(QString::fromUtf8("AVERAGE_S_VOLT_2"));
        AVERAGE_S_VOLT_2->setReadOnly(true);

        horizontalLayout_14->addWidget(AVERAGE_S_VOLT_2);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_43 = new QLabel(groupBox_12);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        horizontalLayout_15->addWidget(label_43);

        LB_MAX_DHG_CUR = new QLineEdit(groupBox_12);
        LB_MAX_DHG_CUR->setObjectName(QString::fromUtf8("LB_MAX_DHG_CUR"));
        LB_MAX_DHG_CUR->setReadOnly(true);

        horizontalLayout_15->addWidget(LB_MAX_DHG_CUR);

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

        label_41 = new QLabel(groupBox_12);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_15->addWidget(label_41);

        VOLT_PP = new QLineEdit(groupBox_12);
        VOLT_PP->setObjectName(QString::fromUtf8("VOLT_PP"));
        VOLT_PP->setReadOnly(true);

        horizontalLayout_15->addWidget(VOLT_PP);


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
        label_28 = new QLabel(groupBox_14);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_13->addWidget(label_28);

        POSITIVE_BUS_RESISTANCE = new QLineEdit(groupBox_14);
        POSITIVE_BUS_RESISTANCE->setObjectName(QString::fromUtf8("POSITIVE_BUS_RESISTANCE"));
        POSITIVE_BUS_RESISTANCE->setMinimumSize(QSize(150, 0));
        POSITIVE_BUS_RESISTANCE->setReadOnly(true);

        horizontalLayout_13->addWidget(POSITIVE_BUS_RESISTANCE);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_22 = new QLabel(groupBox_14);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_20->addWidget(label_22);

        NEGATIVE_BUS_RESISTANCE = new QLineEdit(groupBox_14);
        NEGATIVE_BUS_RESISTANCE->setObjectName(QString::fromUtf8("NEGATIVE_BUS_RESISTANCE"));
        NEGATIVE_BUS_RESISTANCE->setMinimumSize(QSize(150, 0));
        NEGATIVE_BUS_RESISTANCE->setReadOnly(true);

        horizontalLayout_20->addWidget(NEGATIVE_BUS_RESISTANCE);


        verticalLayout_2->addLayout(horizontalLayout_20);


        horizontalLayout_21->addWidget(groupBox_14);

        groupBox_13 = new QGroupBox(groupBox_10);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        verticalLayout = new QVBoxLayout(groupBox_13);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_39 = new QLabel(groupBox_13);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_16->addWidget(label_39);

        PCB_PTemp = new QLineEdit(groupBox_13);
        PCB_PTemp->setObjectName(QString::fromUtf8("PCB_PTemp"));
        PCB_PTemp->setReadOnly(true);

        horizontalLayout_16->addWidget(PCB_PTemp);

        label_37 = new QLabel(groupBox_13);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_16->addWidget(label_37);

        P_PTemp = new QLineEdit(groupBox_13);
        P_PTemp->setObjectName(QString::fromUtf8("P_PTemp"));
        P_PTemp->setReadOnly(true);

        horizontalLayout_16->addWidget(P_PTemp);

        label_36 = new QLabel(groupBox_13);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_16->addWidget(label_36);

        B_PTemp = new QLineEdit(groupBox_13);
        B_PTemp->setObjectName(QString::fromUtf8("B_PTemp"));
        B_PTemp->setReadOnly(true);

        horizontalLayout_16->addWidget(B_PTemp);

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
        label_40 = new QLabel(groupBox_13);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_17->addWidget(label_40);

        BAT_Temp = new QLineEdit(groupBox_13);
        BAT_Temp->setObjectName(QString::fromUtf8("BAT_Temp"));
        BAT_Temp->setReadOnly(true);

        horizontalLayout_17->addWidget(BAT_Temp);

        label_38 = new QLabel(groupBox_13);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_17->addWidget(label_38);

        P_NTemp = new QLineEdit(groupBox_13);
        P_NTemp->setObjectName(QString::fromUtf8("P_NTemp"));
        P_NTemp->setReadOnly(true);

        horizontalLayout_17->addWidget(P_NTemp);

        label_29 = new QLabel(groupBox_13);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_17->addWidget(label_29);

        B_NTemp = new QLineEdit(groupBox_13);
        B_NTemp->setObjectName(QString::fromUtf8("B_NTemp"));
        B_NTemp->setReadOnly(true);

        horizontalLayout_17->addWidget(B_NTemp);

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

        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1590, 69));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_35 = new QLabel(scrollAreaWidgetContents);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout->addWidget(label_35, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

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
        menuBar->setGeometry(QRect(0, 0, 1634, 23));
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
        groupBox_2->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\263\273\347\273\237\346\200\273\346\265\201", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\263\273\347\273\237\347\224\265\345\216\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ShowBCUClass", "\345\221\212\350\255\246\344\277\241\346\201\257", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("ShowBCUClass", "\345\221\212\350\255\246\346\214\207\347\244\272", nullptr));
        lbMOL_P->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMOL_T->setText(QCoreApplication::translate("ShowBCUClass", "\350\275\273\345\276\256\345\221\212\350\255\246", nullptr));
        lbRSL_P->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbRSL_T->setText(QCoreApplication::translate("ShowBCUClass", "\344\270\200\350\210\254\345\221\212\350\255\246", nullptr));
        lbMSL_P->setText(QCoreApplication::translate("ShowBCUClass", "TextLabel", nullptr));
        lbMSL_T->setText(QCoreApplication::translate("ShowBCUClass", "\344\270\245\351\207\215\345\221\212\350\255\246", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("ShowBCUClass", "\346\216\245\350\247\246\345\231\250\347\212\266\346\200\201", nullptr));
        lbMOL_T_2->setText(QCoreApplication::translate("ShowBCUClass", "\350\264\237\346\216\245\350\247\246\345\231\250", nullptr));
        lbMOL_T_3->setText(QCoreApplication::translate("ShowBCUClass", "\351\242\204\345\205\205\346\216\245\350\247\246\345\231\250", nullptr));
        lbMOL_T_4->setText(QCoreApplication::translate("ShowBCUClass", "\346\255\243\346\216\245\350\247\246\345\231\250", nullptr));
        lbMOL_T_5->setText(QCoreApplication::translate("ShowBCUClass", "\351\232\224\347\246\273\345\274\200\345\205\263", nullptr));
        lbMOL_T_6->setText(QCoreApplication::translate("ShowBCUClass", "\347\273\235\347\274\230\347\212\266\346\200\201", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\201\257\347\212\266\346\200\201", nullptr));
        lbMSL_T_3->setText(QCoreApplication::translate("ShowBCUClass", "\350\277\220\350\241\214\346\214\207\347\244\272\347\201\257:", nullptr));
        lbRunLed_Status->setText(QCoreApplication::translate("ShowBCUClass", "DI\345\217\215\351\246\210\347\212\266\346\200\201:", nullptr));
        lbDIFbStatus->setText(QString());
        lbMSL_T_2->setText(QCoreApplication::translate("ShowBCUClass", "\346\225\205\351\232\234\346\214\207\347\244\272\347\201\257:", nullptr));
        lbAlarmLed_Status->setText(QCoreApplication::translate("ShowBCUClass", "DO\345\217\215\351\246\210\347\212\266\346\200\201:", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\251\272\350\260\203\347\212\266\346\200\201", nullptr));
        lbMSL_T_4->setText(QCoreApplication::translate("ShowBCUClass", "\345\234\250\347\272\277:", nullptr));
        lbAC_Line->setText(QCoreApplication::translate("ShowBCUClass", "DI\345\217\215\351\246\210\347\212\266\346\200\201:", nullptr));
        lbMSL_T_6->setText(QCoreApplication::translate("ShowBCUClass", "\350\277\220\350\241\214:", nullptr));
        lbAC_RUN->setText(QCoreApplication::translate("ShowBCUClass", "DO\345\217\215\351\246\210\347\212\266\346\200\201:", nullptr));
        lbDIFbStatus_2->setText(QString());
        lbMSL_T_5->setText(QCoreApplication::translate("ShowBCUClass", "\347\212\266\346\200\201:", nullptr));
        lbAC_Status->setText(QCoreApplication::translate("ShowBCUClass", "DO\345\217\215\351\246\210\347\212\266\346\200\201:", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("ShowBCUClass", "SOH%", nullptr));
        label_2->setText(QCoreApplication::translate("ShowBCUClass", "\345\276\252\347\216\257\346\254\241\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("ShowBCUClass", "SOC%", nullptr));
        label_17->setText(QCoreApplication::translate("ShowBCUClass", "\347\264\257\350\256\241\346\224\276\347\224\265\347\224\265\351\207\217(Ah)", nullptr));
        label_16->setText(QCoreApplication::translate("ShowBCUClass", "\347\264\257\350\256\241\345\205\205\347\224\265\351\207\217(Ah)", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("ShowBCUClass", "\350\277\220\350\241\214\346\225\260\346\215\256\346\214\207\347\244\272", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\345\216\213", nullptr));
        label_42->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\345\205\201\350\256\270\345\205\205\347\224\265\347\224\265\346\265\201", nullptr));
        label_19->setText(QCoreApplication::translate("ShowBCUClass", "Pack\346\234\200\345\244\247\347\224\265\345\216\213", nullptr));
        label_4->setText(QCoreApplication::translate("ShowBCUClass", "->\346\211\200\345\234\250Pack\344\275\215\347\275\256", nullptr));
        label_21->setText(QCoreApplication::translate("ShowBCUClass", "\347\263\273\347\273\237\346\234\200\345\244\247\345\215\225\344\275\223\347\224\265\345\216\213", nullptr));
        label_13->setText(QCoreApplication::translate("ShowBCUClass", "->Pack\345\234\260\345\235\200", nullptr));
        label_10->setText(QCoreApplication::translate("ShowBCUClass", "->\347\224\265\350\212\257\347\274\226\345\217\267", nullptr));
        label_8->setText(QCoreApplication::translate("ShowBCUClass", "\345\271\263\345\235\207\347\224\265\350\212\257\347\224\265\345\216\213", nullptr));
        label_34->setText(QCoreApplication::translate("ShowBCUClass", "\345\271\263\345\235\207Pack\347\224\265\345\216\213", nullptr));
        label_43->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\345\205\201\350\256\270\346\224\276\347\224\265\347\224\265\346\265\201", nullptr));
        label_23->setText(QCoreApplication::translate("ShowBCUClass", "Pack\346\234\200\345\260\217\347\224\265\345\216\213", nullptr));
        label_5->setText(QCoreApplication::translate("ShowBCUClass", "->\346\211\200\345\234\250Pack\344\275\215\347\275\256", nullptr));
        label_25->setText(QCoreApplication::translate("ShowBCUClass", "\347\263\273\347\273\237\346\234\200\345\260\217\345\215\225\344\275\223\347\224\265\345\216\213", nullptr));
        label_14->setText(QCoreApplication::translate("ShowBCUClass", "->Pack\345\234\260\345\235\200", nullptr));
        label_12->setText(QCoreApplication::translate("ShowBCUClass", "->\347\224\265\350\212\257\347\274\226\345\217\267", nullptr));
        label_24->setText(QCoreApplication::translate("ShowBCUClass", "\345\215\225\344\275\223\347\224\265\345\216\213\345\216\213\345\267\256", nullptr));
        label_41->setText(QCoreApplication::translate("ShowBCUClass", "P+P-\347\224\265\345\216\213    ", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\265\201/\347\224\265\351\230\273", nullptr));
        label_28->setText(QCoreApplication::translate("ShowBCUClass", "\346\255\243\346\257\215\347\272\277\347\224\265\351\230\273", nullptr));
        label_22->setText(QCoreApplication::translate("ShowBCUClass", "\350\264\237\346\257\215\347\272\277\347\224\265\351\230\273", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("ShowBCUClass", "\346\270\251\345\272\246", nullptr));
        label_39->setText(QCoreApplication::translate("ShowBCUClass", "PCB \346\270\251\345\272\246", nullptr));
        label_37->setText(QCoreApplication::translate("ShowBCUClass", "P+\346\270\251\345\272\246", nullptr));
        label_36->setText(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240+\346\270\251\345\272\246", nullptr));
        label_20->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\244\247\346\270\251\345\272\246", nullptr));
        label_31->setText(QCoreApplication::translate("ShowBCUClass", "->PACK\344\275\215\347\275\256", nullptr));
        label_33->setText(QCoreApplication::translate("ShowBCUClass", "->\344\274\240\346\204\237\345\231\250\344\275\215\347\275\256", nullptr));
        label_27->setText(QCoreApplication::translate("ShowBCUClass", "\345\271\263\345\235\207\346\270\251\345\272\246", nullptr));
        label_40->setText(QCoreApplication::translate("ShowBCUClass", "\347\216\257\345\242\203\346\270\251\345\272\246", nullptr));
        label_38->setText(QCoreApplication::translate("ShowBCUClass", "P-\346\270\251\345\272\246", nullptr));
        label_29->setText(QCoreApplication::translate("ShowBCUClass", "\347\224\265\346\261\240-\346\270\251\345\272\246", nullptr));
        label_15->setText(QCoreApplication::translate("ShowBCUClass", "\346\234\200\345\260\217\346\270\251\345\272\246", nullptr));
        label_32->setText(QCoreApplication::translate("ShowBCUClass", "->PACK\344\275\215\347\275\256", nullptr));
        label_30->setText(QCoreApplication::translate("ShowBCUClass", "->\344\274\240\346\204\237\345\231\250\344\275\215\347\275\256", nullptr));
        label_26->setText(QCoreApplication::translate("ShowBCUClass", "\346\270\251\345\267\256", nullptr));
        label_35->setText(QCoreApplication::translate("ShowBCUClass", "\346\225\205\351\232\234\346\216\252\346\226\275", nullptr));
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
