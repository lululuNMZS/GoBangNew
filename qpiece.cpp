#include "qpiece.h"
#include <QtWidgets>

QPiece::QPiece()
{

}

QPiece::~QPiece()
{

}

void QPiece::setColour(int colour)
{
    pieceColour = colour;
}

void QPiece::setSize(int size)
{
    pieceSize = size;
}

void QPiece::setPos(QPoint pos)
{
    piecePos.setX(pos.rx());
    piecePos.setY(pos.ry());
}

int QPiece::getColour()
{
    return pieceColour;
}

int QPiece::getSize()
{
    return pieceSize;
}

QPoint QPiece::getPos()
{
    return piecePos;
}
