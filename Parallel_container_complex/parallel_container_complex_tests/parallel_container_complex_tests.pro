QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -latomic

SOURCES +=  tst_parallel_container_complex_tests.cpp

DISTFILES += \
    levels.txt \
    connections.txt \
    elements.txt

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../parallel_container_complex/release/ -lparallel_container_complex
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../parallel_container_complex/debug/ -lparallel_container_complex
else:unix: LIBS += -L$$OUT_PWD/../parallel_container_complex/ -lparallel_container_complex

INCLUDEPATH += $$PWD/../parallel_container_complex
DEPENDPATH += $$PWD/../parallel_container_complex

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_container_complex/release/libparallel_container_complex.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_container_complex/debug/libparallel_container_complex.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_container_complex/release/parallel_container_complex.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_container_complex/debug/parallel_container_complex.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../parallel_container_complex/libparallel_container_complex.a

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../statistics_manager/release/ -lstatistics_manager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../statistics_manager/debug/ -lstatistics_manager
else:unix: LIBS += -L$$OUT_PWD/../../statistics_manager/ -lstatistics_manager

INCLUDEPATH += $$PWD/../../statistics_manager
DEPENDPATH += $$PWD/../../statistics_manager

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../statistics_manager/release/libstatistics_manager.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../statistics_manager/debug/libstatistics_manager.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../statistics_manager/release/statistics_manager.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../statistics_manager/debug/statistics_manager.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../statistics_manager/libstatistics_manager.a

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
