#include <QPainter>

#include "tiledimageprovider.h"
#include "tiledtilelayer.h"
#include "tiledtile.h"

using namespace Tiled;

TiledImageProvider *TiledImageProvider::instance_ = 0;

TiledImageProvider *TiledImageProvider::instance()
{
    if (TiledImageProvider::instance_ == 0) {
        TiledImageProvider::instance_ = new TiledImageProvider;
    }
    return TiledImageProvider::instance_;
}

TiledImageProvider::TiledImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}

//This is not working
QPixmap TiledImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size);
    Q_UNUSED(requestedSize);

    // id: mapSource/tilelayerName/x/y
    qDebug() << "From the Id " <<id;
    QStringList source = id.split(",");


    qDebug() << "String Array 0 :  " << source.at(0);
    qDebug() << "String Array 1 :  " << source.at(1);
    qDebug() << "String Array 2 :  " << source.at(2);
    qDebug() << "String Array 3 :  " << source.at(3);
    qDebug() << "Hash " << mSource2Maps.count();
    QStringList fCon;
    fCon << source.at(0).split("/");
    if (!fCon.isEmpty()){
        QString sd = fCon.last();
        qDebug() << "Contains " << mSource2Maps.contains( sd );

    }


    QString sddf = source.at(0);
    sddf.replace(QRegExp("/"),"_");

    qDebug() <<  mSource2Maps.contains( sddf);
    QPixmap pixmap;
    if ( mSource2Maps.contains(sddf) ) {
        qDebug() << "g1";
        TiledMap *map = mSource2Maps.value(sddf /*source.at(0)*/ );
        TiledTileLayer *layer = map->tileLayer(source.at(1));
        if (layer) {
            qDebug() << "g2";

            TiledTile *tile = layer->tileAt(source.at(2).toInt(), source.at(3).toInt());
            if (tile){
                qDebug() << "Pass in ?  " << tile->property("name");

                pixmap = tile->image();
                qDebug() << pixmap;



            }
        }
    }

    return pixmap;

}

void TiledImageProvider::registerMap(TiledMap *map)
{
    if (map)
        mSource2Maps.insert(map->sourceId(), map);
}

void TiledImageProvider::unregisterMap(TiledMap *map)
{
    if (map)
        mSource2Maps.remove(map->sourceId());
}
