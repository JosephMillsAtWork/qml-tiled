#ifndef TILEDPLUGIN_H
#define TILEDPLUGIN_H
#include <QQmlComponent>
#include <QQmlExtensionPlugin>
#include <QQmlEngine>
#include <QQmlContext>

/**
 * A plugin that provides a tile map item to QML. This allows easily using a
 * tile map created in Tiled in your QML scene.
 */

class TiledPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    explicit TiledPlugin(QObject *parent = 0);
    void registerTypes(const char *uri);
    void initializeEngine(QQmlEngine *engine, const char *uri);
};

#endif // TILEDPLUGIN_H
