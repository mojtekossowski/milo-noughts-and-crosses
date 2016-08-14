#ifndef TICTACBOARD_H
#define TICTACBOARD_H

#include <QAbstractListModel>
#include "tictacplayer.h"

//!
//! \brief The TicTacBoard class
//! Map of Noughts and Crossings - all necesasry data stored in 1d List
//! Access to element: cols/GridSize + rows%GridSize
//!
class TicTacBoard : public QAbstractListModel
{
    Q_OBJECT // clang static code analyser displays a lot of mess here
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
                 int role) override;

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
    QList <bool> _results; // Decoration role
    QList <TicTacPlayer::MarkTypes> _marks; // Display / edit role
};

#endif // TICTACBOARD_H
