QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_layered_data_test.cpp

DISTFILES += \
    layered_data.txt

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../layered_data/release/ -llayered_data
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../layered_data/debug/ -llayered_data
else:unix: LIBS += -L$$OUT_PWD/../layered_data/ -llayered_data

INCLUDEPATH += $$PWD/../layered_data
DEPENDPATH += $$PWD/../layered_data

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../layered_data/release/liblayered_data.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../layered_data/debug/liblayered_data.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../layered_data/release/layered_data.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../layered_data/debug/layered_data.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../layered_data/liblayered_data.a
