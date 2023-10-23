QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamebutton.cpp \
    gettext.cpp \
    guanjiabrowser.cpp \
    main.cpp \
    mrobots.cpp \
    mydatas.cpp \
    mymainwindow.cpp \
    mymap.cpp \
    mypushbutton.cpp \
    ordersbrower.cpp \
    playwindow.cpp \
    selecewindow.cpp \
    startwindow.cpp \
    windialog.cpp

HEADERS += \
    gamebutton.h \
    gettext.h \
    guanjiabrowser.h \
    mrobots.h \
    mydatas.h \
    mymainwindow.h \
    mymap.h \
    mypushbutton.h \
    ordersbrower.h \
    playwindow.h \
    selecewindow.h \
    startwindow.h \
    windialog.h

FORMS += \
    gettext.ui \
    guanjiabrowser.ui \
    mymainwindow.ui \
    ordersbrower.ui \
    windialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mres.qrc

