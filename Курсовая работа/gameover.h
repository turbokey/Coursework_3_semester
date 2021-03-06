#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui
{
    class Gameover;
}
class Gameover : public QDialog
{
    Q_OBJECT
public:
    explicit Gameover(QWidget *parent = 0);
    ~Gameover();
signals:
    void windowShowed();
private:
    Ui::Gameover *ui;
private slots:
    void onWindowShowed();
protected:
    void showEvent(QShowEvent *e)
        {
            QDialog::showEvent(e);
            emit windowShowed();
        }
};
#endif // GAMEOVER_H
