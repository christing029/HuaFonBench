/********************************************************************************
** Form generated from reading UI file 'dataAnalysis.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAANALYSIS_H
#define UI_DATAANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataAnalysisClass
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Export;
    QPushButton *Clear;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QComboBox *comboBox_3;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *StartPb;
    QPushButton *StopPb;
    QPushButton *FastPb;
    QPushButton *SlowPb;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *NextPage;
    QPushButton *PreviousPage;
    QPushButton *FirstPage;
    QPushButton *LastPage;
    QHBoxLayout *horizontalLayout_9;
    QLabel *TotalPage;
    QSpacerItem *horizontalSpacer_2;
    QLabel *PageNo;
    QGridLayout *gridLayout;

    void setupUi(QWidget *dataAnalysisClass)
    {
        if (dataAnalysisClass->objectName().isEmpty())
            dataAnalysisClass->setObjectName(QString::fromUtf8("dataAnalysisClass"));
        dataAnalysisClass->resize(892, 701);
        gridLayout_2 = new QGridLayout(dataAnalysisClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Export = new QPushButton(dataAnalysisClass);
        Export->setObjectName(QString::fromUtf8("Export"));

        horizontalLayout->addWidget(Export);

        Clear = new QPushButton(dataAnalysisClass);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        horizontalLayout->addWidget(Clear);

        label = new QLabel(dataAnalysisClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(dataAnalysisClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_4 = new QLabel(dataAnalysisClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBox_2 = new QComboBox(dataAnalysisClass);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        label_5 = new QLabel(dataAnalysisClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        comboBox_3 = new QComboBox(dataAnalysisClass);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout->addWidget(comboBox_3);

        label_2 = new QLabel(dataAnalysisClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(dataAnalysisClass);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout->addWidget(dateTimeEdit);

        label_3 = new QLabel(dataAnalysisClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dateTimeEdit_2 = new QDateTimeEdit(dataAnalysisClass);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout->addWidget(dateTimeEdit_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        StartPb = new QPushButton(dataAnalysisClass);
        StartPb->setObjectName(QString::fromUtf8("StartPb"));

        horizontalLayout_2->addWidget(StartPb);

        StopPb = new QPushButton(dataAnalysisClass);
        StopPb->setObjectName(QString::fromUtf8("StopPb"));

        horizontalLayout_2->addWidget(StopPb);

        FastPb = new QPushButton(dataAnalysisClass);
        FastPb->setObjectName(QString::fromUtf8("FastPb"));

        horizontalLayout_2->addWidget(FastPb);

        SlowPb = new QPushButton(dataAnalysisClass);
        SlowPb->setObjectName(QString::fromUtf8("SlowPb"));

        horizontalLayout_2->addWidget(SlowPb);

        label_6 = new QLabel(dataAnalysisClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(dataAnalysisClass);
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
        tableWidget->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        NextPage = new QPushButton(dataAnalysisClass);
        NextPage->setObjectName(QString::fromUtf8("NextPage"));

        horizontalLayout_3->addWidget(NextPage);

        PreviousPage = new QPushButton(dataAnalysisClass);
        PreviousPage->setObjectName(QString::fromUtf8("PreviousPage"));

        horizontalLayout_3->addWidget(PreviousPage);

        FirstPage = new QPushButton(dataAnalysisClass);
        FirstPage->setObjectName(QString::fromUtf8("FirstPage"));

        horizontalLayout_3->addWidget(FirstPage);

        LastPage = new QPushButton(dataAnalysisClass);
        LastPage->setObjectName(QString::fromUtf8("LastPage"));

        horizontalLayout_3->addWidget(LastPage);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        TotalPage = new QLabel(dataAnalysisClass);
        TotalPage->setObjectName(QString::fromUtf8("TotalPage"));

        horizontalLayout_9->addWidget(TotalPage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        PageNo = new QLabel(dataAnalysisClass);
        PageNo->setObjectName(QString::fromUtf8("PageNo"));

        horizontalLayout_9->addWidget(PageNo);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout_2->addLayout(verticalLayout_2, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);


        retranslateUi(dataAnalysisClass);

        QMetaObject::connectSlotsByName(dataAnalysisClass);
    } // setupUi

    void retranslateUi(QWidget *dataAnalysisClass)
    {
        dataAnalysisClass->setWindowTitle(QCoreApplication::translate("dataAnalysisClass", "dataAnalysis", nullptr));
        Export->setText(QCoreApplication::translate("dataAnalysisClass", "Export", nullptr));
        Clear->setText(QCoreApplication::translate("dataAnalysisClass", "Clear", nullptr));
        label->setText(QCoreApplication::translate("dataAnalysisClass", "\344\273\216\346\234\272ID:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("dataAnalysisClass", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("dataAnalysisClass", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("dataAnalysisClass", "3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("dataAnalysisClass", "4", nullptr));

        label_4->setText(QCoreApplication::translate("dataAnalysisClass", "\345\210\206\346\236\220\347\261\273\345\236\213", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("dataAnalysisClass", "\346\270\251\345\272\246\346\225\260\346\215\256", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("dataAnalysisClass", "\347\224\265\345\216\213\346\225\260\346\215\256", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("dataAnalysisClass", "\347\212\266\346\200\201\346\225\260\346\215\256", nullptr));

        label_5->setText(QCoreApplication::translate("dataAnalysisClass", "\347\224\265\350\212\257ID", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("dataAnalysisClass", "1", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("dataAnalysisClass", "2", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("dataAnalysisClass", "3", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("dataAnalysisClass", "4", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("dataAnalysisClass", "5", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("dataAnalysisClass", "6", nullptr));
        comboBox_3->setItemText(6, QCoreApplication::translate("dataAnalysisClass", "7", nullptr));
        comboBox_3->setItemText(7, QCoreApplication::translate("dataAnalysisClass", "8", nullptr));
        comboBox_3->setItemText(8, QCoreApplication::translate("dataAnalysisClass", "9", nullptr));
        comboBox_3->setItemText(9, QCoreApplication::translate("dataAnalysisClass", "10", nullptr));
        comboBox_3->setItemText(10, QCoreApplication::translate("dataAnalysisClass", "11", nullptr));
        comboBox_3->setItemText(11, QCoreApplication::translate("dataAnalysisClass", "12", nullptr));
        comboBox_3->setItemText(12, QCoreApplication::translate("dataAnalysisClass", "13", nullptr));
        comboBox_3->setItemText(13, QCoreApplication::translate("dataAnalysisClass", "14", nullptr));
        comboBox_3->setItemText(14, QCoreApplication::translate("dataAnalysisClass", "15", nullptr));
        comboBox_3->setItemText(15, QCoreApplication::translate("dataAnalysisClass", "16", nullptr));
        comboBox_3->setItemText(16, QCoreApplication::translate("dataAnalysisClass", "\345\205\250\351\203\250", nullptr));

        label_2->setText(QCoreApplication::translate("dataAnalysisClass", "\345\274\200\345\247\213\346\227\266\351\227\264:", nullptr));
        label_3->setText(QCoreApplication::translate("dataAnalysisClass", "\347\273\223\346\235\237\346\227\266\351\227\264:", nullptr));
        StartPb->setText(QCoreApplication::translate("dataAnalysisClass", "\345\274\200\345\247\213", nullptr));
        StopPb->setText(QCoreApplication::translate("dataAnalysisClass", "\346\232\202\345\201\234", nullptr));
        FastPb->setText(QCoreApplication::translate("dataAnalysisClass", "\345\277\253\350\277\233", nullptr));
        SlowPb->setText(QCoreApplication::translate("dataAnalysisClass", "\345\233\236\346\224\276", nullptr));
        label_6->setText(QCoreApplication::translate("dataAnalysisClass", "X1", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("dataAnalysisClass", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("dataAnalysisClass", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("dataAnalysisClass", "\345\255\220\351\241\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("dataAnalysisClass", "\345\200\274", nullptr));
        NextPage->setText(QCoreApplication::translate("dataAnalysisClass", "\344\270\213\344\270\200\351\241\265", nullptr));
        PreviousPage->setText(QCoreApplication::translate("dataAnalysisClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        FirstPage->setText(QCoreApplication::translate("dataAnalysisClass", "\347\254\254\344\270\200\351\241\265", nullptr));
        LastPage->setText(QCoreApplication::translate("dataAnalysisClass", "\346\234\200\345\220\216\351\241\265", nullptr));
        TotalPage->setText(QCoreApplication::translate("dataAnalysisClass", "Total Pages:3", nullptr));
        PageNo->setText(QCoreApplication::translate("dataAnalysisClass", "PagesNo:3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dataAnalysisClass: public Ui_dataAnalysisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAANALYSIS_H
