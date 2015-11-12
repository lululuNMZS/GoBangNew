#ifndef CHOOSECOLOURDIALOG_H
#define CHOOSECOLOURDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseColourDialog;
}

class ChooseColourDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseColourDialog(QWidget *parent = 0);
    ~ChooseColourDialog();

private:
    Ui::ChooseColourDialog *ui;

private slots:
    void sendPlayerBlackSignalSlot();
    void sendPlayerWhiteSignalSlot();

signals:
    void blackSignal();
    void whiteSignal();

};

#endif // CHOOSECOLOURDIALOG_H
