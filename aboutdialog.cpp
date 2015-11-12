#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    this->movie = new QMovie("/Users/lxl/Documents/资源/mei.gif");
    this->movie->setScaledSize(ui->labelMovie->size());
    ui->labelMovie->setMovie(movie);
    this->movie->start();

    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(close()));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
