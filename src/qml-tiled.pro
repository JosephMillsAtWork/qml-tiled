include(libtiled/libtiled.pri)

TEMPLATE = lib
CONFIG += qt plugin
QT += qml quick core
TARGET = Tiled
TARGET = $$qtLibraryTarget($$TARGET)
MOC_DIR = .moc
OBJECTS_DIR = .obj
uri = Tiled

INCLUDEPATH += . \
               libtiled

SOURCES += \
    tiledplugin.cpp \
    tiledtile.cpp \
    tiledtilelayer.cpp \
    tiledmap.cpp \
    tiledimageprovider.cpp \
    mapitem.cpp \
    tilelayeritem.cpp

HEADERS += \
    tiledplugin.h \
    tiledtile.h \
    tiledtilelayer.h \
    tiledmap.h \
    tiledimageprovider.h \
    mapitem.h \
    tilelayeritem.h

OTHER_FILES += \
         qmldir
!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir


installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
qmldir.path = $$installPath
target.path = $$installPath
INSTALLS += target qmldir

