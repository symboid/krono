
TARGET = krono-calculo
BUILD_ROOT=../..
COMPONENT_NAME=krono
include($${BUILD_ROOT}/sdk/build/qmake/qt-module.pri)

SOURCES += \
    init.cc

HEADERS += \
    defs.h \
    init.h \
    setup.h

RESOURCES += \
    krono-calculo.qrc

LIBS += $$moduleDep(sdk,arch)
LIBS += $$moduleDep(sdk,controls)
