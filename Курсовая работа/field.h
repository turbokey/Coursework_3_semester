#ifndef FIELD_H
#define FIELD_H
#include <QGraphicsScene>
#include <vector>

using namespace std;
extern  const QPoint point[8];

class Item;
class Field: public QGraphicsScene
{
public:
    Field(QObject * parent = 0)
        :QGraphicsScene(parent)
    {

    }
    vector<vector<Item*>> & getAllItems()
    {
        return allItems;
    }

    void calcMinesAround(Item *item);
    void show_blank(Item *item);
    static int rows,columns,mines;
private:
    vector<vector<Item*>> allItems;
};

#endif // FIELD_H
