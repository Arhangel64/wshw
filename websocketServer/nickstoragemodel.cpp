#include "nickstoragemodel.h"

NickStorageModel::NickStorageModel(QObject *parent) :
    QAbstractTableModel(parent),
    rowC(0),
    colC(3)
{

}

bool NickStorageModel::isAvailable(const QString & nick_p, quint64 pass_p) const
{
    if (storage.contains(nick_p))
    {
        NickModel * model = storage.value(nick_p);
        if (!model->isConnected())
        {
            if (model->passwordMatch(pass_p))
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

QString NickStorageModel::getAvailableNick(quint64 startId) const
{
    QString probe;
    do
    {
        probe = "Guest " + QString::number(startId++);
    }
    while(storage.contains(probe));
    return probe;
}

bool NickStorageModel::checkPassword(const QString & nick, quint64 pass) const
{
    if (storage.contains(nick))
    {
        if (storage.value(nick)->passwordMatch(pass))
        {
            return true;
        }
    }
    return false;
}

void NickStorageModel::setConnected(const QString & nick_p, quint64 id_p)
{
    if (storage.contains(nick_p))
    {
        NickModel * model = storage.value(nick_p);
        model->connect(id_p);
        int i = list.indexOf(model);
        emit dataChanged(NickStorageModel::createIndex(i, 1), NickStorageModel::createIndex(i, 2));
    }
}

void NickStorageModel::setDisconnected(const QString & nick_p)
{
    if (storage.contains(nick_p))
    {
        NickModel* model = storage.value(nick_p);
        model->disconnect();
        int i = list.indexOf(model);
        emit dataChanged(NickStorageModel::createIndex(i, 1), NickStorageModel::createIndex(i, 2));
    }
}

void NickStorageModel::add(const QString & nick_p, quint64 pass_p)
{
    if(!storage.contains(nick_p))
    {
        NickModel* model = new NickModel(nick_p, pass_p);
        storage[nick_p] = model;
        beginInsertRows(QModelIndex(), rowC, rowC);
        list << model;
        ++rowC;
        endInsertRows();
    }
}

void NickStorageModel::remove(const QString & nick_p)
{
    if(storage.contains(nick_p))
    {
        NickModel *model = storage.value(nick_p);
        int index = list.indexOf(model);
        beginRemoveRows(QModelIndex(), index, index);
        list.removeAt(index);
        --rowC;
        endRemoveRows();
    }
}

void NickStorageModel::disconnectAll()
{
    foreach (NickModel* model, list) {
        model->disconnect();
    }
    emit dataChanged(NickStorageModel::createIndex(0, 0), NickStorageModel::createIndex(rowC-1, colC-1));
}

int NickStorageModel::rowCount(const QModelIndex &parent) const
{
    return rowC;
}

int NickStorageModel::columnCount(const QModelIndex &parent) const
{
    return colC;
}

QVariant NickStorageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    int row = index.row();
    if (row >= rowC)
        return QVariant();
    int column = index.column();
    if (column >= colC)
        return QVariant();
    NickModel* model = list.at(row);
    if (role == Qt::DisplayRole)
    {
        switch (column)
        {
        case 0:
            return model->getNick();
        case 1:
            return model->getConnectionId();
        case 2:
            return model->isConnected();
        }
    }
    return QVariant();
}

QVariant NickStorageModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QString("Nick");
        case 1:
            return QString("Connection id");
        case 2:
            return QString("Online");
        }
    }
    return QVariant();
}
