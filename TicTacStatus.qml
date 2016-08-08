import QtQuick 2.0

Rectangle {
    id: statusBar
    width: parent.width
    height: 100
    color: 'green'

    property alias firstPlayerScore: firstPlayerInfo.score
    property alias secondPlayerScore: secondPlayerInfo.score

    signal settingsToggled

    TicTacPlayerInfo {
        id: firstPlayerInfo
        playerId: 1
        anchors.left: parent.left;
    }

    TicTacPlayerInfo {
        id: secondPlayerInfo
        playerId: 2
        anchors.right: parent.right;
    }
}
