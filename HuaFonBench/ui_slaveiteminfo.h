/********************************************************************************
** Form generated from reading UI file 'slaveiteminfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLAVEITEMINFO_H
#define UI_SLAVEITEMINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SlaveItemInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *LabelInfo;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget_3;

    void setupUi(QWidget *SlaveItemInfo)
    {
        if (SlaveItemInfo->objectName().isEmpty())
            SlaveItemInfo->setObjectName(QString::fromUtf8("SlaveItemInfo"));
        SlaveItemInfo->resize(1138, 915);
        verticalLayout = new QVBoxLayout(SlaveItemInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelInfo = new QLabel(SlaveItemInfo);
        LabelInfo->setObjectName(QString::fromUtf8("LabelInfo"));
        LabelInfo->setMaximumSize(QSize(16777215, 10));
        LabelInfo->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        LabelInfo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LabelInfo);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        tabWidget = new QTabWidget(SlaveItemInfo);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 500));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(tableWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableWidget_2 = new QTableWidget(tab_2);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_4->addWidget(tableWidget_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableWidget_3 = new QTableWidget(tab_3);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(tableWidget_3);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(SlaveItemInfo);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SlaveItemInfo);
    } // setupUi

    void retranslateUi(QWidget *SlaveItemInfo)
    {
        SlaveItemInfo->setWindowTitle(QCoreApplication::translate("SlaveItemInfo", "Form", nullptr));
        LabelInfo->setText(QCoreApplication::translate("SlaveItemInfo", "\344\273\216\346\216\247", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SlaveItemInfo", "\345\215\225\344\275\223\347\224\265\345\216\213\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SlaveItemInfo", "\345\215\225\344\275\223\346\270\251\345\272\246\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("SlaveItemInfo", "\345\215\225\344\275\223\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SlaveItemInfo: public Ui_SlaveItemInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLAVEITEMINFO_H
