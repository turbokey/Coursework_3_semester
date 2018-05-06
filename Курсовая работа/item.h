#ifndef ITEM_H
#define ITEM_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QTime>

class Item: public QGraphicsPixmapItem
{

public:
    friend class Field;
    Item(QGraphicsItem * parent = 0)
        :QGraphicsPixmapItem(parent),isMine(0),mineAround(0),
          Leftclicked(false),Rightclicked(0),LeftRightC(false)
    {

    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setImage(Item * item);
    void setRowCol(int r, int c)
    {
        row = r;
        col =c;
    }
    void setMine()
    {
        isMine = true;
    }
    bool Ismine()
    {
        return isMine;
    }
    static int mine_found;
private:
    int row;
    int col;
    bool isMine;
    int mineAround;
    bool Leftclicked;
    int Rightclicked;
    QTime LastRightcTime;
    bool LeftRightC;
    int f_ma;
};


#endif // ITEM_H
