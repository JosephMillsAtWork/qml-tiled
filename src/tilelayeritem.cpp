#include "tilelayeritem.h"

#include "tile.h"
#include "tilelayer.h"
#include "map.h"
#include "maprenderer.h"

#include <QPainter>

using namespace Tiled;

TileLayerItem::TileLayerItem(Tiled::TileLayer *layer, Tiled::MapRenderer *renderer,
                             QQuickItem *parent)
    : QQuickItem(parent)
    , mLayer(layer)
    , mRenderer(renderer)
{
    //setFlag(QQuickItem::ItemUsesExtendedStyleOption);

    syncWithTileLayer();
    setOpacity(mLayer->opacity());
}

void TileLayerItem::syncWithTileLayer()
{
    mBoundingRect = mRenderer->boundingRect(mLayer->bounds());
}

QRectF TileLayerItem::boundingRect() const
{
    return mBoundingRect;
}

void TileLayerItem::paint(QPainter *painter)
{
    mRenderer->drawTileLayer(painter, mLayer);
}
