#ifndef WUNIVERSE_H
#define WUNIVERSE_H

#include <QObject>

class WUniverse : public QObject {
  Q_OBJECT


public:
  WUniverse(QObject *parent = nullptr);


  static WUniverse &shared();
  static void registerData();
 };

#endif // WUNIVERSE_H
