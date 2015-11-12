#ifndef QJUDGE_H
#define QJUDGE_H

#include <QObject>
#include <QtWidgets>
#include "qboard.h"

class QJudge : public QObject
{
    Q_OBJECT
public:
    QJudge();
    ~QJudge();

public:
    bool whoWin( int (*)[15] );
    bool prohibit( int(*)[15] );        //禁手判断

    bool liveThree( int (*)[15], int, int);      //双活三禁手
    bool doubleFour(int (*)[15], int, int);     //双4禁手
    /*三禁手
        黑方一子落下同时形成两个或两个以上的活三，此步为三三禁手。 注意：这里一定要两个都是 “活”三才能算。
      四禁手
        黑方一子落下同时形成两个或两个以上的四，活四、冲四、嵌五之四，包括在此四之内。此步为四四禁手。注意：只要是两个“四”即为禁手，无论是哪种四，活四，跳四，冲四都算。
      四、三、三禁手
        黑方一步使一个四，两个活三同时形成。
      四、四、三禁手
        黑方一步使两个四，一个活三同时形成。
      长连禁手
        黑方一子落下形成连续六子或六子以上相连。注意：白棋出现长连与连五同等作用，即白棋出现长连也将获胜。 如果黑棋一步下去形成多于5个子相连的情况就判负叫长连禁手*/
};

#endif // QJUDGE_H
