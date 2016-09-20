#ifndef TILEDTILELAYER_H_
#define TILEDTILELAYER_H_

#include <QQuickItem>
#include <QHash>

class TiledTile;

namespace Tiled {

class TileLayer;
class Tile;

} // namespace Tiled

class TiledTileLayer : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit TiledTileLayer(QQuickItem *parent = 0);
    ~TiledTileLayer();

    QString name() const { return mName; }
    void setName(const QString &name);

    void setTileLayer(Tiled::TileLayer *tileLayer);

    Q_INVOKABLE TiledTile *tileAt(int x, int y);
    Q_INVOKABLE int layerWidth() const;
    Q_INVOKABLE int layerHeight() const;
    Q_INVOKABLE QString getCustomProperty(const QString &prop);

signals:
    void nameChanged();

private:
    QString mName;
    Tiled::TileLayer *mTileLayer;
    QHash<QString, TiledTile*> mXY2Tiles;
};

QML_DECLARE_TYPE(TiledTileLayer)

#endif // TILEDTILELAYER_H_
