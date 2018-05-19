#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "dialog.h"
#include "scene.h"
#include "select_option.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void create_menu();
    void create_field();
private:
    Select_Option selec;
    Dialog dialog;
    Scene *scene;
    QGraphicsView *view;
public slots:
    void new_game_clicked();
    void options_clicked();
    void about_clicked();
    void getInformation(int rows,int columns,int mines);
};

#endif // MAINWINDOW_H
