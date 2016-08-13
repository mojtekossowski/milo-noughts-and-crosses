import QtQuick 2.0
import "fireworks.js" as Fireworks

Item {
    id: statusBar
    width: parent.width

    TicTacPlayerInfo {
        playerName: FirstPlayer.name
        score: FirstPlayer.score

        anchors.left: statusBar.left

        baseGradient: '#FF9D80'

        isActive: Fireworks.isPlayerActive(TicTacEngine, FirstPlayer.playerMarkType)
    }

    TicTacPlayerInfo {
        playerName: SecondPlayer.name
        score: SecondPlayer.score

        anchors.right: statusBar.right

        baseGradient: '#A6B7CC'

        isActive: Fireworks.isPlayerActive(TicTacEngine, SecondPlayer.playerMarkType)
    }
}
