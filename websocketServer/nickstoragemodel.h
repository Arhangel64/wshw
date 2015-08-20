#ifndef NICKSTORAGEMODEL_H
#define NICKSTORAGEMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QModelIndex>
#include <QHash>
#include <QList>
#include <QString>
#include "nickmodel.h"

class NickStorageModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit NickStorageModel(QObject *parent = 0);

    bool isAvailable(const QString&, quint64) const;
    QString getAvailableNick(quint64 startId = 1) const;
    bool checkPassword(const QString&, quint64) const;
    void setConnected(const QString&, quint64);
    void setDisconnected(const QString&);
    void add(const QString&, quint64);
    void remove(const QString&);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QHash<QString, NickModel*> storage;
    QList<NickModel*> list;

    int rowC;
    int colC;

signals:

public slots:
    void disconnectAll();
};

#endif // NICKSTORAGEMODEL_H
