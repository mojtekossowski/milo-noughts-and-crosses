import QtQuick 2.0
import QtQuick.Window 2.2

Window {
    id: splash
    visible: true
    color: 'black'
    flags: Qt.SplashScreen

    property int timeoutInterval: 2000

    width: splashImage.width
    height: splashImage.height

    signal timeout

    function assignImageToScreenSize() {
        var imageRatio = splashImage.width / splashImage.height;
    }

    Image {
        id: splashImage
        source: 'qrc:/img/gfx/logo.png'
    }

    Timer {
        interval: timeoutInterval
        running: true
        repeat: false
        onTriggered: {
            visible = false
            splash.timeout()
        }
    }
}
