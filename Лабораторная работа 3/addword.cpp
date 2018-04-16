#include "addword.h"
#include <QDialogButtonBox>
#include <QRegExpValidator>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

addword::addword(QWidget *parent)
    : QDialog(parent)
{
    le = 0;
    this->setAttribute(Qt::WA_QuitOnClose, false);

    QVBoxLayout * vbox = new QVBoxLayout;

    vbox->addWidget(new QLabel(tr("Название специализации:")));

    le = new QLineEdit();

    vbox->addWidget(le);

    QRegExpValidator * v = new QRegExpValidator(QRegExp("[\\w\\d_,- \\.]{160}"));
    le->setValidator(v);


    QDialogButtonBox * buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
        | QDialogButtonBox::Cancel);
    vbox->addWidget(buttonBox);
    this->setLayout(vbox);
    setWindowTitle(tr("Добавление специализации"));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

     connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
     connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

addword::~addword()
{

}

QString addword::getNewValue()
{
        return le->text();
}
