import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {
    id: splash

    property int timeoutInterval: 2000

    signal timeout
    color: 'black'
    z: 1

    Image {
        id: splashImage
        source: 'qrc:/img/gfx/logo.png'
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
        width: parent.width *0.8
        height: parent.width *0.8

        SequentialAnimation
        {
            running: true
            PropertyAction { target: splashImage; property: 'opacity'; value: 0.0}
            NumberAnimation {
                target: splashImage; property: 'opacity'; to: 1.0;
                duration: 1500; easing.type: Easing.InOutExpo
            }
            NumberAnimation {target: splashImage; property: 'opacity'; to: 1.0; duration: 2000}
            NumberAnimation {
                target: splash; property: 'opacity'; to: 0.0;
                duration: 1500; easing.type: Easing.OutQuad
            }

            onStopped: splash.timeout()
        }
    }
}
