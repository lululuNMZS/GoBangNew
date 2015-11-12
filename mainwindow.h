#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qboard.h"
#include "qshowboard.h"
#include "choosecolourdialog.h"
#include "qplayer.h"
#include "qrobot.h"
#include "qjudge.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QChar turnFlag;
    int gameMode;

    QBoard board;
    QWidget *window;
    QShowBoard *showBoard;
    QPlayer *player;
    QRobot *robot;
    QJudge *judge;

public:
    void runGame();
    void drawChessBoard();
    void initGame();

//    bool chooseColour();    //1为黑色，2为白色
//    bool setGameStart();    //1 开始， 0未开始
//    bool setWhoPlay();      //'P'为玩家，'R'为电脑


    void changeTurnFlag();

private slots:
    void showChooseDialog();
    void setPlayerBlackSlot();
    void setPlayerWhiteSlot();

    void playingGameSlot();
    void retractSlot();     //悔棋

    void createMenus();
    void showAboutDialogSlot();

};

#endif // MAINWINDOW_H
