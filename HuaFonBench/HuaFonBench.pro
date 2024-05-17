#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T14:04:12
#
#-------------------------------------------------
QT       += core gui
QT       += sql
QT       += network
QT       += charts
QT       += core gui charts
QT       += concurrent
QT += xml
QT += core
msvc {
QMAKE_CFLAGS += /utf-8
QMAKE_CXXFLAGS += /utf-8
} 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TRANSLATIONS  +=  language/tr_zh.ts  \
        language/tr_en.ts

TARGET = HS100Bench
TEMPLATE = app
DESTDIR = $$PWD/bin/
contains( CONFIG,"msvc" ):QMAKE_CXXFLAGS += /source-charset:utf-8 /execution-charset:utf-8
contains( CONFIG,"msvc" ):QMAKE_CFLAGS +=/source-charset:utf-8 /execution-charset:utf-8

TRANSLATIONS  +=  language/tr_zh.ts  \
        language/tr_en.ts
SOURCES += main.cpp\
    mainwindow.cpp  \
    src/drvmng/drvmng.cpp \
    src/loadfrm/loadfrm.cpp \
    src/mastermng/mastermng.cpp \
    src/public/ChartView.cpp \
    src/public/CustomDockWidget.cpp \
    src/public/airflowwidget.cpp \
    src/public/batteryitem.cpp \
    src/public/callout.cpp \
    src/public/json.cpp \
    src/public/skinclass.cpp \
    src/shownetwork/shownetwork.cpp \
    src/showslave/showslave.cpp \
    src/showslave/slaveiteminfo.cpp \
    src/slavemng/slavemng.cpp \
    src/usermng/usermng.cpp

HEADERS  += \
    mainwindow.h  \
    src/drvmng/drvmng.h \
    src/loadfrm/loadfrm.h \
    src/mastermng/mastermng.h \
    src/public/ChartView.h \
    src/public/CustomDockWidget.h \
    src/public/airflowwidget.h \
    src/public/batteryitem.h \
    src/public/callout.h \
    src/public/json.h \
    src/public/skinclass.h \
    src/shownetwork/shownetwork.h \
    src/showslave/showslave.h \
    src/showslave/slaveiteminfo.h \
    src/slavemng/slavemng.h \
    src/usermng/usermng.h

RESOURCES += \
    language/language.qrc \
    saribbonresouce.qrc \

include($$PWD/SARibbonBar.pri)

FORMS += \
    src/drvmng/drvmng.ui \
    src/loadfrm/loadfrm.ui \
    src/mastermng/mastermng.ui \
    src/public/airflowwidget.ui \
    src/public/batteryitem.ui \
    src/shownetwork/shownetwork.ui \
    src/showslave/showslave.ui \
    src/showslave/slaveiteminfo.ui \
    src/slavemng/slavemng.ui \
    src/usermng/usermng.ui


RESOURCES += \
    resource/pic.qrc \
    resource/qss \
    resource/qss.qrc

