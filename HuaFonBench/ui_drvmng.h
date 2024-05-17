/********************************************************************************
** Form generated from reading UI file 'drvmng.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRVMNG_H
#define UI_DRVMNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drvmng
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *CB_Baud;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QComboBox *CB_EXT;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLineEdit *IPlineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *PortlineEdit;
    QPushButton *bt_Connected;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *drvmng)
    {
        if (drvmng->objectName().isEmpty())
            drvmng->setObjectName(QString::fromUtf8("drvmng"));
        drvmng->resize(525, 691);
        centralwidget = new QWidget(drvmng);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setCheckable(true);
        radioButton->setChecked(false);

        horizontalLayout_6->addWidget(radioButton);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        horizontalLayout_6->addWidget(radioButton_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        CB_Baud = new QComboBox(centralwidget);
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->setObjectName(QString::fromUtf8("CB_Baud"));

        horizontalLayout_2->addWidget(CB_Baud);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        comboBox_4 = new QComboBox(centralwidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setMaxCount(10);

        horizontalLayout_7->addWidget(comboBox_4);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        CB_EXT = new QComboBox(centralwidget);
        CB_EXT->addItem(QString());
        CB_EXT->addItem(QString());
        CB_EXT->setObjectName(QString::fromUtf8("CB_EXT"));
        CB_EXT->setMaxCount(10);

        horizontalLayout_3->addWidget(CB_EXT);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_5->addWidget(label_9);

        IPlineEdit = new QLineEdit(centralwidget);
        IPlineEdit->setObjectName(QString::fromUtf8("IPlineEdit"));

        horizontalLayout_5->addWidget(IPlineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_4->addWidget(label_10);

        PortlineEdit = new QLineEdit(centralwidget);
        PortlineEdit->setObjectName(QString::fromUtf8("PortlineEdit"));

        horizontalLayout_4->addWidget(PortlineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        bt_Connected = new QPushButton(centralwidget);
        bt_Connected->setObjectName(QString::fromUtf8("bt_Connected"));

        verticalLayout->addWidget(bt_Connected);

        drvmng->setCentralWidget(centralwidget);
        menubar = new QMenuBar(drvmng);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 525, 23));
        drvmng->setMenuBar(menubar);
        statusbar = new QStatusBar(drvmng);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        drvmng->setStatusBar(statusbar);

        retranslateUi(drvmng);

        comboBox_4->setCurrentIndex(0);
        CB_EXT->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(drvmng);
    } // setupUi

    void retranslateUi(QMainWindow *drvmng)
    {
        drvmng->setWindowTitle(QCoreApplication::translate("drvmng", "\351\200\232\350\256\257\350\256\276\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("drvmng", "\351\200\232\350\256\257\346\216\245\345\217\243\347\261\273\345\236\213", nullptr));
        radioButton->setText(QCoreApplication::translate("drvmng", "CAN", nullptr));
        radioButton_2->setText(QCoreApplication::translate("drvmng", "LAN", nullptr));
        label_5->setText(QCoreApplication::translate("drvmng", "\350\256\276\345\244\207\347\264\242\345\274\225\345\217\267", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("drvmng", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("drvmng", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("drvmng", "3", nullptr));

        label_6->setText(QCoreApplication::translate("drvmng", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        CB_Baud->setItemText(0, QCoreApplication::translate("drvmng", "1000K", nullptr));
        CB_Baud->setItemText(1, QCoreApplication::translate("drvmng", "1000K", nullptr));
        CB_Baud->setItemText(2, QCoreApplication::translate("drvmng", "800K", nullptr));
        CB_Baud->setItemText(3, QCoreApplication::translate("drvmng", "500K", nullptr));
        CB_Baud->setItemText(4, QCoreApplication::translate("drvmng", "100K", nullptr));
        CB_Baud->setItemText(5, QCoreApplication::translate("drvmng", "400K", nullptr));

        label_11->setText(QCoreApplication::translate("drvmng", "\347\254\254\345\207\240\350\267\257CAN\357\274\232", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("drvmng", "\347\254\254\344\270\200\350\267\257", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("drvmng", "\347\254\254\344\272\214\350\267\257", nullptr));

        label_7->setText(QCoreApplication::translate("drvmng", "\345\270\247\347\261\273\345\236\213\357\274\232", nullptr));
        CB_EXT->setItemText(0, QCoreApplication::translate("drvmng", "\346\240\207\345\207\206\345\270\247", nullptr));
        CB_EXT->setItemText(1, QCoreApplication::translate("drvmng", "\346\211\251\345\261\225\345\270\247", nullptr));

        label_9->setText(QCoreApplication::translate("drvmng", "IP Address\357\274\232", nullptr));
        IPlineEdit->setText(QCoreApplication::translate("drvmng", "192.168.2.208", nullptr));
        label_10->setText(QCoreApplication::translate("drvmng", "Server Port\357\274\232", nullptr));
        PortlineEdit->setText(QCoreApplication::translate("drvmng", "9030", nullptr));
        bt_Connected->setText(QCoreApplication::translate("drvmng", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class drvmng: public Ui_drvmng {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRVMNG_H
