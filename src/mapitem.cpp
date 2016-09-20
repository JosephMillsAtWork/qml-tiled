#include "mapitem.h"

#include "tilelayeritem.h"

#include <isometricrenderer.h>
#include <map.h>
#include <orthogonalrenderer.h>
#include <tilelayer.h>
#include <mapreader.h>

using namespace Tiled;

MapItem::MapItem(QQuickItem *parent)
    : QQuickItem(parent)
    , mMap(0)
    , mRenderer(0)
{
    setFlag(ItemHasContents, true);
}

void MapItem::setSource(const QString &source)
{
    if (mSource == source)
        return;

    mSource = source;

    qDebug() << Q_FUNC_INFO << "map source:" << source;

    qDeleteAll(childItems());
    delete mMap;
    delete mRenderer;
    mRenderer = 0;

    Tiled::MapReader reader;
    mMap = reader.readMap(mSource);
    if (!mMap) {
        qDebug() << "Failed to load map:" << source << "\n"
                << reader.errorString();
        return;
    }

    switch (mMap->orientation()) {
    case Map::Isometric:
        mRenderer = new IsometricRenderer(mMap);
        break;
    default:
        mRenderer = new OrthogonalRenderer(mMap);
        break;
    }

    int layerIndex = 0;
    foreach (Layer *layer, mMap->layers()) {
        if (TileLayer *tl = dynamic_cast<TileLayer*>(layer)) {
            QQuickItem *layerItem = new TileLayerItem(tl, mRenderer, this);
            layerItem->setZ(layerIndex);
            ++layerIndex;
        }
    }

    const QSize size = mRenderer->mapSize();
    setImplicitWidth(size.width());
    setImplicitHeight(size.height());

    emit sourceChanged(mSource);
}

QRectF MapItem::boundingRect() const
{
    if (!mMap)
        return QRectF();

    return QRectF(QPointF(), mRenderer->mapSize());
}
