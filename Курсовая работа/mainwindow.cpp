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
    QPixmap pxmp = QPixmap(":/resources/notopen.png");
    int w = pxmp.width();
    int h = pxmp.height();
    int r = Scene::rows;
    int c = Scene::columns;
    int m = Scene::mines;

    delete scene;
    scene = new Scene(this);
    qDebug() << w*c << h*r;
    scene->setSceneRect(0,0,w*c,h*r);
    resize(w*c+20,h*r+40);
    this->setFixedSize(w*c+20,h*r+40);

    view = new QGraphicsView(this);
    view->setScene(scene);
    view->setMinimumSize(w*c+2,h*r+2);

    QWidget *wid = new QWidget(this);
    setCentralWidget(wid);
    QVBoxLayout *vl = new QVBoxLayout;
    vl->addWidget(view);
    wid->setLayout(vl);

    for (int i=0; i<r; i++)
    {
        vector<Item *> tmp;
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
    Item::mine_found = 0;
    create_field();
}

void MainWindow::options_clicked()
{
    selec.show();
}

void MainWindow::about_clicked()
{
    dialog.show();
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

}
