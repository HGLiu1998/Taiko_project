#-------------------------------------------------
#
# Project created by QtCreator 2017-06-08T00:33:06
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
DESTDIR   = $$PWD
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    playpart.cpp \
    taku.cpp \
    point.cpp \
    compliment.cpp \
    easymusic.cpp \
    title.cpp \
    arrow.cpp \
    oni.cpp \
    score.cpp \
    set.cpp \
    dancer.cpp

HEADERS  += mainwindow.h \
    playpart.h \
    taku.h \
    point.h \
    compliment.h \
    easymusic.h \
    title.h \
    arrow.h \
    oni.h \
    score.h \
    set.h \
    dancer.h

RESOURCES += \
    resource.qrc
