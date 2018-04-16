#include <QDialog>
#include <QLineEdit>

class addword : public QDialog
{
    Q_OBJECT

public:
    addword(QWidget *parent = 0);
    ~addword();
    QString getNewValue();

signals:
    void rejected();
    void accepted();

public slots:


private:
    QLineEdit * le;
};
