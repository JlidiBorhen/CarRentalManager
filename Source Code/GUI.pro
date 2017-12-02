#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T17:30:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    Client.cpp \
    ClientDB.cpp \
    Car.cpp \
    CarDB.cpp

HEADERS  += mainwindow.h \
    Client.h \
    ClientDB.h \
    Car.h \
    CarDB.h

FORMS    += mainwindow.ui
