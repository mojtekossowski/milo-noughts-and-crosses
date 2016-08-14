import QtQuick 2.0
import QtGraphicalEffects 1.0

// Represents base map tile objects
Rectangle {
    id: tile

    property int sideLength: 30
    property string gradientColor

    anchors.fill: parent
    radius: 0.2 * sideLenght

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: Qt.lighter(gradientColor)
        }
        GradientStop {
            position: 0.5
            color: gradientColor
        }
    }

    border {
        width: 0.01 * sideLenght
        color: 'black'
    }
}
