#include "gamesimulation.h"
#include <QDebug>

GameSimulation::GameSimulation(QObject *parent) : QObject(parent)
{

}

Show GameSimulation::show() const
{
  return m_show;
}

int GameSimulation::round() const
{
  return m_round;
}

void GameSimulation::nextRound() {

}

void GameSimulation::setShow(const Show &show) {
  qDebug() << "HERE CAME";
//  if (m_show.name() == show.name())
//    return;

  m_show = show;
  emit showChanged();
  qDebug() << "AFTER CAME";
}

void GameSimulation::setRound(int round)
{
  if (m_round == round)
    return;

  m_round = round;
  emit roundChanged(m_round);
}
