#include "tiledtilelayer.h"
#include "tiledtile.h"

#include "tile.h"
#include "tilelayer.h"

using namespace Tiled;

TiledTileLayer::TiledTileLayer(QQuickItem *parent) :
    QQuickItem(parent),
    mTileLayer(0)
{
}

TiledTileLayer::~TiledTileLayer()
{
//    delete tiledTile;
}

void TiledTileLayer::setName(const QString &name)
{
    if (mName == name)
        return;

    mName = name;
    if (mTileLayer)
        mTileLayer->setName(name);
    emit nameChanged();
}

void TiledTileLayer::setTileLayer(TileLayer *tileLayer)
{
    if (mTileLayer)
        return ;

    mTileLayer = tileLayer;
    setName(mTileLayer->name());
}

TiledTile *TiledTileLayer::tileAt(int x, int y)
{
    QString key = QString("%1_%2").arg(x).arg(y);
    if (mXY2Tiles.contains(key))
        return mXY2Tiles.value(key);

    if (mTileLayer) {
        if (not mTileLayer->contains(x, y))
            return 0;

        Tile *tile = mTileLayer->tileAt(x, y);
        if (tile == 0 || tile->id() == 0)
            return 0;

        qDebug() << tile->property("name");
        TiledTile *tiledTile = new TiledTile(this);
        tiledTile->setTile(tile);
        tiledTile->singleProperty("name");
        mXY2Tiles.insert(key, tiledTile);
        return tiledTile;
    }
    else
        return 0;
}

int TiledTileLayer::layerWidth() const
{
    return mTileLayer ? mTileLayer->width() : 0;
}

int TiledTileLayer::layerHeight() const
{
    return mTileLayer ? mTileLayer->height() : 0;
}

QString TiledTileLayer::getCustomProperty(const QString &prop)
{
    if(!prop.isEmpty() && mTileLayer){
        return mTileLayer->property(prop);
    }
    else
    {
        return QString();
    }
}
