/********************************************************************************
** Form generated from reading UI file 'DebugLog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGLOG_H
#define UI_DEBUGLOG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugLogClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Clear;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Export;
    QPushButton *Clear_2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit;
    QPushButton *pushButton_10;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DebugLogClass)
    {
        if (DebugLogClass->objectName().isEmpty())
            DebugLogClass->setObjectName(QString::fromUtf8("DebugLogClass"));
        DebugLogClass->resize(1226, 790);
        centralWidget = new QWidget(DebugLogClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_3->addWidget(dateTimeEdit);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        dateTimeEdit_2 = new QDateTimeEdit(centralWidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout_4->addWidget(dateTimeEdit_2);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        horizontalLayout_5->addWidget(Clear);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_6->addWidget(pushButton_7);


        gridLayout_2->addLayout(horizontalLayout_6, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Export = new QPushButton(centralWidget);
        Export->setObjectName(QString::fromUtf8("Export"));

        horizontalLayout_7->addWidget(Export);


        gridLayout_2->addLayout(horizontalLayout_7, 5, 0, 1, 1);

        Clear_2 = new QPushButton(centralWidget);
        Clear_2->setObjectName(QString::fromUtf8("Clear_2"));

        gridLayout_2->addWidget(Clear_2, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_8->addWidget(lineEdit);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_8->addWidget(pushButton_10);


        gridLayout_2->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        gridLayout_2->addLayout(horizontalLayout_9, 9, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(1000, 0));

        gridLayout->addWidget(tableView, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        DebugLogClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DebugLogClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1226, 23));
        DebugLogClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DebugLogClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DebugLogClass->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DebugLogClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DebugLogClass->setStatusBar(statusBar);

        retranslateUi(DebugLogClass);

        QMetaObject::connectSlotsByName(DebugLogClass);
    } // setupUi

    void retranslateUi(QMainWindow *DebugLogClass)
    {
        DebugLogClass->setWindowTitle(QCoreApplication::translate("DebugLogClass", "DebugLog", nullptr));
        label->setText(QCoreApplication::translate("DebugLogClass", "\350\260\203\350\257\225\346\216\245\345\217\243\347\261\273\345\236\213:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("DebugLogClass", "Can\347\233\221\346\216\247", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("DebugLogClass", "\347\275\221\345\217\243\347\233\221\346\216\247", nullptr));

        label_2->setText(QCoreApplication::translate("DebugLogClass", "\345\274\200\345\247\213\346\227\266\351\227\264:", nullptr));
        label_3->setText(QCoreApplication::translate("DebugLogClass", "\347\273\223\346\235\237\346\227\266\351\227\264:", nullptr));
        Clear->setText(QCoreApplication::translate("DebugLogClass", "\345\274\200\345\247\213\347\233\221\346\216\247", nullptr));
        pushButton_7->setText(QCoreApplication::translate("DebugLogClass", "\346\232\202\345\201\234\347\233\221\346\216\247", nullptr));
        Export->setText(QCoreApplication::translate("DebugLogClass", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        Clear_2->setText(QCoreApplication::translate("DebugLogClass", "\346\225\260\346\215\256\346\270\205\351\231\244", nullptr));
        pushButton_10->setText(QCoreApplication::translate("DebugLogClass", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugLogClass: public Ui_DebugLogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGLOG_H
