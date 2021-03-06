#include "gameover.h"
#include "ui_gameover.h"
#include "item.h"
#include <QDebug>
#include "scene.h"

Gameover::Gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/resources/logo.png"));
    this->setWindowTitle(tr("Конец игры"));
    setWindowFlags(Qt::Dialog|Qt::MSWindowsFixedSizeDialogHint);

    ui->face->setPixmap(QPixmap(":/resources/lose.png"));

    connect(ui->continueButton,SIGNAL(clicked()),SLOT(close()));
    connect(this, SIGNAL(windowShowed()), SLOT(onWindowShowed()), Qt::QueuedConnection);
}
void Gameover::onWindowShowed()
{
    ui->mines->setText(QString::number(Item::mines_found));
}

Gameover::~Gameover()
{
    delete ui;
}
