#include <dialog.h>
#include <ui_dialog.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Как играть?"));
    this->setWindowIcon(QIcon(":/resources/logo.png"));
}

Dialog::~Dialog()
{
    delete ui;
}

