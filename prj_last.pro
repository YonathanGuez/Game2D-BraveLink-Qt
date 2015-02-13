#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T12:19:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prj_last
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bonus.cpp \
    boss.cpp \
    door.cpp \
    element.cpp \
    gamecontroller.cpp \
    goumba.cpp \
    link.cpp \
    monstre.cpp \
    personnage.cpp \
    sonic.cpp \
    zelda.cpp

HEADERS  += mainwindow.h \
    bonus.h \
    boss.h \
    constants.h \
    door.h \
    element.h \
    gamecontroller.h \
    goumba.h \
    link.h \
    monstre.h \
    personnage.h \
    sonic.h \
    zelda.h

FORMS    += mainwindow.ui

RESOURCES += \
    niveau.qrc \
    image.qrc
