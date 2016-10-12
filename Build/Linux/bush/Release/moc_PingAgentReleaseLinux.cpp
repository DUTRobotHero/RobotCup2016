/****************************************************************************
** Meta object code from reading C++ file 'PingAgent.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Utils/bush/agents/PingAgent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PingAgent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PingAgent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   10,   10,   10, 0x0a,
      93,   10,   10,   10, 0x0a,
     112,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PingAgent[] = {
    "PingAgent\0\0network,pings\0"
    "pingChanged(ENetwork,std::map<std::string,double>*)\0"
    "robotsChanged()\0pingReadableWLAN()\0"
    "pingReadableLAN()\0"
};

void PingAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PingAgent *_t = static_cast<PingAgent *>(_o);
        switch (_id) {
        case 0: _t->pingChanged((*reinterpret_cast< ENetwork(*)>(_a[1])),(*reinterpret_cast< std::map<std::string,double>*(*)>(_a[2]))); break;
        case 1: _t->robotsChanged(); break;
        case 2: _t->pingReadableWLAN(); break;
        case 3: _t->pingReadableLAN(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PingAgent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PingAgent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PingAgent,
      qt_meta_data_PingAgent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PingAgent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PingAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PingAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PingAgent))
        return static_cast<void*>(const_cast< PingAgent*>(this));
    return QObject::qt_metacast(_clname);
}

int PingAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PingAgent::pingChanged(ENetwork _t1, std::map<std::string,double> * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
