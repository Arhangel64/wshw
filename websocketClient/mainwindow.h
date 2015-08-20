#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSettings>
#include <QCloseEvent>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include "dialogue.h"
#include "clientcore.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event) Q_DECL_OVERRIDE;

private:
    MainWidget *mainWidget;
    ClientCore *core;
    QSettings *settings;
    QMenu *menu;
    QAction *connectSocketAct;
    QAction *disconnectSocketAct;
    QAction *settingsAct;
    QLabel *statusLabel;
    void readSettings();
    void initDialogueWidget();
    void writeSettings();
    void initMenu();
    void initStatusBar();
    void initCore();

signals:

public slots:

private slots:
    void settingsDialogue();
    void stateChanged(ClientCore::State);
    void serverMessage(const QString&, const QString&);
    void serverInfo(const QString&);
    void serverNickAccepted(const QString&);
    void serverNickDenied();
};

#endif // MAINWINDOW_H
