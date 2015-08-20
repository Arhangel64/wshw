#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include "mainwindow.h"
#include "clientsettingsdialogue.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      mainWidget(new MainWidget(this)),
      core(new ClientCore(this)),
      settings(new QSettings()),
      statusLabel(0)
{
    initDialogueWidget();
    initMenu();
    initStatusBar();
    initCore();
    stateChanged(ClientCore::Disconnected);
    readSettings();
}

MainWindow::~MainWindow()
{
    core->stop();
}

void MainWindow::initCore()
{
    connect(core, SIGNAL(message(const QString&, const QString&)), SLOT(serverMessage(const QString&, const QString&)));
    connect(core, SIGNAL(state(ClientCore::State)), SLOT(stateChanged(ClientCore::State)));
    connect(core, SIGNAL(info(const QString&)), SLOT(serverInfo(const QString&)));
    connect(core, SIGNAL(nickChanged(const QString&)), SLOT(serverNickAccepted(const QString&)));
    connect(core, SIGNAL(nickDenied()), SLOT(serverNickDenied()));
}

void MainWindow::readSettings()
{
    settings->beginGroup("mainWindow");
    resize(settings->value("size", QSize(200, 200)).toSize());
    move(settings->value("offset", QPoint(200, 200)).toPoint());
    settings->endGroup();
    settings->beginGroup("core");
    core->setServerAddress(settings->value("address", "localhost").toString());
    core->setServerPort(settings->value("port", 8080).toUInt());
    core->setNick(settings->value("nick", "host").toString(), settings->value("pass", qHash("")).toUInt());
    settings->endGroup();
    settings->beginGroup("widget");
    QVariant ss = settings->value("splitState");
    if (!ss.isNull())
    {
        mainWidget->setSplitterState(ss.toByteArray());
    }
    settings->endGroup();
    if (settings->value("connected", false).toBool())
    {
        core->start();
    }
}

void MainWindow::stateChanged(ClientCore::State state)
{
    menu->hideTearOffMenu();
    menu->removeAction(disconnectSocketAct);
    menu->removeAction(connectSocketAct);
    mainWidget->block();
    switch(state)
    {
    case ClientCore::Disconnected:
        menu->addAction(connectSocketAct);
        statusLabel->setText("Disconnected");
        break;
    case ClientCore::Connecting:
        menu->addAction(disconnectSocketAct);
        statusLabel->setText("Connecting...");
        break;
    case ClientCore::Handshaking:
        menu->addAction(disconnectSocketAct);
        statusLabel->setText("Handshaking...");
        break;
    case ClientCore::Connected:
        menu->addAction(disconnectSocketAct);
        statusLabel->setText("Connected to " + core->getServerAddress());
        mainWidget->unblock();
        break;
    case::ClientCore::Disconnecting:
        statusLabel->setText("Disconnecting...");
        mainWidget->clearMessages();
        break;
    }
}

void MainWindow::serverNickAccepted(const QString & nick)
{
    mainWidget->message("Now your nickname is "+ nick);
}

void MainWindow::serverNickDenied()
{
    mainWidget->message("Nickname " + core->getNick() + " is not available, trying recomended by system");
}

void MainWindow::initMenu()
{
    connectSocketAct = new QAction(tr("&Connect"), this);
    disconnectSocketAct = new QAction(tr("&Disonnect"), this);
    settingsAct = new QAction(tr("&Settings"), this);

    connect(connectSocketAct, SIGNAL(triggered()), core, SLOT(start()));
    connect(disconnectSocketAct, SIGNAL(triggered()), core, SLOT(stop()));
    connect(settingsAct, SIGNAL(triggered()), SLOT(settingsDialogue()));

    menu = menuBar()->addMenu(tr("&Menu"));
    menu->addAction(settingsAct);
}

void MainWindow::initStatusBar()
{
    QStatusBar *bar = statusBar();
    statusLabel = new QLabel(tr("Disconnected"), this);
    bar->addWidget(statusLabel);
}

void MainWindow::initDialogueWidget()
{
    setCentralWidget(mainWidget);
    mainWidget->setClientsModel(core->getClienListModel());
    connect(mainWidget, SIGNAL(sendMessage(const QString&)), core, SLOT(sendMessage(const QString&)));
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    writeSettings();
    event->accept();
}

void MainWindow::serverMessage(const QString & author, const QString & text)
{
    mainWidget->message(author + ": " + text);
}

void MainWindow::serverInfo(const QString & info)
{
    qDebug() << info;
}

void MainWindow::writeSettings()
{
    settings->beginGroup("mainWindow");
    settings->setValue("size", size());
    settings->setValue("offset", pos());
    settings->endGroup();
    settings->beginGroup("core");
    settings->setValue("address", core->getServerAddress());
    settings->setValue("port", core->getServerPort());
    settings->setValue("nick", core->getNick());
    settings->setValue("pass", core->getPass());
    settings->endGroup();
    settings->beginGroup("widget");
    settings->setValue("splitState", mainWidget->getSplitterState());
    settings->endGroup();
    settings->setValue("connected", core->isConnected());
}

void MainWindow::settingsDialogue()
{
    ClientSettingsDialogue *d = new ClientSettingsDialogue(this);
    d->setNick(core->getNick());
    d->setAddr(core->getServerAddress());
    d->setPort(core->getServerPort());
    if (d->exec())
    {
        bool rec = false;
        if (d->getPort() != core->getServerPort())
        {
            core->setServerPort(d->getPort());
            rec = true;
        }

        if (d->getAddr() != core->getServerAddress())
        {
            core->setServerAddress(d->getAddr());
            rec = true;
        }
        if (rec)
        {
            core->reconnect();
        }
        if (d->getNick() != core->getNick() || !d->getPass().isEmpty())
        {
            core->setNick(d->getNick(), qHash(d->getPass()));
        }
    }

    delete d;
}
