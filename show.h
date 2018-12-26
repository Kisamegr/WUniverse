#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QObject>
#include <QStandardItemModel>
#include "character.h"

class Show : public QObject {
  Q_OBJECT

  Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
  Q_PROPERTY(QString companyName READ companyName WRITE setCompanyName NOTIFY companyNameChanged)

  Q_PROPERTY(QStandardItemModel* roster READ roster CONSTANT)


  QStandardItemModel* m_roster;
  QString m_name;
  QString m_companyName;

public:
  Show(QObject *parent = nullptr);
  Show(const Show &other);

  QStandardItemModel* roster();

  QString name() const;

  QString companyName() const;

public slots:
  void setName(QString name);
  void setCompanyName(QString companyName);
  void addCharacter(const Character &character);
  void addNewCharacter();
  void removeCharacter(int index);
  void temp();

signals:
  void nameChanged(QString name);
  void companyNameChanged(QString companyName);
};

#endif // GAMESESSION_H
