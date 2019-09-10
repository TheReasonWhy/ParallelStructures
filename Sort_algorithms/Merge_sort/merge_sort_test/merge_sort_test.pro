QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_merge_sort_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../merge_sort/release/ -lmerge_sort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../merge_sort/debug/ -lmerge_sort
else:unix: LIBS += -L$$OUT_PWD/../merge_sort/ -lmerge_sort

INCLUDEPATH += $$PWD/../merge_sort
DEPENDPATH += $$PWD/../merge_sort

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../merge_sort/release/libmerge_sort.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../merge_sort/debug/libmerge_sort.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../merge_sort/release/merge_sort.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../merge_sort/debug/merge_sort.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../merge_sort/libmerge_sort.a
