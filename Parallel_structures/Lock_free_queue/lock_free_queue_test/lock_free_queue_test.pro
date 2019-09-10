QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
LIBS += -latomic
TEMPLATE = app

SOURCES +=  tst_lock_free_queue_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lock_free_queue/release/ -llock_free_queue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lock_free_queue/debug/ -llock_free_queue
else:unix: LIBS += -L$$OUT_PWD/../lock_free_queue/ -llock_free_queue

INCLUDEPATH += $$PWD/../lock_free_queue
DEPENDPATH += $$PWD/../lock_free_queue

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lock_free_queue/release/liblock_free_queue.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lock_free_queue/debug/liblock_free_queue.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lock_free_queue/release/lock_free_queue.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lock_free_queue/debug/lock_free_queue.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lock_free_queue/liblock_free_queue.a


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/ -lworkables

INCLUDEPATH += $$PWD/../../../Work_Generator/Workables/workables
DEPENDPATH += $$PWD/../../../Work_Generator/Workables/workables
