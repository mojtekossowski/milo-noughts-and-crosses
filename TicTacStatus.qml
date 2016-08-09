import QtQuick 2.0

Item {
    id: statusBar
    width: parent.width

    TicTacPlayerInfo {
        id: firstPlayerInfo

        playerName: TicTacEngine.firstPlayerName
        score: TicTacEngine.firstPlayerScore

        anchors.left: statusBar.left
        gradientTo: '#FF9D80'
    }

    TicTacPlayerInfo {
        id: secondPlayerInfo

        playerName: TicTacEngine.secondPlayerName
        score: TicTacEngine.secondPlayerScore

        anchors.right: statusBar.right
        gradientTo: '#A6B7CC'
    }
}
