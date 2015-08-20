#ifndef SETTINGSDIALOGUE_H
#define SETTINGSDIALOGUE_H

#include <QDialog>
#include <QWidget>

class SettingsDialogue : public QDialog
{
    Q_OBJECT

public:
    SettingsDialogue(QWidget *parent = 0);
    ~SettingsDialogue();
};

class Setting
{
public:
    Setting(QVariant, );

}

#endif // SETTINGSDIALOGUE_H
