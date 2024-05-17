/********************************************************************************
** Form generated from reading UI file 'BCUCalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCUCALIBRATION_H
#define UI_BCUCALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCUCalibrationClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lE_Start;
    QLabel *label_4;
    QLineEdit *lE_End;
    QLabel *label_5;
    QLineEdit *lE_K;
    QLabel *label_6;
    QLineEdit *lE_B;
    QPushButton *bt_add;
    QPushButton *bt_clear;
    QPushButton *bt_read_all;
    QPushButton *bt_write;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *BCUCalibrationClass)
    {
        if (BCUCalibrationClass->objectName().isEmpty())
            BCUCalibrationClass->setObjectName(QString::fromUtf8("BCUCalibrationClass"));
        BCUCalibrationClass->resize(1018, 683);
        verticalLayout = new QVBoxLayout(BCUCalibrationClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(BCUCalibrationClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(BCUCalibrationClass);
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

        label_3 = new QLabel(BCUCalibrationClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lE_Start = new QLineEdit(BCUCalibrationClass);
        lE_Start->setObjectName(QString::fromUtf8("lE_Start"));

        horizontalLayout->addWidget(lE_Start);

        label_4 = new QLabel(BCUCalibrationClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lE_End = new QLineEdit(BCUCalibrationClass);
        lE_End->setObjectName(QString::fromUtf8("lE_End"));

        horizontalLayout->addWidget(lE_End);

        label_5 = new QLabel(BCUCalibrationClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        lE_K = new QLineEdit(BCUCalibrationClass);
        lE_K->setObjectName(QString::fromUtf8("lE_K"));

        horizontalLayout->addWidget(lE_K);

        label_6 = new QLabel(BCUCalibrationClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        lE_B = new QLineEdit(BCUCalibrationClass);
        lE_B->setObjectName(QString::fromUtf8("lE_B"));

        horizontalLayout->addWidget(lE_B);

        bt_add = new QPushButton(BCUCalibrationClass);
        bt_add->setObjectName(QString::fromUtf8("bt_add"));

        horizontalLayout->addWidget(bt_add);

        bt_clear = new QPushButton(BCUCalibrationClass);
        bt_clear->setObjectName(QString::fromUtf8("bt_clear"));

        horizontalLayout->addWidget(bt_clear);

        bt_read_all = new QPushButton(BCUCalibrationClass);
        bt_read_all->setObjectName(QString::fromUtf8("bt_read_all"));

        horizontalLayout->addWidget(bt_read_all);

        bt_write = new QPushButton(BCUCalibrationClass);
        bt_write->setObjectName(QString::fromUtf8("bt_write"));

        horizontalLayout->addWidget(bt_write);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(BCUCalibrationClass);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout->addLayout(gridLayout);


        retranslateUi(BCUCalibrationClass);

        QMetaObject::connectSlotsByName(BCUCalibrationClass);
    } // setupUi

    void retranslateUi(QWidget *BCUCalibrationClass)
    {
        BCUCalibrationClass->setWindowTitle(QCoreApplication::translate("BCUCalibrationClass", "BCUCalibration", nullptr));
        label_2->setText(QCoreApplication::translate("BCUCalibrationClass", "\346\240\241\345\207\206\347\261\273\345\236\213", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("BCUCalibrationClass", "\347\224\265\346\265\201\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("BCUCalibrationClass", "\347\224\265\346\261\240\347\224\265\345\216\213\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("BCUCalibrationClass", "Pack\347\224\265\345\216\213\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("BCUCalibrationClass", "\347\224\265\346\265\201\344\274\240\346\204\237\345\231\250\347\232\204\346\270\251\345\272\246\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("BCUCalibrationClass", "\345\244\226\351\203\250\347\216\257\345\242\203\347\232\204\346\270\251\345\272\246\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("BCUCalibrationClass", "P-\346\270\251\345\272\246\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("BCUCalibrationClass", "P+\346\270\251\345\272\246\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("BCUCalibrationClass", "B-\346\270\251\345\272\246\346\240\241\345\207\206", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("BCUCalibrationClass", "B+\346\270\251\345\272\246\346\240\241\345\207\206", nullptr));

        label_3->setText(QCoreApplication::translate("BCUCalibrationClass", "\350\265\267\345\247\213\347\202\271", nullptr));
        label_4->setText(QCoreApplication::translate("BCUCalibrationClass", "\347\273\223\346\235\237\347\202\271", nullptr));
        label_5->setText(QCoreApplication::translate("BCUCalibrationClass", "K\345\200\274", nullptr));
        label_6->setText(QCoreApplication::translate("BCUCalibrationClass", "B\345\200\274", nullptr));
        bt_add->setText(QCoreApplication::translate("BCUCalibrationClass", "\346\267\273\345\212\240", nullptr));
        bt_clear->setText(QCoreApplication::translate("BCUCalibrationClass", "\346\270\205\351\231\244", nullptr));
        bt_read_all->setText(QCoreApplication::translate("BCUCalibrationClass", "\350\257\273\345\217\226", nullptr));
        bt_write->setText(QCoreApplication::translate("BCUCalibrationClass", "\344\270\213\350\256\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BCUCalibrationClass", "\350\265\267\345\247\213\347\202\271\357\274\210X0\357\274\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BCUCalibrationClass", "\350\265\267\345\247\213\347\202\271\357\274\210Y0\357\274\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BCUCalibrationClass", "\347\273\223\346\235\237\347\202\271  (X1)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BCUCalibrationClass", "\347\273\223\346\235\237\347\202\271  (Y1)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BCUCalibrationClass", "K", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("BCUCalibrationClass", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BCUCalibrationClass: public Ui_BCUCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCUCALIBRATION_H
