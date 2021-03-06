import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: map

    property int spacing: 10
    property int tileSize: Math.min (getSideLength(map.width),
                                     getSideLength(map.height))

    MessageNotifier{
        id: idleNotifier
    }

    color: 'transparent'

    function getSideLength(side)
    {
        return (side - (TicTacBoard.gridSize + 1) * spacing) / TicTacBoard.gridSize;
    }

    width: parent.width

    Grid {
        id: grid

        // All data stored in List model - a 1Dimentional flat list
        anchors.centerIn: parent
        // Grid Size is can be changed dinamically
        rows: TicTacBoard.gridSize
        columns: TicTacBoard.gridSize
        spacing: map.spacing

        Repeater {
            model: TicTacBoard

            delegate: TicTacTile {
                id: tictactile
                owner: display
                winningfield: decoration
                sideLenght: map.tileSize
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        TicTacEngine.mark(index)
                    }
                }
            }
        }
    }
}
