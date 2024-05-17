/********************************************************************************
** Form generated from reading UI file 'SlaveItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLAVEITEMWIDGET_H
#define UI_SLAVEITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/public/batteryitem.h"

QT_BEGIN_NAMESPACE

class Ui_SlaveItemWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    BatteryItem *widget;

    void setupUi(QWidget *SlaveItemWidgetClass)
    {
        if (SlaveItemWidgetClass->objectName().isEmpty())
            SlaveItemWidgetClass->setObjectName(QString::fromUtf8("SlaveItemWidgetClass"));
        SlaveItemWidgetClass->resize(463, 340);
        verticalLayout = new QVBoxLayout(SlaveItemWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(SlaveItemWidgetClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(label_5);

        label = new QLabel(SlaveItemWidgetClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(SlaveItemWidgetClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(SlaveItemWidgetClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(SlaveItemWidgetClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        widget = new BatteryItem(SlaveItemWidgetClass);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(SlaveItemWidgetClass);

        QMetaObject::connectSlotsByName(SlaveItemWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *SlaveItemWidgetClass)
    {
        SlaveItemWidgetClass->setWindowTitle(QCoreApplication::translate("SlaveItemWidgetClass", "SlaveItemWidget", nullptr));
        label_5->setText(QCoreApplication::translate("SlaveItemWidgetClass", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("SlaveItemWidgetClass", "\346\255\243\345\234\250\345\235\207\350\241\241", nullptr));
        label_2->setText(QCoreApplication::translate("SlaveItemWidgetClass", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("SlaveItemWidgetClass", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("SlaveItemWidgetClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SlaveItemWidgetClass: public Ui_SlaveItemWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLAVEITEMWIDGET_H
