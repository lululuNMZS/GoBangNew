#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qshowboard.h"
#include "choosecolourdialog.h"
#include "aboutdialog.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("五子棋");
    this->setFixedSize(QSize(600,700));       //设置主窗口大小为600*700
    this->createMenus();

    this->runGame();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runGame()              //--------游戏过程
{
    player = new QPlayer;           //做好对象
    robot = new QRobot;
    judge = new QJudge;

    this->drawChessBoard();         //摆好棋盘


    connect(showBoard, SIGNAL(posChangedSignal()), this, SLOT(playingGameSlot()));

}

void MainWindow::drawChessBoard()
{
    window = new QWidget;      //先在表面做一层widget
    this->setCentralWidget(window);

    QPushButton *newGameButton = new QPushButton;       //三个按钮
    QPushButton *quitButton = new QPushButton;
    QPushButton *regretButton = new QPushButton;

    newGameButton->setText("新局");
    regretButton->setText("悔棋");
    quitButton->setText("退出");

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(newGameButton);
    bottomLayout->addWidget(regretButton);
    bottomLayout->addWidget(quitButton);

    showBoard = new QShowBoard;                         //棋盘
    showBoard->setBoard(board);             //取数组信息

    QVBoxLayout *topLayout = new QVBoxLayout;
    topLayout->addWidget(showBoard);
    topLayout->addLayout(bottomLayout);

    window->setLayout(topLayout);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(showChooseDialog()));      //激活选择颜色对话框
    connect(regretButton, SIGNAL(clicked()), this, SLOT(retractSlot()));
}

void MainWindow::showChooseDialog()     /*-------------------------选择颜色----------------------*/
{
    ChooseColourDialog *chooseColourDialog = new ChooseColourDialog;
    chooseColourDialog->show();

    connect(chooseColourDialog, SIGNAL(blackSignal()), this, SLOT(setPlayerBlackSlot()));
    connect(chooseColourDialog, SIGNAL(whiteSignal()), this, SLOT(setPlayerWhiteSlot()));
}

void MainWindow::setPlayerBlackSlot()
{
    player->setPieveColour(1);  //1为黑子
    robot->setPieveColour(2);

    this->initGame();

    showBoard->setGameStart(1);     /*---------------游戏开始--------------*/
    turnFlag = 'P';
}

void MainWindow::setPlayerWhiteSlot()
{
    player->setPieveColour(2);
    robot->setPieveColour(1);

    this->initGame();

    showBoard->setGameStart(1);
    turnFlag = 'R';

    this->playingGameSlot();
}

void MainWindow::playingGameSlot()
{
    if ( 'P' == turnFlag )
    {
        QPoint pos = showBoard->getPoint();        //得到鼠标左击事件中的坐标
        player->playGame(board.getBoard(), pos, board.getTotal());                      //落子

        showBoard->update();

        if ( 1 == player->getPieceColour() )    //判断禁手
        {
            if ( judge->prohibit(board.getBoard()) )
            {
                QMessageBox::information(NULL, "结束", "你输了，禁手", QMessageBox::Yes | QMessageBox::No);
                showBoard->setGameStart(0);
                return;
            }
        }
        if ( judge->whoWin(board.getBoard()) )      //裁判
        {
            QMessageBox::information(NULL, "结束", "你赢了", QMessageBox::Yes | QMessageBox::No);
            showBoard->setGameStart(0);
            return;
        }

        this->changeTurnFlag();
    }
    if ( 'R' == turnFlag )
    {
        /*机器人走*/
        robot->setBoardState(board.getBoard());     //先拿棋盘数据
        robot->algorithmGreed(board.getTotal());

        if ( 1 == robot->getPieceColour() )     //如果 机器人下在禁手位置
        {

        }

        showBoard->update();

        if ( judge->whoWin(board.getBoard()) )           //裁判
        {
             QMessageBox::information(NULL, "结束", "你输了", QMessageBox::Ok | QMessageBox::No);
             showBoard->setGameStart(0);
             return;
        }

        this->changeTurnFlag();

    }
}

void MainWindow::changeTurnFlag()
{
    if ( 'P' == turnFlag )
    {
        turnFlag = 'R';
    }
    else if ( 'R' == turnFlag )
    {
        turnFlag = 'P';
    }
}

void MainWindow::initGame()
{
    int (*boardState)[squareNum];
    boardState = board.getBoard();

    for (int i = 0 ; i < squareNum ; i++ )
    {
        for ( int j = 0 ; j < squareNum ; j++ )
        {
            boardState[i][j] = 0;
        }
    }

    (*board.getTotal()) = 0;

    showBoard->update();
}

void MainWindow::retractSlot()
{
    int (*boardState)[15] = board.getBoard();

    QPoint *playerRetract = player->getRetract();
    boardState[playerRetract->rx()][playerRetract->ry()] = 0;

    QPoint *robotRetract = robot->getRetract();
    boardState[robotRetract->rx()][robotRetract->ry()] = 0;

    showBoard->update();
}

void MainWindow::showAboutDialogSlot()
{
    AboutDialog *aboutDialog = new AboutDialog;
    aboutDialog->show();
}

void MainWindow::createMenus()
{
    QAction *aboutAction = new QAction(tr("关于作者"),this);

    QMenu * helpMenu;
    helpMenu = this->menuBar()->addMenu(tr("帮助"));
    helpMenu->addAction(aboutAction);

    connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialogSlot()));
}
