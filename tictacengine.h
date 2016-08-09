#ifndef TICTACENGINE_H
#define TICTACENGINE_H

#include <QObject>
#include "tictacboard.h"
#include "tictacplayer.h"

class TicTacEngine : public QObject
{
    Q_OBJECT
    Q_CLASSINFO ("Author", "Wojciech Ossowski")

    // Declare score properties
    Q_PROPERTY(int firstPlayerScore READ firstPlayerScore
               WRITE setFirstPlayerScore NOTIFY firstPlayerScoreChanged)

    Q_PROPERTY(int secondPlayerScore READ secondPlayerScore
               WRITE setSecondPlayerScore NOTIFY secondPlayerScoreChanged)

    // Declare name properties
    Q_PROPERTY(QString firstPlayerName READ firstPlayerName
               NOTIFY firstPlayerNameChanged)

    Q_PROPERTY(QString secondPlayerName READ secondPlayerName
               NOTIFY secondPlayerNameChanged)

    // Declare activity
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(int victory READ victory NOTIFY victoryChanged)

public:
    explicit TicTacEngine(QObject *parent = 0);

    TicTacBoard *board() const;

    int firstPlayerScore() const;
    int secondPlayerScore() const;

    QString firstPlayerName() const;
    QString secondPlayerName() const;

    bool active() const;
    int victory() const;

signals:
    void firstPlayerScoreChanged(int score);
    void secondPlayerScoreChanged(int score);

    void firstPlayerNameChanged(const QString &name);
    void secondPlayerNameChanged(const QString &name);

    void activeChanged(bool active);
    void victoryChanged(int victory);

public slots:
    void setFirstPlayerScore(int score);
    void setSecondPlayerScore(int score);
    void setActive(bool active);
    void setVictory(int victory);

    void mark(int place);
    void resetPoints();

private:
    int _currentPlayer;
    bool _active;
    int _victory;
    QList<TicTacPlayer*> _players;
    TicTacBoard *_board;
};

#endif // TICTACENGINE_H
