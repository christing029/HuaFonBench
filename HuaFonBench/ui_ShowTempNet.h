/********************************************************************************
** Form generated from reading UI file 'ShowTempNet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWTEMPNET_H
#define UI_SHOWTEMPNET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowTempNetClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ShowTempNetClass)
    {
        if (ShowTempNetClass->objectName().isEmpty())
            ShowTempNetClass->setObjectName(QString::fromUtf8("ShowTempNetClass"));
        ShowTempNetClass->resize(714, 502);
        verticalLayout = new QVBoxLayout(ShowTempNetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(ShowTempNetClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ShowTempNetClass);

        QMetaObject::connectSlotsByName(ShowTempNetClass);
    } // setupUi

    void retranslateUi(QWidget *ShowTempNetClass)
    {
        ShowTempNetClass->setWindowTitle(QCoreApplication::translate("ShowTempNetClass", "ShowTempNet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowTempNetClass: public Ui_ShowTempNetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTEMPNET_H
