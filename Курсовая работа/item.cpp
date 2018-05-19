#include "item.h"
#include "scene.h"
#include <QDebug>

int Item::mine_found = 0;

void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Scene * scene = (Scene *)this->scene();
    if (scene->isOver())
        return;
    f_ma = 0;

    if(this->Leftclicked && ((event->buttons() & Qt::LeftButton
                              && event->buttons() & Qt::RightButton) ||
                             (event->buttons() & Qt::RightButton &&
                              event->buttons() & Qt::LeftButton)))
    {
        LeftRightC = true;
        for (int i=0; i<8; i++)
        {
            int x = row + point[i].x();
            int y = col + point[i].y();
            if(x>=Scene::rows || x<0)
                continue;
            if(y>=Scene::columns || y<0)
                continue;
            Item *item = scene->getAllItems()[x][y];
            if(item->Leftclicked)
                continue;
            if(item->Rightclicked > 0)
            {
                f_ma++;
                continue;
            }
            item->setPixmap(QPixmap(":/resources/0.png"));
        }
    }
    if (event->button() & Qt::LeftButton)
    {
        if(Rightclicked > 0 || Leftclicked)
            return;
        Leftclicked = true;
        setImage(this);
        scene->decreace_number();
        if(scene->isOver())
            return;
        if(this->isMine)
        {
            scene->Lose();
        }
        if(this->mineAround == 0)
            scene->show_blank(this);
    }
    if (event->button() & Qt::RightButton)
    {
        if(Leftclicked)
            return;
        else
        {
            QTime curTime = QTime::currentTime();
            if (LastRightcTime.hour() == curTime.hour() &&
                    LastRightcTime.minute() == curTime.minute() &&
                    LastRightcTime.second() == curTime.second())
            {
                int curmsec = curTime.msec();
                int lastmsec = LastRightcTime.msec();
                if (curmsec - lastmsec < 100)
                    return;
            }
            LastRightcTime = curTime;
            if(Rightclicked == 0)
            {
                this->setPixmap(QPixmap(":/resources/flag.png"));
                Rightclicked++;
            }
            else if (Rightclicked == 1)
            {
                this->setPixmap(QPixmap(":/resources/question.png"));
                Rightclicked++;
            }
            else if (Rightclicked == 2)
            {
                this->setPixmap(QPixmap(":/resources/notopen.png"));
                Rightclicked = 0;
            }
        }
    }
}

void Item::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Scene *scene = (Scene*) this->scene();
    if(scene->isOver())
        return;
    if (this->Leftclicked && !((event->buttons() & Qt::LeftButton
                                && event->buttons() & Qt::RightButton) ||
                               (event->buttons() & Qt::RightButton &&
                                event->button() & Qt::LeftButton)))
    {
        LeftRightC = false;
        for (int i=0; i<8; i++)
        {
            int x = row + point[i].x();
            int y = col + point[i].y();
            if(x>=Scene::rows || x<0)
                continue;
            if(y>=Scene::columns || y<0)
                continue;
            Item *item = scene->getAllItems()[x][y];
            if(item->Leftclicked)
                continue;
            if(item->Rightclicked > 0)
                continue;
            if(mineAround - f_ma == 0)
            {
                item->Leftclicked = true;
                if (item->Ismine())
                {
                    item->setPixmap(QPixmap(":/resources/bombhere.png"));
                    scene->Lose();
                }
                //qDebug() << "До проверки: " << (scene->isOver);
                if(scene->isOver())
                    return;
                item->setImage(item);
                scene->decreace_number();

                if(item->mineAround == 0)
                {
                    scene->show_blank(item);
                }
            }
            else
            {
                item->setPixmap(QPixmap(":/resources/notopen.png"));
            }

        }
    }
}

void Item::setImage(Item *item)
{
    if (item->isMine)
        item->setPixmap(QPixmap(":/resources/bombhere"));
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
