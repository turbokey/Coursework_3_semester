#include <select_option.h>
#include <ui_select_option.h>
#include <QDebug>
#include <QIntValidator>
Select_Option::Select_Option(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_Option)
{

    ui->setupUi(this);
    setWindowIcon(QIcon(":/resources/logo.png"));
    setWindowTitle(tr("Настройки"));
    setWindowFlags(Qt::Dialog|Qt::MSWindowsFixedSizeDialogHint);

    connect(ui->pushButton_OK, SIGNAL(clicked()), SLOT(click_ok()));
    connect(ui->pushButton_cancel, SIGNAL(clicked()), SLOT(close()));
    connect(ui->slider_row,SIGNAL(valueChanged(int)),SLOT(value(int)));
    connect(ui->slider_col,SIGNAL(valueChanged(int)),SLOT(value(int)));
    connect(ui->slider_mine,SIGNAL(valueChanged(int)),SLOT(value(int)));

    ui->lineEdit_row->setStyleSheet("QLineEdit {background-color: rgba(0, 0, 0, 0);}");
    ui->lineEdit_col->setStyleSheet("QLineEdit {background-color: rgba(0, 0, 0, 0);}");
    ui->lineEdit_mine->setStyleSheet("QLineEdit {background-color: rgba(0, 0, 0, 0);}");

    ui->row->setText(QString::number(ui->slider_row->value()));
    ui->col->setText(QString::number(ui->slider_col->value()));
    ui->mine->setText(QString::number(ui->slider_mine->value()));
}

Select_Option::~Select_Option()
{
    delete ui;
}
void Select_Option::click_ok()
{

    int row = ui->slider_row->value();
    int col = ui->slider_col->value();
    int mine = ui->slider_mine->value();

    if(mine>row*col)
        return;
    emit sendInformation(row, col, mine);
    close();
}
void Select_Option::value(int)
{
    ui->row->setText(QString::number(ui->slider_row->value()));
    ui->col->setText(QString::number(ui->slider_col->value()));
    ui->mine->setText(QString::number(ui->slider_mine->value()));
}
