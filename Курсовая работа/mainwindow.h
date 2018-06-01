#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "losewindia.h"
#include "scene.h"
#include "select_option.h"
#include "victory.h"
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel *timer = new QLabel;
    QPushButton *start = new QPushButton;
    void create_menu();
    void create_field();
    void enableTimer();
private:
    Select_Option selec;
    LoseWinDia dia;
    Scene *scene;
    QGraphicsView *view;
    QTimer m_timer;
    Victory victory;
    int timeR = 60;
public slots:
    void new_game_clicked();
    void record_clicked();
    void options_clicked();
    void about_clicked();
    void getInformation(int rows,int columns,int mines);
private slots:
    void timerTick();
    void start_clicked();
    void getDeleteRow(int rows);
};

#endif // MAINWINDOW_H
