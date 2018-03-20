#-------------------------------------------------
#
# Project created by QtCreator 2016-11-17T14:38:09
#
#-------------------------------------------------

QT       -= gui
QT += widgets
TARGET = Figure
TEMPLATE = lib

DEFINES += FIGURE_LIBRARY

SOURCES += container.cpp \
    shape.cpp \
    circle.cpp \
    rectangle.cpp \
    square.cpp


HEADERS += container.h \
        figure_global.h \
    shape.h \
    circle.h \
    rectangle.h \
    square.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}
