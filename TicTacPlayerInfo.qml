import QtQuick 2.0

Rectangle {
    id: player

    property int playerId
    property int score

    Text {
        id: playerNameLabel

        text: qsTr("Player %1").arg(player.playerId)
        horizontalAlignment: player.playerId === 1 ? Text.AlignLeft
                                                   : Text.AlignRight

        font.weight: Font.DemiBold
        font.pixelSize: 22
    }
    Text {
        id: playerScoreLabel
        anchors.top: playerNameLabel.bottom

        text: qsTr("Score: %1").arg(String(player.score))
        horizontalAlignment: playerNameLabel.horizontalAlignment
    }

}
