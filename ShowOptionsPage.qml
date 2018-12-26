import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.4
import QtGraphicalEffects 1.0

import WUniverse 1.0

Item {
  id: root
  property Show show


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
          Layout.minimumWidth: 100

          contentItem: RowLayout {
            Image {
              source: "qrc:/images/back.svg"
              sourceSize: Qt.size(header.iconSize, header.iconSize)
            }

            Label {
              text: qsTr("Back")
            }
          }

          onClicked: stackView.pop()
        }

        TextField {
          id: showName
          placeholderText: qsTr("Enter show name...")
          Layout.fillWidth: true
          text: show.name
          onEditingFinished: show.name = text
        }

        ToolButton {
          Layout.minimumWidth: 100
          text: qsTr("Start")
          enabled: show && show.name != "" && rosterView.count > 0
          onClicked: {
            app.showNewGameScreen(root.show)
            stackView.pop()
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
          padding: 3

          ListView {
            id: rosterView
            anchors.fill: parent
            clip: true
            spacing: 0

            model: show.roster


            footer: ToolButton {
              width: rosterView.width
              height: 20
              padding: 2
              icon.source: "qrc:/images/plus.svg"

              onClicked: show.addNewCharacter()
            }

            delegate: ItemDelegate {
              width: rosterView.width
              leftPadding: 8
              rightPadding: 2

              contentItem: RowLayout {
                spacing: 10
                TextField {
                  Layout.fillWidth: true
                  text: name
                  readOnly: false
                  onEditingFinished: name = text
                }


                ComboBox {
                  model: 10
                  Layout.preferredWidth: 65

                }

                ToolButton {
                  Layout.preferredWidth: 24
                  Layout.preferredHeight: 24
                  icon.source: "qrc:/images/x.svg"

                  onClicked: show.removeCharacter(index)
                }

              }// RowLayout
            }
          } // ListView
        } // Pane
      } // ColumnLayout
    } // Pane
  }
}
