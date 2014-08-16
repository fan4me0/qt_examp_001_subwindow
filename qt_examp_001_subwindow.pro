#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T00:02:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_examp_001_subwindow
TEMPLATE = app

#------------------------------------------------------------
# Compiler settings

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    mywidget.h
