#ifndef QPIECE_H
#define QPIECE_H

#include <QObject>
#include <QPoint>

class QPiece : public QObject
{
    Q_OBJECT
public:
    QPiece();
    ~QPiece();

private:
    int pieceColour;
    int pieceSize;
    QPoint piecePos;        //对应棋盘上的坐标，比如(0,0), (1,3)

public:
    void setColour(int);
    void setSize(int);
    void setPos(QPoint);

    int getColour();
    int getSize();
    QPoint getPos();
};

#endif // QPIECE_H
