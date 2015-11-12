#ifndef QSHOWBOARD_H
#define QSHOWBOARD_H

#include "qboard.h"
#include <QWidget>
#include "qjudge.h"
#include "qplayer.h"
#include "qrobot.h"

#define squareNum 15
#define squareSize 35

namespace Ui {
class QShowBoard;
}

class QShowBoard : public QWidget
{
    Q_OBJECT

public:
    explicit QShowBoard(QWidget *parent = 0);
    ~QShowBoard();

private:
    Ui::QShowBoard *ui;

private:
    int gameStart;          //控制鼠标左击事件，1为可以左击，0为不可
    QPoint playerPoint;     //返回mousePressEvent事件中，对应棋盘的点击位置

    int (*boardState)[squareNum];   //用来接收数组信息

protected:
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent *);

public:
    void setBoard(QBoard &board);
    void setGameStart(int);

    QPoint getPoint();      //鼠标事件落子位置的接口

signals:
    void posChangedSignal();

private:
    void sendPosChangedSignal();    //用来发信号

};

#endif // QSHOWBOARD_H
