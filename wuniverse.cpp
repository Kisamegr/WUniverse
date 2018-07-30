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
  qRegisterMetaType<Show *>("Show");
  qmlRegisterType<Show> ("WUniverse", 1, 0, "Show");
  qmlRegisterType<GameSimulation> ("WUniverse", 1, 0, "GameSimulation");
}

WUniverse::WUniverse(QObject *parent) : QObject(parent) {

}

WUniverse &WUniverse::shared() {
  static WUniverse instance;
  return instance;
}
