import QtQuick 2.0
import "fireworks.js" as Fireworks

Item {
    id: statusBar
    width: parent.width

    TicTacPlayerInfo {
        id: firstPlayerInfo

        playerName: TicTacEngine.firstPlayerName
        score: TicTacEngine.firstPlayerScore

        anchors.left: statusBar.left

        baseGradient: '#FF9D80'

        isActive: Fireworks.isPlayerActive(TicTacEngine, 0)
    }

    TicTacPlayerInfo {
        id: secondPlayerInfo

        playerName: TicTacEngine.secondPlayerName
        score: TicTacEngine.secondPlayerScore

        anchors.right: statusBar.right

        baseGradient: '#A6B7CC'

        isActive: Fireworks.isPlayerActive(TicTacEngine, 1)
    }
}
