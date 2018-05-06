#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "dialog.h"
#include "field.h"
#include "select_option.h"
//#include <QTimer>
//#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void create_menu();
    void create_field();
private:
    Ui::MainWindow *ui;
    Select_Option selec;
    Dialog dialog;
    Field *field;
    QGraphicsView *view;
    //QTimer *tmr;
public slots:
    void new_game_clicked();
    void options_clicked();
    void about_clicked();
    void getInformation(int rows,int columns,int mines);
    //void updateTime();
};

#endif // MAINWINDOW_H
