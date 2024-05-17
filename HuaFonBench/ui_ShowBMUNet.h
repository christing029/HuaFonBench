/********************************************************************************
** Form generated from reading UI file 'ShowBMUNet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWBMUNET_H
#define UI_SHOWBMUNET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowBMUNetClass
{
public:

    void setupUi(QWidget *ShowBMUNetClass)
    {
        if (ShowBMUNetClass->objectName().isEmpty())
            ShowBMUNetClass->setObjectName(QString::fromUtf8("ShowBMUNetClass"));
        ShowBMUNetClass->resize(234, 210);
        ShowBMUNetClass->setMaximumSize(QSize(16777215, 16777215));

        retranslateUi(ShowBMUNetClass);

        QMetaObject::connectSlotsByName(ShowBMUNetClass);
    } // setupUi

    void retranslateUi(QWidget *ShowBMUNetClass)
    {
        ShowBMUNetClass->setWindowTitle(QCoreApplication::translate("ShowBMUNetClass", "ShowBMUNet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowBMUNetClass: public Ui_ShowBMUNetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWBMUNET_H
