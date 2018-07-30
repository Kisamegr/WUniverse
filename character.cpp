#include "character.h"

Character::Character(const QString name, int team, QObject *parent) :
  QObject(parent),
  m_name(name),
  m_team(team) {

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
