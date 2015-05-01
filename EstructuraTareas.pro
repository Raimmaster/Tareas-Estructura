#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T16:34:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EstructuraTareas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    T1/calle.cpp \
    T1/T1Semaforo.cpp \
    T2/t2cartas.cpp

HEADERS  += mainwindow.h \
    T1/calle.h \
    T1/T1Semaforo.h \
    T2/t2cartas.h

FORMS    += mainwindow.ui \
    T1/t1semaforo.ui \    
    T2/t2cartas.ui
