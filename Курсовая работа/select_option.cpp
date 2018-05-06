#include <select_option.h>
#include <ui_select_option.h>
#include <QDebug>
#include <QIntValidator>
Select_Option::Select_Option(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_Option)
{

    ui->setupUi(this);
    setWindowTitle(tr("Настройки"));

    connect(ui->pushButton_OK, SIGNAL(clicked()), SLOT(click_ok()));
    connect(ui->pushButton_cancel, SIGNAL(clicked()), SLOT(close()));

    QIntValidator * val1 = new QIntValidator(1, 20, this);
    ui->lineEdit_row->setValidator(val1);
    ui->lineEdit_col->setValidator(val1);

    QIntValidator * val2 = new QIntValidator(1, 99, this);
    ui->lineEdit_mine->setValidator(val2);

}

Select_Option::~Select_Option()
{

    delete ui;

}
void Select_Option::click_ok()
{

    int row = ui->lineEdit_row->text().toInt();
    int col = ui->lineEdit_col->text().toInt();
    int mine = ui->lineEdit_mine->text().toInt();

    if(mine>row*col)
        return;
    emit sendInformation(row, col, mine);
    close();
}
