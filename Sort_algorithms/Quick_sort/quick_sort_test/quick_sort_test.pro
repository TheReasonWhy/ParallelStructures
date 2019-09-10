QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_quick_sort_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../quick_sort/release/ -lquick_sort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quick_sort/debug/ -lquick_sort
else:unix: LIBS += -L$$OUT_PWD/../quick_sort/ -lquick_sort

INCLUDEPATH += $$PWD/../quick_sort
DEPENDPATH += $$PWD/../quick_sort

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../quick_sort/release/libquick_sort.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../quick_sort/debug/libquick_sort.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../quick_sort/release/quick_sort.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../quick_sort/debug/quick_sort.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../quick_sort/libquick_sort.a
