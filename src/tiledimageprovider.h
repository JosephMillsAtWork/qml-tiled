#ifndef TILEDIMAGEPROVIDER_H_
#define TILEDIMAGEPROVIDER_H_

#include <QQuickImageProvider>
#include <QQuickItem>
#include <QImage>
#include <QHash>

#include "tiledmap.h"

namespace Tiled {

class Map;
class Tile;

} // namespace Tiled

class TiledImageProvider : public QQuickImageProvider
{
public:
    static TiledImageProvider *instance();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

    void registerMap(TiledMap *map);
    void unregisterMap(TiledMap *map);

private:
    TiledImageProvider();

    static TiledImageProvider *instance_;

    QHash<QString, TiledMap*> mSource2Maps;
};

#endif // TILEDIMAGEPROVIDER_H_
