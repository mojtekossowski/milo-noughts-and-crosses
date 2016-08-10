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

    function getSideLength(side)
    {
        return (side - (TicTacBoard.gridSize + 1) * spacing) / TicTacBoard.gridSize;
    }

    width: parent.width
    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#293c04";
        }
        GradientStop {
            position: 1.00;
            color: "#000000";
        }
    }

    Grid {
        id: grid

        anchors.centerIn: parent
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

    WinnerNotify {
        id: winnerNotify
    }
}
