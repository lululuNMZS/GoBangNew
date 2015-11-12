#include "qrobot.h"

#include <QtWidgets>

QRobot::QRobot()
{
    N = 15;
}

QRobot::~QRobot()
{

}

void QRobot::setPieveColour(int colour)
{
    piece = new QPiece;
    piece->setColour(colour);
    piece->setSize(35);
}

void QRobot::setBoardState(int (*temp)[15])
{
    boardState = temp;
}

int QRobot::getPieceColour()
{
    return piece->getColour();
}

void QRobot::algorithmGreed(int *total)
{
    if ( 0 == *total )
    {
        boardState[rand()&15][rand()&15] = this->piece->getColour();
        (*total)++;
        return;
    }

    vector<vector<int> > HumanState, ComputerState;
    vector<int> temp(N, 0);
    for (int i = 0; i < N; i++)
    {
        HumanState.push_back(temp);
        ComputerState.push_back(temp);
    }
    QPoint ps, ps1, ps2;

    for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (boardState[i][j] == 0)
                {
                    setScore(i, j, 1, HumanState);
                    setScore(i, j, 2, ComputerState);
                }
            }
        }

        int maxP = 0, maxC = 0; //计算机和人状态值的最大值
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (HumanState[i][j] > maxP)
                {
                    maxP = HumanState[i][j];
                    ps1.setX(i);
                    ps1.setY(j);
                }
                if (ComputerState[i][j] > maxC)
                {
                    maxC = ComputerState[i][j];
                    ps2.setX(i);
                    ps2.setY(j);
                }
            }
        }
        if (maxP >= maxC)
        {
            ps.setX(ps1.rx());
            ps.setY(ps1.ry());
        }
        else
        {
            ps.setX(ps2.rx());
            ps.setY(ps2.ry());
        }

        boardState[ps.rx()][ps.ry()] = this->piece->getColour();

        retract.setX(ps.rx());      //用于悔棋
        retract.setY(ps.ry());
        (*total)++;
        qDebug() << *total;
}

void QRobot::setScore(const int i, const int j, const int Who, vector<vector<int> > & State)
{
    int Another; //与要求的状态相对的另一方
    if (Who == 1)
    {
        Another = 2;
    }
    else if (Who == 2)
    {
        Another = 1;
    }
    else
    {
        return;
    }
    int bp[2], k, num, max = 0, temp = 0;

    //横向
    //向右
    bp[0] = 1; bp[1] = 1;
    num = 0;
    for (k = 1; k < N - i; k++)
    {
        if (boardState[i+k][j] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i+k][j] == 0)
        {
            bp[1] = 0;
            break;
        }
        if (boardState[i+k][j] == Another)
        {
            bp[1] = 1;
            break;
        }
    }
    //向左
    for (k = 1; k <= i; k++)
    {
        if (boardState[i-k][j] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i-k][j] == 0)
        {
            bp[0] = 0;
            break;
        }
        if (boardState[i-k][j] == Another)
        {
            bp[0] = 1;
            break;
        }
    }
    //调用评分函数
    temp = p_Score(num, bp);
    max += temp;

    //纵向
    bp[0] = 1; bp[1] = 1;
    num = 0;
    //向下
    for (k = 1; k < N - j; k++)
    {
        if (boardState[i][j+k] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i][j+k] == 0)
        {
            bp[1] = 0;
            break;
        }
        if (boardState[i][j+k] == Another)
        {
            bp[1] = 1;
            break;
        }
    }
    //向上
    for (k = 1; k <= j; k++)
    {
        if (boardState[i][j-k] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i][j-k] == 0)
        {
            bp[0] = 0;
            break;
        }
        if (boardState[i][j-k] == Another)
        {
            bp[0] = 1;
            break;
        }
    }
    temp = p_Score(num, bp);
    max += temp;

    //从左上到右下
    bp[0] = 1; bp[1] = 1;
    num = 0;

    //下
    for (k = 1; k < N-i && k < N-j; k++)
    {
        if (boardState[i+k][j+k] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i+k][j+k] == 0)
        {
            bp[1] = 0;
            break;
        }
        if (boardState[i+k][j+k] == Another)
        {
            bp[1] = 1;
            break;
        }
    }
    //上
    for (k = 1; k <= j && k <= i; k++)
    {
        if (boardState[i-k][j-k] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i-k][j-k] == 0)
        {
            bp[0] = 0;
            break;
        }
        if (boardState[i-k][j-k] == Another)
        {
            bp[0] = 1;
            break;
        }
    }
    temp = p_Score(num, bp);
    max += temp;

    //从右上到左下
    bp[0] = 1; bp[1] = 1;
    num = 0;
    //下
    for (k = 1; k < N-j && k <= i; k++)
    {
        if (boardState[i-k][j+k] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i-k][j+k] == 0)
        {
            bp[1] = 0;
            break;
        }
        if (boardState[i-k][j+k] == Another)
        {
            bp[1] = 1;
            break;
        }
    }
    //上
    for (k = 1; k <= j && k < N-i; k++)
    {
        if (boardState[i+k][j-k] == Who)
        {
            num++;
            continue;
        }
        if (boardState[i+k][j-k] == 0)
        {
            bp[0] = 0;
            break;
        }
        if (boardState[i+k][j-k] == Another)
        {
            bp[0] = 1;
            break;
        }
    }
    temp = p_Score(num, bp);
    max += temp;

    if (max > State[i][j])
    {
        State[i][j] = max;
    }
}

//实际的评分函数
int QRobot::p_Score(int num, int bp[])
{
    int max = 0;
    if (num >= 4)
    {
        max += 10000; //成五
    }
    else if (num == 3)
    {
        if (bp[1] == 1 && bp[0] == 1) //不成五
        {
            max += 0;
        }
        else if (bp[1] == 0 && bp[0] == 0) //活四
        {
            max += 3000;
        }
        else
        {
            max += 900; //冲四
        }
    }
    else if (num == 2)
    {
        if (bp[0] == 0 && bp[1] == 0)
        {
            max += 460; //活三
        }
        else if (bp[0] == 1 && bp[1] == 1)
        {
            max += 0; //不成五
        }
        else
        {
            max += 30; //死三
        }
    }
    else if (num == 1)
    {
        if (bp[0] == 0 && bp[1] == 0)
        {
            max += 45;  //活二
        }
        else if (bp[0] == 1 && bp[1] == 1)
        {
            max += 0;
        }
        else
        {
            max += 5;
        }
    }
    else if (num == 0)
    {
        if (bp[0] == 0 && bp[1] == 0)
        {
            max += 3;
        }
        else if (bp[0] == 1 && bp[1] == 1)
        {
            max += 0;
        }
        else
        {
            max += 1;
        }
    }
    return max;
}

QPoint* QRobot::getRetract()
{
    return &retract;
}
