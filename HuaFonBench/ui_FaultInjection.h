/********************************************************************************
** Form generated from reading UI file 'FaultInjection.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTINJECTION_H
#define UI_FAULTINJECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultInjectionClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *cBDeviceType;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QPushButton *bt_clear;
    QPushButton *bt_read_all;
    QPushButton *bt_write;
    QGridLayout *gridLayout;

    void setupUi(QWidget *FaultInjectionClass)
    {
        if (FaultInjectionClass->objectName().isEmpty())
            FaultInjectionClass->setObjectName(QString::fromUtf8("FaultInjectionClass"));
        FaultInjectionClass->resize(1166, 700);
        verticalLayout = new QVBoxLayout(FaultInjectionClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(FaultInjectionClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        cBDeviceType = new QComboBox(FaultInjectionClass);
        cBDeviceType->addItem(QString());
        cBDeviceType->addItem(QString());
        cBDeviceType->setObjectName(QString::fromUtf8("cBDeviceType"));

        horizontalLayout->addWidget(cBDeviceType);

        label_3 = new QLabel(FaultInjectionClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox_2 = new QComboBox(FaultInjectionClass);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        label_2 = new QLabel(FaultInjectionClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(FaultInjectionClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        checkBox = new QCheckBox(FaultInjectionClass);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        bt_clear = new QPushButton(FaultInjectionClass);
        bt_clear->setObjectName(QString::fromUtf8("bt_clear"));

        horizontalLayout->addWidget(bt_clear);

        bt_read_all = new QPushButton(FaultInjectionClass);
        bt_read_all->setObjectName(QString::fromUtf8("bt_read_all"));

        horizontalLayout->addWidget(bt_read_all);

        bt_write = new QPushButton(FaultInjectionClass);
        bt_write->setObjectName(QString::fromUtf8("bt_write"));

        horizontalLayout->addWidget(bt_write);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout->addLayout(gridLayout);


        retranslateUi(FaultInjectionClass);

        QMetaObject::connectSlotsByName(FaultInjectionClass);
    } // setupUi

    void retranslateUi(QWidget *FaultInjectionClass)
    {
        FaultInjectionClass->setWindowTitle(QCoreApplication::translate("FaultInjectionClass", "FaultInjection", nullptr));
        label_4->setText(QCoreApplication::translate("FaultInjectionClass", "\346\263\250\345\205\245\346\225\205\351\232\234\347\232\204\350\256\276\345\244\207", nullptr));
        cBDeviceType->setItemText(0, QCoreApplication::translate("FaultInjectionClass", "BMU", nullptr));
        cBDeviceType->setItemText(1, QCoreApplication::translate("FaultInjectionClass", "BCU", nullptr));

        label_3->setText(QCoreApplication::translate("FaultInjectionClass", "\344\273\216\346\234\272ID", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("FaultInjectionClass", "1", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("FaultInjectionClass", "2", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("FaultInjectionClass", "3", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("FaultInjectionClass", "4", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("FaultInjectionClass", "5", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("FaultInjectionClass", "6", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("FaultInjectionClass", "7", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("FaultInjectionClass", "8", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("FaultInjectionClass", "9", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("FaultInjectionClass", "10", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("FaultInjectionClass", "11", nullptr));
        comboBox_2->setItemText(11, QCoreApplication::translate("FaultInjectionClass", "12", nullptr));
        comboBox_2->setItemText(12, QCoreApplication::translate("FaultInjectionClass", "13", nullptr));
        comboBox_2->setItemText(13, QCoreApplication::translate("FaultInjectionClass", "14", nullptr));
        comboBox_2->setItemText(14, QCoreApplication::translate("FaultInjectionClass", "15", nullptr));
        comboBox_2->setItemText(15, QCoreApplication::translate("FaultInjectionClass", "16", nullptr));
        comboBox_2->setItemText(16, QCoreApplication::translate("FaultInjectionClass", "\345\205\250\351\203\250", nullptr));

        label_2->setText(QCoreApplication::translate("FaultInjectionClass", "     \346\263\250\345\205\245\347\261\273\345\236\213", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("FaultInjectionClass", "\347\224\265\345\216\213\346\263\250\345\205\245\346\225\205\351\232\234", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("FaultInjectionClass", "\346\270\251\345\272\246\346\263\250\345\205\245\346\225\205\351\232\234", nullptr));

        checkBox->setText(QCoreApplication::translate("FaultInjectionClass", "\345\205\250\351\200\211", nullptr));
        bt_clear->setText(QCoreApplication::translate("FaultInjectionClass", "\346\270\205\351\231\244", nullptr));
        bt_read_all->setText(QCoreApplication::translate("FaultInjectionClass", "\350\257\273\345\217\226", nullptr));
        bt_write->setText(QCoreApplication::translate("FaultInjectionClass", "\344\270\213\350\256\276\345\205\250\351\203\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaultInjectionClass: public Ui_FaultInjectionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTINJECTION_H
