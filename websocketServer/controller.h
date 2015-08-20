#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QString>
#include <QTableView>
#include <QAbstractItemModel>

class Controller : public QWidget
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = 0);

    void setRegistredModel(QAbstractItemModel*);
private:
    QPlainTextEdit * log;
    QTableView *registred;

signals:
    void clicked();

public slots:
    void message(const QString&);
};

#endif // CONTROLLER_H
