import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

ApplicationWindow {
    id: mainWindow
    visible: true

    minimumWidth: 360
    minimumHeight: 450
    width: 360
    height: 450

    property bool splashVisible: true
    property Gradient mainGradient: Gradient {
        GradientStop {
            position: 0.00;
            color: '#21361A';
        }
        GradientStop {
            position: 0.8;
            color: "#000000";
        }
    }

    title: qsTr('Milo - Noughts and Crosses')

    MiloSplashScreen{
        id: splash
        visible: mainWindow.splashVisible
        anchors.fill: parent
        onTimeout: mainWindow.splashVisible = false
    }

    SwipeView {
        anchors.fill: parent
        currentIndex: 1

        TicTacSettings {
            gradient: mainWindow.mainGradient
        }

        MainMenu{
            gradient: mainWindow.mainGradient
        }

        Rectangle {
            gradient: mainWindow.mainGradient

            TicTacMap {
                id: map
                anchors.top: mainWindow.top
                height: 0.8*mainWindow.height
            }

            TicTacStatus {
                anchors.top: map.bottom
                height: 0.2*mainWindow.height
            }
        }
    }
}
