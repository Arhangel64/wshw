#include <QHostAddress>
#include <QtAlgorithms>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    server(new ServerCore(this)),
    widget(new Controller(this)),
    settings(new QSettings()),
    serverToggleAct(0),
    settingsAct(0)
{
    initServer();
    initControllWidget();
    initMenu();
    readSettings();
}

MainWindow::~MainWindow()
{
    server->stop();
}

void MainWindow::readSettings()
{
    settings->beginGroup("mainWindow");
    resize(settings->value("size", QSize(200, 200)).toSize());
    move(settings->value("offset", QPoint(200, 200)).toPoint());
    settings->endGroup();
    if (settings->value("running", false).toBool()) {
        server->start(settings->value("port", 8080).toUInt());
    }
}

void MainWindow::initControllWidget()
{
    setCentralWidget(widget);
    widget->setRegistredModel(server->clients);
}

void MainWindow::initServer()
{
    connect(server, SIGNAL(started(quint16)), SLOT(onServerStarted(quint16)));
    connect(server, SIGNAL(stopped()), SLOT(onServerStopped()));
    connect(server, SIGNAL(message(const QString&)), SLOT(message(const QString&)));
}

void MainWindow::message(const QString & message)
{
    widget->message(message);
}

void MainWindow::onServerStarted(quint16 port)
{
    message("Server started on port " + QString::number(port));
    serverToggleAct->setText(tr("&Disconnect"));
}

void MainWindow::onServerStopped()
{
    message("Server stopped");
    serverToggleAct->setText(tr("&Connect"));
}

void MainWindow::serverToggle()
{
    if (server->isRunning())
        server->stop();
    else
        server->start(settings->value("port", 8080).toUInt());
}

void MainWindow::writeSettings()
{
    settings->beginGroup("mainWindow");
    settings->setValue("size", size());
    settings->setValue("offset", pos());
    settings->endGroup();
    settings->setValue("running", server->isRunning());
}

void MainWindow::initMenu()
{
    serverToggleAct = new QAction(tr("&Connect"), this);
    settingsAct = new QAction(tr("&Settings"), this);

    connect(serverToggleAct, SIGNAL(triggered()), SLOT(serverToggle()));
    connect(settingsAct, SIGNAL(triggered()), SLOT(settingsDialogue()));

    menu = menuBar()->addMenu(tr("&Menu"));
    menu->addAction(settingsAct);
    menu->addAction(serverToggleAct);
}

void MainWindow::settingsDialogue()
{

}


void MainWindow::closeEvent(QCloseEvent * event)
{
    writeSettings();
    event->accept();
}
