import QtQuick 2.0

Item {
    property bool containsItem: false
    property alias source: image.source
    width: 40 // parent.width
    height: 40 // parent.height
    Image {
        id: image
        anchors.fill: parent
        width: 40 // parent.width
        height: 40 // parent.height
        sourceSize.width: width
        sourceSize.height: height
    }

}
