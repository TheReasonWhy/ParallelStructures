QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -latomic

SOURCES +=  tst_parallel_stack_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../parallel_stack/release/ -lparallel_stack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../parallel_stack/debug/ -lparallel_stack
else:unix: LIBS += -L$$OUT_PWD/../parallel_stack/ -lparallel_stack

INCLUDEPATH += $$PWD/../parallel_stack
DEPENDPATH += $$PWD/../parallel_stack

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_stack/release/libparallel_stack.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_stack/debug/libparallel_stack.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_stack/release/parallel_stack.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_stack/debug/parallel_stack.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../parallel_stack/libparallel_stack.a



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/ -lworkables

INCLUDEPATH += $$PWD/../../../Work_Generator/Workables/workables
DEPENDPATH += $$PWD/../../../Work_Generator/Workables/workables
