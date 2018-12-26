import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import WUniverse 1.0

ApplicationWindow {
  id: app
  visible: true
  width: 800
  height: 640
  title: qsTr("WUniverse Alpha")
  color: "black"

  function showNewGameScreen(show) {
    var comp = Qt.createComponent("GameScreen.qml")
    var obj = comp.createObject(app, {"activeShow" : show})
    if(obj)
      obj.show()
    else
      console.log(comp.errorString())
  }

  StackView {
    id: stackView
    anchors.fill: parent

    initialItem: Item {

      ColumnLayout {
        anchors.fill: parent
        Image {
          Layout.fillWidth: true
          source: "qrc:/images/wuniverse_logo.png"
        }
        Button {
          Layout.preferredWidth: 300
          Layout.preferredHeight: 120
          Layout.alignment: Qt.AlignHCenter
          text: qsTr("NEW GAME")
          font.pixelSize: 30
          font.bold: true
          onClicked: {
            var show = WU.createShow()
            stackView.push("ShowOptionsPage.qml", {"show" : show})
          }
        }
      }

    }
  }
}
