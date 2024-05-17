/********************************************************************************
** Form generated from reading UI file 'shownetwork.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWNETWORK_H
#define UI_SHOWNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <src/shownetwork/GaugeWidgets.h>
#include "src/public/batteryitem.h"
#include "src/showslave/slaveitemwidget.h"

QT_BEGIN_NAMESPACE

class Ui_shownetwork
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    BatteryItem *widget_9;
    QLabel *label;
    SlaveItemWidget *widget_4;
    SlaveItemWidget *widget_2;
    SlaveItemWidget *widget_3;
    SlaveItemWidget *widget_5;
    SlaveItemWidget *widget;
    SlaveItemWidget *widget_8;
    SlaveItemWidget *widget_6;
    SlaveItemWidget *widget_7;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    GaugeWidgets *widget_10;
    GaugeWidgets *widget_11;
    GaugeWidgets *widget_12;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *shownetwork)
    {
        if (shownetwork->objectName().isEmpty())
            shownetwork->setObjectName(QString::fromUtf8("shownetwork"));
        shownetwork->resize(1135, 930);
        horizontalLayout = new QHBoxLayout(shownetwork);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(shownetwork);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setMinimumSize(QSize(500, 0));
        groupBox->setMaximumSize(QSize(500, 16777215));
        groupBox->setMouseTracking(false);
        widget_9 = new BatteryItem(groupBox);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setEnabled(false);
        widget_9->setGeometry(QRect(280, 360, 200, 150));
        widget_9->setMinimumSize(QSize(200, 150));
        widget_9->setMaximumSize(QSize(300, 300));
        widget_9->setMouseTracking(true);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 1028, 24, 16));
        label->setMaximumSize(QSize(100, 50));
        widget_4 = new SlaveItemWidget(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(11, 341, 150, 100));
        widget_4->setMinimumSize(QSize(150, 100));
        widget_4->setMaximumSize(QSize(150, 100));
        widget_2 = new SlaveItemWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(11, 129, 150, 100));
        widget_2->setMinimumSize(QSize(150, 100));
        widget_2->setMaximumSize(QSize(150, 100));
        widget_3 = new SlaveItemWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(11, 235, 150, 100));
        widget_3->setMinimumSize(QSize(150, 100));
        widget_3->setMaximumSize(QSize(150, 100));
        widget_5 = new SlaveItemWidget(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(11, 447, 150, 100));
        widget_5->setMinimumSize(QSize(150, 100));
        widget_5->setMaximumSize(QSize(150, 100));
        widget = new SlaveItemWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 23, 150, 100));
        widget->setMinimumSize(QSize(150, 100));
        widget->setMaximumSize(QSize(150, 100));
        widget_8 = new SlaveItemWidget(groupBox);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(11, 765, 150, 100));
        widget_8->setMinimumSize(QSize(150, 100));
        widget_8->setMaximumSize(QSize(150, 100));
        widget_8->setMouseTracking(true);
        widget_6 = new SlaveItemWidget(groupBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(11, 553, 150, 100));
        widget_6->setMinimumSize(QSize(150, 100));
        widget_6->setMaximumSize(QSize(150, 100));
        widget_7 = new SlaveItemWidget(groupBox);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(11, 659, 150, 100));
        widget_7->setMinimumSize(QSize(150, 100));
        widget_7->setMaximumSize(QSize(150, 100));
        widget_7->setMouseTracking(true);

        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(shownetwork);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_10 = new GaugeWidgets(groupBox_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));

        horizontalLayout_2->addWidget(widget_10);

        widget_11 = new GaugeWidgets(groupBox_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));

        horizontalLayout_2->addWidget(widget_11);

        widget_12 = new GaugeWidgets(groupBox_3);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));

        horizontalLayout_2->addWidget(widget_12);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);

        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 12)
            tableWidget->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 500));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(tableWidget);


        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(shownetwork);

        QMetaObject::connectSlotsByName(shownetwork);
    } // setupUi

    void retranslateUi(QWidget *shownetwork)
    {
        shownetwork->setWindowTitle(QCoreApplication::translate("shownetwork", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("shownetwork", "\347\275\221\347\273\234\346\213\223\346\211\221\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("shownetwork", "\345\205\205\347\224\265", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("shownetwork", "\346\225\260\346\215\256\346\230\276\347\244\272\345\233\276", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("shownetwork", "GroupBox", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("shownetwork", "\346\226\260\345\273\272\345\210\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shownetwork: public Ui_shownetwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWNETWORK_H
