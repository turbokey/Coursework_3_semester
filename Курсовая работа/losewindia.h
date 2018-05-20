#ifndef LOSEWINDIA_H
#define LOSEWINDIA_H

#include <QDialog>

namespace Ui {
class LoseWinDia;
}
class LoseWinDia : public QDialog
{
    Q_OBJECT
public:
    explicit LoseWinDia(QWidget *parent = 0);
    ~LoseWinDia();
private:
    Ui::LoseWinDia *ui;
};
#endif // LOSEWINDIA_H
