#include "field.h"
#include "item.h"
#include <QPoint>
#include "mainwindow.h"

int Field::rows = 9;
int Field::columns = 9;
int Field::mines = 10;

const QPoint point[8] = {
    QPoint(-1,-1),
    QPoint(-1,0),
    QPoint(-1,1),
    QPoint(0,-1),
    QPoint(0,1),
    QPoint(1,-1),
    QPoint(1,0),
    QPoint(1,1),
};
void Field::calcMinesAround(Item *item)
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

void Field::show_blank(Item *item)
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
        if(tmp->mineAround == 0)
            show_blank(tmp);
    }
}
