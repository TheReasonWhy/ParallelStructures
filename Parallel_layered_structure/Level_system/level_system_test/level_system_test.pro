QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

LIBS += -latomic

TEMPLATE = app

SOURCES +=  tst_level_system_test.cpp

DISTFILES += \
    connections.txt

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../level_system/release/ -llevel_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../level_system/debug/ -llevel_system
else:unix: LIBS += -L$$OUT_PWD/../level_system/ -llevel_system

INCLUDEPATH += $$PWD/../level_system
DEPENDPATH += $$PWD/../level_system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../level_system/release/liblevel_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../level_system/debug/liblevel_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../level_system/release/level_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../level_system/debug/level_system.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../level_system/liblevel_system.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Layered_data/layered_data/release/ -llayered_data
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Layered_data/layered_data/debug/ -llayered_data
else:unix: LIBS += -L$$OUT_PWD/../../Layered_data/layered_data/ -llayered_data

INCLUDEPATH += $$PWD/../../Layered_data/layered_data
DEPENDPATH += $$PWD/../../Layered_data/layered_data

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Layered_data/layered_data/release/liblayered_data.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Layered_data/layered_data/debug/liblayered_data.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Layered_data/layered_data/release/layered_data.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Layered_data/layered_data/debug/layered_data.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Layered_data/layered_data/liblayered_data.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Interval_system/interval_system/release/ -linterval_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Interval_system/interval_system/debug/ -linterval_system
else:unix: LIBS += -L$$OUT_PWD/../../Interval_system/interval_system/ -linterval_system

INCLUDEPATH += $$PWD/../../Interval_system/interval_system
DEPENDPATH += $$PWD/../../Interval_system/interval_system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/release/libinterval_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/debug/libinterval_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/release/interval_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/debug/interval_system.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/libinterval_system.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/release/ -lbinary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/debug/ -lbinary_tree
else:unix: LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/ -lbinary_tree

INCLUDEPATH += $$PWD/../../../Non_parallel_structures/Binary_tree/binary_tree
DEPENDPATH += $$PWD/../../../Non_parallel_structures/Binary_tree/binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/release/libbinary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/debug/libbinary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/release/binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/debug/binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_tree/binary_tree/libbinary_tree.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/release/ -lfactory_abstract
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/debug/ -lfactory_abstract
else:unix: LIBS += -L$$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/ -lfactory_abstract

INCLUDEPATH += $$PWD/../../../Work_Generator/Factory_abstract/factory_abstract
DEPENDPATH += $$PWD/../../../Work_Generator/Factory_abstract/factory_abstract

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/release/libfactory_abstract.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/debug/libfactory_abstract.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/release/factory_abstract.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/debug/factory_abstract.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Factory_abstract/factory_abstract/libfactory_abstract.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../statistics_manager/release/ -lstatistics_manager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../statistics_manager/debug/ -lstatistics_manager
else:unix: LIBS += -L$$OUT_PWD/../../../statistics_manager/ -lstatistics_manager

INCLUDEPATH += $$PWD/../../../statistics_manager
DEPENDPATH += $$PWD/../../../statistics_manager

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../statistics_manager/release/libstatistics_manager.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../statistics_manager/debug/libstatistics_manager.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../statistics_manager/release/statistics_manager.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../statistics_manager/debug/statistics_manager.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../statistics_manager/libstatistics_manager.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Timer/timer/release/ -ltimer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Timer/timer/debug/ -ltimer
else:unix: LIBS += -L$$OUT_PWD/../../../Timer/timer/ -ltimer

INCLUDEPATH += $$PWD/../../../Timer/timer
DEPENDPATH += $$PWD/../../../Timer/timer

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Timer/timer/release/libtimer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Timer/timer/debug/libtimer.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Timer/timer/release/timer.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Timer/timer/debug/timer.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Timer/timer/libtimer.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/release/ -lbinary_heap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/debug/ -lbinary_heap
else:unix: LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/ -lbinary_heap

INCLUDEPATH += $$PWD/../../../Non_parallel_structures/Binary_heap/binary_heap
DEPENDPATH += $$PWD/../../../Non_parallel_structures/Binary_heap/binary_heap

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/release/libbinary_heap.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/debug/libbinary_heap.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/release/binary_heap.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/debug/binary_heap.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/libbinary_heap.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/release/ -lheap_sort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/debug/ -lheap_sort
else:unix: LIBS += -L$$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/ -lheap_sort

INCLUDEPATH += $$PWD/../../../Sort_algorithms/Heap_sort/heap_sort
DEPENDPATH += $$PWD/../../../Sort_algorithms/Heap_sort/heap_sort

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/release/libheap_sort.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/debug/libheap_sort.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/release/heap_sort.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/debug/heap_sort.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Sort_algorithms/Heap_sort/heap_sort/libheap_sort.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/release/ -lparallel_stack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/debug/ -lparallel_stack
else:unix: LIBS += -L$$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/ -lparallel_stack

INCLUDEPATH += $$PWD/../../../Parallel_structures/Parallel_stack/parallel_stack
DEPENDPATH += $$PWD/../../../Parallel_structures/Parallel_stack/parallel_stack

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/release/libparallel_stack.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/debug/libparallel_stack.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/release/parallel_stack.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/debug/parallel_stack.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_stack/parallel_stack/libparallel_stack.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/ -lparallel_binary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/ -lparallel_binary_tree
else:unix: LIBS += -L$$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/ -lparallel_binary_tree

INCLUDEPATH += $$PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree
DEPENDPATH += $$PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/libparallel_binary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/libparallel_binary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/parallel_binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/parallel_binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/libparallel_binary_tree.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/release/ -lwork_generator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/debug/ -lwork_generator
else:unix: LIBS += -L$$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/ -lwork_generator

INCLUDEPATH += $$PWD/../../../Work_Generator/Work_generator/work_generator
DEPENDPATH += $$PWD/../../../Work_Generator/Work_generator/work_generator

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/release/libwork_generator.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/debug/libwork_generator.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/release/work_generator.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/debug/work_generator.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Work_Generator/Work_generator/work_generator/libwork_generator.a
