#ifndef MATCH_H
#define MATCH_H

#include <QObject>
#include "character.h"

class Match : public QObject {
  Q_OBJECT

  Q_PROPERTY(Character* firstPlayer READ firstPlayer WRITE setFirstPlayer NOTIFY firstPlayerChanged)
  Q_PROPERTY(Character* secondPlayer READ secondPlayer WRITE setSecondPlayer NOTIFY secondPlayerChanged)
  Q_PROPERTY(MatchResult result READ result WRITE setResult NOTIFY resultChanged)

public:
  enum MatchRoles {
    FirstPlayer = Qt::UserRole + 1,
    SecondPlayer,
    Result
  };

  enum MatchResult {
    NotPlayed,
    FirstWon,
    SecondWon,
    Tie
  };
  Q_ENUM(MatchResult)

  Match(QObject* parent = nullptr);
  Match(Character *first, Character *second, QObject *parent = nullptr);
  Match(const Match &other);
  Match& operator=(const Match &other);
  bool operator==(const Match &other) const;

  Character* firstPlayer() const;
  Character* secondPlayer() const;

  MatchResult result() const;

public slots:
  void setFirstPlayer(Character *firstPlayer);
  void setSecondPlayer(Character *secondPlayer);

  void setResult(MatchResult result);

private:
  Character* m_firstPlayer;
  Character* m_secondPlayer;
  MatchResult m_result;

signals:
  void firstPlayerChanged();
  void secondPlayerChanged();
  void resultChanged(MatchResult result);
};

#endif // MATCH_H
