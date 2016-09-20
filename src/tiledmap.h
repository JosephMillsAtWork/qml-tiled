#ifndef TILEDMAP_H_
#define TILEDMAP_H_

#include <QQuickItem>
#include <QHash>
#include <QDebug>

class TiledTileLayer;

namespace Tiled {

class Map;
class MapReader;

} // namespace Tiled

/**
 *
 */
class TiledMap : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    /*Q_PROPERTY(int contentWidth READ contentWidth NOTIFY contentWidthChanged)
    Q_PROPERTY(int contentHeight READ contentHeight NOTIFY contentHeightChanged)
*/
public:
    explicit TiledMap(QQuickItem *parent = 0);
    ~TiledMap();

    QString source() const;
    void setSource(const QString &source);

    Q_INVOKABLE TiledTileLayer *tileLayer(const QString &name);
    Q_INVOKABLE int layerCount() const;

    // width and height in pixel
    Q_INVOKABLE int contentWidth() const;
    Q_INVOKABLE int contentHeight() const;
    Q_INVOKABLE int rows() const;
    Q_INVOKABLE int columns() const;
    Q_INVOKABLE QString sourceId() const;

signals:
    void sourceChanged(const QUrl &source);
    /*void contentWidthChanged(int contentWidth);
    void contentHeightChanged(int contentHeight);
*/
private:
    QString mSource;
    Tiled::Map *mMap;
    QHash<QString, TiledTileLayer*> mName2TileLayers;
};

QML_DECLARE_TYPE(TiledMap)

#endif // TILEDMAP_H_
