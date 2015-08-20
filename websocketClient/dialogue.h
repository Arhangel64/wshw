#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>
#include <QListView>
#include <QAbstractListModel>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    void block();
    void unblock();
    void setClientsModel(QAbstractListModel * model);
    void clearMessages();
    void setSplitterState(const QByteArray&);
    QByteArray getSplitterState() const;

private:
    QPlainTextEdit *log;
    QListView * clients;
    QSplitter *split;
    QLineEdit *line;
    QPushButton *sendButton;

signals:
    void sendMessage(const QString&);

public slots:
    void buttonPushed();
    void message(const QString&);
};

#endif // DIALOGUE_H
