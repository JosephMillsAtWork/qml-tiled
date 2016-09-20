var tileComponent = Qt.createComponent("qrc:/RenderImage.qml");

function renderMap(par) {
    var mapSourceId = map.source;
//    console.log(
//                " rows: " + map.width / 10  + " columns: " + map.height / 10  +
//                " layer count:" + map.width * map.height,
//                " sourceId: " + mapSourceId);

    var enemiesLayer = map.tileLayer("enemies");
    var environmentLayer = map.tileLayer("environment");
    var columns = environmentLayer.layerWidth();
    var rows = environmentLayer.layerHeight();

//    console.log("layer " + environmentLayer.name +
//                " width: " + columns + " height: " + rows);

    for (var i = 0; i < columns; i++) {
        for (var j = 0; j < rows; j++) {
            var tile = environmentLayer.tileAt(i, j);

            if (tile !== null)
            {
                //"image://tiledimages/mapSourceId/tilelayerName/x/y"
                var tileSource = "image://tiledimages/" + mapSourceId +
                                 "," + environmentLayer.name +
                                 "," + i + "," + j;
                createEnvironmentTile(tileSource, tile.id(), i, j, par);
            }
        }
    }
}


function createEnvironmentTile(tileSource, tileId, column, row, par) {
    if (tileComponent.status === Component.Ready) {

        // Fixme make so that call back contains a name with it for custom process

        var box2dtile = tileComponent.createObject(par);
        box2dtile.x = column * 40  //tileWidth;
        box2dtile.y = row * 40 //tileWidth;
        box2dtile.width = 40 //tileWidth;
        box2dtile.height = 40 //tileWidth;
        box2dtile.source = tileSource;

    }
}
