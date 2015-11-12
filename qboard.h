#ifndef QBOARD_H
#define QBOARD_H

#include <QObject>
#include <QtWidgets>

#define squareNum 15      //格子数 = squareNum * squareNum
#define squareSize 35     //格子大小，以像素为单位

class QBoard
{
public:
    QBoard();
    ~QBoard();

private:
    int (*pBoard)[squareNum];           //建立二维数组指针，以便传递
    int total;                          //棋盘上棋子总数

public:
    int (*getBoard())[squareNum] ;
    int* getTotal();
};

#endif // QBOARD_H
