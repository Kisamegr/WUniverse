#ifndef GAMESIMULATION_H
#define GAMESIMULATION_H

#include <QObject>
#include <QQueue>
#include "show.h"
#include "match.h"
#include "matchlistmodel.h"

class GameSimulation : public QObject {
  Q_OBJECT

  Q_PROPERTY(int round READ round WRITE setRound NOTIFY roundChanged)
  Q_PROPERTY(Show* show READ show WRITE setShow NOTIFY showChanged)
  Q_PROPERTY(GameState state READ state WRITE setState NOTIFY stateChanged)
  Q_PROPERTY(Match* activeMatch READ activeMatch WRITE setActiveMatch NOTIFY activeMatchChanged)
  Q_PROPERTY(MatchListModel* nextMatches READ nextMatches CONSTANT)


public:
  enum GameState {

    MATCH_IN_PROGRESS,
    MATCH_ENDED,
    GAME_FINISHED
  };
  Q_ENUM(GameState)

  GameSimulation(QObject *parent = nullptr);
  Show *show();
  int round() const;

  GameState state() const;

  Match* activeMatch() const;

  MatchListModel* nextMatches() const;

private:
  void simulate();
  void nextMatch();

  void calculateNextMatches();
  void resetAvailableCharacters();

  GameState m_state;
  Match* m_activeMatch;
  Show *m_show;
  int m_round;
  QQueue<Character *> m_availableCharacters;
  MatchListModel* m_nextMatches;

public slots:
  void resetSimulation();
  void nextRound();
  void setShow(Show *show);
  void setRound(int round);

  void setState(GameState state);

  void setActiveMatch(Match *activeMatch);
  void onShowChanged();

signals:
  void showChanged();
  void roundChanged(int round);
  void stateChanged(GameState state);
  void activeMatchChanged();
};

#endif // GAMESIMULATION_H
