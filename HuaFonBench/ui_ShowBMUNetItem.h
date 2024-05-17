/********************************************************************************
** Form generated from reading UI file 'ShowBMUNetItem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWBMUNETITEM_H
#define UI_SHOWBMUNETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowBMUNetItemClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *ShowBMUNetItemClass)
    {
        if (ShowBMUNetItemClass->objectName().isEmpty())
            ShowBMUNetItemClass->setObjectName(QString::fromUtf8("ShowBMUNetItemClass"));
        ShowBMUNetItemClass->resize(434, 145);
        horizontalLayout = new QHBoxLayout(ShowBMUNetItemClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(ShowBMUNetItemClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(60, 60));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(label_4);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(label_6);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(label_7);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(ShowBMUNetItemClass);

        QMetaObject::connectSlotsByName(ShowBMUNetItemClass);
    } // setupUi

    void retranslateUi(QWidget *ShowBMUNetItemClass)
    {
        ShowBMUNetItemClass->setWindowTitle(QCoreApplication::translate("ShowBMUNetItemClass", "ShowBMUNetItem", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ShowBMUNetItemClass", "\347\224\265\346\261\240\345\215\225\344\275\223\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("ShowBMUNetItemClass", "\345\235\207\350\241\241", nullptr));
        label_2->setText(QCoreApplication::translate("ShowBMUNetItemClass", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("ShowBMUNetItemClass", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("ShowBMUNetItemClass", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("ShowBMUNetItemClass", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("ShowBMUNetItemClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowBMUNetItemClass: public Ui_ShowBMUNetItemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWBMUNETITEM_H
