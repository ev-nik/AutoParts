QT += core
QT -= gui

CONFIG += c++11

TARGET = AutoParts
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Auto.cpp \
    Block.cpp

HEADERS += \
    cars.h \
    Auto.h \
    Block.h \
    Part.h
