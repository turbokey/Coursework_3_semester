#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <vector>
#include "gameover.h"

using namespace std;
extern  const QPoint point[8];

class Item;
class Scene: public QGraphicsScene
{
public:
    Scene(QObject * parent = 0)
        :QGraphicsScene(parent)
    {

    }
    vector<vector<Item*>> & getAllItems()
    {
        return allItems;
    }

    void calcMinesAround(Item *item);
    bool isOver()
    {
        return game_over;
    }
    void show_blank(Item *item);
    void Lose();
    void decreace_number();
    static int rows,columns,mines;
private:
    vector<vector<Item*>> allItems;
    bool game_over = false;
    Gameover lose;
    int Number_nomine = rows*columns - mines;
};

#endif // SCENE_H
