#include "tictacplayer.h"

TicTacPlayer::TicTacPlayer(MarkTypes playerMarkType,
                           QObject *parent)
    : QObject (parent)
    , _playerMarkType (playerMarkType)
    , _score (0)
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
    this->_name = name;
}

TicTacPlayer::MarkTypes TicTacPlayer::playerMarkType() const
{
    return this->_playerMarkType;
}

void TicTacPlayer::increaseScore()
{
    this->setScore(this->_score++);
}

void TicTacPlayer::setPlayerMarkType(const MarkTypes &playerMarkType)
{
    this->_playerMarkType = playerMarkType;
}

