#include <QAbstractTableModel>

class Table : public QAbstractTableModel {
    Q_OBJECT
public:
    Table( QObject* parent = 0 );

    int rowCount (const QModelIndex& parent) const;
    int columnCount (const QModelIndex& parent) const;
    QVariant data (const QModelIndex& index, int role) const;
    QVariant getData(int row, int column) const;
    bool setData (int row, const QVariant& value, int column);
    QVariant headerData (int section, Qt::Orientation orientation, int role) const;
    void removeSelected (int row);
    void clear();
    void appendDoctor(const QString& name, const QString& surname, const QString& room, const QString& specialization);

private:
    enum Column {
        NAME = 0,
        SURNAME,
        ROOM,
        SPECIALIZATION
    };

    typedef QHash< Column, QVariant > DoctorData;
    typedef QList< DoctorData > Doctors;
    Doctors m_doctors;
};
