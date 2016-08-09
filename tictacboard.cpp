#include <QDebug>
#include "tictacboard.h"

TicTacBoard::TicTacBoard(QObject *parent)
    : QAbstractListModel(parent)
    , _gridSize(0)
{
    this->setGridSize(3);
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
#ifndef QT_NO_DEBUG
    // Display data in console
    for (int i = 0; i < this->_gridSize; i++)
    {
        qDebug () << this->_marks[i*this->_gridSize]
                  << this->_marks[i*this->_gridSize + 1]
                  << this->_marks[i*this->_gridSize + 2];
    }
#endif

    // Check winning for rows (1,2,3) ...
    this->checkSideCrosing(1, this->_gridSize, winningFields);
    if (!winningFields.isEmpty())
        return this->displayWinner(winningFields);

    // Check winning for columns (0, 3, 6) ...
    this->checkSideCrosing(this->_gridSize, 1, winningFields);
    if (!winningFields.isEmpty())
        return this->displayWinner(winningFields);

    // Check first diagonal winning (0, 4, 8)
    this->checkDiagonalCrossing(0,
                                this->_gridSize + 1, winningFields);
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

void TicTacBoard::setGridSize(int gridSize)
{
    if (this->_gridSize != gridSize)
    {
        this->_gridSize = gridSize;

        if (!this->_marks.isEmpty())
        {
            this->beginRemoveRows(QModelIndex(), 0, this->_marks.size() - 1);
            this->removeRows(0, this->_marks.size() - 1);
            this->endRemoveRows();

            this->_results.clear();
            this->_marks.clear();
        }

        int modelSize = this->_gridSize * this->_gridSize;
        for (int i = 0; i < modelSize; i++)
        {
            this->_marks << TicTacPlayer::MT_Empty;
            this->_results << false;
        }

        // Fill map with new model
        this->beginInsertRows(QModelIndex(), 0, this->_marks.size() - 1);
        this->insertRows(0, this->_marks.size() - 1);
        this->endInsertRows();

        emit this->gridSizeChanged(gridSize);
    }
}

void TicTacBoard::checkSideCrosing(int rowBase,
                                   int columnBase,
                                   QList<int> &winningFields) const
{
    TicTacPlayer::MarkTypes possibleWinner;
    TicTacPlayer::MarkTypes regionWinner;

    for (int i = 0; i < this->_gridSize; i++)
    {
        winningFields.clear();
        regionWinner = TicTacPlayer::MT_Empty;
        possibleWinner = TicTacPlayer::MT_Empty;

        for (int j = 0; j < this->_gridSize; j++)
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

//!
//! \brief TicTacBoard::displayWinner
//! \param winningFields list of winning fields
//! \return true
//!
bool TicTacBoard::displayWinner(const QList<int> &winningFields)
{
    for (int i = 0; i < winningFields.size(); i++)
        this->setData(this->index(winningFields[i]), true, Qt::DecorationRole);

    return true;
}
