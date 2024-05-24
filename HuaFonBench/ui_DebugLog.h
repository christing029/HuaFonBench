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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
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
    QPushButton *PBStart;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *PBStop;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Export;
    QPushButton *PBClear;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QPushButton *PBSearch;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DebugLogClass)
    {
        if (DebugLogClass->objectName().isEmpty())
            DebugLogClass->setObjectName(QString::fromUtf8("DebugLogClass"));
        DebugLogClass->resize(1185, 728);
        centralWidget = new QWidget(DebugLogClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_3->addWidget(dateTimeEdit);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        dateTimeEdit_2 = new QDateTimeEdit(centralWidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout_4->addWidget(dateTimeEdit_2);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        PBStart = new QPushButton(centralWidget);
        PBStart->setObjectName(QString::fromUtf8("PBStart"));

        horizontalLayout_5->addWidget(PBStart);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        PBStop = new QPushButton(centralWidget);
        PBStop->setObjectName(QString::fromUtf8("PBStop"));

        horizontalLayout_6->addWidget(PBStop);


        gridLayout->addLayout(horizontalLayout_6, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Export = new QPushButton(centralWidget);
        Export->setObjectName(QString::fromUtf8("Export"));

        horizontalLayout_7->addWidget(Export);


        gridLayout->addLayout(horizontalLayout_7, 5, 0, 1, 1);

        PBClear = new QPushButton(centralWidget);
        PBClear->setObjectName(QString::fromUtf8("PBClear"));

        gridLayout->addWidget(PBClear, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_8->addWidget(lineEdit);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_8->addWidget(comboBox_2);

        PBSearch = new QPushButton(centralWidget);
        PBSearch->setObjectName(QString::fromUtf8("PBSearch"));

        horizontalLayout_8->addWidget(PBSearch);


        gridLayout->addLayout(horizontalLayout_8, 7, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        gridLayout->addLayout(horizontalLayout_9, 9, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(tableView, 0, 1, 1, 1);

        DebugLogClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DebugLogClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1185, 23));
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
        PBStart->setText(QCoreApplication::translate("DebugLogClass", "\345\274\200\345\247\213\347\233\221\346\216\247", nullptr));
        PBStop->setText(QCoreApplication::translate("DebugLogClass", "\346\232\202\345\201\234\347\233\221\346\216\247", nullptr));
        Export->setText(QCoreApplication::translate("DebugLogClass", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        PBClear->setText(QCoreApplication::translate("DebugLogClass", "\346\225\260\346\215\256\346\270\205\351\231\244", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("DebugLogClass", "\346\227\266\351\227\264", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("DebugLogClass", "\346\216\245\345\217\243\347\261\273\345\236\213", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("DebugLogClass", "\345\270\247ID", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("DebugLogClass", "\346\225\260\346\215\256\346\226\271\345\220\221", nullptr));

        PBSearch->setText(QCoreApplication::translate("DebugLogClass", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugLogClass: public Ui_DebugLogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGLOG_H
