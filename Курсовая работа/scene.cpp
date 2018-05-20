#include "scene.h"
#include "item.h"
#include <QPoint>
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>

int Scene::rows = 4;
int Scene::columns = 4;
int Scene::mines = 1;

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
        if(isOver())
            return;
        if(tmp->mineAround == 0)
            show_blank(tmp);
    }
}


void Scene::Lose()
{
    game_over = true;
    lose.show();
}
void Scene::setGameOver(bool b)
{
    game_over = b;
}
void Scene::checkLowering()
{
    for (int i = 0; i < columns; i++)
    {
        Item *item = allItems[rows-1][i];
        if((item->Leftclicked) || (item->Rightclicked == 1 && item->isMine))
            continue;
        return;
    }
    deleteRow();
    //checkLowering();

}
void Scene::deleteRow()
{
    for (int a = 0; a < rows; a++)
        for (int b = 0; b < columns; b++)
            qDebug() << allItems.value(a).value(b)->isMine;
    for (int i = rows-1; i > 0; i--)
        for (int j = 0; j < columns; j++)
        {
           allItems[i][j]=allItems[i-1][j];
           updateItemImg(allItems[i][j]);
        }
    qDebug() <<"             ";
    for (int a = 0; a < rows; a++)
        for (int b = 0; b < columns; b++)
            qDebug() << allItems.value(a).value(b)->isMine;
}

void Scene::updateItemImg(Item* item)
{
    if (item->Leftclicked == false)
    {
        item->setPixmap(QPixmap(":/resources/notopen.png"));
        if (item->Rightclicked != 0)
        {
            switch (item->Rightclicked)
            {
            case 1:
                item->setPixmap(QPixmap(":/resources/flag.png"));
                break;
            case 2:
                item->setPixmap(QPixmap(":/resources/question.png"));
                break;
            }
        }
    }
    else
    {
        switch (item->mineAround)
        {
        case 0:
            item->setPixmap(QPixmap(":/resources/0.png"));
            break;
        case 1:
            item->setPixmap(QPixmap(":/resources/1.png"));
            break;
        case 2:
            item->setPixmap(QPixmap(":/resources/2.png"));
            break;
        case 3:
            item->setPixmap(QPixmap(":/resources/3.png"));
            break;
        case 4:
            item->setPixmap(QPixmap(":/resources/4.png"));
            break;
        case 5:
            item->setPixmap(QPixmap(":/resources/5.png"));
            break;
        case 6:
            item->setPixmap(QPixmap(":/resources/6.png"));
            break;
        case 7:
            item->setPixmap(QPixmap(":/resources/7.png"));
            break;
        case 8:
            item->setPixmap(QPixmap(":/resources/8.png"));
            break;
        }
    }
}
