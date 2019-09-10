QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
LIBS += -latomic
SOURCES += \ 
    tst_work_generator_test.cpp




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Factory_abstract/factory_abstract/release/ -lfactory_abstract
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Factory_abstract/factory_abstract/debug/ -lfactory_abstract
else:unix: LIBS += -L$$OUT_PWD/../../Factory_abstract/factory_abstract/ -lfactory_abstract

INCLUDEPATH += $$PWD/../../Factory_abstract/factory_abstract
DEPENDPATH += $$PWD/../../Factory_abstract/factory_abstract

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/release/libfactory_abstract.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/debug/libfactory_abstract.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/release/factory_abstract.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/debug/factory_abstract.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/libfactory_abstract.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Parallel_structures/parallel_container/release/ -lparallel_container
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Parallel_structures/parallel_container/debug/ -lparallel_container
else:unix: LIBS += -L$$OUT_PWD/../../../Parallel_structures/parallel_container/ -lparallel_container

INCLUDEPATH += $$PWD/../../../Parallel_structures/parallel_container
DEPENDPATH += $$PWD/../../../Parallel_structures/parallel_container

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/parallel_container/release/libparallel_container.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/parallel_container/debug/libparallel_container.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/parallel_container/release/parallel_container.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/parallel_container/debug/parallel_container.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Parallel_structures/parallel_container/libparallel_container.a

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


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../work_generator/release/ -lwork_generator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../work_generator/debug/ -lwork_generator
else:unix: LIBS += -L$$OUT_PWD/../work_generator/ -lwork_generator

INCLUDEPATH += $$PWD/../work_generator
DEPENDPATH += $$PWD/../work_generator

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../work_generator/release/libwork_generator.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../work_generator/debug/libwork_generator.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../work_generator/release/work_generator.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../work_generator/debug/work_generator.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../work_generator/libwork_generator.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Factory_abstract/factory_abstract/release/ -lfactory_abstract
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Factory_abstract/factory_abstract/debug/ -lfactory_abstract
else:unix: LIBS += -L$$OUT_PWD/../../Factory_abstract/factory_abstract/ -lfactory_abstract

INCLUDEPATH += $$PWD/../../Factory_abstract/factory_abstract
DEPENDPATH += $$PWD/../../Factory_abstract/factory_abstract

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/release/libfactory_abstract.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/debug/libfactory_abstract.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/release/factory_abstract.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/debug/factory_abstract.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Factory_abstract/factory_abstract/libfactory_abstract.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Workables/workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Workables/workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../../Workables/workables/ -lworkables

INCLUDEPATH += $$PWD/../../Workables/workables
DEPENDPATH += $$PWD/../../Workables/workables

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
