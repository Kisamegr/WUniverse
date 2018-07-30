#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QHash>

class Character : public QObject {
  Q_OBJECT

  Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
  Q_PROPERTY(int team READ team WRITE setTeam NOTIFY teamChanged)

  QString m_name;
  int m_team;

public:
  enum CharacterRoles {
    CharacterName = Qt::UserRole,
    CharacterTeam
  };

  static QHash<int, QByteArray> roleNames() {
    static const auto roles = QHash<int, QByteArray>{
      { CharacterName, "name" },
      { CharacterTeam, "team" },
    };
    return roles;
  }

  Q_ENUM(CharacterRoles)

  Character(const QString name, int team = 0, QObject *parent = nullptr);
  QString name() const;
  int team() const;

public slots:
  void setName(QString name);
  void setTeam(int team);

signals:
  void nameChanged(QString name);
  void teamChanged(int team);
};

#endif // CHARACTER_H
