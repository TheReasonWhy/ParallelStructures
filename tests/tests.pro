include(../common.pri)

QT += testlib
QT += gui

CONFIG += c++17 console
CONFIG += qt warn_on depend_includepath testcase
LIBS += -latomic

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    victim_tests.cpp \
    parallel_binary_tree_tests.cpp \
    parallel_stack_tests.cpp \
    lock_free_queue_tests.cpp \
    parallel_queue_tests.cpp \
    work_generator_tests.cpp \
    parallel_set_tests.cpp \
    threadpool_tests.cpp \
    binary_tree_tests.cpp \
    binary_heap_tests.cpp \
    indexator_tests.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../non_parallel_structures/release/ -lnon_parallel_structures
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../non_parallel_structures/debug/ -lnon_parallel_structures
else:unix: LIBS += -L$$OUT_PWD/../non_parallel_structures/ -lnon_parallel_structures

INCLUDEPATH += $$PWD/../non_parallel_structures
DEPENDPATH += $$PWD/../non_parallel_structures

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/release/libnon_parallel_structures.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/debug/libnon_parallel_structures.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/release/non_parallel_structures.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/debug/non_parallel_structures.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/libnon_parallel_structures.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../parallel_structures/release/ -lparallel_structures
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../parallel_structures/debug/ -lparallel_structures
else:unix: LIBS += -L$$OUT_PWD/../parallel_structures/ -lparallel_structures

INCLUDEPATH += $$PWD/../parallel_structures
DEPENDPATH += $$PWD/../parallel_structures

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/release/libparallel_structures.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/debug/libparallel_structures.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/release/parallel_structures.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/debug/parallel_structures.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/libparallel_structures.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../victim/release/ -lvictim
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../victim/debug/ -lvictim
else:unix: LIBS += -L$$OUT_PWD/../victim/ -lvictim

INCLUDEPATH += $$PWD/../victim
DEPENDPATH += $$PWD/../victim

HEADERS += \
    autotest.h \
    victim_tests.h \
    parallel_binary_tree_tests.h \
    parallel_stack_tests.h \
    lock_free_queue_tests.h \
    parallel_queue_tests.h \
    work_generator_tests.h \
    parallel_set_tests.h \
    threadpool_tests.h \
    binary_tree_tests.h \
    binary_heap_tests.h \
    indexator_tests.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../factory_abstract/release/ -lfactory_abstract
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../factory_abstract/debug/ -lfactory_abstract
else:unix: LIBS += -L$$OUT_PWD/../factory_abstract/ -lfactory_abstract

INCLUDEPATH += $$PWD/../factory_abstract
DEPENDPATH += $$PWD/../factory_abstract

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../factory_abstract/release/libfactory_abstract.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../factory_abstract/debug/libfactory_abstract.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../factory_abstract/release/factory_abstract.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../factory_abstract/debug/factory_abstract.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../factory_abstract/libfactory_abstract.a
