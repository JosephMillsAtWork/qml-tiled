#ifndef MAPITEM_H
#define MAPITEM_H

#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QDebug>

namespace Tiled {

class Map;
class MapRenderer;

} // namespace Tiled

/**
 * A graphics item that displays a Map.
 */
class MapItem : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)

public:
    MapItem(QQuickItem *parent = 0);

    QString source() const { return mSource; }
    void setSource(const QString &source);

    QRectF boundingRect() const;
    void paint(QPainter *) {}

signals:
    void sourceChanged(const QUrl &source);

private:
    QString mSource;

    Tiled::Map *mMap;
    Tiled::MapRenderer *mRenderer;
};

QML_DECLARE_TYPE(MapItem)

#endif // MAPITEM_H
