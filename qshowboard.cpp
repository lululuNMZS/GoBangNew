#include "qshowboard.h"
#include "ui_qshowboard.h"
#include <QtWidgets>

QShowBoard::QShowBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QShowBoard)
{
    ui->setupUi(this);
    gameStart = 0;
}

QShowBoard::~QShowBoard()
{
    delete ui;
}

void QShowBoard::setBoard(QBoard &board)
{
    boardState = board.getBoard();
}

void QShowBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QRect rect(0,0, (squareNum+1)*squareSize,(squareNum+1)*squareSize);
    QPixmap pixmap;
    pixmap.load("/Users/lxl/Documents/资源/木质纹理.jpg");

    painter.drawPixmap(rect, pixmap);

    painter.setPen(QPen(Qt::black,2));
    for ( int i = 1 ; i <= 15 ; i++ )           //画格子
    {
        painter.drawLine(squareSize, squareSize*i, squareSize*squareNum, squareSize*i);
        painter.drawLine(squareSize*i, squareSize, squareSize*i, squareSize*squareNum);
    }


    /*--------------------画棋子-------------------*/
    QPointF center ;
    for ( int i = 0 ; i < 15 ; i++ )
    {
        for ( int j = 0 ; j < 15 ; j++ )
        {
            if ( 1 == boardState[i][j] )
            {
                QBrush blackBrush(Qt::black);
                painter.setBrush(blackBrush);

                center.setX(i*squareSize+squareSize);
                center.setY(j*squareSize+squareSize);
                painter.drawEllipse(center, squareSize/4*1.6, squareSize/4*1.6);
            }
            else if ( 2 == boardState[i][j] )
            {
                QBrush whiteBrush(Qt::white);
                painter.setBrush(whiteBrush);

                center.setX(i*squareSize+squareSize);
                center.setY(j*squareSize+squareSize);
                painter.drawEllipse(center, squareSize/4*1.6, squareSize/4*1.6);
            }
        }
    }
}

void QShowBoard::mousePressEvent(QMouseEvent *event)
{
    if ( 0 == gameStart )
    {
        return;
    }

    int x = event->pos().rx();
    int y = event->pos().ry();
    if ( x < squareSize/2 || x >= squareSize*squareNum + squareSize/2
        || y < squareSize/2 || y >= squareSize*squareNum + squareSize/2 )        //如果左击不在范围内，则没动作
    {
        return ;
    }

    if ( event->button() == Qt::LeftButton )
    {
        int i = (x-squareSize/2)/squareSize ;
        int j = (y-squareSize/2)/squareSize ;

        if ( 0 != boardState[i][j] )        //若该点已有棋子，则返回
        {
            return ;
        }
        playerPoint.setX(i);
        playerPoint.setY(j);


        this->sendPosChangedSignal();
        qDebug() << i << j;
    }
}

void QShowBoard::setGameStart(int isStart)
{
    gameStart = isStart;
}

QPoint QShowBoard::getPoint()
{
    return playerPoint;
}

void QShowBoard::sendPosChangedSignal()
{
    emit posChangedSignal();
}
