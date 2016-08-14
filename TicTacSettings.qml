import QtQuick 2.2
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1

Rectangle {

    ColumnLayout {
        id: options
        property int fontSize: 22

        height: parent.height * 0.8
        width: parent.width * 0.8

        anchors.centerIn: parent

        Text {
            text: qsTr('Game grid size: ')
            font.pixelSize: options.fontSize
            color: '#fafafa'
            Layout.alignment: Qt.AlignLeft
        }

        SpinBox{
            value: TicTacBoard.gridSize
            onValueChanged: TicTacBoard.gridSize = value
            Layout.alignment: Qt.AlignRight
        }

        Text {
            text: qsTr('"Noughts" player name:')
            font.pixelSize: options.fontSize
            color: '#fafafa'
            Layout.alignment: Qt.AlignLeft
        }

        TextField {
            text: FirstPlayer.name
            onTextChanged: FirstPlayer.name = text
            color: '#fafafa'
            Layout.alignment: Qt.AlignRight
        }

        Text {
            text: qsTr('"Crosses" player name:')
            font.pixelSize: options.fontSize
            color: '#fafafa'
            Layout.alignment: Qt.AlignLeft
        }

        TextField {
            text: SecondPlayer.name
            onTextChanged: SecondPlayer.name = text
            color: '#fafafa'
            Layout.alignment: Qt.AlignRight
        }

        Text {
            text: qsTr('Clear map:')
            font.pixelSize: options.fontSize
            color: '#fafafa'
            Layout.alignment: Qt.AlignLeft
        }

        Rectangle {
            Layout.minimumWidth: options.fontSize *3
            Layout.minimumHeight: options.fontSize *3

            Layout.alignment: Qt.AlignCenter

            Button {
                id: removeButton

                anchors.fill: parent


                Image {
                    id: clearImage
                    anchors.fill: parent
                    source: "qrc:/img/gfx/trash.png"
                }

                onClicked: dialog.open()

                MessageDialog {
                    id: dialog
                    title: qsTr("Clear")
                    text: qsTr("Do you want to clear map?")
                    icon: StandardIcon.Question
                    standardButtons: MessageDialog.Ok | MessageDialog.Cancel
                    onAccepted: TicTacEngine.resetPoints()
                }
            }
        }

    }
}
