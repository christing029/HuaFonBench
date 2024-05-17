/********************************************************************************
** Form generated from reading UI file 'masterfrm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERFRM_H
#define UI_MASTERFRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_masterfrm
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *masterfrm)
    {
        if (masterfrm->objectName().isEmpty())
            masterfrm->setObjectName(QString::fromUtf8("masterfrm"));
        masterfrm->resize(800, 600);
        menubar = new QMenuBar(masterfrm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        masterfrm->setMenuBar(menubar);
        centralwidget = new QWidget(masterfrm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        masterfrm->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(masterfrm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        masterfrm->setStatusBar(statusbar);

        retranslateUi(masterfrm);

        QMetaObject::connectSlotsByName(masterfrm);
    } // setupUi

    void retranslateUi(QMainWindow *masterfrm)
    {
        masterfrm->setWindowTitle(QCoreApplication::translate("masterfrm", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class masterfrm: public Ui_masterfrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERFRM_H
