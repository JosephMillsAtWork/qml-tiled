#include "tiledplugin.h"
#include "tiledmap.h"
#include "tiledtilelayer.h"
#include "tiledtile.h"
#include "tiledimageprovider.h"
#include "mapitem.h"
#include <qqml.h>
TiledPlugin::TiledPlugin(QObject *parent) :
    QQmlExtensionPlugin(parent)
{
}

void TiledPlugin::registerTypes(const char *uri)
{
    // @uri Tiled
    qmlRegisterType<TiledMap>(uri, 1, 0, "TiledMap");
    qmlRegisterType<TiledTileLayer>(uri, 1, 0, "TileLayer");
    qmlRegisterType<TiledTile>(uri, 1, 0, "TiledTile");
    qmlRegisterType<MapItem>(uri, 1, 0, "TiledMapRender");
}

void TiledPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(uri);
//    engine->addImageProvider(QLatin1String("colors"), new ColorPixmapProvider);

    engine->addImageProvider(QLatin1String("tiledimages"), TiledImageProvider::instance() );
}
