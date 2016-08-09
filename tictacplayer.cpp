#include "tictacplayer.h"

TicTacPlayer::TicTacPlayer(QString name,
                           MarkTypes playerMarkType,
                           QObject *parent)
    : QObject (parent)
    , _playerMarkType (playerMarkType)
    , _score (0)
    , _name(name)
{

}

int TicTacPlayer::score() const
{
    return this->_score;
}

void TicTacPlayer::setScore(int score)
{
    if (this->_score != score)
    {
        this->_score = score;
        emit this->scoreChanged(score);
    }
}

QString TicTacPlayer::name() const
{
    return this->_name;
}

void TicTacPlayer::setName(const QString &name)
{
    if (this->_name != name)
    {
        this->_name = name;
        emit this->nameChanged(name);
    }
}

TicTacPlayer::MarkTypes TicTacPlayer::playerMarkType() const
{
    return this->_playerMarkType;
}

void TicTacPlayer::increaseScore()
{
    this->setScore(this->_score + 1);
}

void TicTacPlayer::setPlayerMarkType(const MarkTypes &playerMarkType)
{
    this->_playerMarkType = playerMarkType;
}

