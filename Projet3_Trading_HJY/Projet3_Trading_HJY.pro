#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T22:48:39
#
#-------------------------------------------------

QT       += core gui network webkitwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet3_Trading_HJY
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cotationsview.cpp \
    optionsdialog.cpp

HEADERS  += mainwindow.h \
    cotationsview.h \
    optionsdialog.h

FORMS    += mainwindow.ui \
    cotationsview.ui \
    optionsdialog.ui

RESOURCES += \
    myresources.qrc
