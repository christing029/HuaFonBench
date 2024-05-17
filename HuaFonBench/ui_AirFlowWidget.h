/********************************************************************************
** Form generated from reading UI file 'AirFlowWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRFLOWWIDGET_H
#define UI_AIRFLOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AirFlowWidgetClass
{
public:

    void setupUi(QWidget *AirFlowWidgetClass)
    {
        if (AirFlowWidgetClass->objectName().isEmpty())
            AirFlowWidgetClass->setObjectName(QString::fromUtf8("AirFlowWidgetClass"));
        AirFlowWidgetClass->resize(600, 400);

        retranslateUi(AirFlowWidgetClass);

        QMetaObject::connectSlotsByName(AirFlowWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *AirFlowWidgetClass)
    {
        AirFlowWidgetClass->setWindowTitle(QCoreApplication::translate("AirFlowWidgetClass", "AirFlowWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirFlowWidgetClass: public Ui_AirFlowWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRFLOWWIDGET_H
