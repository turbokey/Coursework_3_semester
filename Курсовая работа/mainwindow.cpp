#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <time.h>
#include <stdlib.h>
#include "item.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    m_timer.setInterval(1000);
    create_menu();
    create_field();
}

void MainWindow::create_menu()
{
    this->setWindowIcon(QIcon(":/resources/logo.png"));
    this->setWindowTitle(tr("Сапёр"));

    QMenu *game_menu = new QMenu(tr("Игра"),this);
    QAction *new_game = new QAction(tr("Новая игра"),this);
    QAction *options = new QAction(tr("Опции"), this);
    QAction *exit = new QAction(tr("Выход"), this);
    game_menu->addAction(new_game);
    game_menu->addAction(options);
    game_menu->addAction(exit);

    QMenu *help_menu = new QMenu(tr("Помощь"),this);
    QAction *about = new QAction(tr("Об игре"),this);
    help_menu->addAction(about);

    menuBar()->addMenu(game_menu);
    menuBar()->addMenu(help_menu);

    connect(new_game, SIGNAL(triggered()),SLOT(new_game_clicked()));
    connect(options, SIGNAL(triggered()),SLOT(options_clicked()));
    connect(exit, SIGNAL(triggered()),SLOT(close()));
    connect(about, SIGNAL(triggered()),SLOT(about_clicked()));
    connect(&selec, SIGNAL(sendInformation(int, int,int)),SLOT(getInformation(int,int,int)));
}

void MainWindow::create_field()
{
    Item::mines_found = 0;
    timeR = 60;

    QPixmap pxmp = QPixmap(":/resources/notopen.png");
    int w = pxmp.width();
    int h = pxmp.height();
    int r = Scene::rows;
    int c = Scene::columns;
    int m = Scene::mines;

    scene = new Scene(this);
    scene->setSceneRect(0,0,w*c,h*r);
    scene->setGameOver(true);
    resize(w*c+20,h*r+80);
    this->setFixedSize(w*c+20,h*r+80);

    view = new QGraphicsView(this);
    view->setScene(scene);
    view->setMinimumSize(w*c+2,h*r+2);
    view->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    QWidget *wid = new QWidget(this);
    setCentralWidget(wid);
    QVBoxLayout *vl = new QVBoxLayout;
    vl->setAlignment(Qt::AlignHCenter);
    timer->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    timer->setAlignment(Qt::AlignHCenter);
    timer->setText(tr("01:00"));
    timer->setFont(QFont("Arial",20,QFont::Bold));
    timer->setVisible(false);
    timer->setVisible(false);

    QHBoxLayout *hl = new QHBoxLayout;
    hl->addWidget(start);
    start->setFont(QFont("Arial",17,QFont::Normal));
    start->setText(tr("Начать игру"));
    start->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    start->setVisible(true);
    connect(start,SIGNAL(clicked()),SLOT(start_clicked()));

    vl->addLayout(hl);
    vl->addWidget(timer);
    vl->addWidget(view);
    wid->setLayout(vl);

    for (int i=0; i<r; i++)
    {
        QVector<Item *> tmp;
        for (int j=0; j<c; j++)
        {
            tmp.push_back(0);
        }
        scene->getAllItems().push_back(tmp);
    }

    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            Item *item = new Item;
            item->setPixmap(pxmp);
            scene->addItem(item);
            item->setPos(j*w,i*h);
            item->setRowCol(i,j);
            scene->getAllItems()[i][j] = item;
        }
    }

    srand(time(0));
    do
    {
        int rand_row = rand()%r;
        int rand_column = rand()%c;
        Item *item = scene->getAllItems()[rand_row][rand_column];
        if (!item->Ismine())
        {
            item->setMine();
            m--;
            scene->calcMinesAround(item);
        }
    } while(m > 0);

}

void MainWindow::new_game_clicked()
{
    create_field();
}

void MainWindow::options_clicked()
{
    selec.show();
}

void MainWindow::about_clicked()
{
    dia.show();
}

void MainWindow::getInformation(int rows, int columns, int mines)
{
    Scene::rows = rows;
    Scene::columns = columns;
    Scene::mines = mines;
    create_field();
}

MainWindow::~MainWindow()
{
    delete view;
    delete scene;
}
void MainWindow::enableTimer()
{
    m_timer.start();
}
void MainWindow::timerTick()
{
    timeR--;
    timer->setText("00:" + QString::number(timeR));
    if (timeR == 0)
    {
        victory.show();
        m_timer.stop();
        scene->setGameOver(true);
    }
    else if(scene->isOver()) {
        m_timer.stop();
    }
}
void MainWindow::start_clicked()
{
    start->setVisible(false);
    timer->setVisible(true);
    scene->setGameOver(false);
    m_timer.start();
}
