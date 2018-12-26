#include "show.h"
#include <QDebug>

Show::Show(QObject *parent) : QObject(parent),
  m_roster(new QStandardItemModel(this)) {
  m_roster->setItemRoleNames(Character::roleNames());

  m_name = "a";
  m_companyName = "";
  addNewCharacter();
  addNewCharacter();
  addNewCharacter();
  addNewCharacter();
  addNewCharacter();
}

Show::Show(const Show &other) {
  m_name = other.m_name;
  m_companyName = other.m_companyName;
  m_roster->clear();
  for (int i=0; i<other.m_roster->rowCount(); i++)
    m_roster->appendRow(other.m_roster->item(i)->clone());
}


QStandardItemModel *Show::roster() {
  return m_roster;
}

QString Show::name() const {
  return m_name;
}

QString Show::companyName() const {
  return m_companyName;
}

void Show::setName(QString name) {
  if (m_name == name)
    return;

  m_name = name;
  emit nameChanged(m_name);
}

void Show::setCompanyName(QString companyName)
{
  if (m_companyName == companyName)
    return;

  m_companyName = companyName;
  emit companyNameChanged(m_companyName);
}

void Show::addCharacter(const Character &character) {
  QStandardItem *item = new QStandardItem();
  item->setData(character.name(), Character::CharacterName);
  item->setData(character.team(), Character::CharacterTeam);
  m_roster->appendRow(item);
}

void Show::addNewCharacter() {
  QStandardItem *item = new QStandardItem();
  item->setData(QString("Mpampoglas %1").arg(m_roster->rowCount() + 1), Character::CharacterName);
  m_roster->appendRow(item);
}

void Show::removeCharacter(int index) {
  m_roster->removeRow(index);
}

void Show::temp()
{
  for(int i=0; i<m_roster->rowCount(); i++)
    qDebug() <<m_roster->item(i)->data(Character::CharacterTeam);
}
