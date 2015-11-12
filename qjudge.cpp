#include "qjudge.h"

QJudge::QJudge()
{

}

QJudge::~QJudge()
{

}

bool QJudge::whoWin( int (*boardState)[15] )
{
    int state = 0;

    for ( int x = 0 ; x < 15 ; x++ )
    {
        for ( int y = 0 ; y < 15 ; y++ )
        {
            if ( 0 == boardState[x][y] )
            {
                continue;
            }
            for ( int i = 0 ; i < 4 ; i++ )
            {
                int k,j;
                switch (i)
                {
                case 0: //横向
                    k = x+1;
                    while (k < 15 && boardState[k][y] == boardState[x][y])
                    {
                        state++;
                        k++;
                    }
                    if (state >= 4)
                    {

                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;

                case 1: //竖向
                    j = y + 1; //从上往下
                    while (j < 15 && boardState[x][j] == boardState[x][y])
                    {
                        state++;
                        j++;
                    }
                    if (state >= 4)
                    {
                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;

                case 2: //左上到右下
                    k = x + 1;
                    j = y + 1;
                    while (k < 15 && j < 15 && boardState[k][j] == boardState[x][y])
                    {
                        state++;
                        k++;
                        j++;
                    }
                    if (state >= 4)
                    {

                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;

                case 3: //右上到左下
                    k = x - 1;
                    j = y + 1;
                    while (k >= 0 && j < 15 && boardState[k][j] == boardState[x][y])
                    {
                        state++;
                        k--;
                        j++;
                    }
                    if (state >= 4)
                    {

                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;
                default:
                    break;

                }
            }
        }
    }
    return false;
}

bool QJudge::prohibit(int (*boardState)[15])
{
    int state = 0;

    for ( int x = 0 ; x < 15 ; x++ )
    {
        for ( int y = 0 ; y < 15 ; y++ )
        {
            if ( 0 == boardState[x][y] )
            {
                continue;
            }
            for ( int i = 0 ; i < 4 ; i++ )         //六子长连禁手
            {
                int k,j;
                switch (i)
                {
                case 0: //横向
                    k = x+1;
                    while (k < 15 && boardState[k][y] == boardState[x][y])
                    {
                        state++;
                        k++;
                    }

                    if (state >= 5)     //6子长连禁手
                    {
                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;

                case 1: //竖向
                    j = y + 1; //从上往下
                    while (j < 15 && boardState[x][j] == boardState[x][y])
                    {
                        state++;
                        j++;
                    }
                    if (state >= 5)
                    {
                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;

                case 2: //左上到右下
                    k = x + 1;
                    j = y + 1;
                    while (k < 15 && j < 15 && boardState[k][j] == boardState[x][y])
                    {
                        state++;
                        k++;
                        j++;
                    }
                    if (state >= 5)
                    {

                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;

                case 3: //右上到左下
                    k = x - 1;
                    j = y + 1;
                    while (k >= 0 && j < 15 && boardState[k][j] == boardState[x][y])
                    {
                        state++;
                        k--;
                        j++;
                    }
                    if (state >= 5)
                    {

                        return true;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;
                default:
                    break;

                }
            }

            if (liveThree(boardState, x, y))         //双活三禁手
            {
                return true;
            }

            if (doubleFour(boardState, x, y))       //双4禁手
            {
                return true;
            }
        }
    }
    return false;
}

bool QJudge::liveThree(int (*boardState)[15], int x, int y)      //双活三禁手
{
    int k,j;
    int state;
    int liveThreeNum = 0;

    if (0 == boardState[x+1][y] && x+1 < 15)    //左
    {
        state = 0;
        k = x-1;
        while (k >= 0 && boardState[k][y] == boardState[x][y])
        {
            state++;
            k--;
        }
        if ( state == 2 && boardState[x-3][y] == 0 && x-3 >= 0)     //判断活3
        {
            liveThreeNum++;
        }
    }
    if (0 == boardState[x-1][y] && x-1 >= 0)    //右
    {
        state = 0;
        k = x+1;
        while (k < 15 && boardState[k][y] == boardState[x][y])
        {
            state++;
            k++;
        }
        if ( state == 2 && boardState[x+3][y] == 0 && x+3 < 15)
        {
            liveThreeNum++;
        }
    }
    if (0 == boardState[x][y+1] && y+1 < 15)    //上
    {
        state = 0;
        k = y-1;
        while (k >= 0 && boardState[x][k] == boardState[x][y])
        {
            state++;
            k--;
        }
        if ( state == 2 && boardState[x][y-3] == 0 && y-3 >= 0)
        {
            liveThreeNum++;
        }
    }
    if (0 == boardState[x][y-1] && y-1 >= 0)    //下
    {
        state = 0;
        k = y+1;
        while (k < 15 && boardState[x][k] == boardState[x][y])
        {
            state++;
            k++;
        }
        if ( state == 2 && boardState[x][y+3] == 0 && y+3 < 15)
        {
            liveThreeNum++;
        }
    }
    if (0 == boardState[x+1][y+1] && x+1 < 15 && y+1 < 15)    //左上
    {
        state = 0;
        k = x-1;
        j = y-1;
        while (k >= 0 && j >= 0 && boardState[k][j] == boardState[x][y])
        {
            state++;
            k--;
            j--;
        }
        if ( state == 2 && boardState[x-3][y-3] == 0 && x-3 >= 0 && y-3 >= 0)
        {
            liveThreeNum++;
        }
    }
    if (0 == boardState[x-1][y-1] && x-1 >= 0 && y-1 >= 0)    //右下
    {
        state = 0;
        k = x+1;
        j = y+1;
        while (k < 15 && j < 15 && boardState[k][j] == boardState[x][y])
        {
            state++;
            k++;
            j++;
        }
        if ( state == 2 && boardState[x+3][y+3] == 0 && x+3 < 15 && y+3 < 15)
        {
            liveThreeNum++;
        }
    }
    if (0 == boardState[x-1][y+1] && x-1 >= 0 && y+1 < 15)    //右上
    {
        state = 0;
        k = x+1;
        j = y-1;
        while (k < 15 && j >= 0 && boardState[k][j] == boardState[x][y])
        {
            state++;
            k++;
            j--;
        }
        if ( state == 2 && boardState[x+3][y-3] == 0 && x+3 < 15 && y-3 >= 0)
        {
            liveThreeNum++;
        }
    }
    if (0 == boardState[x+1][y-1] && x+1 < 15 && y-1 >=0)    //左下
    {
        state = 0;
        k = x-1;
        j = y+1;
        while (k >= 0 && j < 15 && boardState[k][j] == boardState[x][y])
        {
            state++;
            k--;
            j++;
        }
        if ( state == 2 && boardState[x-3][y+3] == 0 && x-3 >= 0 && y+3 < 15)
        {
            liveThreeNum++;
        }
    }

    if ( liveThreeNum >= 2 )
    {
        return true;
    }
    return false;
}

bool QJudge::doubleFour(int (*boardState)[15], int x, int y)    //双4禁手
{
    int k,j;
    int statePiece, stateSpace;
    int doubleFourNum = 0;

    if (1)    //左
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( x-k >= 0 && boardState[x-k][y] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( x-k >= 0 && 0 == boardState[x-k][y])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }
    if (1)    //右
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( x+k < 15 && boardState[x+k][y] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( x+k < 15 && 0 == boardState[x+k][y])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }
    if (1)    //上
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( y-k >= 0 && boardState[x][y-k] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( y-k >= 0 && 0 == boardState[x][y-k])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }    if (1)    //下
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( y+k < 15 && boardState[x][y+k] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( y+k < 15 && 0 == boardState[x][y+k])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }
    if (1)    //左上
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( x-k >= 0 && y-k >= 0 && boardState[x-k][y-k] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( x-k >= 0 && y-k >= 0 && 0 == boardState[x-k][y-k])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }
    if (1)    //右下
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( x+k < 15 && y+k < 15 && boardState[x+k][y+k] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( x+k < 15 && y+k < 15 && 0 == boardState[x+k][y+k])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }
    if (1)    //右上
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( x+k < 15 && y-k >= 0 && boardState[x+k][y-k] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( x+k < 15 && y-k >= 0 && 0 == boardState[x+k][y-k])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }
    if (1)    //左下
    {
        statePiece = stateSpace = 0;
        k = 1;
        while (k <= 4)
        {
            if ( x-k >= 0 && y+k < 15 && boardState[x-k][y+k] == boardState[x][y] )
            {
               statePiece++;
            }
            if ( x-k >= 0 && y+k < 15 && 0 == boardState[x-k][y+k])
            {
                stateSpace++;
            }
            k++;
        }
        if ( statePiece == 3 && stateSpace == 1)
        {
            doubleFourNum++;
        }
    }

    if ( doubleFourNum >= 2 )
    {
        return true;
    }
    return false;
}
