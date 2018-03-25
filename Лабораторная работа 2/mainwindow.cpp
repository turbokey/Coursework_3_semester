#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardItemModel>
#include <QFileDialog>

QStandardItemModel *model = new QStandardItemModel();
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    tableView = new QTableView(this);
    tableView->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->setWordWrap(true);

    loadButton = new QPushButton(this);
    loadButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    loadButton->setText(tr("Загрузка"));
    connect(loadButton, SIGNAL(clicked(bool)), SLOT(load_clicked()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setAlignment(loadButton,Qt::AlignHCenter);
    layout->addWidget(tableView);
    layout->addWidget(loadButton);
    this->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_clicked()
{
    model->clear();
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
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine() + "\n";
                QList<QStandardItem *> standardItemsList;
                foreach(QString item,parseCSV(line, in))
                {
                    standardItemsList.append(new QStandardItem(item));
                }
                model->appendRow(standardItemsList);
            }
            file.close();
    }
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
            else
            {
                if (symbol != '\n')
                {
                    value += symbol;
                }
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
            else
            {
                if (symbol == '\n')
                {
                    value += '\r\n';
                    string = in.readLine()+"\n";
                    i = -1;
                }
                else
                {
                    value += symbol;
                }
            }

        }
    }
    if (!value.isEmpty())
        fields.append(value);
    return fields;
}
