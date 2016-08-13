import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: options

    property int fontSize: 22

    ListView{
        ListElement {

        }
    }

    Item {
        Text {
            id: gridSizeLabel

            text: qsTr('Game grid size: ')
            font.pixelSize: fontSize
        }

        SpinBox{
            anchors.left: gridSizeLabel.right
            value: TicTacBoard.gridSize
            onValueChanged: TicTacBoard.gridSize = value
        }
    }

}
