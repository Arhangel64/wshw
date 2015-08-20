#ifndef CLIENTSETTINGSDIALOGUE_H
#define CLIENTSETTINGSDIALOGUE_H

#include <QDialog>
#include <QSpinBox>
#include <QLineEdit>

class ClientSettingsDialogue : public QDialog
{
    Q_OBJECT
public:
    explicit ClientSettingsDialogue(QWidget *parent = 0);

    void setNick(const QString&);
    void setAddr(const QString&);
    void setPort(quint16);

    QString getNick() const;
    QString getPass() const;
    QString getAddr() const;
    quint16 getPort() const;

private:
    QLineEdit *nick;
    QLineEdit *pass;
    QLineEdit *addr;
    QSpinBox *port;

signals:

public slots:
};

#endif // CLIENTSETTINGSDIALOGUE_H
