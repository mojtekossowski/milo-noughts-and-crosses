import QtQuick 2.0

Rectangle {
    id: player

    property int fontPixelSize: player.height/4
    property string playerName: ""
    property int score: 0
    property string gradientTo

    width: parent.width / 2
    height: parent.height

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: 'black'
        }
        GradientStop {
            position: 0.7
            color: player.gradientTo
        }
    }

    Text {
        id: playerNameLabel

        text: player.playerName

        width: parent.width
        font.pixelSize: player.fontPixelSize
        font.weight: Font.DemiBold

        horizontalAlignment: Text.AlignHCenter
        anchors.centerIn: parent

        color: "#1f1f1f"
    }
    Text {
        id: playerScoreLabel

        text: qsTr("Score: %1").arg(player.score)

        width: parent.width
        anchors.top: playerNameLabel.bottom

        font.pixelSize: parent.fontPixelSize / 2

        horizontalAlignment: Text.AlignHCenter
    }
}
