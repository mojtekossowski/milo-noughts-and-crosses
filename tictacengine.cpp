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
    auto player1 = new TicTacPlayer("Noughts", TicTacPlayer::MT_Noughted, this);

    this->connect(player1,  SIGNAL(scoreChanged(int)),
                  this,     SIGNAL(firstPlayerScoreChanged(int)));

    this->connect(player1,  SIGNAL(nameChanged(QString)),
                  this,     SIGNAL(firstPlayerNameChanged(QString)));


    auto player2 = new TicTacPlayer("Crosses", TicTacPlayer::MT_Crossed, this);

    this->connect(player2,  SIGNAL(scoreChanged(int)),
                  this,     SIGNAL(secondPlayerScoreChanged(int)));

    this->connect(player2,  SIGNAL(nameChanged(QString)),
                  this,     SIGNAL(secondPlayerNameChanged(QString)));

    // Push players into players list
    this->_players << player1;
    this->_players << player2;
}

TicTacBoard *TicTacEngine::board() const
{
    return this->_board;
}

int TicTacEngine::firstPlayerScore() const
{
    return this->_players[0]->score();
}

int TicTacEngine::secondPlayerScore() const
{
    return this->_players[1]->score();
}

QString TicTacEngine::firstPlayerName() const
{
    return this->_players[0]->name();
}

QString TicTacEngine::secondPlayerName() const
{
    return this->_players[1]->name();
}

bool TicTacEngine::active() const
{
    return this->_active;
}

int TicTacEngine::victory() const
{
    return this->_victory;
}

void TicTacEngine::setFirstPlayerScore(int score)
{
    this->_players[0]->setScore(score);
}

void TicTacEngine::setSecondPlayerScore(int score)
{
    this->_players[1]->setScore(score);
}

void TicTacEngine::setActive(bool active)
{
    this->_active = active;
    emit this->activeChanged(active);
}

void TicTacEngine::setVictory(int victory)
{
    this->_victory = victory;
    emit this->victoryChanged(victory);

    this->setActive(false);
}

void TicTacEngine::mark(int place)
{
    // An 'active' flag is used to stop/pause the game
    // before user's mark action. It's necessary to
    // notify after win/draw
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
            this->setVictory(0);
        }

        // Change player
        this->_currentPlayer = (this->_currentPlayer + 1) % this->_players.size();
    }
}

void TicTacEngine::resetPoints()
{
    foreach (auto player, this->_players)
    {
        player->setScore(0);
        this->setVictory(-1);
    }
}
