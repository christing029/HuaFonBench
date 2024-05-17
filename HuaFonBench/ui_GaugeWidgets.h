/********************************************************************************
** Form generated from reading UI file 'GaugeWidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUGEWIDGETS_H
#define UI_GAUGEWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GaugeWidgetsClass
{
public:

    void setupUi(QWidget *GaugeWidgetsClass)
    {
        if (GaugeWidgetsClass->objectName().isEmpty())
            GaugeWidgetsClass->setObjectName(QString::fromUtf8("GaugeWidgetsClass"));
        GaugeWidgetsClass->resize(268, 279);

        retranslateUi(GaugeWidgetsClass);

        QMetaObject::connectSlotsByName(GaugeWidgetsClass);
    } // setupUi

    void retranslateUi(QWidget *GaugeWidgetsClass)
    {
        GaugeWidgetsClass->setWindowTitle(QCoreApplication::translate("GaugeWidgetsClass", "GaugeWidgets", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GaugeWidgetsClass: public Ui_GaugeWidgetsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUGEWIDGETS_H
