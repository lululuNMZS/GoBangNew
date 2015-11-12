#ifndef QPLAYER_H
#define QPLAYER_H

#include <QObject>
#include "qpiece.h"
#include "qboard.h"

class QPlayer
{
public:
    QPlayer();
    ~QPlayer();

private:
    QPiece *piece;
    QPoint retract;     //悔棋点

public:
    void setPieveColour(int);
    int getPieceColour();
    void playGame(int (*)[15], QPoint, int* total);         //落子

    QPoint* getRetract();
};

#endif // QPLAYER_H
