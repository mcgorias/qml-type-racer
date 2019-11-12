import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property string text: ""
    property string progressText: ""
    property string lastContent : ""

    function reset(){
        text         = "";
        progressText = "";
        lastContent  = "";
    }

    Rectangle{
        anchors.fill: parent
    }

    TextEdit{
        id: textarea
        anchors.fill: parent
        textFormat: TextEdit.RichText
        wrapMode:  Text.Wrap


        Keys.onReleased: {

            var pattern = /<|>/;
            var rawText = String(textarea.getText(0,text.length));

            if(pattern.test(rawText))
            {
                var cursor = textarea.cursorPosition -1;
                textarea.text = lastContent;
                textarea.cursorPosition = cursor;
            }
            else
            {
                lastContent = textarea.text;
                parent.text = rawText;
            }

        }
    }

    onProgressTextChanged: {
        var cursor = textarea.cursorPosition;
        textarea.text = progressText;
        textarea.cursorPosition = cursor;
    }
}

