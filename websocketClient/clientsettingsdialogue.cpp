#include "clientsettingsdialogue.h"
#include <QGridLayout>
#include <QFormLayout>
#include <QPushButton>

ClientSettingsDialogue::ClientSettingsDialogue(QWidget *parent) :
    QDialog(parent),
    nick(new QLineEdit()),
    pass(new QLineEdit()),
    addr(new QLineEdit()),
    port(new QSpinBox())
{
    setWindowTitle(tr("Settings"));
    QFormLayout *form = new QFormLayout();
    QGridLayout *grid = new QGridLayout(this);
    grid->addLayout(form, 0,0, 1,2);
    form->setParent(grid);
    QPushButton *rejectBtn = new QPushButton(tr("Reject"));
    QPushButton *acceptBtn = new QPushButton(tr("Accept"));
    grid->addWidget(acceptBtn, 1,0, 1,1);
    grid->addWidget(rejectBtn, 1,1, 1,1);

    connect(rejectBtn, SIGNAL(clicked()), SLOT(reject()));
    connect(acceptBtn, SIGNAL(clicked()), SLOT(accept()));

    port->setRange(1, 65535);
    pass->setEchoMode(QLineEdit::Password);

    form->addRow(tr("Nick"), nick);
    form->addRow(tr("Password"), pass);
    form->addRow(tr("Server address"), addr);
    form->addRow(tr("Port"), port);
}

void ClientSettingsDialogue::setNick(const QString & nick_p)
{
    nick->setText(nick_p);
}

void ClientSettingsDialogue::setAddr(const QString & addr_p)
{
    addr->setText(addr_p);
}

void ClientSettingsDialogue::setPort(quint16 port_p)
{
    port->setValue(port_p);
}

QString ClientSettingsDialogue::getNick() const
{
    return nick->text();
}

QString ClientSettingsDialogue::getPass() const
{
    return pass->text();
}

QString ClientSettingsDialogue::getAddr() const
{
    return addr->text();
}

quint16 ClientSettingsDialogue::getPort() const
{
    return port->value();
}
