/********************************************************************************
** Form generated from reading UI file 'HistoryAlarmLog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYALARMLOG_H
#define UI_HISTORYALARMLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryAlarmLogClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_10;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Export;
    QDateTimeEdit *dateTimeEdit_2;
    QHBoxLayout *horizontalLayout_7;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_12;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_10;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Clear;
    QLineEdit *m_ctlFilter;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_7;
    QPushButton *LastPage;
    QPushButton *PreviousPage_2;
    QPushButton *pushButton_11;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HistoryAlarmLogClass)
    {
        if (HistoryAlarmLogClass->objectName().isEmpty())
            HistoryAlarmLogClass->setObjectName(QString::fromUtf8("HistoryAlarmLogClass"));
        HistoryAlarmLogClass->resize(1214, 755);
        centralWidget = new QWidget(HistoryAlarmLogClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 7, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        gridLayout_2->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        Export = new QPushButton(centralWidget);
        Export->setObjectName(QString::fromUtf8("Export"));

        gridLayout_2->addWidget(Export, 13, 0, 1, 1);

        dateTimeEdit_2 = new QDateTimeEdit(centralWidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        gridLayout_2->addWidget(dateTimeEdit_2, 11, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        gridLayout_2->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout_2->addWidget(dateTimeEdit, 8, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        gridLayout_2->addLayout(horizontalLayout_9, 16, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        gridLayout_2->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        horizontalLayout_11->addWidget(pushButton_12);


        gridLayout_2->addLayout(horizontalLayout_11, 14, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 15, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_8->addWidget(pushButton_10);


        gridLayout_2->addLayout(horizontalLayout_8, 12, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        horizontalLayout_5->addWidget(Clear);


        gridLayout_2->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        m_ctlFilter = new QLineEdit(centralWidget);
        m_ctlFilter->setObjectName(QString::fromUtf8("m_ctlFilter"));
        m_ctlFilter->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        gridLayout_2->addWidget(m_ctlFilter, 2, 0, 1, 1);


        horizontalLayout_10->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(1000, 0));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        LastPage = new QPushButton(centralWidget);
        LastPage->setObjectName(QString::fromUtf8("LastPage"));

        horizontalLayout->addWidget(LastPage);

        PreviousPage_2 = new QPushButton(centralWidget);
        PreviousPage_2->setObjectName(QString::fromUtf8("PreviousPage_2"));

        horizontalLayout->addWidget(PreviousPage_2);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout->addWidget(pushButton_11);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_10->addLayout(verticalLayout);

        HistoryAlarmLogClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HistoryAlarmLogClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1214, 23));
        HistoryAlarmLogClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HistoryAlarmLogClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        HistoryAlarmLogClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HistoryAlarmLogClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        HistoryAlarmLogClass->setStatusBar(statusBar);

        retranslateUi(HistoryAlarmLogClass);

        QMetaObject::connectSlotsByName(HistoryAlarmLogClass);
    } // setupUi

    void retranslateUi(QMainWindow *HistoryAlarmLogClass)
    {
        HistoryAlarmLogClass->setWindowTitle(QCoreApplication::translate("HistoryAlarmLogClass", "HistoryAlarmLog", nullptr));
        label->setText(QCoreApplication::translate("HistoryAlarmLogClass", "UUID:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("HistoryAlarmLogClass", "\345\205\250\351\203\250", nullptr));

        label_2->setText(QCoreApplication::translate("HistoryAlarmLogClass", "\345\274\200\345\247\213\346\227\266\351\227\264:", nullptr));
        Export->setText(QCoreApplication::translate("HistoryAlarmLogClass", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        pushButton_12->setText(QCoreApplication::translate("HistoryAlarmLogClass", "\346\225\260\346\215\256\345\272\223\346\270\205\351\231\244", nullptr));
        label_3->setText(QCoreApplication::translate("HistoryAlarmLogClass", "\347\273\223\346\235\237\346\227\266\351\227\264:", nullptr));
        pushButton_10->setText(QCoreApplication::translate("HistoryAlarmLogClass", "\346\227\266\351\227\264\346\237\245\350\257\242", nullptr));
        Clear->setText(QCoreApplication::translate("HistoryAlarmLogClass", "UUID\346\237\245\350\257\242", nullptr));
        m_ctlFilter->setPlaceholderText(QCoreApplication::translate("HistoryAlarmLogClass", "\346\214\211\345\220\215\345\255\227\346\237\245\350\257\242", nullptr));
        pushButton_7->setText(QCoreApplication::translate("HistoryAlarmLogClass", "First Page", nullptr));
        LastPage->setText(QCoreApplication::translate("HistoryAlarmLogClass", "Last Page", nullptr));
        PreviousPage_2->setText(QCoreApplication::translate("HistoryAlarmLogClass", "Previous Page", nullptr));
        pushButton_11->setText(QCoreApplication::translate("HistoryAlarmLogClass", "Next Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryAlarmLogClass: public Ui_HistoryAlarmLogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYALARMLOG_H
