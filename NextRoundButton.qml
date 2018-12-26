import QtQuick 2.11
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.4

Button {
  id: control

  text: qsTr("Next")
  font.pixelSize: 36
  font.bold: true
  hoverEnabled: true

  contentItem: Text {
    height: control.height
    text: control.text
    font: control.font
    opacity: enabled ? 1.0 : 0.3
    color: "white"
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    wrapMode: Text.WordWrap
  }

  background: Rectangle {
    radius: width/2
    color: control.hovered
           ? Material.color(Material.Red)
           : Material.color(Material.Red, Material.Shade700)
    border.width: 2
    border.color: Material.color(Material.Red, Material.Shade900)
  }


}
