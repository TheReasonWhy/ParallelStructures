QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -latomic

SOURCES +=  tst_parallel_queue_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../parallel_queue/release/ -lparallel_queue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../parallel_queue/debug/ -lparallel_queue
else:unix: LIBS += -L$$OUT_PWD/../parallel_queue/ -lparallel_queue

INCLUDEPATH += $$PWD/../parallel_queue
DEPENDPATH += $$PWD/../parallel_queue

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_queue/release/libparallel_queue.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_queue/debug/libparallel_queue.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_queue/release/parallel_queue.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_queue/debug/parallel_queue.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../parallel_queue/libparallel_queue.a



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/ -lworkables

INCLUDEPATH += $$PWD/../../../Work_Generator/Workables/workables
DEPENDPATH += $$PWD/../../../Work_Generator/Workables/workables
