#include "qplayer.h"

QPlayer::QPlayer()
{

}

QPlayer::~QPlayer()
{

}

void QPlayer::setPieveColour(int colour)
{
    piece = new QPiece;
    piece->setColour(colour);
    piece->setSize(35);
}

int QPlayer::getPieceColour()
{
    return piece->getColour();
}

void QPlayer::playGame(int (*boardState)[15], QPoint pos, int* total)
{
    boardState[pos.rx()][pos.ry()] = this->piece->getColour();

    retract.setX(pos.rx());     //悔棋的点
    retract.setY(pos.ry());

    (*total)++;
}

QPoint* QPlayer::getRetract()
{
    return &retract;
}
