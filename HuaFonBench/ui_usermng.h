/********************************************************************************
** Form generated from reading UI file 'usermng.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMNG_H
#define UI_USERMNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usermng
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *m_ctlFilter;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txName;
    QLabel *label_10;
    QLineEdit *txPasswrd;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QComboBox *cbUserRole;
    QLabel *label_12;
    QLineEdit *txUserTel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLineEdit *txUserInfo;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bt_add;
    QPushButton *bt_remove;
    QPushButton *bt_modify;

    void setupUi(QWidget *usermng)
    {
        if (usermng->objectName().isEmpty())
            usermng->setObjectName(QString::fromUtf8("usermng"));
        usermng->resize(532, 621);
        verticalLayout = new QVBoxLayout(usermng);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_ctlFilter = new QLineEdit(usermng);
        m_ctlFilter->setObjectName(QString::fromUtf8("m_ctlFilter"));
        m_ctlFilter->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(m_ctlFilter);

        treeWidget = new QTreeWidget(usermng);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setRootIsDecorated(false);
        treeWidget->setAllColumnsShowFocus(true);
        treeWidget->header()->setDefaultSectionSize(80);

        verticalLayout->addWidget(treeWidget);

        groupBox = new QGroupBox(usermng);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 151));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txName = new QLineEdit(groupBox);
        txName->setObjectName(QString::fromUtf8("txName"));

        horizontalLayout->addWidget(txName);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout->addWidget(label_10);

        txPasswrd = new QLineEdit(groupBox);
        txPasswrd->setObjectName(QString::fromUtf8("txPasswrd"));

        horizontalLayout->addWidget(txPasswrd);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_2->addWidget(label_11);

        cbUserRole = new QComboBox(groupBox);
        cbUserRole->addItem(QString());
        cbUserRole->addItem(QString());
        cbUserRole->addItem(QString());
        cbUserRole->addItem(QString());
        cbUserRole->setObjectName(QString::fromUtf8("cbUserRole"));

        horizontalLayout_2->addWidget(cbUserRole);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        txUserTel = new QLineEdit(groupBox);
        txUserTel->setObjectName(QString::fromUtf8("txUserTel"));

        horizontalLayout_2->addWidget(txUserTel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        txUserInfo = new QLineEdit(groupBox);
        txUserInfo->setObjectName(QString::fromUtf8("txUserInfo"));

        horizontalLayout_3->addWidget(txUserInfo);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bt_add = new QPushButton(groupBox);
        bt_add->setObjectName(QString::fromUtf8("bt_add"));

        horizontalLayout_4->addWidget(bt_add);

        bt_remove = new QPushButton(groupBox);
        bt_remove->setObjectName(QString::fromUtf8("bt_remove"));

        horizontalLayout_4->addWidget(bt_remove);

        bt_modify = new QPushButton(groupBox);
        bt_modify->setObjectName(QString::fromUtf8("bt_modify"));

        horizontalLayout_4->addWidget(bt_modify);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox);


        retranslateUi(usermng);

        QMetaObject::connectSlotsByName(usermng);
    } // setupUi

    void retranslateUi(QWidget *usermng)
    {
        usermng->setWindowTitle(QCoreApplication::translate("usermng", "Form", nullptr));
        m_ctlFilter->setPlaceholderText(QCoreApplication::translate("usermng", "\346\214\211\345\220\215\345\255\227\346\237\245\350\257\242", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("usermng", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("usermng", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("usermng", "\347\224\250\346\210\267\350\247\222\350\211\262", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("usermng", "\347\231\273\345\275\225\345\257\206\347\240\201", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("usermng", "\347\231\273\345\275\225\347\224\250\346\210\267", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("usermng", "\345\272\217\345\217\267", nullptr));
        groupBox->setTitle(QCoreApplication::translate("usermng", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("usermng", "\347\231\273\345\275\225\347\224\250\346\210\267", nullptr));
        label_10->setText(QCoreApplication::translate("usermng", "\347\231\273\345\275\225\345\257\206\347\240\201", nullptr));
        label_11->setText(QCoreApplication::translate("usermng", "\347\224\250\346\210\267\350\247\222\350\211\262", nullptr));
        cbUserRole->setItemText(0, QCoreApplication::translate("usermng", "\347\256\241\347\220\206\345\221\230", nullptr));
        cbUserRole->setItemText(1, QCoreApplication::translate("usermng", "\345\274\200\345\217\221\344\272\272\345\221\230", nullptr));
        cbUserRole->setItemText(2, QCoreApplication::translate("usermng", "\346\265\213\350\257\225\344\272\272\345\221\230", nullptr));
        cbUserRole->setItemText(3, QCoreApplication::translate("usermng", "\344\270\200\350\210\254\347\224\250\346\210\267", nullptr));

        label_12->setText(QCoreApplication::translate("usermng", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        label_9->setText(QCoreApplication::translate("usermng", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        bt_add->setText(QCoreApplication::translate("usermng", "\346\267\273\345\212\240", nullptr));
        bt_remove->setText(QCoreApplication::translate("usermng", "\345\210\240\351\231\244", nullptr));
        bt_modify->setText(QCoreApplication::translate("usermng", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usermng: public Ui_usermng {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMNG_H
