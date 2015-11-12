#ifndef QROBOT_H
#define QROBOT_H

#include <QObject>
#include "qpiece.h"

using namespace std;

class QRobot
{
public:
    QRobot();
    ~QRobot();

private:
    int N;
    int (*boardState)[15];
    QPiece *piece;
    QPoint retract;     //悔棋点

public:
    void setPieveColour(int);
    void setBoardState(int (*)[15]);
    int getPieceColour();
    QPoint* getRetract();

    void setScore(const int i, const int j, const int who, vector<vector<int> > & State);
    int p_Score(int num, int bp[]);

    void algorithmGreed(int *);          //贪心算法
};

#endif // QROBOT_H
