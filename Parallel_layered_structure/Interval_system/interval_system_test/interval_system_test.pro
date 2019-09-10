QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_interval_system_tes.cpp

DISTFILES += \
    intervals.txt

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../interval_system/release/ -linterval_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../interval_system/debug/ -linterval_system
else:unix: LIBS += -L$$OUT_PWD/../interval_system/ -linterval_system

INCLUDEPATH += $$PWD/../interval_system
DEPENDPATH += $$PWD/../interval_system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../interval_system/release/libinterval_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../interval_system/debug/libinterval_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../interval_system/release/interval_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../interval_system/debug/interval_system.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../interval_system/libinterval_system.a
