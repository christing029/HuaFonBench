#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T14:04:12
#
#-------------------------------------------------

QT       += core gui

QT       += sql
QT       += core gui
QT       += serialport network
QT       += charts
QT       += core gui charts
QT      +=  printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HS100Bench
TEMPLATE = app
DESTDIR = $$PWD/../../../bin/

SOURCES += main.cpp\
    ../../mastermng/masterfrm.cpp \
    mainwindow.cpp 

HEADERS  += \
    ../../mastermng/masterfrm.h \
    mainwindow.h 



RESOURCES += \
    saribbonresouce.qrc \

include($$PWD/../../../SARibbonBar.pri)

FORMS += \
    ../../mastermng/masterfrm.ui
