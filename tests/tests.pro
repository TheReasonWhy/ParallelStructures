include(../common.pri)

QT += testlib
QT += gui

CONFIG += c++17 console
CONFIG += qt warn_on depend_includepath testcase
LIBS += -latomic

TEMPLATE = app

SOURCES +=  tst_mytestcase.cpp
