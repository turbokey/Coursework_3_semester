#include "losewindia.h"
#include "ui_losewindia.h"

LoseWinDia::LoseWinDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoseWinDia)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Как играть?"));
    this->setWindowIcon(QIcon(":/resources/logo.png"));
    setWindowFlags(Qt::Dialog|Qt::MSWindowsFixedSizeDialogHint);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(close()));
}

LoseWinDia::~LoseWinDia()
{
    delete ui;
}
