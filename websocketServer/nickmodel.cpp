#include "nickmodel.h"

NickModel::NickModel():
    nick(""),
    pass(0),
    connected(false),
    connectionId(false)
{

}

NickModel::NickModel(const QString& nick_p, quint64 pass_p):
    nick(nick_p),
    pass(pass_p),
    connected(false),
    connectionId(0)
{

}

void NickModel::connect(quint64 id)
{
    connected = true;
    connectionId = id;
}

void NickModel::disconnect()
{
    connected = false;
    connectionId = 0;
}

bool NickModel::isConnected() const
{
    return connected;
}

quint64 NickModel::getConnectionId() const
{
    return connectionId;
}

bool NickModel::passwordMatch(quint64 pass_p) const
{
    return pass == pass_p;
}

QString NickModel::getNick() const
{
    return nick;
}
