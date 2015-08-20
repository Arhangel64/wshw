#include "controller.h"
#include <QGridLayout>
#include <QHeaderView>

Controller::Controller(QWidget *parent) :
    QWidget(parent),
    log(new QPlainTextEdit()),
    registred(new QTableView())
{
    QGridLayout *grid = new QGridLayout(this);

    grid->addWidget(log, 0,0, 1,1);
    grid->addWidget(registred, 0,1, 1,1);
    log->setProperty("readOnly", true);
    registred->verticalHeader()->setHidden(true);
    registred->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Controller::message(const QString& message)
{
    log->appendPlainText(message);

}

void Controller::setRegistredModel(QAbstractItemModel* model)
{
    registred->setModel(model);
}

