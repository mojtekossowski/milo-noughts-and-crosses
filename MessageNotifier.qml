import QtQuick 2.0
import "fireworks.js" as Fireworks

// Winner notify
Rectangle {
    id: messageNotifier

    property bool runAnimation: true

    width: parent.width
    height: parent.height * 0.2
    z:1
    y: -height
    opacity: 0.7

    Text {
        id: name
        anchors.centerIn: parent
        text: Fireworks.getWinnerInfo(TicTacEngine.victory,
                                      FirstPlayer,
                                      SecondPlayer)

        font.pixelSize: messageNotifier.height / 3
    }

    Text {
        id: tapToPlay
        anchors.top: name.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        visible: TicTacEngine.victory !== 0

        text: qsTr('Tap to play!')

        font.pixelSize: messageNotifier.height / 6
    }

    MouseArea {
        onClicked: TicTacEngine.active = true
    }

    states: [
        State {
            name: 'shown'
            PropertyChanges {
                target: messageNotifier
                y: 0
            }
            when: !TicTacEngine.active
        },
        State {
            name: 'hidden'
            PropertyChanges {
                target: messageNotifier
                y: -height
            }
            when: TicTacEngine.active
        }
    ]

    transitions: Transition {
        NumberAnimation {
            target: messageNotifier
            property: 'y'
            duration: 200
            easing.type: Easing.InOutQuad
        }
    }
}
