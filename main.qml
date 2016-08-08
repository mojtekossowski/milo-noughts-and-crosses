import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

ApplicationWindow {
    id: mainWindow
    visible: false
    width: 360
    height: 450

    minimumWidth: 360
    minimumHeight: 450

    title: qsTr('Milo - Noughts and Crosses')

    MiloSplashScreen{
        id: splash
        visible: true
        onTimeout: mainWindow.visible = true
    }

    TicTacMap {
        id: map
        anchors.top: parent.top
    }

    TicTacStatus {
        anchors.top: map.bottom
        onSettingsToggled: {
            settings.visible = true
        }
    }
}
