/********************************************************************************
** Form generated from reading UI file 'slavemng.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLAVEMNG_H
#define UI_SLAVEMNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SlaveMng
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cb_channle;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QPushButton *bt_up_2;
    QPushButton *bt_up_4;
    QPushButton *bt_up;
    QPushButton *bt_up_3;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SlaveMng)
    {
        if (SlaveMng->objectName().isEmpty())
            SlaveMng->setObjectName(QString::fromUtf8("SlaveMng"));
        SlaveMng->resize(839, 609);
        centralwidget = new QWidget(SlaveMng);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cb_channle = new QComboBox(centralwidget);
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->addItem(QString());
        cb_channle->setObjectName(QString::fromUtf8("cb_channle"));

        horizontalLayout->addWidget(cb_channle);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        bt_up_2 = new QPushButton(centralwidget);
        bt_up_2->setObjectName(QString::fromUtf8("bt_up_2"));

        horizontalLayout->addWidget(bt_up_2);

        bt_up_4 = new QPushButton(centralwidget);
        bt_up_4->setObjectName(QString::fromUtf8("bt_up_4"));

        horizontalLayout->addWidget(bt_up_4);

        bt_up = new QPushButton(centralwidget);
        bt_up->setObjectName(QString::fromUtf8("bt_up"));

        horizontalLayout->addWidget(bt_up);

        bt_up_3 = new QPushButton(centralwidget);
        bt_up_3->setObjectName(QString::fromUtf8("bt_up_3"));

        horizontalLayout->addWidget(bt_up_3);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        SlaveMng->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SlaveMng);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 839, 23));
        SlaveMng->setMenuBar(menubar);
        statusbar = new QStatusBar(SlaveMng);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SlaveMng->setStatusBar(statusbar);

        retranslateUi(SlaveMng);

        QMetaObject::connectSlotsByName(SlaveMng);
    } // setupUi

    void retranslateUi(QMainWindow *SlaveMng)
    {
        SlaveMng->setWindowTitle(QCoreApplication::translate("SlaveMng", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("SlaveMng", "\350\256\276\345\244\207ID", nullptr));
        cb_channle->setItemText(0, QCoreApplication::translate("SlaveMng", "1", nullptr));
        cb_channle->setItemText(1, QCoreApplication::translate("SlaveMng", "2", nullptr));
        cb_channle->setItemText(2, QCoreApplication::translate("SlaveMng", "3", nullptr));
        cb_channle->setItemText(3, QCoreApplication::translate("SlaveMng", "4", nullptr));
        cb_channle->setItemText(4, QCoreApplication::translate("SlaveMng", "5", nullptr));
        cb_channle->setItemText(5, QCoreApplication::translate("SlaveMng", "6", nullptr));
        cb_channle->setItemText(6, QCoreApplication::translate("SlaveMng", "7", nullptr));
        cb_channle->setItemText(7, QCoreApplication::translate("SlaveMng", "8", nullptr));
        cb_channle->setItemText(8, QCoreApplication::translate("SlaveMng", "9", nullptr));
        cb_channle->setItemText(9, QCoreApplication::translate("SlaveMng", "10", nullptr));
        cb_channle->setItemText(10, QCoreApplication::translate("SlaveMng", "11", nullptr));
        cb_channle->setItemText(11, QCoreApplication::translate("SlaveMng", "12", nullptr));
        cb_channle->setItemText(12, QCoreApplication::translate("SlaveMng", "13", nullptr));
        cb_channle->setItemText(13, QCoreApplication::translate("SlaveMng", "14", nullptr));
        cb_channle->setItemText(14, QCoreApplication::translate("SlaveMng", "15", nullptr));

        checkBox->setText(QCoreApplication::translate("SlaveMng", "\350\257\273\345\217\226", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SlaveMng", "\344\273\216\346\234\272\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SlaveMng", "\344\273\216\346\234\272\346\270\251\345\272\246\351\200\232\351\201\223\350\256\276\347\275\256", nullptr));

        bt_up_2->setText(QCoreApplication::translate("SlaveMng", "\351\273\230\350\256\244\345\200\274", nullptr));
        bt_up_4->setText(QCoreApplication::translate("SlaveMng", "\346\211\200\346\234\211\345\217\202\346\225\260\344\270\213\345\217\221", nullptr));
        bt_up->setText(QCoreApplication::translate("SlaveMng", "\344\270\213\350\256\276\346\211\200\346\234\211\344\273\216\346\216\247", nullptr));
        bt_up_3->setText(QCoreApplication::translate("SlaveMng", "\346\270\205\347\251\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SlaveMng", "\345\217\202\346\225\260\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SlaveMng", "\351\273\230\350\256\244\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SlaveMng", "\345\256\236\351\231\205\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SlaveMng", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SlaveMng", "\346\240\274\345\274\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SlaveMng", "\344\270\213\350\256\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("SlaveMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("SlaveMng", "\350\257\273\345\217\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SlaveMng: public Ui_SlaveMng {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLAVEMNG_H
