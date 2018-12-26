#include "character.h"

Character::Character(QObject *parent) : QObject (parent){

}

Character::Character(const QString name, int team, QObject *parent) :
  QObject(parent),
  m_name(name),
  m_team(team) {

}

Character::Character(const Character &other) {
  setName(other.name());
  setTeam(other.team());
}

Character &Character::operator=(const Character &other) {
  if (this != &other) { // self-assignment check expected
    setName(other.name());
    setTeam(other.team());
  }
  return *this;
}

bool Character::operator==(const Character &other) const{
  return other.m_name != m_name && other.m_team != m_team;
}

QString Character::name() const
{
  return m_name;
}

int Character::team() const
{
  return m_team;
}

void Character::setName(QString name)
{
  if (m_name == name)
    return;

  m_name = name;
  emit nameChanged(m_name);
}

void Character::setTeam(int team)
{
  if (m_team == team)
    return;

  m_team = team;
  emit teamChanged(m_team);
}
