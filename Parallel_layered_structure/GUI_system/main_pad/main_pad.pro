#-------------------------------------------------
#
# Project created by QtCreator 2019-09-15T20:33:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main_pad
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../call_pad/call_pad_view/release/ -lcall_pad_view
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../call_pad/call_pad_view/debug/ -lcall_pad_view
else:unix: LIBS += -L$$OUT_PWD/../call_pad/call_pad_view/ -lcall_pad_view

INCLUDEPATH += $$PWD/../call_pad/call_pad_view
DEPENDPATH += $$PWD/../call_pad/call_pad_view

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../call_pad/call_pad_view/release/libcall_pad_view.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../call_pad/call_pad_view/debug/libcall_pad_view.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../call_pad/call_pad_view/release/call_pad_view.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../call_pad/call_pad_view/debug/call_pad_view.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../call_pad/call_pad_view/libcall_pad_view.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../move_pad/move_pad_view/release/ -lmove_pad_view
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../move_pad/move_pad_view/debug/ -lmove_pad_view
else:unix: LIBS += -L$$OUT_PWD/../move_pad/move_pad_view/ -lmove_pad_view

INCLUDEPATH += $$PWD/../move_pad/move_pad_view
DEPENDPATH += $$PWD/../move_pad/move_pad_view

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../move_pad/move_pad_view/release/libmove_pad_view.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../move_pad/move_pad_view/debug/libmove_pad_view.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../move_pad/move_pad_view/release/move_pad_view.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../move_pad/move_pad_view/debug/move_pad_view.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../move_pad/move_pad_view/libmove_pad_view.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../result_pad/result_pad_view/release/ -lresult_pad_view
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../result_pad/result_pad_view/debug/ -lresult_pad_view
else:unix: LIBS += -L$$OUT_PWD/../result_pad/result_pad_view/ -lresult_pad_view

INCLUDEPATH += $$PWD/../result_pad/result_pad_view
DEPENDPATH += $$PWD/../result_pad/result_pad_view

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../result_pad/result_pad_view/release/libresult_pad_view.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../result_pad/result_pad_view/debug/libresult_pad_view.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../result_pad/result_pad_view/release/result_pad_view.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../result_pad/result_pad_view/debug/result_pad_view.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../result_pad/result_pad_view/libresult_pad_view.a
