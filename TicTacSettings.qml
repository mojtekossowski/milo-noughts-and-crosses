import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: options

    property int fontSize: 22

    Item {
        anchors.verticalCenter: options.horizontalCenter

        Text {
            id: gridSizeLabel

            text: qsTr('')
            font.pixelSize: fontSize
        }

        SpinBox{
            value: TicTacBoard.gridSize
            onValueChanged: TicTacBoard.gridSize = value
        }
    }

}
