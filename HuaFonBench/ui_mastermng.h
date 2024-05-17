/********************************************************************************
** Form generated from reading UI file 'mastermng.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERMNG_H
#define UI_MASTERMNG_H

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

class Ui_MasterMng
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QPushButton *bt_default_all;
    QPushButton *bt_read_all;
    QPushButton *bt_write_all;
    QPushButton *bt_clear_all;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MasterMng)
    {
        if (MasterMng->objectName().isEmpty())
            MasterMng->setObjectName(QString::fromUtf8("MasterMng"));
        MasterMng->resize(913, 694);
        centralwidget = new QWidget(MasterMng);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        bt_default_all = new QPushButton(centralwidget);
        bt_default_all->setObjectName(QString::fromUtf8("bt_default_all"));

        horizontalLayout->addWidget(bt_default_all);

        bt_read_all = new QPushButton(centralwidget);
        bt_read_all->setObjectName(QString::fromUtf8("bt_read_all"));

        horizontalLayout->addWidget(bt_read_all);

        bt_write_all = new QPushButton(centralwidget);
        bt_write_all->setObjectName(QString::fromUtf8("bt_write_all"));

        horizontalLayout->addWidget(bt_write_all);

        bt_clear_all = new QPushButton(centralwidget);
        bt_clear_all->setObjectName(QString::fromUtf8("bt_clear_all"));

        horizontalLayout->addWidget(bt_clear_all);


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

        MasterMng->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MasterMng);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 913, 23));
        MasterMng->setMenuBar(menubar);
        statusbar = new QStatusBar(MasterMng);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MasterMng->setStatusBar(statusbar);

        retranslateUi(MasterMng);

        QMetaObject::connectSlotsByName(MasterMng);
    } // setupUi

    void retranslateUi(QMainWindow *MasterMng)
    {
        MasterMng->setWindowTitle(QCoreApplication::translate("MasterMng", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MasterMng", "\344\270\273\346\216\247", nullptr));
        label_2->setText(QCoreApplication::translate("MasterMng", "\345\257\204\345\255\230\345\231\250\345\214\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MasterMng", "\350\256\276\345\244\207\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MasterMng", "\351\200\232\350\256\257\346\216\245\345\217\243\351\205\215\347\275\256", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MasterMng", "\347\275\221\347\273\234\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MasterMng", "SOC\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MasterMng", "\346\240\241\345\207\206\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MasterMng", "\347\224\265\346\261\240\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MasterMng", "\345\235\207\350\241\241\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MasterMng", "\344\274\240\346\204\237\345\231\250\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MasterMng", "\344\270\200\347\272\247\351\227\250\351\231\220\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MasterMng", "\344\272\214\347\272\247\351\227\250\351\231\220\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MasterMng", "\344\270\211\347\272\247\351\227\250\351\231\220\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MasterMng", "\346\216\247\345\210\266\345\221\275\344\273\244", nullptr));

        checkBox->setText(QCoreApplication::translate("MasterMng", "\350\257\273\345\217\226", nullptr));
        bt_default_all->setText(QCoreApplication::translate("MasterMng", "\351\273\230\350\256\244\345\200\274", nullptr));
        bt_read_all->setText(QCoreApplication::translate("MasterMng", "\350\257\273\345\217\226\346\211\200\346\234\211\345\217\202\346\225\260", nullptr));
        bt_write_all->setText(QCoreApplication::translate("MasterMng", "\344\270\213\350\256\276\346\211\200\346\234\211\344\270\273\346\216\247", nullptr));
        bt_clear_all->setText(QCoreApplication::translate("MasterMng", "\346\270\205\347\251\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MasterMng", "\346\226\260\345\273\272\345\210\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MasterMng: public Ui_MasterMng {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERMNG_H
