#ifndef TICTACPLAYER_H
#define TICTACPLAYER_H

#include <QObject>

class TicTacPlayer : public QObject
{
    Q_OBJECT
    Q_CLASSINFO ("Author", "Wojciech Ossowski")
    Q_ENUMS (MarkTypes)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)

public:
    enum MarkTypes {
        MT_Empty = 0,
        MT_Crossed = 1,
        MT_Noughted = 2
    };

    explicit TicTacPlayer(MarkTypes playerMarkType,
                          QObject *parent = 0);

    int score() const;
    QString name() const;
    MarkTypes playerMarkType() const;
    void increaseScore();

signals:
    void scoreChanged(int score);

public slots:
    void setScore(int score);
    void setName(const QString &name);
    void setPlayerMarkType(const MarkTypes &playerMarkType);

private:
    MarkTypes _playerMarkType;
    int _score;
    QString _name;
};

#endif // TICTACPLAYER_H
