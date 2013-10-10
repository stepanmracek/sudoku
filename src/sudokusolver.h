#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <QList>
#include "gamestate.h"

class SudokuSolver
{
public:
    static bool SolveRecursive(GameState &state, int &step);
};

#endif // SUDOKUSOLVER_H
