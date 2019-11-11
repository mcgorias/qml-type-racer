import QtQuick 2.4
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Typing Race")

    TextMetrics {
        id: textMetrics
        font.family: "Arial"
        font.pixelSize: 50
        text: textSelector.currentText
    }

    ColumnLayout{

        anchors.fill: parent
        spacing: 2
        ComboBox {
            model: texts
            id: textSelector
        }

        Rectangle{
            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "grey"
            Text {
                anchors.top: parent.top
                anchors.left: parent.left

                height: parent.height
                width: parent.width

                text: textMetrics.text
                font: textMetrics.font
                minimumPixelSize: 2
                fontSizeMode: Text.Fit
                wrapMode:  Text.Wrap

            }
        }
        TypingZone{
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter
        }
        Component.onCompleted: {

        }
    }

}