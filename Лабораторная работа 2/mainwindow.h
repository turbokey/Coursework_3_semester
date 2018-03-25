#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
    QTableView *tableView;
    QPushButton *loadButton;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void load_clicked();
private:
    QStringList parseCSV(QString&, QTextStream&);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
