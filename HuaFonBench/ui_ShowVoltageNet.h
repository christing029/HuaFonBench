/********************************************************************************
** Form generated from reading UI file 'ShowVoltageNet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWVOLTAGENET_H
#define UI_SHOWVOLTAGENET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowVoltageNetClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ShowVoltageNetClass)
    {
        if (ShowVoltageNetClass->objectName().isEmpty())
            ShowVoltageNetClass->setObjectName(QString::fromUtf8("ShowVoltageNetClass"));
        ShowVoltageNetClass->resize(888, 596);
        verticalLayout = new QVBoxLayout(ShowVoltageNetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(ShowVoltageNetClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ShowVoltageNetClass);

        QMetaObject::connectSlotsByName(ShowVoltageNetClass);
    } // setupUi

    void retranslateUi(QWidget *ShowVoltageNetClass)
    {
        ShowVoltageNetClass->setWindowTitle(QCoreApplication::translate("ShowVoltageNetClass", "ShowVoltageNet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowVoltageNetClass: public Ui_ShowVoltageNetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWVOLTAGENET_H
