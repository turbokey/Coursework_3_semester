#include "scene.h"
#include "item.h"
#include <QPoint>
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>

int Scene::rows = 9;
int Scene::columns = 9;
int Scene::mines = 10;

const QPoint point[8] = {
    QPoint(-1,-1),
    QPoint(-1,0),
    QPoint(0,-1),
    QPoint(-1,1),
    QPoint(1,0),
    QPoint(0,1),
    QPoint(1,-1),
    QPoint(1,1),
};
void Scene::calcMinesAround(Item *item)
{
    for(int i=0; i<8; i++)
    {

        int x = item->row + point[i].x();
        int y = item->col + point[i].y();
        if(x>(rows-1) || x<0) continue;
        if(y>(columns-1) || y<0) continue;
        Item * tmp = allItems[x][y];
        if(tmp->isMine)
            continue;
        ++tmp->mineAround;
    }
}

void Scene::show_blank(Item *item)
{
    for(int i=0; i<8; i++)
    {

        int x = item->row + point[i].x();
        int y = item->col + point[i].y();
        if(x>(rows-1) || x<0) continue;
        if(y>(columns-1) || y<0) continue;
        Item * tmp = allItems[x][y];
        if(tmp->Leftclicked || tmp->Rightclicked>0)
            continue;
        tmp->Leftclicked = true;
        tmp->setImage(tmp);
        decreace_number();
        if(isOver())
            return;
        if(tmp->mineAround == 0)
            show_blank(tmp);
    }
}

void Scene::decreace_number()
{
    Number_nomine--;
    qDebug() << Number_nomine;
    if(Number_nomine == 0)
    {
        for (int i = 0; i < rows; i++)
            for(int j = 0; j < columns; j++)
            {
                Item *item = this->allItems[i][j];
                if (!item->Leftclicked && (item->Rightclicked == 0 || item->Rightclicked == 2))
                    item->setPixmap(QPixmap(":/resources/flag.png"));
            }
        MainWindow *mw = (MainWindow*)this->parent();
        QMessageBox::information(mw,tr("Победа"),tr("Поле успешно разминировано"));
        game_over = true;
    }
}
void Scene::Lose()
{
    game_over = true;
    lose.show();
}
