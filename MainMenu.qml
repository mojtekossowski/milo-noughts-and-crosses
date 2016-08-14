import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {

    ColumnLayout {
        id: mainMenu

        anchors.fill: parent

        Image {
            id: logo
            Layout.alignment: Qt.AlignHCenter
            source: "qrc:/img/gfx/title.png"

            SequentialAnimation
            {
                running: true
                NumberAnimation {target: logo; property: 'scale'; to: 0.7; duration: 2000}
                NumberAnimation {target: logo; property: 'scale'; to: 1.0; duration: 2000}
                onStopped: start()
            }
        }

        Image {
            id: options
            source: "qrc:/img/gfx/options.png"
            Layout.alignment: Qt.AlignHCenter
        }

        Image {
            id: game
            source: "qrc:/img/gfx/game.png"
            Layout.alignment: Qt.AlignHCenter
        }
    }

}
