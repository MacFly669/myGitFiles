#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T12:56:30
#
#-------------------------------------------------

QT       += core gui webkitwidgets sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Projet3_TRADING
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cotationsview.cpp \
    optiondialog.cpp \
    qcustomplot.cpp \
    graphique.cpp

HEADERS  += mainwindow.h \
    cotationsview.h \
    optiondialog.h \
    qcustomplot.h \
    graphique.h

FORMS    += mainwindow.ui \
    cotationsview.ui \
    optiondialog.ui \
    graphique.ui

RESOURCES += \
    myresources.qrc
