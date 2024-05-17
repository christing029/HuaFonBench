/********************************************************************************
** Form generated from reading UI file 'loadfrm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADFRM_H
#define UI_LOADFRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loadfrm
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QCheckBox *chkBoxSave;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *work_name;
    QLabel *label_4;
    QLineEdit *passward;
    QLabel *label_5;
    QComboBox *comboBox;
    QDialogButtonBox *yesorno;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loadfrm)
    {
        if (loadfrm->objectName().isEmpty())
            loadfrm->setObjectName(QString::fromUtf8("loadfrm"));
        loadfrm->resize(531, 413);
        centralwidget = new QWidget(loadfrm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 30, 471, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(25);
        font.setBold(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:transparent;"));
        chkBoxSave = new QCheckBox(centralwidget);
        chkBoxSave->setObjectName(QString::fromUtf8("chkBoxSave"));
        chkBoxSave->setGeometry(QRect(570, 360, 201, 20));
        chkBoxSave->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        chkBoxSave->setIconSize(QSize(8, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 110, 391, 251));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 30));
        label->setMaximumSize(QSize(100, 30));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"\n"
"selection-background-color: rgb(255, 255, 255);"));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        work_name = new QLineEdit(widget);
        work_name->setObjectName(QString::fromUtf8("work_name"));
        work_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(work_name, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setMinimumSize(QSize(100, 30));
        label_4->setMaximumSize(QSize(100, 30));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        passward = new QLineEdit(widget);
        passward->setObjectName(QString::fromUtf8("passward"));
        passward->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(passward, 1, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setMinimumSize(QSize(100, 30));
        label_5->setMaximumSize(QSize(100, 30));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        yesorno = new QDialogButtonBox(widget);
        yesorno->setObjectName(QString::fromUtf8("yesorno"));
        yesorno->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        yesorno->setOrientation(Qt::Horizontal);
        yesorno->setStandardButtons(QDialogButtonBox::Ok);
        yesorno->setCenterButtons(false);

        gridLayout->addWidget(yesorno, 3, 1, 1, 1);

        loadfrm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loadfrm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 23));
        loadfrm->setMenuBar(menubar);
        statusbar = new QStatusBar(loadfrm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        loadfrm->setStatusBar(statusbar);

        retranslateUi(loadfrm);

        QMetaObject::connectSlotsByName(loadfrm);
    } // setupUi

    void retranslateUi(QMainWindow *loadfrm)
    {
        loadfrm->setWindowTitle(QCoreApplication::translate("loadfrm", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("loadfrm", "\345\215\216\345\263\260\345\202\250\350\203\275\350\207\252\345\212\250\345\214\226\346\265\213\350\257\225\347\263\273\347\273\237H100", nullptr));
        chkBoxSave->setText(QCoreApplication::translate("loadfrm", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("loadfrm", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("loadfrm", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("loadfrm", "\350\257\255\350\250\200\357\274\210Language\357\274\211", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("loadfrm", "\344\270\255\346\226\207", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("loadfrm", "English", nullptr));

    } // retranslateUi

};

namespace Ui {
    class loadfrm: public Ui_loadfrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADFRM_H
