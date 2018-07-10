import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2

import WUniverse 1.0

Window {

  width: 600
  height: 500

  ColumnLayout {
    anchors.fill: parent
    anchors.margins: 6

    TextField {
      placeholderText: "Game name..."
      Layout.alignment: Qt.AlignTop
    }
  }
}
