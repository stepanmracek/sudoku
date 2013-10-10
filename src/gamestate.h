#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QPair>
#include <QHash>
#include <QSet>

typedef QPair<int, int> Coord;
#define MAX 9

class GameState
{
private:
    QHash<Coord, int> field;
    QSet<Coord> fixed;

public:
    GameState() {}
    GameState(const QHash<Coord, int> &fixedItems);
    GameState(const GameState &src);

    bool isValidMove(Coord coord, int newValue) const;
    void applyMove(Coord coord, int newValue);
    void unset(Coord coord);
    Coord getFirstEmptyCoord();
    bool isSolved() const { return field.count() == (MAX*MAX); }
    void print();
};

#endif // GAMESTATE_H
