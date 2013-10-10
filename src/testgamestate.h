#ifndef TESTGAMESTATE_H
#define TESTGAMESTATE_H

#include <QObject>

class TestGameState : public QObject
{
    Q_OBJECT
public:
    explicit TestGameState(QObject *parent = 0);

private slots:
    void isValidMove();

};

#endif // TESTGAMESTATE_H
