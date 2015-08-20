/****************************************************************************
** Meta object code from reading C++ file 'clientcore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clientcore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientcore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientCore_t {
    QByteArrayData data[26];
    char stringdata[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientCore_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientCore_t qt_meta_stringdata_ClientCore = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ClientCore"
QT_MOC_LITERAL(1, 11, 7), // "message"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "info"
QT_MOC_LITERAL(4, 25, 5), // "state"
QT_MOC_LITERAL(5, 31, 17), // "ClientCore::State"
QT_MOC_LITERAL(6, 49, 11), // "nickChanged"
QT_MOC_LITERAL(7, 61, 10), // "nickDenied"
QT_MOC_LITERAL(8, 72, 5), // "start"
QT_MOC_LITERAL(9, 78, 4), // "stop"
QT_MOC_LITERAL(10, 83, 4), // "soft"
QT_MOC_LITERAL(11, 88, 9), // "reconnect"
QT_MOC_LITERAL(12, 98, 11), // "sendMessage"
QT_MOC_LITERAL(13, 110, 12), // "socketOpened"
QT_MOC_LITERAL(14, 123, 15), // "socketConnected"
QT_MOC_LITERAL(15, 139, 18), // "socketDisconnected"
QT_MOC_LITERAL(16, 158, 11), // "socketError"
QT_MOC_LITERAL(17, 170, 10), // "receivedId"
QT_MOC_LITERAL(18, 181, 7), // "WSetId*"
QT_MOC_LITERAL(19, 189, 15), // "receivedMessage"
QT_MOC_LITERAL(20, 205, 9), // "WMessage*"
QT_MOC_LITERAL(21, 215, 12), // "receivedNick"
QT_MOC_LITERAL(22, 228, 14), // "WNickResponse*"
QT_MOC_LITERAL(23, 243, 18), // "receivedClientList"
QT_MOC_LITERAL(24, 262, 12), // "WClientList*"
QT_MOC_LITERAL(25, 275, 27) // "socketBinaryMessageReceived"

    },
    "ClientCore\0message\0\0info\0state\0"
    "ClientCore::State\0nickChanged\0nickDenied\0"
    "start\0stop\0soft\0reconnect\0sendMessage\0"
    "socketOpened\0socketConnected\0"
    "socketDisconnected\0socketError\0"
    "receivedId\0WSetId*\0receivedMessage\0"
    "WMessage*\0receivedNick\0WNickResponse*\0"
    "receivedClientList\0WClientList*\0"
    "socketBinaryMessageReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientCore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  109,    2, 0x06 /* Public */,
       3,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,
       6,    1,  120,    2, 0x06 /* Public */,
       7,    0,  123,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  124,    2, 0x0a /* Public */,
       9,    1,  125,    2, 0x0a /* Public */,
       9,    0,  128,    2, 0x2a /* Public | MethodCloned */,
      11,    0,  129,    2, 0x0a /* Public */,
      12,    1,  130,    2, 0x0a /* Public */,
      13,    0,  133,    2, 0x08 /* Private */,
      14,    0,  134,    2, 0x08 /* Private */,
      15,    0,  135,    2, 0x08 /* Private */,
      16,    0,  136,    2, 0x08 /* Private */,
      17,    1,  137,    2, 0x08 /* Private */,
      19,    1,  140,    2, 0x08 /* Private */,
      21,    1,  143,    2, 0x08 /* Private */,
      23,    1,  146,    2, 0x08 /* Private */,
      25,    1,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 24,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void ClientCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientCore *_t = static_cast<ClientCore *>(_o);
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->info((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->state((*reinterpret_cast< ClientCore::State(*)>(_a[1]))); break;
        case 3: _t->nickChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->nickDenied(); break;
        case 5: _t->start(); break;
        case 6: _t->stop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->stop(); break;
        case 8: _t->reconnect(); break;
        case 9: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->socketOpened(); break;
        case 11: _t->socketConnected(); break;
        case 12: _t->socketDisconnected(); break;
        case 13: _t->socketError(); break;
        case 14: _t->receivedId((*reinterpret_cast< WSetId*(*)>(_a[1]))); break;
        case 15: _t->receivedMessage((*reinterpret_cast< WMessage*(*)>(_a[1]))); break;
        case 16: _t->receivedNick((*reinterpret_cast< WNickResponse*(*)>(_a[1]))); break;
        case 17: _t->receivedClientList((*reinterpret_cast< WClientList*(*)>(_a[1]))); break;
        case 18: _t->socketBinaryMessageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientCore::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientCore::message)) {
                *result = 0;
            }
        }
        {
            typedef void (ClientCore::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientCore::info)) {
                *result = 1;
            }
        }
        {
            typedef void (ClientCore::*_t)(ClientCore::State );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientCore::state)) {
                *result = 2;
            }
        }
        {
            typedef void (ClientCore::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientCore::nickChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (ClientCore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientCore::nickDenied)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject ClientCore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientCore.data,
      qt_meta_data_ClientCore,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientCore::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientCore.stringdata))
        return static_cast<void*>(const_cast< ClientCore*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void ClientCore::message(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientCore::info(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientCore::state(ClientCore::State _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientCore::nickChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientCore::nickDenied()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
