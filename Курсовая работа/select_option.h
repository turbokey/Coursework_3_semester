#ifndef SELECT_OPTION_H
#define SELECT_OPTION_H

#include <QDialog>

namespace Ui {

class Select_Option;

}

class Select_Option : public QDialog
{

    Q_OBJECT

public:
    explicit Select_Option(QWidget *parent = 0);
    ~Select_Option();
signals:
    void sendInformation(int, int, int);

public slots:
    void click_ok();
    void value(int);

private:
    Ui::Select_Option *ui;

};

#endif // SELECT_OPTION_H
