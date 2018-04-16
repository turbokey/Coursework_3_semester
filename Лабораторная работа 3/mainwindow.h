#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QGroupBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
    QComboBox *specialization;
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;
    QLineEdit *roomEdit;
    QTableView *tableView;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *saveButton;
    QGroupBox *editBox;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void load_clicked();
    void add_clicked();
    void save_clicked();
    void exit_clicked();
    void remove_clicked();
    void enter_clicked();
    void tableViewClicked();
    void specialization_changed(int);
private:
    QStringList list;
    QStringList parseCSV(QString&, QTextStream&);
    void getSpecList();
    void updateList();
    void prepareTable();
    QString generateCSV(int &row);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
