/********************************************************************************
** Form generated from reading UI file 'ShowMaster.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWMASTER_H
#define UI_SHOWMASTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowMasterClass
{
public:
    QWidget *widget;
    QLabel *label;

    void setupUi(QWidget *ShowMasterClass)
    {
        if (ShowMasterClass->objectName().isEmpty())
            ShowMasterClass->setObjectName(QString::fromUtf8("ShowMasterClass"));
        ShowMasterClass->resize(854, 657);
        widget = new QWidget(ShowMasterClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 120, 80));
        label = new QLabel(ShowMasterClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 40, 54, 12));

        retranslateUi(ShowMasterClass);

        QMetaObject::connectSlotsByName(ShowMasterClass);
    } // setupUi

    void retranslateUi(QWidget *ShowMasterClass)
    {
        ShowMasterClass->setWindowTitle(QCoreApplication::translate("ShowMasterClass", "ShowMaster", nullptr));
        label->setText(QCoreApplication::translate("ShowMasterClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowMasterClass: public Ui_ShowMasterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWMASTER_H
