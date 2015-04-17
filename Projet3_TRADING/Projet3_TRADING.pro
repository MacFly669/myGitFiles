#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T12:56:30
#
#-------------------------------------------------

QT       += core gui webkitwidgets sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet3_TRADING
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        cotationsview.cpp \
        optiondialog.cpp \
        aboutdialog.cpp \
        simulation.cpp\
        graphique.cpp

HEADERS  += mainwindow.h \
        cotationsview.h \
        optiondialog.h \
        aboutdialog.h \
        xml.h \
        simulation.h \
        graphique.h\

FORMS    += mainwindow.ui \
        cotationsview.ui \
        optiondialog.ui \
        aboutdialog.ui \
        simulation.ui \
        graphique.ui

RESOURCES += \
    myresources.qrc
