#-------------------------------------------------
#
# Project created by QtCreator 2016-01-21T00:07:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Parking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inputdialog.cpp \
    spoticon.cpp

HEADERS  += mainwindow.h \
    inputdialog.h \
    spoticon.h

FORMS    += mainwindow.ui \
    inputdialog.ui \
    checkdialog.ui
