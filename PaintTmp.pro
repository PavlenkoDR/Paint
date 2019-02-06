#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T00:17:58
#
#-------------------------------------------------

QT       += core

QT       += widgets

QT       -= gui

TARGET = PaintTmp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app



HEADERS += paintwidget.h \
    drawingarea.h \
    shape.h \
    rectangle.h \
    square.h \
    circle.h \
    line.h
SOURCES += main.cpp \
    paintwidget.cpp \
    drawingarea.cpp \
    shape.cpp \
    rectangle.cpp \
    square.cpp \
    circle.cpp \
    line.cpp
