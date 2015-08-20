#ifndef CLIENTLISTMODEL_H
#define CLIENTLISTMODEL_H

#include <QAbstractListModel>
#include <QModelIndex>
#include <QVariant>
#include <QHash>
#include <QList>

class ClientListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ClientListModel(QObject* parent = 0);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QString getById(quint64) const;

    void setNick(quint64, const QString&);
    void removeNick(quint64);
    void clear();
private:
    QHash<quint64, QString*> idNameHash;
    QList<QString*> list;
    int rowC;
};

#endif // CLIENTLISTMODEL_H
