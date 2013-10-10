#include "gamestate.h"

#include <QDebug>
#include <cassert>

GameState::GameState(const GameState &src) :
    field(src.field), fixed(src.fixed)
{

}

GameState::GameState(const QHash<Coord, int> &fixedItems)
{
    foreach (const Coord &coord, fixedItems.keys())
    {
        field[coord] = fixedItems[coord];
        fixed << coord;
    }
}

bool GameState::isValidMove(Coord coord, int newValue) const
{
    assert(!fixed.contains(coord));
    assert(newValue >= 1 && newValue <= MAX);
    assert(coord.first >= 0 && coord.first < MAX);
    assert(coord.second >= 0 && coord.second < MAX);

    // check row
    int row = coord.first;
    for (int col = 0; col < MAX; col++)
    {
        if (col == coord.second) continue;
        Coord probe(row, col);
        if (field.contains(probe) && (field[probe] == newValue))
            return false;
    }

    // check col
    int col = coord.second;
    for (int row = 0; row < MAX; row++)
    {
        if (row == coord.first) continue;
        Coord probe(row, col);
        if (field.contains(probe) && (field[probe] == newValue))
            return false;
    }

    // check rectangle
    int rowStart = (coord.first / 3) * 3;
    int colStart = (coord.second / 3) * 3;
    for (int row = rowStart; row < rowStart + 3; row++)
    {
        for (int col = colStart; col < colStart + 3; col++)
        {
            if (row == coord.first && col == coord.second) continue;
            Coord probe(row, col);
            if (field.contains(probe) && (field[probe] == newValue))
                return false;
        }
    }

    return true;
}

void GameState::applyMove(Coord coord, int newValue)
{
    assert(!fixed.contains(coord));
    assert(newValue >= 1 && newValue <= MAX);
    assert(coord.first >= 0 && coord.first < MAX);
    assert(coord.second >= 0 && coord.second < MAX);

    field[coord] = newValue;

    //const GameState &src = *this;
    //GameState newState(src);
    //newState.field[coord] = newValue;
    //return newState;
}

void GameState::unset(Coord coord)
{
    assert(!fixed.contains(coord));
    assert(coord.first >= 0 && coord.first < MAX);
    assert(coord.second >= 0 && coord.second < MAX);

    field.remove(coord);
}

Coord GameState::getFirstEmptyCoord()
{
    for (int col = 0; col < MAX; col++)
    {
        for (int row = 0; row < MAX; row++)
        {
            Coord probe(row, col);
            if (!field.contains(probe)) return probe;
        }
    }

    return Coord(-1, -1);
}

void GameState::print()
{
    QTextStream stream(stdout);

    for (int col = 0; col < MAX; col++)
    {
        for (int row = 0; row < MAX; row++)
        {
            Coord coord(col, row);
            if (!field.contains(coord))
                stream << "  ";
            else
                stream << field[coord] << " ";

        }
        stream << "\n";
    }
    stream << "------------------\n";
    stream.flush();
}
