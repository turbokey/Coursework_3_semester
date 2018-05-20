#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QVector>
#include <QTimer>
#include "gameover.h"
#include "victory.h"

using namespace std;
extern  const QPoint point[8];

class Item;
class Scene: public QGraphicsScene
{
public:
    Scene(QObject * parent = 0) : QGraphicsScene(parent)
    {

    }
    QVector<QVector<Item*>> & getAllItems()
    {
        return allItems;
    }

    void calcMinesAround(Item *item);
    bool isOver()
    {
        return game_over;
    }
    void show_blank(Item *item);
    void checkLowering();
    void deleteRow();
    void updateItemImg(Item *item);
    void Lose();
    void setGameOver(bool);
    static int rows,columns,mines;
private:
    QVector<QVector<Item*>> allItems;
    bool game_over = false;
    Gameover lose;
    int Number_nomine = rows*columns - mines;
};

#endif // SCENE_H
