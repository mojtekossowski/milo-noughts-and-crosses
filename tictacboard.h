#ifndef TICTACBOARD_H
#define TICTACBOARD_H

#include <QAbstractListModel>
#include "tictacplayer.h"

class TicTacBoard : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int gridSize READ gridSize WRITE setGridSize NOTIFY gridSizeChanged)

public:
    explicit TicTacBoard(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;

    // QAbstractItemModel interface
    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role);

    int gridSize () const {return this->_gridSize;}

    bool checkWinner(QList<int> &winningFields);
    bool checkDraw() const;

signals:
    void gridSizeChanged(int gridSize);

public slots:
    void clearMap();
    void setGridSize(int gridSize);

private:
    void checkSideCrosing(int rowBase,
                          int columnBase,
                          QList<int> &winningFields) const;

    void checkDiagonalCrossing(int beginning,
                               int increment,
                               QList<int> &winningFields) const;

    bool displayWinner(const QList<int> &winningFields);

private:
    int _gridSize;
    QList <bool> _results;
    QList <TicTacPlayer::MarkTypes> _marks;
};

#endif // TICTACBOARD_H
