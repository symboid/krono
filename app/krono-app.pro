
TARGET = krono-app
BUILD_ROOT=../..
COMPONENT_NAME=krono
include($${BUILD_ROOT}/build/qmake/application.pri)

SOURCES += \
    main.cc

HEADERS += \
    init.h \
    setup.h \
    defs.h

RESOURCES += \
    krono-app.qrc

LIBS += $$moduleDep(krono,calculo)
LIBS += $$externDep(sdk,hosting)
LIBS += $$externDep(sdk,controls)
LIBS += $$externDep(sdk,network)
LIBS += $$externDep(sdk,arch)

android: {
    ANDROID_EXTRA_LIBS += $$externPath(sdk,arch)
    ANDROID_EXTRA_LIBS += $$externPath(sdk,network)
    ANDROID_EXTRA_LIBS += $$externPath(sdk,controls)
    ANDROID_EXTRA_LIBS += $$externPath(sdk,hosting)
    ANDROID_EXTRA_LIBS += $$externPath(krono,calculo)
}

QMAKE_EXTRA_TARGETS += $$object_dep_on_component_header(main)
