#ifndef WUNIVERSE_H
#define WUNIVERSE_H

#include <QObject>
#include "show.h"

class WUniverse : public QObject {
  Q_OBJECT


public:
  WUniverse(QObject *parent = nullptr);
  Q_INVOKABLE Show* createShow();


  static WUniverse &shared();
  static void registerData();


 };

#endif // WUNIVERSE_H
