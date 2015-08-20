#include <QGridLayout>
#include <QLabel>
#include "dialogue.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    log(new QPlainTextEdit()),
    clients(new QListView()),
    split(new QSplitter()),
    line(new QLineEdit()),
    sendButton(new QPushButton("Send"))

{
    split->addWidget(clients);
    split->addWidget(log);

    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(split, 0, 0, 1, 2);
    layout->addWidget(line, 1, 0, 1, 1);
    layout->addWidget(sendButton, 1, 1, 1, 1);

    log->setProperty("readOnly", true);

    connect(sendButton, SIGNAL(clicked()), SLOT(buttonPushed()));
    connect(line, SIGNAL(returnPressed()), SLOT(buttonPushed()));
    block();
}

void MainWidget::buttonPushed()
{
    emit sendMessage(line->text());
    line->clear();
}

void MainWidget::message(const QString& message)
{
    log->appendPlainText(message);
}

void MainWidget::block () {
    line->setEnabled(false);
    sendButton->setEnabled(false);
}
void MainWidget::unblock () {
    line->setEnabled(true);
    sendButton->setEnabled(true);
}

void MainWidget::setClientsModel(QAbstractListModel * model)
{
    clients->setModel(model);
}

void MainWidget::clearMessages()
{
    log->clear();
}

void MainWidget::setSplitterState(const QByteArray & ba)
{
    split->restoreState(ba);
}

QByteArray MainWidget::getSplitterState() const
{
    return split->saveState();
}
