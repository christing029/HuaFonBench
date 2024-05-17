/********************************************************************************
** Form generated from reading UI file 'QtWidgetsFan.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSFAN_H
#define UI_QTWIDGETSFAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsFanClass
{
public:

    void setupUi(QWidget *QtWidgetsFanClass)
    {
        if (QtWidgetsFanClass->objectName().isEmpty())
            QtWidgetsFanClass->setObjectName(QString::fromUtf8("QtWidgetsFanClass"));
        QtWidgetsFanClass->resize(600, 400);

        retranslateUi(QtWidgetsFanClass);

        QMetaObject::connectSlotsByName(QtWidgetsFanClass);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsFanClass)
    {
        QtWidgetsFanClass->setWindowTitle(QCoreApplication::translate("QtWidgetsFanClass", "QtWidgetsFan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsFanClass: public Ui_QtWidgetsFanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSFAN_H
