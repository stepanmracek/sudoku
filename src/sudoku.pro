#-------------------------------------------------
#
# Project created by QtCreator 2013-10-10T19:51:52
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = sudoku
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    gamestate.cpp \
    testgamestate.cpp \
    sudokusolver.cpp

HEADERS += \
    gamestate.h \
    testgamestate.h \
    sudokusolver.h
