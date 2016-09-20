#include "tiledtile.h"

#include "tile.h"
#include "tileset.h"

using namespace Tiled;

TiledTile::TiledTile(QQuickItem *parent) :
    QQuickItem(parent),
    mTile(0)
{
}

TiledTile::~TiledTile()
{
}

void TiledTile::setTile(Tile *tile)
{
    // TODO hack only
    if (mTile)
        return ;

    mTile = tile;
    emit imageChanged(image());
}

QPixmap TiledTile::image()
{
    if (mTile)
        return mTile->image();
    else
        return QPixmap();
}

int TiledTile::id() const
{

    if (mTile)
        return mTile->id();
    else
        return 0;
}

QString TiledTile::tilesetFileName() const
{
    if (mTile)
        return mTile->tileset()->name();
    else
        return QString();
}


QString TiledTile::singleProperty(const QString &prop) const
{
    if (mTile)
        return mTile->property(prop);
    else
        return QString();
}



QString TiledTile::property(const QString &key) const
{
    return mTile ? mTile->properties().value(key) : QString();
}

