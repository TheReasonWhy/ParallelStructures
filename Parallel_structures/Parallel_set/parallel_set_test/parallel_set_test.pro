QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -latomic

SOURCES +=  tst_parallel_set_test.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../parallel_set/release/ -lparallel_set
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../parallel_set/debug/ -lparallel_set
else:unix: LIBS += -L$$OUT_PWD/../parallel_set/ -lparallel_set

INCLUDEPATH += $$PWD/../parallel_set
DEPENDPATH += $$PWD/../parallel_set

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_set/release/libparallel_set.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_set/debug/libparallel_set.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_set/release/parallel_set.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_set/debug/parallel_set.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../parallel_set/libparallel_set.a


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/release/ -lparallel_binary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/debug/ -lparallel_binary_tree
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/ -lparallel_binary_tree

INCLUDEPATH += $$PWD/../../Parallel_binary_tree/parallel_binary_tree
DEPENDPATH += $$PWD/../../Parallel_binary_tree/parallel_binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/release/libparallel_binary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/debug/libparallel_binary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/release/parallel_binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/debug/parallel_binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_binary_tree/parallel_binary_tree/libparallel_binary_tree.a


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/ -lworkables

INCLUDEPATH += $$PWD/../../../Work_Generator/Workables/workables
DEPENDPATH += $$PWD/../../../Work_Generator/Workables/workables

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Lock_free_queue/lock_free_queue/release/ -llock_free_queue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Lock_free_queue/lock_free_queue/debug/ -llock_free_queue
else:unix: LIBS += -L$$OUT_PWD/../../Lock_free_queue/lock_free_queue/ -llock_free_queue

INCLUDEPATH += $$PWD/../../Lock_free_queue/lock_free_queue
DEPENDPATH += $$PWD/../../Lock_free_queue/lock_free_queue

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/release/liblock_free_queue.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/debug/liblock_free_queue.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/release/lock_free_queue.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/debug/lock_free_queue.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/liblock_free_queue.a
