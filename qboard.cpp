#include "qboard.h"

QBoard::QBoard()
{
/*
    QVector<QVector<int> >boardState;
    QVector<int> temp(15,0);
    for ( int i = 0 ; i < 15 ; i++ )
    {
        boardState.push_back(temp);
    }
    */

    pBoard = new int[squareNum][squareNum];             //初始化二维数组
    for ( int i = 0 ; i < squareNum ; i++ )
    {
        for ( int j = 0 ; j < 15 ; j++ )
        {
            pBoard[i][j] = 0 ;
        }
    }

    total = 0;
}

QBoard::~QBoard()
{

}

int ( *QBoard::getBoard() )[squareNum]
{
    return pBoard;
}

int* QBoard::getTotal()
{
    return &total;
}
