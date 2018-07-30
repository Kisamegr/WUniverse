import QtQuick 2.0
import QtQuick.Window 2.11

import WUniverse 1.0


Window {
  id: gameWindow
  property Show activeShow
  title: activeShow.name

  width: 1024
  height: 800
 GameSimulation {
    id: game
    show: gameWindow.activeShow
  }
}
