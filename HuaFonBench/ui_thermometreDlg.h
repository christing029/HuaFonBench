/********************************************************************************
** Form generated from reading UI file 'thermometreDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THERMOMETREDLG_H
#define UI_THERMOMETREDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thermometreDlgClass
{
public:

    void setupUi(QWidget *thermometreDlgClass)
    {
        if (thermometreDlgClass->objectName().isEmpty())
            thermometreDlgClass->setObjectName(QString::fromUtf8("thermometreDlgClass"));
        thermometreDlgClass->resize(600, 400);

        retranslateUi(thermometreDlgClass);

        QMetaObject::connectSlotsByName(thermometreDlgClass);
    } // setupUi

    void retranslateUi(QWidget *thermometreDlgClass)
    {
        thermometreDlgClass->setWindowTitle(QCoreApplication::translate("thermometreDlgClass", "thermometreDlg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thermometreDlgClass: public Ui_thermometreDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THERMOMETREDLG_H
