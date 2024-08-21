QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kidney_Stone_Detection
TEMPLATE = app

QT_CONFIG -= no-pkg-config
CONFIG  += link_pkgconfig
PKGCONFIG += opencv4


SOURCES += main.cpp\
    MatToQImage.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    MatToQImage.h

FORMS    += mainwindow.ui
