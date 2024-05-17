/********************************************************************************
** Form generated from reading UI file 'SwitchControl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHCONTROL_H
#define UI_SWITCHCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchControlClass
{
public:

    void setupUi(QWidget *SwitchControlClass)
    {
        if (SwitchControlClass->objectName().isEmpty())
            SwitchControlClass->setObjectName(QString::fromUtf8("SwitchControlClass"));
        SwitchControlClass->resize(600, 400);

        retranslateUi(SwitchControlClass);

        QMetaObject::connectSlotsByName(SwitchControlClass);
    } // setupUi

    void retranslateUi(QWidget *SwitchControlClass)
    {
        SwitchControlClass->setWindowTitle(QCoreApplication::translate("SwitchControlClass", "SwitchControl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SwitchControlClass: public Ui_SwitchControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHCONTROL_H
