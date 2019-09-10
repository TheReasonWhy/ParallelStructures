#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T13:46:57
#
#-------------------------------------------------

QT       -= gui

TARGET = handler_system
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \

HEADERS += \
        handler_system.hpp \
        handler.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Level_system/level_system/release/ -llevel_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Level_system/level_system/debug/ -llevel_system
else:unix: LIBS += -L$$OUT_PWD/../../Level_system/level_system/ -llevel_system

INCLUDEPATH += $$PWD/../../Level_system/level_system
DEPENDPATH += $$PWD/../../Level_system/level_system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Level_system/level_system/release/liblevel_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Level_system/level_system/debug/liblevel_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Level_system/level_system/release/level_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Level_system/level_system/debug/level_system.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Level_system/level_system/liblevel_system.a

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
