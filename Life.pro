#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T23:56:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Life
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    gamecanvas.cpp

HEADERS  += mainwindow.h \
    cell.h \
    gamecanvas.h

FORMS    += mainwindow.ui

CONFIG += c++11
