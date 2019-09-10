QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
LIBS += -latomic
TEMPLATE = app

SOURCES +=  tst_threadpool_test.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../threadpool/release/ -lthreadpool
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../threadpool/debug/ -lthreadpool
else:unix: LIBS += -L$$OUT_PWD/../threadpool/ -lthreadpool

INCLUDEPATH += $$PWD/../threadpool
DEPENDPATH += $$PWD/../threadpool

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool/release/libthreadpool.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool/debug/libthreadpool.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool/release/threadpool.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool/debug/threadpool.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../threadpool/libthreadpool.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/release/ -llock_free_queue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/debug/ -llock_free_queue
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/ -llock_free_queue

INCLUDEPATH += $$PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue
DEPENDPATH += $$PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/release/liblock_free_queue.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/debug/liblock_free_queue.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/release/lock_free_queue.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/debug/lock_free_queue.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Lock_free_queue/lock_free_queue/liblock_free_queue.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/release/ -lparallel_set
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/debug/ -lparallel_set
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/ -lparallel_set

INCLUDEPATH += $$PWD/../../Parallel_structures/Parallel_set/parallel_set
DEPENDPATH += $$PWD/../../Parallel_structures/Parallel_set/parallel_set

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/release/libparallel_set.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/debug/libparallel_set.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/release/parallel_set.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/debug/parallel_set.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_set/parallel_set/libparallel_set.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/parallel_container/release/ -lparallel_container
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/parallel_container/debug/ -lparallel_container
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/parallel_container/ -lparallel_container

INCLUDEPATH += $$PWD/../../Parallel_structures/parallel_container
DEPENDPATH += $$PWD/../../Parallel_structures/parallel_container

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/release/libparallel_container.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/debug/libparallel_container.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/release/parallel_container.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/debug/parallel_container.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/libparallel_container.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/ -lparallel_binary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/ -lparallel_binary_tree
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/ -lparallel_binary_tree

INCLUDEPATH += $$PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree
DEPENDPATH += $$PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/release/ -lparallel_stack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/debug/ -lparallel_stack
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/ -lparallel_stack

INCLUDEPATH += $$PWD/../../Parallel_structures/Parallel_stack/parallel_stack
DEPENDPATH += $$PWD/../../Parallel_structures/Parallel_stack/parallel_stack

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/release/libparallel_stack.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/debug/libparallel_stack.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/release/parallel_stack.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/debug/parallel_stack.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_stack/parallel_stack/libparallel_stack.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/release/ -lparallel_queue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/debug/ -lparallel_queue
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/ -lparallel_queue

INCLUDEPATH += $$PWD/../../Parallel_structures/Parallel_queue/parallel_queue
DEPENDPATH += $$PWD/../../Parallel_structures/Parallel_queue/parallel_queue

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/release/libparallel_queue.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/debug/libparallel_queue.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/release/parallel_queue.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/debug/parallel_queue.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_queue/parallel_queue/libparallel_queue.a
