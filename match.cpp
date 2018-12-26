#include "match.h"

Match::Match(QObject *parent) :
  QObject (parent),
  m_firstPlayer(nullptr),
  m_secondPlayer(nullptr),
  m_result(NotPlayed) {
}

Match::Match(Character *first, Character *second, QObject *parent) :
  QObject (parent),
  m_firstPlayer(first),
  m_secondPlayer(second),
  m_result(NotPlayed) {
}

Match::Match(const Match &other) {
  m_firstPlayer = other.m_firstPlayer;
  m_secondPlayer = other.m_secondPlayer;
}

Match &Match::operator=(const Match &other) {
  if (this != &other) { // self-assignment check expected
   m_firstPlayer = other.m_firstPlayer;
   m_secondPlayer = other.m_secondPlayer;
  }
  return *this;
}

bool Match::operator==(const Match &other) const {
  return other.m_firstPlayer == m_firstPlayer &&
      other.m_secondPlayer == m_secondPlayer &&
      other.m_result == m_result;
}

Character *Match::firstPlayer() const {
  return m_firstPlayer;
}

Character *Match::secondPlayer() const {
  return m_secondPlayer;
}

Match::MatchResult Match::result() const {
  return m_result;
}

void Match::setFirstPlayer(Character *firstPlayer) {
  if (m_firstPlayer == firstPlayer)
    return;

  m_firstPlayer = firstPlayer;
  emit firstPlayerChanged();
}

void Match::setSecondPlayer(Character *secondPlayer) {
  if (m_secondPlayer == secondPlayer)
    return;

  m_secondPlayer = secondPlayer;
  emit secondPlayerChanged();
}

void Match::setResult(Match::MatchResult result) {
  if (m_result == result)
    return;

  m_result = result;
  emit resultChanged(m_result);
}
