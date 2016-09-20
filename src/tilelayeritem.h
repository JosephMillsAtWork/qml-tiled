#ifndef TILELAYERITEM_H
#define TILELAYERITEM_H

#include <QQuickItem>

namespace Tiled {

class TileLayer;
class MapRenderer;

} // namespace Tiled

/**
 * A graphics item displaying a tile layer in a QGraphicsView.
 */
class TileLayerItem : public QQuickItem
{
public:
    /**
     * Constructor.
     *
     * @param layer    the tile layer to be displayed
     * @param renderer the map renderer to use to render the layer
     */
    TileLayerItem(Tiled::TileLayer *layer, Tiled::MapRenderer *renderer,
                  QQuickItem *parent = 0);

    /**
     * Updates the size and position of this item. Should be called when the
     * size of either the tile layer or its associated map have changed.
     *
     * Calling this function when the size of the map changes is necessary
     * because in certain map orientations this affects the layer position
     * (when using the IsometricRenderer for example).
     */
    void syncWithTileLayer();

    // QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter);

private:
    Tiled::TileLayer *mLayer;
    Tiled::MapRenderer *mRenderer;
    QRectF mBoundingRect;
};

#endif // TILELAYERITEM_H
