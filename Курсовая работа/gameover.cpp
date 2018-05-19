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
    this->setWindowIcon(QIcon(":/images/logo.png"));
    this->setWindowTitle(tr("Это фиаско, братан!"));
    ui->lineEdit->setText(tr("Обнаружено мин:"));
    ui->lineEdit_3->setText(tr("Мин осталось:"));
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(show_info()));
}

Gameover::show_info()
{
    ui->lineEdit_2->setText(QString::number(Item::mine_found));
    ui->lineEdit_4->setText(QString::number(Scene::mines-Item::mine_found));
}

Gameover::~Gameover()
{
    delete ui;
}
