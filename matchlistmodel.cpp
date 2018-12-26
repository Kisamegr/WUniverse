#include "matchlistmodel.h"

MatchListModel::MatchListModel(QObject *parent) : QAbstractListModel (parent) {
}

QHash<int, QByteArray> MatchListModel::roleNames() const {
  static QHash<int, QByteArray> roles {
    { Match::FirstPlayer,  "firstPlayer" },
    { Match::SecondPlayer, "secondPlayer" },
    { Match::Result,       "result" }
  };

  return roles;
}

int MatchListModel::rowCount(const QModelIndex &/*parent*/) const {
  return m_matches.count();
}

QVariant MatchListModel::data(const QModelIndex &index, int role) const {
  if(index.row() >= 0 && index.row() < m_matches.count()) {
    const Match* match = m_matches[index.row()];

    switch (role) {
    case Match::FirstPlayer:
      return QVariant::fromValue(match->firstPlayer());
    case Match::SecondPlayer:
      return QVariant::fromValue(match->secondPlayer());
    case Match::Result:
      return QVariant::fromValue(match->result());
    default:
      return QVariant();
    }
  }
  return QVariant();
}

void MatchListModel::clear() {
  beginResetModel();
  m_matches.clear();
  endResetModel();
}

void MatchListModel::enqueueMatch(Match *match) {
  beginInsertRows(QModelIndex(), m_matches.count(), m_matches.count());
  m_matches.enqueue(match);
  endInsertRows();
}

Match *MatchListModel::dequeueMatch() {
  beginRemoveRows(QModelIndex(), 0, 0);
  Match *match = m_matches.dequeue();
  endRemoveRows();

  return match;
}
