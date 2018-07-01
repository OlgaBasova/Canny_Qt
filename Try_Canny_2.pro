#-------------------------------------------------
#
# Project created by QtCreator 2018-06-29T15:28:01
#
#-------------------------------------------------

INCLUDEPATH += /usr/include/opencv /usr/include/opencv2

LIBS += -lopencv_core -lopencv_imgproc\
                                       -lopencv_highgui
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Try_Canny_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
