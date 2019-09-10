QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_victim_test.cpp



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../workables/ -lworkables

INCLUDEPATH += $$PWD/../workables
DEPENDPATH += $$PWD/../workables
