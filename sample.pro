QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    generatedata.cpp \
    main.cpp \
    mainwindow.cpp \
    openfiledialog.cpp \
    plotdataobject.cpp \
    scatterdatamodifier.cpp \
    scatterplotwindow.cpp \
    surface_tutorial.cpp \
    treeitem.cpp \
    treemodel.cpp

HEADERS += \
    generatedata.h \
    mainwindow.h \
    openfiledialog.h \
    plotdataobject.h \
    scatterdatamodifier.h \
    scatterplotwindow.h \
    surface_tutorial.h \
    treeitem.h \
    treemodel.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    sample_en_US.ts

QT += datavisualization

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
