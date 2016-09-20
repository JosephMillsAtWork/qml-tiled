#include "tiledmap.h"
#include "tiledtilelayer.h"
#include "tiledimageprovider.h"

#include "mapreader.h"
#include "map.h"
#include "tilelayer.h"

using namespace Tiled;

TiledMap::TiledMap(QQuickItem *parent)
    : QQuickItem(parent),
      mMap(0)
{
}

TiledMap::~TiledMap()
{
    if (mMap)
        delete mMap;

    if (not mName2TileLayers.isEmpty())
        mName2TileLayers.clear();
}

QString TiledMap::source() const { return mSource; }

void TiledMap::setSource(const QString &source)
{
    if (mSource == source)
        return;

    TiledImageProvider::instance()->unregisterMap(this);

    mSource = source;
    if (mMap) {
        delete mMap;
    }

    // TODO delete every TiledTileLayer object
    if (not mName2TileLayers.isEmpty())
        mName2TileLayers.clear();

    Tiled::MapReader reader;
    mMap = reader.readMap(mSource);
    if (!mMap) {
        qDebug() << "Failed to load map:" << source << "\n"
                 << reader.errorString();
        return;
    }

    foreach (Layer *layer, mMap->layers()) {
        if (TileLayer *tl = dynamic_cast<TileLayer*>(layer)) {
            TiledTileLayer *tileLayer = new TiledTileLayer(this);
            tileLayer->setTileLayer(tl);
            qDebug() << tl->name();
            mName2TileLayers.insert(tl->name(), tileLayer);
        }
    }

    TiledImageProvider::instance()->registerMap(this);

    emit sourceChanged(mSource);
}

TiledTileLayer *TiledMap::tileLayer(const QString &name)
{
    return mName2TileLayers.value(name);
}

int TiledMap::layerCount() const
{
    if (mMap)
        return mMap->layerCount();
    else
        return 0;
}

int TiledMap::contentWidth() const
{
    if (mMap)
        return mMap->width() * mMap->tileWidth();
    else
        return 0;
}

int TiledMap::contentHeight() const
{
    if (mMap)
        return mMap->height() * mMap->tileHeight();
    else
        return 0;
}

int TiledMap::rows() const
{
    if (mMap)
        return mMap->height();
    else
        return 0;
}

int TiledMap::columns() const
{
    if (mMap)
        return mMap->width();
    else
        return 0;
}

QString TiledMap::sourceId() const
{
    QString sourceId = mSource;
    return sourceId.replace('/', QLatin1String("_"));
}
