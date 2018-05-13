#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addword.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSizePolicy>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    QVBoxLayout *boxLayout = new QVBoxLayout(this);
    QMenuBar* menuBar = new QMenuBar();
    QMenu *fileMenu = new QMenu(tr("Файл"));
    menuBar->addMenu(fileMenu);
    QAction *loadAction = new QAction(tr("Загрузить"),fileMenu);
    QAction *saveAction = new QAction(tr("Сохранить"),fileMenu);
    QAction *exitAction = new QAction(tr("Выход"),fileMenu);
    connect(loadAction, SIGNAL(triggered()), this, SLOT(load_clicked()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save_clicked()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exit_clicked()));
    fileMenu->addAction(loadAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(exitAction);

    this->layout()->setMenuBar(menuBar);
    table_model = new Table;
    tableView = new QTableView(this);
    tableView->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode( QAbstractItemView::SingleSelection );
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //tableView->setModel(model);
    tableView->setModel(table_model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->setWordWrap(true);
    connect(tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(tableViewClicked()));

    addButton = new QPushButton(tr("Добавить"),this);
    addButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(addButton, SIGNAL(clicked(bool)), SLOT(add_clicked()));

    nameEdit = new QLineEdit(this);
    surnameEdit = new QLineEdit(this);
    roomEdit = new QLineEdit(this);
    specialization = new QComboBox(this);
    specialization->setMinimumContentsLength(18);
    specialization->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    specialization->addItems(QStringList() << "" << tr("Добавить..."));
    connect(specialization, SIGNAL(currentIndexChanged (int)), this, SLOT(specialization_changed(int)));

    removeButton = new QPushButton(tr("Удалить"),this);
    connect(removeButton, SIGNAL(clicked(bool)), SLOT(remove_clicked()));
    saveButton = new QPushButton(tr("Сохранить"),this);
    connect(saveButton, SIGNAL(clicked(bool)), SLOT(enter_clicked()));

    QGridLayout * grid = new QGridLayout();
    QGridLayout * grid2 = new QGridLayout();
    QGridLayout * grid3 = new QGridLayout();
    grid->setSpacing(10);
    grid->setColumnStretch(0,1);
    grid->setColumnStretch(1,1);
    grid2->setSpacing(10);
    grid2->addWidget(removeButton,0,0,Qt::AlignRight);
    grid2->addWidget(saveButton,0,1,Qt::AlignLeft);
    grid->addWidget(tableView,0,0,4,1);
    grid->addWidget(addButton,4,0,Qt::AlignRight);
    grid3->setSpacing(10);
    grid3->addWidget(new QLabel(tr("Фамилия"),this),0,0,Qt::AlignRight);
    grid3->addWidget(new QLabel(tr("Имя"),this),1,0,Qt::AlignRight);
    grid3->addWidget(new QLabel(tr("Кабинет"),this),2,0,Qt::AlignRight);
    grid3->addWidget(new QLabel(tr("Специализация"),this),3,0,Qt::AlignRight);
    grid3->addWidget(nameEdit,0,1,Qt::AlignLeft);
    grid3->addWidget(surnameEdit,1,1,Qt::AlignLeft);
    grid3->addWidget(roomEdit,2,1,Qt::AlignLeft);
    grid3->addWidget(specialization,3,1,Qt::AlignLeft);
    grid3->addItem(grid2,4,1);

    editBox = new QGroupBox(this);
    editBox->setEnabled(false);
    editBox->setLayout(grid3);

    grid->addWidget(editBox,0,1);
    boxLayout->addItem(grid);
    setMinimumSize(900,300);
}
void MainWindow::tableViewClicked()
{
    editBox->setEnabled(true);
    int rowidx = tableView->selectionModel()->currentIndex().row();
    nameEdit->setText(table_model->getData(rowidx , 0).toString());
    surnameEdit->setText(table_model->getData(rowidx , 1).toString());
    roomEdit->setText(table_model->getData(rowidx , 2).toString());
    specialization->setCurrentText(table_model->getData(rowidx , 3).toString());
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "", tr("CSV-файлы (*.csv)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly))
        {
            qDebug() << file.errorString();
            return;
        }
        QTextStream out(&file);

        int rows = table_model->rowCount(tableView->selectionModel()->currentIndex());

        for (int i = 0; i < rows; i++)
        {
            out << generateCSV(i);
        }
        file.close();
    }
}
void MainWindow::exit_clicked()
{
    close();
}
void MainWindow::add_clicked()
{
    table_model->appendDoctor("","","","");
}

void MainWindow::enter_clicked()
{
    int rowidx = tableView->selectionModel()->currentIndex().row();
    table_model->setData(rowidx,nameEdit->text(),0);
    table_model->setData(rowidx,surnameEdit->text(),1);
    table_model->setData(rowidx,roomEdit->text(),2);
    table_model->setData(rowidx,specialization->currentText(),3);
}

void MainWindow::remove_clicked()
{
    int rowidx = tableView->selectionModel()->currentIndex().row();
    table_model->removeSelected(rowidx);
    if (table_model->rowCount(tableView->selectionModel()->currentIndex()) == 0)
    {
        prepareTable();
        specialization->addItems(QStringList() << "" << tr("Добавить..."));
    }
}
void MainWindow::updateList()
{
    specialization->clear();
    specialization->addItems(list);
    specialization->addItem(tr("Добавить..."));
}

void MainWindow::specialization_changed(int num)
{
    QString s = specialization->currentText();
    if (s.contains(tr("Добавить...")))
    {
        addword dialog;
        if(dialog.exec() == QDialog::Accepted)
        {
            QString text = dialog.getNewValue();
            if (!text.isEmpty())
            {
                if (!list.contains(text))
                {
                    list.append(text);
                    updateList();
                    specialization->setCurrentIndex(specialization->findText(text));
                }
                else
                {
                    QMessageBox::critical(0,tr("Ошибка"),tr("Данная специализация уже существует!"),tr("Да"),QString(),0,1);
                }
            }
        }
    }
}
void MainWindow::getSpecList()
{
    list.clear();
    int rows = table_model->rowCount(tableView->selectionModel()->currentIndex());
    for (int i = 0; i < rows; i++)
    {
        if(!list.contains(table_model->getData(i,3).toString()))
        {
            list.append(table_model->getData(i,3).toString());
        }
    }
}
void MainWindow::prepareTable()
{
    table_model->clear();
    editBox->setEnabled(false);
    nameEdit->clear();
    surnameEdit->clear();
    roomEdit->clear();
    specialization->clear();
}

void MainWindow::load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Загрузить файл"), "", tr("CSV-файлы (*.csv)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly))
        {
            qDebug() << file.errorString();
            return;
        }
        prepareTable();
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine() + "\n";
            table_model->appendDoctor(parseCSV(line,in).at(0),parseCSV(line,in).at(1),parseCSV(line,in).at(2),parseCSV(line,in).at(3));
        }
        file.close();
        getSpecList();
        updateList();
    }
}
QString MainWindow::generateCSV(int &row)
{
    int columns = table_model->columnCount(tableView->selectionModel()->currentIndex());
    QString textData;
    QString doubleQuote = QString('"');
    doubleQuote += '"';
    for (int i = 0; i < columns; i++)
    {
        QString word = table_model->getData(row,i).toString();
        if (word.contains(',') || word.contains('"'))
        {
            word.replace('"',doubleQuote);
            word = '"' + word + '"';
        }
        if (i+1 != columns)
        {
            word += ",";
        }
        textData += word;
    }
    textData += "\r\n";
    return textData;
}

QStringList MainWindow::parseCSV(QString &string, QTextStream &in)
{
    enum State {Normal, Quote} state = Normal;
    QStringList fields;
    QString value;

    for (int i = 0; i < string.size(); i++)
    {
        QChar symbol = string.at(i);
        if (state == Normal)
        {
            if (symbol == ',')
            {
                fields.append(value);
                value.clear();
            }
            else if (symbol == '"')
            {
                state = Quote;
            }
            else if (symbol != '\n')
            {
                value += symbol;
            }
        }
        else if (state == Quote)
        {
            if (symbol == '"')
            {
                if (i+1 < string.size())
                {
                    QChar next = string.at(i+1);
                    if (next == '"')
                    {
                        value += '"';
                        i++;
                    }
                    else
                    {
                        state = Normal;
                    }
                }
            }
            else if (symbol == '\n')
            {
                value += "\r\n";
                string = in.readLine()+"\n";
                i = -1;
            }
            else
            {
                value += symbol;
            }

        }
    }
    if (!value.isEmpty())
        fields.append(value);
    return fields;
}
