#ifndef TICTACENGINE_H
#define TICTACENGINE_H

#include <QObject>
#include "tictacboard.h"
#include "tictacplayer.h"

class TicTacEngine : public QObject
{
    Q_OBJECT
    Q_CLASSINFO ("Author", "Wojciech Ossowski")

    // Declare activity
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(int victory READ victory NOTIFY victoryChanged)
    Q_PROPERTY(int currentPlayer READ currentPlayer
               WRITE setCurrentPlayer NOTIFY currentPlayerChanged)

public:
    explicit TicTacEngine(QObject *parent = 0);

    TicTacBoard *board() const;

    bool active() const;
    TicTacPlayer::MarkTypes victory() const;

    TicTacPlayer::MarkTypes currentPlayer() const;
    TicTacPlayer *firstPlayer();
    TicTacPlayer *secondPlayer();

signals:
    void activeChanged(bool active);
    void victoryChanged(TicTacPlayer::MarkTypes victory);
    void currentPlayerChanged(int playerId);

public slots:
    void setActive(bool active);
    void setVictory(TicTacPlayer::MarkTypes victory);
    void setCurrentPlayer(int currentPlayer);

    void mark(int place);
    void resetPoints();

private:
    int _currentPlayer;
    bool _active;
    TicTacPlayer::MarkTypes _victory;
    QList<TicTacPlayer*> _players;
    TicTacBoard *_board;
};

#endif // TICTACENGINE_H
