import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property string text: "value"
    Rectangle{
        anchors.fill: parent

    }
    TextEdit{
        id: textarea
        anchors.fill: parent
        textFormat: TextEdit.RichText

        Keys.onReleased: {




        }
    }
}

