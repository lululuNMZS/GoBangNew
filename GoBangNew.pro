######################################################################
# Automatically generated by qmake (3.0) ?? 7? 14 12:38:43 2015
######################################################################
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = GoBangNew
INCLUDEPATH += .

# Input
HEADERS += choosecolourdialog.h \
           mainwindow.h \
           qboard.h \
           qjudge.h \
           qpiece.h \
           qplayer.h \
           qrobot.h \
           qshowboard.h \
    aboutdialog.h
FORMS += choosecolourdialog.ui mainwindow.ui qchesspiece.ui qshowboard.ui \
    aboutdialog.ui
SOURCES += choosecolourdialog.cpp \
           main.cpp \
           mainwindow.cpp \
           qboard.cpp \
           qjudge.cpp \
           qpiece.cpp \
           qplayer.cpp \
           qrobot.cpp \
           qshowboard.cpp \
    aboutdialog.cpp

ICON = GoBangNew.icns
