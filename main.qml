import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.0

import WUniverse 1.0

ApplicationWindow {
  id: app
  visible: true
  width: 200
  height: 100
  title: qsTr("Hello World")


  Button {
    anchors.centerIn: parent
    text: "New Game"
    onClicked: {
      var comp = Qt.createComponent("NewGameWindow.qml")
      var obj = comp.createObject()
      if(obj !== null) {
        obj.show()
      }
      else
        console.log(comp.errorString())
    }
  }
}
