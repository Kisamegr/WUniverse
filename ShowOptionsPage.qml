import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.4

import WUniverse 1.0

Item {

  Show {
    id: show
  }

  ColumnLayout {
    anchors.fill: parent
    anchors.margins: 6
    spacing: 10

    Pane {
      Material.elevation: 1
      Layout.fillWidth: true
      RowLayout {
        id: header
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: 10

        property real iconSize: 24

        ToolButton {
          contentItem: RowLayout {
            Image {
              source: "qrc:/images/back.svg"
              sourceSize: Qt.size(header.iconSize, header.iconSize)
            }

            Label {
              text: qsTr("Back")
            }
          }
        }

        TextField {
          id: showName
          placeholderText: qsTr("Enter show name...")
          Layout.fillWidth: true
          text: show.name
          onEditingFinished: show.name = text
        }

        ToolButton {
          contentItem: RowLayout {
            Label {
              text: qsTr("Next")
            }

            Image {
              source: "qrc:/images/forward.svg"
              sourceSize: Qt.size(header.iconSize, header.iconSize)
            }


          }

          onClicked: {
            var comp = Qt.createComponent("GameScreen.qml")
            var obj = comp.createObject(app, {"activeShow" : show})
            obj.show()
          }

        }
      }

    }


    Pane {
      Material.elevation: 1
      Layout.fillWidth: true
      Layout.fillHeight: true

      ColumnLayout {
        anchors.fill: parent

        TextField {
          id: companyName
          Layout.fillWidth: true
          placeholderText: qsTr("Enter company name...")
          text: show.companyName
          onEditingFinished: show.companyName = text
        }

        Label {
          text: qsTr("Roster:")
        }

        Pane {
          Material.elevation: 2
          Layout.fillHeight: true
          Layout.fillWidth: true

          ListView {
            id: rosterView
            anchors.fill: parent
            clip: true

            model: show.roster


            delegate: RowLayout {
              width: rosterView.width

              TextField {
                Layout.fillWidth: true
                text: name
                readOnly: false
                onEditingFinished: name = text
              }

              SpinBox {
                value: team
                from: 0
                to: 10

                onValueChanged: team = value
              }
            }
          }
        }



      }

    }





    Item {
      Layout.fillHeight: true
    }
  }
}
