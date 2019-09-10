QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_heap_sort_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../heap_sort/release/ -lheap_sort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../heap_sort/debug/ -lheap_sort
else:unix: LIBS += -L$$OUT_PWD/../heap_sort/ -lheap_sort

INCLUDEPATH += $$PWD/../heap_sort
DEPENDPATH += $$PWD/../heap_sort

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../heap_sort/release/libheap_sort.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../heap_sort/debug/libheap_sort.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../heap_sort/release/heap_sort.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../heap_sort/debug/heap_sort.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../heap_sort/libheap_sort.a


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
