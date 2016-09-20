# Include this file to add the base libtiled classes to your project
INCLUDEPATH += $$PWD
SOURCES += \
    $$PWD/compression.cpp \
    $$PWD/map.cpp \
    $$PWD/mapwriter.cpp \
    $$PWD/properties.cpp \
    $$PWD/isometricrenderer.cpp \
    $$PWD/mapobject.cpp \
    $$PWD/objectgroup.cpp \
    $$PWD/tilelayer.cpp \
    $$PWD/layer.cpp \
    $$PWD/mapreader.cpp \
    $$PWD/orthogonalrenderer.cpp \
    $$PWD/tileset.cpp
HEADERS += \
    $$PWD/compression.h \
    $$PWD/mapobject.h \
    $$PWD/objectgroup.h \
    $$PWD/tiled_global.h \
    $$PWD/isometricrenderer.h \
    $$PWD/mapreader.h \
    $$PWD/object.h \
    $$PWD/tile.h \
    $$PWD/layer.h \
    $$PWD/maprenderer.h \
    $$PWD/orthogonalrenderer.h \
    $$PWD/tilelayer.h \
    $$PWD/map.h \
    $$PWD/mapwriter.h \
    $$PWD/properties.h \
    $$PWD/tileset.h

