import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.0

import WUniverse 1.0

ApplicationWindow {
  id: app
  visible: true
  width: 800
  height: 640
  title: qsTr("Hello World")

  StackView {
    id: stackView
    anchors.fill: parent

    initialItem: Item {

      Button {
        anchors.centerIn: parent
        text: qsTr("New Game")
        onClicked: {
          stackView.push("ShowOptionsPage.qml")
        }
      }
    }
  }

}
