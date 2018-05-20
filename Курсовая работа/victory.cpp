#include "victory.h"
#include "ui_victory.h"
#include "item.h"
#include <QDebug>
#include "scene.h"

Victory::Victory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Victory)
{
    ui->setupUi(this);

    ui->new_record_label->setVisible(false);

    this->setWindowIcon(QIcon(":/resources/logo.png"));
    this->setWindowTitle(tr("Конец игры"));
    setWindowFlags(Qt::Dialog|Qt::MSWindowsFixedSizeDialogHint);

    ui->face->setPixmap(QPixmap(":/resources/victory.png"));

//        if (new record)
//            ui->new_record_label->setVisible(true);
    connect(ui->continueButton,SIGNAL(clicked()),SLOT(close()));
    connect(this, SIGNAL(windowShowed()), SLOT(onWindowShowed()), Qt::QueuedConnection);
}
void Victory::onWindowShowed()
{
    ui->mines->setText(QString::number(Item::mines_found));
}
Victory::~Victory()
{
    delete ui;
}
