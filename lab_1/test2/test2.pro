QT += core
QT -= gui

CONFIG += c++11

TARGET = test2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    test.cpp



win32: LIBS += -L$$PWD/./ -lFigure

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
