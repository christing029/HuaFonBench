/********************************************************************************
** Form generated from reading UI file 'LogWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
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

class Ui_LogWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_10;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit_2;
    QPushButton *ContentSearch;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Export;
    QPushButton *Clear;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_7;
    QPushButton *LastPage;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *PreviousPage;
    QPushButton *pushButton_8;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit;
    QPushButton *pushButton_10;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *TotalPage;
    QSpacerItem *horizontalSpacer_2;
    QLabel *PageNo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LogWindowClass)
    {
        if (LogWindowClass->objectName().isEmpty())
            LogWindowClass->setObjectName(QString::fromUtf8("LogWindowClass"));
        LogWindowClass->resize(1216, 3031);
        centralWidget = new QWidget(LogWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(1000, 0));

        horizontalLayout_10->addWidget(tableView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_3->addWidget(dateTimeEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        dateTimeEdit_2 = new QDateTimeEdit(centralWidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout_4->addWidget(dateTimeEdit_2);


        verticalLayout->addLayout(horizontalLayout_4);

        ContentSearch = new QPushButton(centralWidget);
        ContentSearch->setObjectName(QString::fromUtf8("ContentSearch"));

        verticalLayout->addWidget(ContentSearch);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Export = new QPushButton(centralWidget);
        Export->setObjectName(QString::fromUtf8("Export"));

        horizontalLayout_5->addWidget(Export);

        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        horizontalLayout_5->addWidget(Clear);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_6->addWidget(pushButton_7);

        LastPage = new QPushButton(centralWidget);
        LastPage->setObjectName(QString::fromUtf8("LastPage"));

        horizontalLayout_6->addWidget(LastPage);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        PreviousPage = new QPushButton(centralWidget);
        PreviousPage->setObjectName(QString::fromUtf8("PreviousPage"));

        horizontalLayout_7->addWidget(PreviousPage);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_7->addWidget(pushButton_8);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_8->addWidget(lineEdit);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_8->addWidget(pushButton_10);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        TotalPage = new QLabel(centralWidget);
        TotalPage->setObjectName(QString::fromUtf8("TotalPage"));

        horizontalLayout_9->addWidget(TotalPage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        PageNo = new QLabel(centralWidget);
        PageNo->setObjectName(QString::fromUtf8("PageNo"));

        horizontalLayout_9->addWidget(PageNo);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_2);

        LogWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LogWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1216, 23));
        LogWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LogWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LogWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LogWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LogWindowClass->setStatusBar(statusBar);

        retranslateUi(LogWindowClass);

        QMetaObject::connectSlotsByName(LogWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *LogWindowClass)
    {
        LogWindowClass->setWindowTitle(QCoreApplication::translate("LogWindowClass", "LogWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("LogWindowClass", "Add Log1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LogWindowClass", "Add Log2", nullptr));
        label->setText(QCoreApplication::translate("LogWindowClass", "Log Type:", nullptr));
        label_2->setText(QCoreApplication::translate("LogWindowClass", "\345\274\200\345\247\213\346\227\266\351\227\264:", nullptr));
        label_3->setText(QCoreApplication::translate("LogWindowClass", "\347\273\223\346\235\237\346\227\266\351\227\264:", nullptr));
        ContentSearch->setText(QCoreApplication::translate("LogWindowClass", "Search", nullptr));
        Export->setText(QCoreApplication::translate("LogWindowClass", "Export", nullptr));
        Clear->setText(QCoreApplication::translate("LogWindowClass", "Clear", nullptr));
        pushButton_7->setText(QCoreApplication::translate("LogWindowClass", "First Page", nullptr));
        LastPage->setText(QCoreApplication::translate("LogWindowClass", "Last Page", nullptr));
        PreviousPage->setText(QCoreApplication::translate("LogWindowClass", "Previous Page", nullptr));
        pushButton_8->setText(QCoreApplication::translate("LogWindowClass", "Next Page", nullptr));
        pushButton_10->setText(QCoreApplication::translate("LogWindowClass", "Search", nullptr));
        TotalPage->setText(QCoreApplication::translate("LogWindowClass", "Total Pages:3", nullptr));
        PageNo->setText(QCoreApplication::translate("LogWindowClass", "PagesNo:3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWindowClass: public Ui_LogWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
