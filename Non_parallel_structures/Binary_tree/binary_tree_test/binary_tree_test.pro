QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_binary_tree_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../binary_tree/release/ -lbinary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../binary_tree/debug/ -lbinary_tree
else:unix: LIBS += -L$$OUT_PWD/../binary_tree/ -lbinary_tree

INCLUDEPATH += $$PWD/../binary_tree
DEPENDPATH += $$PWD/../binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../binary_tree/release/libbinary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../binary_tree/debug/libbinary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../binary_tree/release/binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../binary_tree/debug/binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../binary_tree/libbinary_tree.a
