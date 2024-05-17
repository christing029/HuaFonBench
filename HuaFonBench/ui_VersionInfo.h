/********************************************************************************
** Form generated from reading UI file 'VersionInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONINFO_H
#define UI_VERSIONINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VersionInfoClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QTextBrowser *textBrowser;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VersionInfoClass)
    {
        if (VersionInfoClass->objectName().isEmpty())
            VersionInfoClass->setObjectName(QString::fromUtf8("VersionInfoClass"));
        VersionInfoClass->resize(600, 400);
        centralWidget = new QWidget(VersionInfoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        VersionInfoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VersionInfoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        VersionInfoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VersionInfoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VersionInfoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VersionInfoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VersionInfoClass->setStatusBar(statusBar);

        retranslateUi(VersionInfoClass);

        QMetaObject::connectSlotsByName(VersionInfoClass);
    } // setupUi

    void retranslateUi(QMainWindow *VersionInfoClass)
    {
        VersionInfoClass->setWindowTitle(QCoreApplication::translate("VersionInfoClass", "VersionInfo", nullptr));
        label_2->setText(QCoreApplication::translate("VersionInfoClass", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("VersionInfoClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VersionInfoClass: public Ui_VersionInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONINFO_H
