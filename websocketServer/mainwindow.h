#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>
#include <QByteArray>
#include <QSettings>
#include <QAction>
#include <QMenuBar>
#include <QCloseEvent>

#include "controller.h"
#include "servercore.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event) Q_DECL_OVERRIDE;

private:
    ServerCore * server;
    Controller * widget;
    QSettings * settings;

    QAction * serverToggleAct;
    QAction * settingsAct;

    QMenu * menu;
    void initControllWidget();
    void initServer();
    void readSettings();
    void writeSettings();
    void initMenu();

signals:

private slots:
    void message(const QString&);
    void onServerStarted(quint16);
    void onServerStopped();
    void serverToggle();
    void settingsDialogue();
};

#endif // MAINWINDOW_H
