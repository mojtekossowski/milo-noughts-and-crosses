import QtQuick 2.0

Flipable {
    id: flipable
    property int sideLenght: 30
    property int owner: 0
    property bool winningfield: false

    width: sideLenght
    height: sideLenght

    function getTileColor (){
        if (owner === 1){
            return winningfield ? '#366399' : '#A6B7CC';
        }
        else if (owner === 2){
            return winningfield ? '#CC4A3D' : '#FF9D80';
        }
        else{
            return '#5F5F5F'
        }
    }

    function getImage (){
        if (owner === 1){
            return 'qrc:/img/gfx/settings.png';
        }
        else if (owner === 2){
            return 'qrc:/img/gfx/trash.png';
        }
        else {
            return '';
        }
    }

    front: TicTacBaseTile{
        sideLength: flipable.sideLenght
    }

    back: TicTacBaseTile{
        sideLength: flipable.sideLenght
        color: getTileColor()
        Image{
            source: getImage()
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

