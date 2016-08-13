#include "tictacengine.h"
#include <QDebug>
#include <QtWidgets/QApplication>

TicTacEngine::TicTacEngine(QObject *parent)
    : QObject(parent)
    , _currentPlayer(0)
    , _active(false)
{
    this->_board = new TicTacBoard(this);

    // Handle grid size change
    this->connect(this->_board,     SIGNAL(gridSizeChanged(int)),
                  this,             SLOT(resetPoints()));

    // Create players and assign signal forwarding for score changes
    this->_players << new TicTacPlayer("Noughts", TicTacPlayer::MT_Noughted, this)
                   << new TicTacPlayer("Crosses", TicTacPlayer::MT_Crossed, this);
}

TicTacBoard *TicTacEngine::board() const
{
    return this->_board;
}

bool TicTacEngine::active() const
{
    return this->_active;
}

TicTacPlayer::MarkTypes TicTacEngine::victory() const
{
    return this->_victory;
}

TicTacPlayer::MarkTypes TicTacEngine::currentPlayer() const
{
    return this->_players.at(this->_currentPlayer)->playerMarkType();
}

TicTacPlayer *TicTacEngine::firstPlayer()
{
    return this->_players[0];
}

TicTacPlayer *TicTacEngine::secondPlayer()
{
    return this->_players[1];
}

void TicTacEngine::setActive(bool active)
{
    this->_active = active;
    emit this->activeChanged(active);
}

void TicTacEngine::setVictory(TicTacPlayer::MarkTypes victory)
{
    this->_victory = victory;
    emit this->victoryChanged(victory);

    this->setActive(false);
}

void TicTacEngine::mark(int place)
{
    // An 'active' flag is used to stop/pause
    // the game before user's mark action.
    // It's necessary to notify when win/draw occurs
    if (!this->_active)
    {
        this->setActive(!this->_active);
        this->_board->clearMap();
        return;
    }

    // Get current player
    TicTacPlayer *player = this->_players[this->_currentPlayer];

    // Try to set marking data
    if (this->_board->setData(this->_board->index(place),
                              player->playerMarkType(), Qt::EditRole))
    {
        // Explore winning fields
        // winningFields list contains model elements of winning stack
        QList <int> winningFields;
        if (this->_board->checkWinner(winningFields))
        {
            player->increaseScore();
            this->setVictory(player->playerMarkType());
        }
        else if (this->_board->checkDraw())
        {
            this->setVictory(TicTacPlayer::MT_Draw);
        }

        this->setCurrentPlayer((this->_currentPlayer + 1) % this->_players.size());
    }
}

void TicTacEngine::resetPoints()
{
    foreach (auto player, this->_players)
    {
        player->setScore(0);
        this->setVictory(TicTacPlayer::MT_Empty);
    }
}

void TicTacEngine::setCurrentPlayer(int currentPlayer)
{
    if (this->_currentPlayer != currentPlayer)
    {
        this->_currentPlayer = currentPlayer;
        emit this->currentPlayerChanged(currentPlayer);
    }
}
