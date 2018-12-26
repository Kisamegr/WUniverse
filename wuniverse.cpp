#include "wuniverse.h"
#include "gamesimulation.h"
#include "show.h"

#include <QQmlEngine>


QObject *factory(QQmlEngine *engine, QJSEngine *scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  auto result = &WUniverse::shared();
  QQmlEngine::setObjectOwnership(result, QQmlEngine::CppOwnership);
  return result;
}

void WUniverse::registerData() {
  qmlRegisterSingletonType<WUniverse>("WUniverse", 1, 0, "WU", &factory);
  qmlRegisterUncreatableType<Show>("WUniverse", 1, 0, "Show", "Can't Create Show");
  qmlRegisterUncreatableType<Character>("WUniverse", 1, 0, "Character", "Can't Create Character");
  qmlRegisterType<Show> ("WUniverse", 1, 0, "Show");
  qmlRegisterType<GameSimulation> ("WUniverse", 1, 0, "GameSimulation");
  qmlRegisterType<Character> ("WUniverse", 1, 0, "Character");

}

WUniverse::WUniverse(QObject *parent) : QObject(parent) {

}

Show *WUniverse::createShow() {
  Show *show = new Show();
  QQmlEngine::setObjectOwnership(show, QQmlEngine::CppOwnership);
  return show;
}

WUniverse &WUniverse::shared() {
  static WUniverse instance;
  return instance;
}
