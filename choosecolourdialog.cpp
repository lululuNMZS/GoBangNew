#include "choosecolourdialog.h"
#include "ui_choosecolourdialog.h"

ChooseColourDialog::ChooseColourDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseColourDialog)
{
    ui->setupUi(this);

    connect(ui->blackButton, SIGNAL(clicked()), this, SLOT(sendPlayerBlackSignalSlot()));
    connect(ui->whiteButton, SIGNAL(clicked()), this, SLOT(sendPlayerWhiteSignalSlot()));
}

ChooseColourDialog::~ChooseColourDialog()
{
    delete ui;
}

void ChooseColourDialog::sendPlayerBlackSignalSlot()    //发送玩家选择了黑子的信号
{
    emit blackSignal();
    accept();
}

void ChooseColourDialog::sendPlayerWhiteSignalSlot()
{
    emit whiteSignal();
    accept();
}
