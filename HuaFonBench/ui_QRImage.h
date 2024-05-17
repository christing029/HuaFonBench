/********************************************************************************
** Form generated from reading UI file 'QRImage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRIMAGE_H
#define UI_QRIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRImageClass
{
public:

    void setupUi(QWidget *QRImageClass)
    {
        if (QRImageClass->objectName().isEmpty())
            QRImageClass->setObjectName(QString::fromUtf8("QRImageClass"));
        QRImageClass->resize(600, 400);

        retranslateUi(QRImageClass);

        QMetaObject::connectSlotsByName(QRImageClass);
    } // setupUi

    void retranslateUi(QWidget *QRImageClass)
    {
        QRImageClass->setWindowTitle(QCoreApplication::translate("QRImageClass", "QRImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QRImageClass: public Ui_QRImageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRIMAGE_H
