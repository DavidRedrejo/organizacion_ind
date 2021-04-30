QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clases_lotes.cpp \
    dialog_factura.cpp \
    dialog_plan.cpp \
    factura.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    clases_lotes.h \
    dialog_factura.h \
    dialog_plan.h \
    factura.h \
    mainwindow.h

FORMS += \
    dialog_factura.ui \
    dialog_plan.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
