
include (../build/qmake/deps.pri)

SUBDIRS = \
    $$module_dep(sdk,arch) \
    $$module_dep(sdk,controls) \
    $$module_dep(sdk,hosting) \
    $$module_dep(krono,calculo) \
    $$module_dep(krono,app)
