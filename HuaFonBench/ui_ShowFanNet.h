/********************************************************************************
** Form generated from reading UI file 'ShowFanNet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWFANNET_H
#define UI_SHOWFANNET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowFanNetClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ShowFanNetClass)
    {
        if (ShowFanNetClass->objectName().isEmpty())
            ShowFanNetClass->setObjectName(QString::fromUtf8("ShowFanNetClass"));
        ShowFanNetClass->resize(751, 595);
        verticalLayout = new QVBoxLayout(ShowFanNetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(ShowFanNetClass);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ShowFanNetClass);

        QMetaObject::connectSlotsByName(ShowFanNetClass);
    } // setupUi

    void retranslateUi(QWidget *ShowFanNetClass)
    {
        ShowFanNetClass->setWindowTitle(QCoreApplication::translate("ShowFanNetClass", "ShowFanNet", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ShowFanNetClass", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ShowFanNetClass", "\351\243\216\346\211\207\350\275\254\351\200\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ShowFanNetClass", "\351\243\216\346\211\207\345\201\234\350\275\254\346\225\205\351\232\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ShowFanNetClass", "\351\243\216\346\211\207\350\275\254\351\200\237\344\270\215\345\214\271\351\205\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowFanNetClass: public Ui_ShowFanNetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFANNET_H
