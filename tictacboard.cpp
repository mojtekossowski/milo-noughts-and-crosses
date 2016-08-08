#include <QDebug>
#include "tictacboard.h"

TicTacBoard::TicTacBoard(QObject *parent)
    : QAbstractListModel(parent)
    , _gridSize(3)
{
    int modelSize = this->_gridSize * this->_gridSize;
    for (int i = 0; i < modelSize; i++)
    {
        this->_marks << TicTacPlayer::MT_Empty;
        this->_results << false;
    }

    // Fill map with new model
    beginInsertRows(QModelIndex(), 0, this->_marks.size() - 1);
    insertRows(0, this->_marks.size() - 1);
    endInsertRows();
}

int TicTacBoard::rowCount(const QModelIndex &/*parent*/) const
{
    return this->_marks.size();
}

QVariant TicTacBoard::data(const QModelIndex &index,
                           int role) const
{
    if (!index.isValid())
        return QVariant();
    else if (role == Qt::DisplayRole)
        return this->_marks[index.row()];
    else if (role == Qt::DecorationRole)
        return this->_results[index.row()];
    else
        return QVariant();
}

bool TicTacBoard::setData(const QModelIndex &index,
                          const QVariant &value,
                          int role)
{
    if (!index.isValid())
        return false;

    if (role == Qt::EditRole || role == Qt::DisplayRole)
    {
        bool ok = false;
        TicTacPlayer::MarkTypes mark = (TicTacPlayer::MarkTypes) value.toInt(&ok);

        if (ok)
        {
            if (this->_marks[index.row()] != TicTacPlayer::MT_Empty
                && role != Qt::DisplayRole)
                return false;

            this->_marks[index.row()] = mark;
            emit dataChanged(index, index);

            return true;
        }
    }
    else if (role == Qt::DecorationRole)
    {
        this->_results[index.row()] = value.toBool();
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

bool TicTacBoard::checkWinner(QList<int> &winningFields)
{
    // Just for debug :3
    for (int i = 0; i < this->_gridSize; i++)
    {
        qDebug () << this->_marks[i*this->_gridSize]
                  << this->_marks[i*this->_gridSize + 1]
                  << this->_marks[i*this->_gridSize + 2];
    }

    // Check winning for rows (1,2,3) ...
    this->checkSideCrosing(0, 1, this->_gridSize, winningFields);
    if (!winningFields.isEmpty())
        return this->displayWinner(winningFields);

    // Check winning for columns (0, 3, 6) ...
    this->checkSideCrosing(0, this->_gridSize, 1, winningFields);
    if (!winningFields.isEmpty())
        return this->displayWinner(winningFields);

    // Check first diagonal winning (0, 4, 8)
    this->checkDiagonalCrossing(0, this->_gridSize + 1, winningFields);
    if (!winningFields.isEmpty())
        return this->displayWinner(winningFields);

    // Check second diagonal winning (6, 4, 0)
    this->checkDiagonalCrossing(this->_gridSize - 1,
                                this->_gridSize - 1, winningFields);
    if (!winningFields.isEmpty())
        return this->displayWinner(winningFields);

    return false;
}

bool TicTacBoard::checkDraw() const
{
    for (int i = 0; i < this->_marks.size(); i++)
    {
        if (this->_marks[i] != TicTacPlayer::MT_Empty)
            continue;
        else
            return false;
    }
    return true;
}

void TicTacBoard::clearMap()
{
    // Set default data
    for (int i = 0; i < this->_marks.size(); i++)
    {
        this->setData(this->index(i), TicTacPlayer::MT_Empty, Qt::DisplayRole);
        this->setData(this->index(i), false, Qt::DecorationRole);
    }
}

void TicTacBoard::checkSideCrosing(int beginning,
                                   int rowBase,
                                   int columnBase,
                                   QList<int> &winningFields) const
{
    TicTacPlayer::MarkTypes possibleWinner;
    TicTacPlayer::MarkTypes regionWinner;

    for (int i = beginning; i < this->_gridSize; i++)
    {
        winningFields.clear();
        regionWinner = TicTacPlayer::MT_Empty;
        possibleWinner = TicTacPlayer::MT_Empty;

        for (int j = beginning; j < this->_gridSize; j++)
        {
            int index = i*rowBase + j*columnBase;
            regionWinner = this->_marks[index];

            if (regionWinner == TicTacPlayer::MT_Empty)
                break;

            if (j == 0)
                possibleWinner = regionWinner;

            if (regionWinner != possibleWinner)
                break;

            winningFields << index;
        }

        if (winningFields.size() == this->_gridSize)
            break;
    }

    if (winningFields.size() != this->_gridSize)
        winningFields.clear();
}

void TicTacBoard::checkDiagonalCrossing(int beginning,
                                        int increment,
                                        QList<int> &winningFields) const
{
    TicTacPlayer::MarkTypes possibleWinner = TicTacPlayer::MT_Empty;
    TicTacPlayer::MarkTypes regionWinner = TicTacPlayer::MT_Empty;

    for (int i = beginning; i < this->_marks.size(); i+= increment)
    {
        regionWinner = this->_marks[i];

        if (regionWinner == TicTacPlayer::MT_Empty)
            break;

        if (i == beginning)
            possibleWinner = regionWinner;

        if (regionWinner != possibleWinner)
            break;

        winningFields << i;
    }

    if (winningFields.size() != this->_gridSize)
        winningFields.clear();
}

bool TicTacBoard::displayWinner(const QList<int> &winningFields)
{
    for (int i = 0; i < winningFields.size(); i++)
        this->setData(this->index(winningFields[i]), true, Qt::DecorationRole);

    return true;
}
