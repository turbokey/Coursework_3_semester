#include "table.h"
#include <QDebug>
Table::Table( QObject* parent ) : QAbstractTableModel( parent ) {

}

int Table::rowCount ( const QModelIndex& parent ) const {
    Q_UNUSED ( parent )
    return m_doctors.count();
}

int Table::columnCount ( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return SPECIALIZATION+1;
}

QVariant Table::headerData ( int section, Qt::Orientation orientation, int role ) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Vertical) {
        return section;
    }

    switch( section ) {
    case NAME:
        return tr("Имя");
    case SURNAME:
        return tr("Фамилия");
    case ROOM:
        return tr("Кабинет");
    case SPECIALIZATION:
        return tr("Специализация");
    }

    return QVariant();
}

QVariant Table::getData(int row, int column) const {
    return m_doctors[row][ Column(column) ];
}

QVariant Table::data( const QModelIndex& index, int role ) const {
    if(
            !index.isValid() ||
            m_doctors.count() <= index.row() ||
            ( role != Qt::DisplayRole && role != Qt::EditRole )
            ) {
        return QVariant();
    }

    return m_doctors[ index.row() ][ Column( index.column() ) ];
}

bool Table::setData(int row, const QVariant& value, int column) {
    m_doctors[row][Column(column)] = value;
    emit dataChanged(index(row,column),index(row,column));

    return true;
}
void Table::appendDoctor(const QString& name, const QString& surname, const QString& room, const QString& specialization) {
    DoctorData doctor;
    doctor[ NAME ] = name;
    doctor[ SURNAME ] = surname;
    doctor[ ROOM ] = room;
    doctor[ SPECIALIZATION ] = specialization;

    int row = m_doctors.count();
    beginInsertRows( QModelIndex(), row, row );
    m_doctors.append( doctor );
    endInsertRows();
}

void Table::removeSelected(int row) {
    beginRemoveRows(QModelIndex(), row, row);
    m_doctors.removeAt(row);
    endRemoveRows();
}
void Table::clear(){
    int i = 0;
    Doctors::iterator it = m_doctors.begin();
    while( it != m_doctors.end() ) {
        beginRemoveRows( QModelIndex(), i, i );
        it = m_doctors.erase (it);
        endRemoveRows();
    }
}
