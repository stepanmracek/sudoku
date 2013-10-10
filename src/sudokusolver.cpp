#include "sudokusolver.h"
#include <QDebug>

bool SudokuSolver::SolveRecursive(GameState &state, int &step)
{
    step++;

    if (step % 250000 == 0)
        qDebug() << "steps:" << step;

    Coord probe = state.getFirstEmptyCoord();
    if (probe.first == -1 && probe.second == -1)
    {
        return true;
    }

    for (int newValue = 1; newValue <= MAX; newValue++)
    {
        if (state.isValidMove(probe, newValue))
        {
            state.applyMove(probe, newValue);

            if (SolveRecursive(state, step))
            {
                return true;
            }

            state.unset(probe);
        }
    }

    return false;
}
