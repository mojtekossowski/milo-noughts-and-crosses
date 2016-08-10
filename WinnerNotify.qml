import QtQuick 2.0

Rectangle {
    id: dialog

    property string dialogMessage: 'asdf'
    property string winnerColor: '#366399'

    anchors.centerIn: parent
    width: parent.width
    height: parent.height / 2

    z: 2

    visible: false
    opacity: 0.65

    gradient: Gradient {
        GradientStop {
            position: 0.0;
            color: Qt.lighter(winnerColor);
        }
        GradientStop {
            position: 0.5;
            color: winnerColor;
        }
    }

    Text {
        id: name
        text: dialogMessage
        font.pixelSize: dialog.height / 2
    }
}
