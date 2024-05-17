/********************************************************************************
** Form generated from reading UI file 'UPFileWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPFILEWINDOWS_H
#define UI_UPFILEWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UPFileWindowsClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QRadioButton *rB_Eth;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_16;
    QLineEdit *IPEdit;
    QLabel *label_12;
    QLineEdit *PortEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QRadioButton *rB_Uart;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_13;
    QComboBox *serialCb;
    QLabel *label_4;
    QComboBox *cb_Baud;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_18;
    QRadioButton *rb_Can;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_17;
    QComboBox *Cb_CanPort;
    QLabel *label_10;
    QComboBox *cb_CanBaud;
    QPushButton *bt_open;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rb_TypeBMU;
    QRadioButton *rb_TypeBCU;
    QRadioButton *rb_TypeBAC;
    QLabel *label;
    QComboBox *Cb_DeviceID;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *rB_BMode;
    QRadioButton *rB_PMode;
    QLabel *label_2;
    QComboBox *cb_downspeed;
    QLabel *label_9;
    QCheckBox *checkBox_force;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_IDALL;
    QCheckBox *checkBox_ID1;
    QCheckBox *checkBox_ID2;
    QCheckBox *checkBox_ID3;
    QCheckBox *checkBox_ID4;
    QCheckBox *checkBox_ID5;
    QCheckBox *checkBox_ID6;
    QCheckBox *checkBox_ID7;
    QCheckBox *checkBox_ID8;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QPushButton *bt_loadfile;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QPushButton *bt_download;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bt_version_get;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UPFileWindowsClass)
    {
        if (UPFileWindowsClass->objectName().isEmpty())
            UPFileWindowsClass->setObjectName(QString::fromUtf8("UPFileWindowsClass"));
        UPFileWindowsClass->resize(675, 607);
        centralWidget = new QWidget(UPFileWindowsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_11->addWidget(label_15);

        rB_Eth = new QRadioButton(groupBox);
        rB_Eth->setObjectName(QString::fromUtf8("rB_Eth"));
        rB_Eth->setCheckable(true);
        rB_Eth->setChecked(true);

        horizontalLayout_11->addWidget(rB_Eth);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_11->addWidget(label_16);

        IPEdit = new QLineEdit(groupBox);
        IPEdit->setObjectName(QString::fromUtf8("IPEdit"));
        IPEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout_11->addWidget(IPEdit);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_11->addWidget(label_12);

        PortEdit = new QLineEdit(groupBox);
        PortEdit->setObjectName(QString::fromUtf8("PortEdit"));
        PortEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout_11->addWidget(PortEdit);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_2->addWidget(label_14);

        rB_Uart = new QRadioButton(groupBox);
        rB_Uart->setObjectName(QString::fromUtf8("rB_Uart"));
        rB_Uart->setCheckable(true);
        rB_Uart->setChecked(false);

        horizontalLayout_2->addWidget(rB_Uart);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(label_13);

        serialCb = new QComboBox(groupBox);
        serialCb->setObjectName(QString::fromUtf8("serialCb"));
        serialCb->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(serialCb);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        cb_Baud = new QComboBox(groupBox);
        cb_Baud->addItem(QString());
        cb_Baud->addItem(QString());
        cb_Baud->addItem(QString());
        cb_Baud->setObjectName(QString::fromUtf8("cb_Baud"));
        cb_Baud->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(cb_Baud);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_10->addWidget(label_18);

        rb_Can = new QRadioButton(groupBox);
        rb_Can->setObjectName(QString::fromUtf8("rb_Can"));
        rb_Can->setCheckable(true);
        rb_Can->setChecked(false);

        horizontalLayout_10->addWidget(rb_Can);

        horizontalSpacer_7 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_10->addWidget(label_17);

        Cb_CanPort = new QComboBox(groupBox);
        Cb_CanPort->addItem(QString());
        Cb_CanPort->addItem(QString());
        Cb_CanPort->setObjectName(QString::fromUtf8("Cb_CanPort"));
        Cb_CanPort->setMinimumSize(QSize(150, 0));

        horizontalLayout_10->addWidget(Cb_CanPort);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        cb_CanBaud = new QComboBox(groupBox);
        cb_CanBaud->addItem(QString());
        cb_CanBaud->addItem(QString());
        cb_CanBaud->addItem(QString());
        cb_CanBaud->setObjectName(QString::fromUtf8("cb_CanBaud"));
        cb_CanBaud->setMinimumSize(QSize(150, 0));

        horizontalLayout_10->addWidget(cb_CanBaud);


        verticalLayout->addLayout(horizontalLayout_10);

        bt_open = new QPushButton(groupBox);
        bt_open->setObjectName(QString::fromUtf8("bt_open"));

        verticalLayout->addWidget(bt_open);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rb_TypeBMU = new QRadioButton(groupBox_2);
        rb_TypeBMU->setObjectName(QString::fromUtf8("rb_TypeBMU"));
        rb_TypeBMU->setEnabled(false);
        rb_TypeBMU->setChecked(true);

        horizontalLayout_3->addWidget(rb_TypeBMU);

        rb_TypeBCU = new QRadioButton(groupBox_2);
        rb_TypeBCU->setObjectName(QString::fromUtf8("rb_TypeBCU"));
        rb_TypeBCU->setEnabled(false);

        horizontalLayout_3->addWidget(rb_TypeBCU);

        rb_TypeBAC = new QRadioButton(groupBox_2);
        rb_TypeBAC->setObjectName(QString::fromUtf8("rb_TypeBAC"));
        rb_TypeBAC->setEnabled(false);

        horizontalLayout_3->addWidget(rb_TypeBAC);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        Cb_DeviceID = new QComboBox(groupBox_2);
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->addItem(QString());
        Cb_DeviceID->setObjectName(QString::fromUtf8("Cb_DeviceID"));
        Cb_DeviceID->setEnabled(true);

        horizontalLayout_3->addWidget(Cb_DeviceID);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        verticalLayout_3->addLayout(horizontalLayout_5);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rB_BMode = new QRadioButton(groupBox_5);
        rB_BMode->setObjectName(QString::fromUtf8("rB_BMode"));

        horizontalLayout_6->addWidget(rB_BMode);

        rB_PMode = new QRadioButton(groupBox_5);
        rB_PMode->setObjectName(QString::fromUtf8("rB_PMode"));
        rB_PMode->setChecked(true);

        horizontalLayout_6->addWidget(rB_PMode);

        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        cb_downspeed = new QComboBox(groupBox_5);
        cb_downspeed->addItem(QString());
        cb_downspeed->addItem(QString());
        cb_downspeed->addItem(QString());
        cb_downspeed->addItem(QString());
        cb_downspeed->addItem(QString());
        cb_downspeed->addItem(QString());
        cb_downspeed->addItem(QString());
        cb_downspeed->addItem(QString());
        cb_downspeed->setObjectName(QString::fromUtf8("cb_downspeed"));

        horizontalLayout_6->addWidget(cb_downspeed);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        checkBox_force = new QCheckBox(groupBox_5);
        checkBox_force->setObjectName(QString::fromUtf8("checkBox_force"));

        horizontalLayout_6->addWidget(checkBox_force);


        verticalLayout_3->addWidget(groupBox_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        checkBox_IDALL = new QCheckBox(centralWidget);
        checkBox_IDALL->setObjectName(QString::fromUtf8("checkBox_IDALL"));

        horizontalLayout_9->addWidget(checkBox_IDALL);

        checkBox_ID1 = new QCheckBox(centralWidget);
        checkBox_ID1->setObjectName(QString::fromUtf8("checkBox_ID1"));

        horizontalLayout_9->addWidget(checkBox_ID1);

        checkBox_ID2 = new QCheckBox(centralWidget);
        checkBox_ID2->setObjectName(QString::fromUtf8("checkBox_ID2"));

        horizontalLayout_9->addWidget(checkBox_ID2);

        checkBox_ID3 = new QCheckBox(centralWidget);
        checkBox_ID3->setObjectName(QString::fromUtf8("checkBox_ID3"));

        horizontalLayout_9->addWidget(checkBox_ID3);

        checkBox_ID4 = new QCheckBox(centralWidget);
        checkBox_ID4->setObjectName(QString::fromUtf8("checkBox_ID4"));

        horizontalLayout_9->addWidget(checkBox_ID4);

        checkBox_ID5 = new QCheckBox(centralWidget);
        checkBox_ID5->setObjectName(QString::fromUtf8("checkBox_ID5"));

        horizontalLayout_9->addWidget(checkBox_ID5);

        checkBox_ID6 = new QCheckBox(centralWidget);
        checkBox_ID6->setObjectName(QString::fromUtf8("checkBox_ID6"));

        horizontalLayout_9->addWidget(checkBox_ID6);

        checkBox_ID7 = new QCheckBox(centralWidget);
        checkBox_ID7->setObjectName(QString::fromUtf8("checkBox_ID7"));

        horizontalLayout_9->addWidget(checkBox_ID7);

        checkBox_ID8 = new QCheckBox(centralWidget);
        checkBox_ID8->setObjectName(QString::fromUtf8("checkBox_ID8"));

        horizontalLayout_9->addWidget(checkBox_ID8);


        verticalLayout_3->addLayout(horizontalLayout_9);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        bt_loadfile = new QPushButton(groupBox_3);
        bt_loadfile->setObjectName(QString::fromUtf8("bt_loadfile"));

        horizontalLayout->addWidget(bt_loadfile);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);

        bt_download = new QPushButton(groupBox_3);
        bt_download->setObjectName(QString::fromUtf8("bt_download"));

        horizontalLayout_4->addWidget(bt_download);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        bt_version_get = new QPushButton(groupBox_3);
        bt_version_get->setObjectName(QString::fromUtf8("bt_version_get"));

        horizontalLayout_8->addWidget(bt_version_get);


        verticalLayout_2->addLayout(horizontalLayout_8);

        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(792, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        bt_clear = new QPushButton(groupBox_3);
        bt_clear->setObjectName(QString::fromUtf8("bt_clear"));

        horizontalLayout_7->addWidget(bt_clear);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupBox_3);

        UPFileWindowsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UPFileWindowsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 675, 23));
        UPFileWindowsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UPFileWindowsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UPFileWindowsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UPFileWindowsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UPFileWindowsClass->setStatusBar(statusBar);

        retranslateUi(UPFileWindowsClass);

        QMetaObject::connectSlotsByName(UPFileWindowsClass);
    } // setupUi

    void retranslateUi(QMainWindow *UPFileWindowsClass)
    {
        UPFileWindowsClass->setWindowTitle(QCoreApplication::translate("UPFileWindowsClass", "UPFileWindows", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UPFileWindowsClass", "\351\200\232\350\256\257\350\256\276\347\275\256", nullptr));
        label_15->setText(QCoreApplication::translate("UPFileWindowsClass", "\351\200\232\350\256\257\347\253\257\345\217\243", nullptr));
        rB_Eth->setText(QCoreApplication::translate("UPFileWindowsClass", "\347\275\221\345\217\243", nullptr));
        label_16->setText(QCoreApplication::translate("UPFileWindowsClass", "IP\345\234\260\345\235\200:", nullptr));
        IPEdit->setText(QCoreApplication::translate("UPFileWindowsClass", "192.168.2.202", nullptr));
        label_12->setText(QCoreApplication::translate("UPFileWindowsClass", "\347\253\257\345\217\243\345\217\267", nullptr));
        PortEdit->setText(QCoreApplication::translate("UPFileWindowsClass", "9030", nullptr));
        label_14->setText(QCoreApplication::translate("UPFileWindowsClass", "\351\200\232\350\256\257\347\253\257\345\217\243", nullptr));
        rB_Uart->setText(QCoreApplication::translate("UPFileWindowsClass", "\344\270\262\345\217\243", nullptr));
        label_13->setText(QCoreApplication::translate("UPFileWindowsClass", "\347\253\257\345\217\243\345\217\267:", nullptr));
        label_4->setText(QCoreApplication::translate("UPFileWindowsClass", "\346\263\242\347\211\271\347\216\207", nullptr));
        cb_Baud->setItemText(0, QCoreApplication::translate("UPFileWindowsClass", "115200", nullptr));
        cb_Baud->setItemText(1, QCoreApplication::translate("UPFileWindowsClass", "38400", nullptr));
        cb_Baud->setItemText(2, QCoreApplication::translate("UPFileWindowsClass", "9600", nullptr));

        label_18->setText(QCoreApplication::translate("UPFileWindowsClass", "\351\200\232\350\256\257\347\253\257\345\217\243", nullptr));
        rb_Can->setText(QCoreApplication::translate("UPFileWindowsClass", "CAN\345\217\243", nullptr));
        label_17->setText(QCoreApplication::translate("UPFileWindowsClass", "\347\253\257\345\217\243\345\217\267:", nullptr));
        Cb_CanPort->setItemText(0, QCoreApplication::translate("UPFileWindowsClass", "\347\253\257\345\217\2431", nullptr));
        Cb_CanPort->setItemText(1, QCoreApplication::translate("UPFileWindowsClass", "\347\253\257\345\217\2432", nullptr));

        label_10->setText(QCoreApplication::translate("UPFileWindowsClass", "\346\263\242\347\211\271\347\216\207", nullptr));
        cb_CanBaud->setItemText(0, QCoreApplication::translate("UPFileWindowsClass", "500K", nullptr));
        cb_CanBaud->setItemText(1, QCoreApplication::translate("UPFileWindowsClass", "1000K", nullptr));
        cb_CanBaud->setItemText(2, QCoreApplication::translate("UPFileWindowsClass", "2000K", nullptr));

        bt_open->setText(QCoreApplication::translate("UPFileWindowsClass", "\346\211\223\345\274\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("UPFileWindowsClass", "\350\256\276\345\244\207\347\261\273\345\236\213", nullptr));
        rb_TypeBMU->setText(QCoreApplication::translate("UPFileWindowsClass", "\344\270\200\347\272\247\344\273\216\346\216\247", nullptr));
        rb_TypeBCU->setText(QCoreApplication::translate("UPFileWindowsClass", "\344\272\214\347\272\247\344\270\273\346\216\247", nullptr));
        rb_TypeBAC->setText(QCoreApplication::translate("UPFileWindowsClass", "\344\270\211\347\272\247\344\270\273\346\216\247", nullptr));
        label->setText(QCoreApplication::translate("UPFileWindowsClass", "\350\256\276\345\244\207\345\217\267", nullptr));
        Cb_DeviceID->setItemText(0, QCoreApplication::translate("UPFileWindowsClass", "1", nullptr));
        Cb_DeviceID->setItemText(1, QCoreApplication::translate("UPFileWindowsClass", "2", nullptr));
        Cb_DeviceID->setItemText(2, QCoreApplication::translate("UPFileWindowsClass", "3", nullptr));
        Cb_DeviceID->setItemText(3, QCoreApplication::translate("UPFileWindowsClass", "4", nullptr));
        Cb_DeviceID->setItemText(4, QCoreApplication::translate("UPFileWindowsClass", "5", nullptr));
        Cb_DeviceID->setItemText(5, QCoreApplication::translate("UPFileWindowsClass", "6", nullptr));
        Cb_DeviceID->setItemText(6, QCoreApplication::translate("UPFileWindowsClass", "7", nullptr));
        Cb_DeviceID->setItemText(7, QCoreApplication::translate("UPFileWindowsClass", "8", nullptr));
        Cb_DeviceID->setItemText(8, QCoreApplication::translate("UPFileWindowsClass", "9", nullptr));
        Cb_DeviceID->setItemText(9, QCoreApplication::translate("UPFileWindowsClass", "10", nullptr));
        Cb_DeviceID->setItemText(10, QCoreApplication::translate("UPFileWindowsClass", "11", nullptr));
        Cb_DeviceID->setItemText(11, QCoreApplication::translate("UPFileWindowsClass", "12", nullptr));
        Cb_DeviceID->setItemText(12, QCoreApplication::translate("UPFileWindowsClass", "13", nullptr));
        Cb_DeviceID->setItemText(13, QCoreApplication::translate("UPFileWindowsClass", "14", nullptr));
        Cb_DeviceID->setItemText(14, QCoreApplication::translate("UPFileWindowsClass", "15", nullptr));
        Cb_DeviceID->setItemText(15, QCoreApplication::translate("UPFileWindowsClass", "16", nullptr));

        groupBox_5->setTitle(QCoreApplication::translate("UPFileWindowsClass", "\345\215\207\347\272\247\346\250\241\345\274\217", nullptr));
        rB_BMode->setText(QCoreApplication::translate("UPFileWindowsClass", "\345\271\277\346\222\255", nullptr));
        rB_PMode->setText(QCoreApplication::translate("UPFileWindowsClass", "\347\202\271\345\257\271\347\202\271", nullptr));
        label_2->setText(QCoreApplication::translate("UPFileWindowsClass", "\345\215\207\347\272\247\351\200\237\345\272\246", nullptr));
        cb_downspeed->setItemText(0, QCoreApplication::translate("UPFileWindowsClass", "100", nullptr));
        cb_downspeed->setItemText(1, QCoreApplication::translate("UPFileWindowsClass", "200", nullptr));
        cb_downspeed->setItemText(2, QCoreApplication::translate("UPFileWindowsClass", "300", nullptr));
        cb_downspeed->setItemText(3, QCoreApplication::translate("UPFileWindowsClass", "500", nullptr));
        cb_downspeed->setItemText(4, QCoreApplication::translate("UPFileWindowsClass", "1000", nullptr));
        cb_downspeed->setItemText(5, QCoreApplication::translate("UPFileWindowsClass", "50", nullptr));
        cb_downspeed->setItemText(6, QCoreApplication::translate("UPFileWindowsClass", "1", nullptr));
        cb_downspeed->setItemText(7, QCoreApplication::translate("UPFileWindowsClass", "20", nullptr));

        label_9->setText(QCoreApplication::translate("UPFileWindowsClass", "ms", nullptr));
        checkBox_force->setText(QCoreApplication::translate("UPFileWindowsClass", "\345\274\272\345\210\266\345\215\207\347\272\247", nullptr));
        checkBox_IDALL->setText(QCoreApplication::translate("UPFileWindowsClass", "\345\205\250\351\200\211", nullptr));
        checkBox_ID1->setText(QCoreApplication::translate("UPFileWindowsClass", "1", nullptr));
        checkBox_ID2->setText(QCoreApplication::translate("UPFileWindowsClass", "2", nullptr));
        checkBox_ID3->setText(QCoreApplication::translate("UPFileWindowsClass", "3", nullptr));
        checkBox_ID4->setText(QCoreApplication::translate("UPFileWindowsClass", "4", nullptr));
        checkBox_ID5->setText(QCoreApplication::translate("UPFileWindowsClass", "5", nullptr));
        checkBox_ID6->setText(QCoreApplication::translate("UPFileWindowsClass", "6", nullptr));
        checkBox_ID7->setText(QCoreApplication::translate("UPFileWindowsClass", "7", nullptr));
        checkBox_ID8->setText(QCoreApplication::translate("UPFileWindowsClass", "8", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("UPFileWindowsClass", "\345\215\207\347\272\247\347\250\213\345\272\217", nullptr));
        label_6->setText(QCoreApplication::translate("UPFileWindowsClass", "\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        bt_loadfile->setText(QCoreApplication::translate("UPFileWindowsClass", "\350\275\275\345\205\245", nullptr));
        label_7->setText(QCoreApplication::translate("UPFileWindowsClass", "\347\241\254\344\273\266\345\236\213\345\217\267:", nullptr));
        label_8->setText(QCoreApplication::translate("UPFileWindowsClass", "\350\275\257\344\273\266\347\211\210\346\234\254:", nullptr));
        bt_download->setText(QCoreApplication::translate("UPFileWindowsClass", "\344\270\213\350\275\275", nullptr));
        bt_version_get->setText(QCoreApplication::translate("UPFileWindowsClass", "\346\237\245\350\257\242\350\256\276\345\244\207\347\211\210\346\234\254", nullptr));
        bt_clear->setText(QCoreApplication::translate("UPFileWindowsClass", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UPFileWindowsClass: public Ui_UPFileWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPFILEWINDOWS_H
