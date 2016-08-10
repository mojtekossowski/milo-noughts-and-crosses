import QtQuick 2.0
import "fireworks.js" as Fireworks

Flipable {
    id: flipable

    property int sideLenght: 30
    property int owner: 0
    property bool winningfield: false

    width: sideLenght
    height: sideLenght

    front: TicTacBaseTile{
        sideLength: flipable.sideLenght
        gradientColor: Fireworks.getTileColor(flipable.owner,
                                              flipable.winningfield)
    }

    back: TicTacBaseTile{
        sideLength: flipable.sideLenght
        gradientColor: Fireworks.getTileColor(flipable.owner,
                                              flipable.winningfield)
        Image{
            source: Fireworks.getImage(flipable.owner)
            anchors.fill: parent
        }
    }

    transform: Rotation {
        id: rotation
        origin.x: flipable.sideLenght/2;
        origin.y: flipable.sideLenght/2;
        axis.x: 0; axis.y: 1; axis.z: 0
        angle: 0
    }

    states: [
        State {
            name: 'empty'
            PropertyChanges {
                target: rotation
                angle: 0
            }
            when: owner === 0
        },
        State {
            name: 'crossed'
            PropertyChanges {
                target: rotation
                angle: 180
            }
            when: owner === 1
        },
        State {
            name: 'noughted'
            PropertyChanges {
                target: rotation
                angle: -180
            }
            when: owner === 2
        }
    ]

    transitions: Transition {
        NumberAnimation {
            target: rotation
            property: 'angle'
            duration: 400
            easing.type: Easing.OutQuad
        }
    }
}

