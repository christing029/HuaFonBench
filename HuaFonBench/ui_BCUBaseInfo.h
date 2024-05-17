/********************************************************************************
** Form generated from reading UI file 'BCUBaseInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCUBASEINFO_H
#define UI_BCUBASEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCUBaseInfoClass
{
public:

    void setupUi(QWidget *BCUBaseInfoClass)
    {
        if (BCUBaseInfoClass->objectName().isEmpty())
            BCUBaseInfoClass->setObjectName(QString::fromUtf8("BCUBaseInfoClass"));
        BCUBaseInfoClass->resize(600, 400);

        retranslateUi(BCUBaseInfoClass);

        QMetaObject::connectSlotsByName(BCUBaseInfoClass);
    } // setupUi

    void retranslateUi(QWidget *BCUBaseInfoClass)
    {
        BCUBaseInfoClass->setWindowTitle(QCoreApplication::translate("BCUBaseInfoClass", "BCUBaseInfo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BCUBaseInfoClass: public Ui_BCUBaseInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCUBASEINFO_H
