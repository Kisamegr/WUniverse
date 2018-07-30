#ifndef GAMESIMULATION_H
#define GAMESIMULATION_H

#include <QObject>
#include "show.h"

class GameSimulation : public QObject {
  Q_OBJECT

  Q_PROPERTY(int round READ round WRITE setRound NOTIFY roundChanged)
  Q_PROPERTY(Show show READ show WRITE setShow NOTIFY showChanged)

  Show m_show;

  int m_round;

public:
  GameSimulation(QObject *parent = nullptr);
  Show show() const;
  int round() const;

public slots:
  void nextRound();
  void setShow(const Show &show);
  void setRound(int round);

signals:
  void showChanged();
  void roundChanged(int round);
};

#endif // GAMESIMULATION_H
