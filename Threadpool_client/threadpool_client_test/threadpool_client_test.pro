QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
LIBS += -latomic
SOURCES +=  tst_threadpool_client_test.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/release/ -lbinary_heap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/debug/ -lbinary_heap
else:unix: LIBS += -L$$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/ -lbinary_heap

INCLUDEPATH += $$PWD/../../Non_parallel_structures/Binary_heap/binary_heap
DEPENDPATH += $$PWD/../../Non_parallel_structures/Binary_heap/binary_heap

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/release/libbinary_heap.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/debug/libbinary_heap.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/release/binary_heap.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/debug/binary_heap.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_heap/binary_heap/libbinary_heap.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/release/ -lbinary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/debug/ -lbinary_tree
else:unix: LIBS += -L$$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/ -lbinary_tree

INCLUDEPATH += $$PWD/../../Non_parallel_structures/Binary_tree/binary_tree
DEPENDPATH += $$PWD/../../Non_parallel_structures/Binary_tree/binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/release/libbinary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/debug/libbinary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/release/binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/debug/binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Non_parallel_structures/Binary_tree/binary_tree/libbinary_tree.a

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/ -lparallel_binary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/ -lparallel_binary_tree
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/ -lparallel_binary_tree

INCLUDEPATH += $$PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree
DEPENDPATH += $$PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/libparallel_binary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/libparallel_binary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/parallel_binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/parallel_binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/libparallel_binary_tree.a

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Threadpool/threadpool/release/ -lthreadpool
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Threadpool/threadpool/debug/ -lthreadpool
else:unix: LIBS += -L$$OUT_PWD/../../Threadpool/threadpool/ -lthreadpool

INCLUDEPATH += $$PWD/../../Threadpool/threadpool
DEPENDPATH += $$PWD/../../Threadpool/threadpool

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Threadpool/threadpool/release/libthreadpool.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Threadpool/threadpool/debug/libthreadpool.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Threadpool/threadpool/release/threadpool.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Threadpool/threadpool/debug/threadpool.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Threadpool/threadpool/libthreadpool.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../threadpool_client/release/ -lthreadpool_client
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../threadpool_client/debug/ -lthreadpool_client
else:unix: LIBS += -L$$OUT_PWD/../threadpool_client/ -lthreadpool_client

INCLUDEPATH += $$PWD/../threadpool_client
DEPENDPATH += $$PWD/../threadpool_client

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool_client/release/libthreadpool_client.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool_client/debug/libthreadpool_client.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool_client/release/threadpool_client.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../threadpool_client/debug/threadpool_client.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../threadpool_client/libthreadpool_client.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Timer/timer/release/ -ltimer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Timer/timer/debug/ -ltimer
else:unix: LIBS += -L$$OUT_PWD/../../Timer/timer/ -ltimer

INCLUDEPATH += $$PWD/../../Timer/timer
DEPENDPATH += $$PWD/../../Timer/timer

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Timer/timer/release/libtimer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Timer/timer/debug/libtimer.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Timer/timer/release/timer.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Timer/timer/debug/timer.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Timer/timer/libtimer.a


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Work_Generator/Workables/workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Work_Generator/Workables/workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../../Work_Generator/Workables/workables/ -lworkables

INCLUDEPATH += $$PWD/../../Work_Generator/Workables/workables
DEPENDPATH += $$PWD/../../Work_Generator/Workables/workables

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/release/ -lfactory_abstract
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/debug/ -lfactory_abstract
else:unix: LIBS += -L$$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/ -lfactory_abstract

INCLUDEPATH += $$PWD/../../Work_Generator/Factory_abstract/factory_abstract
DEPENDPATH += $$PWD/../../Work_Generator/Factory_abstract/factory_abstract

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/release/libfactory_abstract.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/debug/libfactory_abstract.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/release/factory_abstract.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/debug/factory_abstract.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Factory_abstract/factory_abstract/libfactory_abstract.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Work_Generator/Work_generator/work_generator/release/ -lwork_generator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Work_Generator/Work_generator/work_generator/debug/ -lwork_generator
else:unix: LIBS += -L$$OUT_PWD/../../Work_Generator/Work_generator/work_generator/ -lwork_generator

INCLUDEPATH += $$PWD/../../Work_Generator/Work_generator/work_generator
DEPENDPATH += $$PWD/../../Work_Generator/Work_generator/work_generator

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Work_generator/work_generator/release/libwork_generator.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Work_generator/work_generator/debug/libwork_generator.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Work_generator/work_generator/release/work_generator.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Work_generator/work_generator/debug/work_generator.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Work_Generator/Work_generator/work_generator/libwork_generator.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/release/ -lheap_sort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/debug/ -lheap_sort
else:unix: LIBS += -L$$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/ -lheap_sort

INCLUDEPATH += $$PWD/../../Sort_algorithms/Heap_sort/heap_sort
DEPENDPATH += $$PWD/../../Sort_algorithms/Heap_sort/heap_sort

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/release/libheap_sort.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/debug/libheap_sort.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/release/heap_sort.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/debug/heap_sort.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Sort_algorithms/Heap_sort/heap_sort/libheap_sort.a
