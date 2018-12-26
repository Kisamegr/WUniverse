#include "gamesimulation.h"
#include <QDebug>

#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time

GameSimulation::GameSimulation(QObject *parent) :
  QObject(parent),
  m_activeMatch(nullptr),
  m_show(nullptr),
  m_round(0),
  m_nextMatches(new MatchListModel(this)) {

  connect(this, &GameSimulation::showChanged, this, &GameSimulation::onShowChanged);
}

Show *GameSimulation::show() {
  return m_show;
}

int GameSimulation::round() const {
  return m_round;
}

GameSimulation::GameState GameSimulation::state() const {
  return m_state;
}

Match* GameSimulation::activeMatch() const {
  return m_activeMatch;
}

MatchListModel *GameSimulation::nextMatches() const {
  return m_nextMatches;
}


void GameSimulation::simulate() {
  switch (m_state) {
  case MATCH_ENDED:
    nextMatch();
    return;
  case MATCH_IN_PROGRESS:
    //
    return;
  default:
    return;
  }
}

void GameSimulation::nextMatch() {
  if(m_availableCharacters.count() >= 2) {

  }
}

void GameSimulation::calculateNextMatches() {
  m_nextMatches->clear();
  while(m_availableCharacters.count() > 2) {
    Character *first = m_availableCharacters.dequeue();
    Character *second = m_availableCharacters.dequeue();

    Match *match = new Match(first, second, this);
    m_nextMatches->enqueueMatch(match);
  }
}

void GameSimulation::resetAvailableCharacters() {
  if(m_show) {
    m_availableCharacters.clear();

    for(int i=0; i<m_show->roster()->rowCount(); i++) {
      Character* character = new Character(
            m_show->roster()->item(i)->data(Character::CharacterName).toString(),
            m_show->roster()->item(i)->data(Character::CharacterTeam).toInt(),
            this);

      m_availableCharacters.append(character);
    }

    std::random_shuffle(m_availableCharacters.begin(), m_availableCharacters.end());
  }
}

void GameSimulation::resetSimulation() {
  setRound(0);
  resetAvailableCharacters();
  calculateNextMatches();

  m_activeMatch = m_nextMatches->dequeueMatch();
}

void GameSimulation::nextRound() {
  simulate();
  setRound(m_round + 1);
}

void GameSimulation::setShow(Show *show) {
  if(!show)
    return;

  if (m_show && m_show->name() == show->name())
    return;

  m_show = show;
  emit showChanged();
}

void GameSimulation::setRound(int round) {
  if (m_round == round)
    return;

  m_round = round;
  emit roundChanged(m_round);
}

void GameSimulation::setState(GameSimulation::GameState state) {
  if (m_state == state)
    return;

  m_state = state;
  emit stateChanged(m_state);
}

void GameSimulation::setActiveMatch(Match *activeMatch) {
  if (m_activeMatch == activeMatch)
    return;

  m_activeMatch = activeMatch;
  emit activeMatchChanged();
}

void GameSimulation::onShowChanged() {
  resetSimulation();
}
