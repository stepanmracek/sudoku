/*#include "testgamestate.h"
#include <QtTest/QtTest>
QTEST_MAIN(TestGameState)*/

#include "sudokusolver.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QHash<Coord, int> state;
    state[Coord(0,0)] = 8;
    state[Coord(1,2)] = 3;
    state[Coord(1,3)] = 6;
    state[Coord(0,0)] = 8;
    state[Coord(2,1)] = 7;
    state[Coord(2,4)] = 9;
    state[Coord(2,6)] = 2;
    state[Coord(3,1)] = 5;
    state[Coord(3,5)] = 7;
    state[Coord(4,4)] = 4;
    state[Coord(4,5)] = 5;
    state[Coord(4,6)] = 7;
    state[Coord(5,3)] = 1;
    state[Coord(5,7)] = 3;
    state[Coord(6,2)] = 1;
    state[Coord(6,7)] = 6;
    state[Coord(6,8)] = 8;
    state[Coord(7,2)] = 8;
    state[Coord(7,3)] = 5;
    state[Coord(7,7)] = 1;
    state[Coord(8,1)] = 9;
    state[Coord(8,6)] = 4;


    GameState game(state);
    game.print();
    int step = 0;
    SudokuSolver::SolveRecursive(game, step);
    game.print();
    qDebug() << "Solved in" << step << "steps";
}
