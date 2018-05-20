#ifndef VICTORY_H
#define VICTORY_H

#include <QDialog>

namespace Ui
{
    class Victory;
}
class Victory : public QDialog
{
    Q_OBJECT
public:
    explicit Victory(QWidget *parent = 0);
    ~Victory();
signals:
    void windowShowed();
private:
    Ui::Victory *ui;
private slots:
    void onWindowShowed();
protected:
    void showEvent(QShowEvent *e)
        {
            QDialog::showEvent(e);
            emit windowShowed();
        }
};
#endif // VICTORY_H
