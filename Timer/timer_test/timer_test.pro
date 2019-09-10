
QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_timer_test.cpp



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../timer/release/ -ltimer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../timer/debug/ -ltimer
else:unix: LIBS += -L$$OUT_PWD/../timer/ -ltimer

INCLUDEPATH += $$PWD/../timer
DEPENDPATH += $$PWD/../timer

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../timer/release/libtimer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../timer/debug/libtimer.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../timer/release/timer.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../timer/debug/timer.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../timer/libtimer.a


