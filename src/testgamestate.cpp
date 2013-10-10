#include "testgamestate.h"

 #include <QtTest/QtTest>

#include "gamestate.h"

TestGameState::TestGameState(QObject *parent) :
    QObject(parent)
{
}

void TestGameState::isValidMove()
{
    QHash<Coord, int> task; task[Coord(0,0)] = 1;
    GameState state(task);

    QVERIFY(!state.isValidMove(Coord(0,1), 1));
    QVERIFY(!state.isValidMove(Coord(1,0), 1));
    QVERIFY(!state.isValidMove(Coord(1,1), 1));

    QVERIFY(state.isValidMove(Coord(0,1), 2));
    QVERIFY(state.isValidMove(Coord(1,0), 2));
    QVERIFY(state.isValidMove(Coord(1,1), 2));
}
