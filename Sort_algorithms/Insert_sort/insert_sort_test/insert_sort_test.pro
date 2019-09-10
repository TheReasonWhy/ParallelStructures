QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_insert_sort_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../insert_sort/release/ -linsert_sort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../insert_sort/debug/ -linsert_sort
else:unix: LIBS += -L$$OUT_PWD/../insert_sort/ -linsert_sort

INCLUDEPATH += $$PWD/../insert_sort
DEPENDPATH += $$PWD/../insert_sort

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../insert_sort/release/libinsert_sort.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../insert_sort/debug/libinsert_sort.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../insert_sort/release/insert_sort.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../insert_sort/debug/insert_sort.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../insert_sort/libinsert_sort.a
