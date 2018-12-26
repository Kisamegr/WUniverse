import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.2

import WUniverse 1.0


ApplicationWindow {
  id: gameWindow
  property alias activeShow: game.show
  title: app.title + " - " + ( activeShow ? activeShow.name : "")

  width: 1024
  height: 600
  color: "black"

  GameSimulation {
    id: game
  }

  RowLayout {
    anchors.fill: parent
    anchors.margins: 4

    Rectangle {
      Layout.fillHeight: true
      Layout.preferredWidth: 200
      radius: 4
      color: "white"

      ListView {
        id: nextMatchesView
        anchors.fill: parent
        anchors.margins: 2
        model: game.nextMatches
        spacing: 5
        clip: true

        header: ColumnLayout {
          z: 100
          width: nextMatchesView.width
          Label {
            Layout.fillWidth: true
            text: qsTr("NEXT MATCHES:")
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
          }

          Rectangle {
            Layout.preferredHeight: 1
            Layout.fillWidth: true
            color: "black"
          }

          Item {
            Layout.preferredHeight: nextMatchesView.spacing
          }

        }

        delegate: ItemDelegate {
          width: nextMatchesView.width

          background: Rectangle{
            color: Material.color(Material.Blue)
            radius: 4
          }


          contentItem: ColumnLayout {
            id: matchDelegate

            Label {
              font.bold: true
              color: "white"
              Layout.alignment: Qt.AlignHCenter
              text: model.firstPlayer.name
            }

            Text {
              Layout.alignment: Qt.AlignHCenter
              text: qsTr("VS")
              color: "white"
            }

            Label {
              font.bold: true
              color: "white"
              Layout.alignment: Qt.AlignHCenter
              text: model.secondPlayer.name
            }
          }
        }
      }
    }

    ColumnLayout {
      Layout.fillWidth: true
      Layout.fillHeight: true

      Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        radius: 4

        ColumnLayout {
          anchors.fill: parent
          anchors.margins: 5

          spacing: 20

          Label {
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("ROUND ") + game.round
            font.pixelSize: 36
          }

          Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Loader {
              active: game.activeMatch ? true:false
              anchors.fill: parent

              sourceComponent: ColumnLayout {
                ButtonGroup {
                  id: matchResultGroup
                }

                RowLayout {
                  Layout.alignment: Qt.AlignCenter

                  ToolButton {
                    id: leftPlayer
                    checkable: true
                    font.bold: true
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: 100
                    text: game.activeMatch.firstPlayer.name
                    font.pixelSize: 30
                    ButtonGroup.group: matchResultGroup

                  }

                  Text {
                    Layout.alignment: Qt.AlignHCenter
                    text: qsTr("VS")
                    font.pixelSize: 30
                  }

                  ToolButton {
                    id: rightPlayer
                    checkable: true
                    font.bold: true
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: 100
                    text: game.activeMatch.secondPlayer.name
                    font.pixelSize: 30
                    ButtonGroup.group: matchResultGroup
                  }
                }


                ToolButton {
                  id: tieButton
                  checkable: true
                  font.bold: true
                  Layout.alignment: Qt.AlignHCenter
                  Layout.preferredHeight: 100
                  text: qsTr("TIE")
                  font.pixelSize: 30
                  ButtonGroup.group: matchResultGroup
                }
                Item {
                  Layout.fillHeight: true
                }

                Label {
                  font.bold: true
                  Layout.alignment: Qt.AlignHCenter
                  Layout.preferredHeight: 100
                  text: qsTr("CHOOSE YOUR DESTINY")
                  font.pixelSize: 30
                }
              }
            }

          }
        }
      }


      RowLayout {
        Layout.fillWidth: true
        Layout.maximumHeight: 150


        TextArea {
          Layout.fillWidth: true
          Layout.fillHeight: true

          padding: 5
          text: "TODO: Add console log for history..."

          readOnly: true
          background: Rectangle{
            radius: 4
          }

        }

        NextRoundButton {
          id: nextRoundButton
          Layout.fillHeight: true
          implicitWidth: height
          onClicked: game.nextRound()
        }

      } // RowLayout
    } // ColumnLayout
  } // RowLayout
}
