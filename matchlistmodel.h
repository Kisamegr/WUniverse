#ifndef MATCHLISTMODEL_H
#define MATCHLISTMODEL_H

#include <QAbstractListModel>
#include <QQueue>
#include "match.h"

class MatchListModel : public QAbstractListModel {
  Q_OBJECT

  QQueue<Match *> m_matches;

public:
  MatchListModel(QObject *parent = nullptr);

  QHash<int, QByteArray> roleNames() const;
  int rowCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  void clear();
  void enqueueMatch(Match *match);
  Match *dequeueMatch();
};

#endif // MATCHLISTMODEL_H
