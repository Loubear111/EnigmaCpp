#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T22:19:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Enigma
TEMPLATE = app


SOURCES += main.cpp\
        gui.cpp \
    send.cpp \
    receive.cpp

HEADERS  += gui.h \
    send.h \
    receive.h

FORMS    += gui.ui
