/********************************************************************************
** Form generated from reading UI file 'showslave.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSLAVE_H
#define UI_SHOWSLAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowSlave
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowSlave)
    {
        if (ShowSlave->objectName().isEmpty())
            ShowSlave->setObjectName(QString::fromUtf8("ShowSlave"));
        ShowSlave->resize(800, 655);
        centralwidget = new QWidget(ShowSlave);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMinimumSize(QSize(220, 0));
        treeView->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(treeView);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        ShowSlave->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ShowSlave);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        ShowSlave->setMenuBar(menubar);
        statusbar = new QStatusBar(ShowSlave);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ShowSlave->setStatusBar(statusbar);

        retranslateUi(ShowSlave);

        QMetaObject::connectSlotsByName(ShowSlave);
    } // setupUi

    void retranslateUi(QMainWindow *ShowSlave)
    {
        ShowSlave->setWindowTitle(QCoreApplication::translate("ShowSlave", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowSlave: public Ui_ShowSlave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSLAVE_H
