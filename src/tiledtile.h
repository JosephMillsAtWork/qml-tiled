#ifndef TILEDTILE_H_
#define TILEDTILE_H_

#include <QQuickItem>
#include <QPixmap>

namespace Tiled {

class Tile;
class TileSet;

} // namespace Tiled

class TiledTile : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QPixmap image READ image NOTIFY imageChanged)

public:
    explicit TiledTile(QQuickItem *parent = 0);
    ~TiledTile();

    void setTile(Tiled::Tile *tile);
    QPixmap image();
    QString singleProperty(const QString &prop) const;

    Q_INVOKABLE int id() const;
    Q_INVOKABLE QString tilesetFileName() const;
    Q_INVOKABLE QString property(const QString &key) const;

signals:
    void imageChanged(const QPixmap& image);

private:
    Tiled::Tile *mTile;
};

QML_DECLARE_TYPE(TiledTile)

#endif // TILEDTILE_H_
