#include "victory.h"
#include "ui_victory.h"
#include "item.h"
#include <QDebug>
#include <QFile>
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

    connect(ui->continueButton,SIGNAL(clicked()),SLOT(close()));
    connect(this, SIGNAL(windowShowed()), SLOT(onWindowShowed()), Qt::QueuedConnection);
}
void Victory::onWindowShowed()
{
    ui->new_record_label->setVisible(false);
    ui->mines->setText(QString::number(Item::mines_found));
    ui->score->setText(QString::number(Item::score));

    QFile f("record.dat");
    QString record = "";

    if (f.open(QIODevice::ReadWrite))
    {
        QTextStream in(&f);
        while(!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if((fields.at(0) == QString::number(Scene::rows)) && (fields.at(1) == QString::number(Scene::columns)) && (fields.at(2) == QString::number(Scene::mines)))
            {
                record = fields.at(3);
            }
        }
        f.close();
    }
    if (f.open(QIODevice::ReadWrite))
    {
        if (Item::score > record.toInt())
        {
            QString s;
            QTextStream t(&f);
            while(!t.atEnd())
            {
                QString line = t.readLine();
                QStringList fields = line.split(",");
                if(!((fields.at(0) == QString::number(Scene::rows)) && (fields.at(1) == QString::number(Scene::columns)) && (fields.at(2) == QString::number(Scene::mines))))
                {
                    s.append(line + "\r\n");
                }
            }
            f.resize(0);
            t << s;
            f.write((QString::number(Scene::rows) + ","+ QString::number(Scene::columns) +"," + QString::number(Scene::mines) + "," + QString::number(Item::score) + "\r\n").toUtf8());
            ui->new_record_label->setVisible(true);
        }
        f.close();
    }
}
Victory::~Victory()
{
    delete ui;
}
