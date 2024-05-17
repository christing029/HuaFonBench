/********************************************************************************
** Form generated from reading UI file 'batteryitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYITEM_H
#define UI_BATTERYITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatteryItem
{
public:

    void setupUi(QWidget *BatteryItem)
    {
        if (BatteryItem->objectName().isEmpty())
            BatteryItem->setObjectName(QString::fromUtf8("BatteryItem"));
        BatteryItem->resize(408, 301);

        retranslateUi(BatteryItem);

        QMetaObject::connectSlotsByName(BatteryItem);
    } // setupUi

    void retranslateUi(QWidget *BatteryItem)
    {
        BatteryItem->setWindowTitle(QCoreApplication::translate("BatteryItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BatteryItem: public Ui_BatteryItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYITEM_H
