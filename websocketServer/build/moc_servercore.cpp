/****************************************************************************
** Meta object code from reading C++ file 'servercore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../servercore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servercore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerCore_t {
    QByteArrayData data[20];
    char stringdata[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerCore_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerCore_t qt_meta_stringdata_ServerCore = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ServerCore"
QT_MOC_LITERAL(1, 11, 7), // "started"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "port"
QT_MOC_LITERAL(4, 25, 7), // "stopped"
QT_MOC_LITERAL(5, 33, 14), // "newConnnection"
QT_MOC_LITERAL(6, 48, 7), // "message"
QT_MOC_LITERAL(7, 56, 5), // "start"
QT_MOC_LITERAL(8, 62, 4), // "stop"
QT_MOC_LITERAL(9, 67, 15), // "onNewConnection"
QT_MOC_LITERAL(10, 83, 20), // "onSocketDisconnected"
QT_MOC_LITERAL(11, 104, 15), // "onBinaryMessage"
QT_MOC_LITERAL(12, 120, 11), // "castMessage"
QT_MOC_LITERAL(13, 132, 9), // "WMessage*"
QT_MOC_LITERAL(14, 142, 21), // "castClientNickUpdated"
QT_MOC_LITERAL(15, 164, 22), // "castSocketDisconnected"
QT_MOC_LITERAL(16, 187, 10), // "changeNick"
QT_MOC_LITERAL(17, 198, 13), // "WNickRequest*"
QT_MOC_LITERAL(18, 212, 15), // "sendClientsList"
QT_MOC_LITERAL(19, 228, 7) // "Client*"

    },
    "ServerCore\0started\0\0port\0stopped\0"
    "newConnnection\0message\0start\0stop\0"
    "onNewConnection\0onSocketDisconnected\0"
    "onBinaryMessage\0castMessage\0WMessage*\0"
    "castClientNickUpdated\0castSocketDisconnected\0"
    "changeNick\0WNickRequest*\0sendClientsList\0"
    "Client*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerCore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,
       6,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   92,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    1,   98,    2, 0x08 /* Private */,
      12,    1,  101,    2, 0x08 /* Private */,
      14,    2,  104,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    1,  112,    2, 0x08 /* Private */,
      18,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,

       0        // eod
};

void ServerCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerCore *_t = static_cast<ServerCore *>(_o);
        switch (_id) {
        case 0: _t->started((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 1: _t->stopped(); break;
        case 2: _t->newConnnection(); break;
        case 3: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->start((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 5: _t->stop(); break;
        case 6: _t->onNewConnection(); break;
        case 7: _t->onSocketDisconnected(); break;
        case 8: _t->onBinaryMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 9: _t->castMessage((*reinterpret_cast< WMessage*(*)>(_a[1]))); break;
        case 10: _t->castClientNickUpdated((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->castSocketDisconnected((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 12: _t->changeNick((*reinterpret_cast< WNickRequest*(*)>(_a[1]))); break;
        case 13: _t->sendClientsList((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServerCore::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerCore::started)) {
                *result = 0;
            }
        }
        {
            typedef void (ServerCore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerCore::stopped)) {
                *result = 1;
            }
        }
        {
            typedef void (ServerCore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerCore::newConnnection)) {
                *result = 2;
            }
        }
        {
            typedef void (ServerCore::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerCore::message)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ServerCore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerCore.data,
      qt_meta_data_ServerCore,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ServerCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerCore::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ServerCore.stringdata))
        return static_cast<void*>(const_cast< ServerCore*>(this));
    return QObject::qt_metacast(_clname);
}

int ServerCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ServerCore::started(quint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerCore::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ServerCore::newConnnection()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ServerCore::message(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
