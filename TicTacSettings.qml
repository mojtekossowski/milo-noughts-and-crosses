import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id: options

    property int fontSize: 22

    Item {
        anchors.verticalCenter: options.verticalCenter

        Text {
            id: gridSizeLabel

            text: qsTr('')
            font.pixelSize: fontSize
        }
        SpinBox{
            value: TicTacBoard.gridSize
            minimumValue: 3
            maximumValue: 9
            onValueChanged: TicTacBoard.gridSize = value
        }
    }

}
