import QtQuick 2.3
import QtQuick.Window 2.2
import Tiled 1.0
import Box2D 2.0

import "testTiled.js" as TileTest

Window {
    id:root
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello Tiled")
    Rectangle{
        id: w
        anchors.fill: parent
        color: "green"
        Component.onCompleted: {
            TileTest.renderMap(w)
        }

        TiledMap{
            id: map
            source: "/home/joseph/sandbox/marioMockup/mario.tmx"
            width: 2400
            height: 480

        }

        World {
            id: world
            gravity: Qt.point(0, -20)
        }
    }
}
