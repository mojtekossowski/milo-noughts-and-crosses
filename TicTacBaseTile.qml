import QtQuick 2.0

Rectangle {
    property int sideLength: 30

    anchors.fill: parent
    color: '#5F5F5F'
    radius: 0.2 * sideLenght
    border {
        width: 0.01 * sideLenght
        color: 'black'
    }
}
