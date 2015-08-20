#include "clientlistmodel.h"
#include <QDebug>

ClientListModel::ClientListModel(QObject * parent):
    QAbstractListModel(parent),
    rowC(0)
{

}

int ClientListModel::rowCount(const QModelIndex &parent) const
{
    return rowC;
}

QVariant ClientListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return *(list.at(index.row()));
    }
    else
    {
        return QVariant();
    }
}

QVariant ClientListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || section !=0)
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        QString("Connected users");
    }
    else
    {
        return QVariant();
    }
}

QString ClientListModel::getById(quint64 id) const
{
    return *(idNameHash.value(id));
}

void ClientListModel::setNick(quint64 id, const QString & nick)
{
    QString * n;
    if (idNameHash.contains(id))
    {
        n = idNameHash[id];
        *(n) = nick;
        int i = list.indexOf(n);
        emit dataChanged(ClientListModel::createIndex(i, 0), ClientListModel::createIndex(i, 0));
    }
    else
    {
        beginInsertRows(QModelIndex(), rowC, rowC);
        n = new QString(nick);
        idNameHash[id] = n;
        list << n;
        ++rowC;
        endInsertRows();
    }
}

void ClientListModel::removeNick(quint64 id)
{
    if (idNameHash.contains(id))
    {
        QString * name = idNameHash[id];
        int i = list.indexOf(name);
        beginRemoveRows(QModelIndex(), i, i);
        list.removeAt(i);
        name = 0;
        idNameHash.remove(id);
        --rowC;
        endRemoveRows();
    }
}

void ClientListModel::clear()
{
    if (rowC != 0) {
        beginRemoveRows(QModelIndex(), 0, rowC-1);
        list.clear();
        idNameHash.clear();
        rowC = 0;
        endRemoveRows();
    }
}
