#include "scene.h"
#include "item.h"
#include <QPoint>
#include "mainwindow.h"
#include "deleterow.h"
#include <QMessageBox>
#include <QDebug>

int Scene::rows = 10;
int Scene::columns = 10;
int Scene::mines = 8;

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
        if(x>298 || x<0) continue;
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
        if(x>=lastDelRow || x<lastDelRow-rows) continue;
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
    int r = 0;
    for (int i = lastDelRow-1; i >= 0; i--)
    {
        for (int j = 0; j < columns; j++)
        {
            Item *item = allItems[i][j];
            if(item->Leftclicked || (item->Rightclicked == 1 && item->isMine))
                continue;
            if (r>1)
            {
                deleteRow(r);
                Item::score += r*10;
                lastDelRow -= r;
            }
            return;
        }
        r++;
    }
}
void Scene::deleteRow(int row)
{
   emit delRow(row);
}
