import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property string text: ""
    property string progressText: ""

    Rectangle{
        anchors.fill: parent
    }

    TextEdit{
        id: textarea
        anchors.fill: parent
        textFormat: TextEdit.RichText

        Keys.onReleased: {
            parent.text = textarea.getText(0,text.length) // Pour ne pas recuperer le formattage
        }
    }

    onProgressTextChanged: {
        var cursor = textarea.cursorPosition;
        textarea.text = progressText;
        textarea.cursorPosition = cursor;
    }
}

