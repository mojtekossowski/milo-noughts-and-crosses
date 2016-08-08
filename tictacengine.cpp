#include "tictacengine.h"
#include <QDebug>
#include <QtWidgets/QApplication>

TicTacEngine::TicTacEngine(QObject *parent)
    : QObject(parent)
    , _currentPlayer(0)
    , _active(false)
{
    this->_board = new TicTacBoard(this);

    this->_players << new TicTacPlayer(TicTacPlayer::MT_Noughted, this);
    this->_players << new TicTacPlayer(TicTacPlayer::MT_Crossed, this);
}

TicTacBoard *TicTacEngine::board() const
{
    return this->_board;
}

void TicTacEngine::mark(int place)
{
    if (!this->_active)
    {
        this->_active = !this->_active;
        this->_board->clearMap();
        return;
    }

    // Get current player
    TicTacPlayer *player = this->_players[this->_currentPlayer];

    // Try to set data
    if (this->_board->setData(this->_board->index(place),
                              player->playerMarkType(), Qt::EditRole))
    {
        // Explore winning fields
        QList <int> winningFields;
        if (this->_board->checkWinner(winningFields))
        {
            player->increaseScore();
            this->_active = false;
        }
        else if (this->_board->checkDraw())
        {
            this->_active = false;
        }

        // Change player
        this->_currentPlayer = (this->_currentPlayer + 1) % this->_players.size();
    }
}
