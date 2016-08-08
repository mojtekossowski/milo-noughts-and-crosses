#ifndef TICTACENGINE_H
#define TICTACENGINE_H

#include <QObject>
#include "tictacboard.h"
#include "tictacplayer.h"

class TicTacEngine : public QObject
{
    Q_OBJECT
    Q_CLASSINFO ("Author", "Wojciech Ossowski")


public:
    explicit TicTacEngine(QObject *parent = 0);

    TicTacBoard *board() const;

signals:
    void firstPlayerScoreChanged(int score);
    void secondPlayerScoreChanged(int score);

public slots:
    void mark(int place);

private:
    int _currentPlayer;
    bool _active;
    QList<TicTacPlayer*> _players;
    TicTacBoard *_board;
};

#endif // TICTACENGINE_H
