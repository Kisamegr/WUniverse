#include "wuniverse.h"
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
}

WUniverse::WUniverse()
{

}

WUniverse &WUniverse::shared() {
  static WUniverse instance;
  return instance;
}
