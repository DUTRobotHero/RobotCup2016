/****************************************************************************
** Meta object code from reading C++ file 'Context.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Utils/bush/cmdlib/Context.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Context.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContextRunnable[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   17,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ContextRunnable[] = {
    "ContextRunnable\0\0status\0sFinished(bool)\0"
};

void ContextRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ContextRunnable *_t = static_cast<ContextRunnable *>(_o);
        switch (_id) {
        case 0: _t->sFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ContextRunnable::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ContextRunnable::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ContextRunnable,
      qt_meta_data_ContextRunnable, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContextRunnable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContextRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContextRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContextRunnable))
        return static_cast<void*>(const_cast< ContextRunnable*>(this));
    return QThread::qt_metacast(_clname);
}

int ContextRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ContextRunnable::sFinished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_Context[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,    9,    8,    8, 0x05,
      59,   52,    8,    8, 0x05,
      75,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   52,    8,    8, 0x0a,
     114,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Context[] = {
    "Context\0\0context,cmdLine\0"
    "sExecute(Context*,QString)\0status\0"
    "sFinished(bool)\0sCancelFinished()\0"
    "threadFinished(bool)\0cancel()\0"
};

void Context::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Context *_t = static_cast<Context *>(_o);
        switch (_id) {
        case 0: _t->sExecute((*reinterpret_cast< Context*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->sFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sCancelFinished(); break;
        case 3: _t->threadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->cancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Context::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Context::staticMetaObject = {
    { &AbstractConsole::staticMetaObject, qt_meta_stringdata_Context,
      qt_meta_data_Context, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Context::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Context::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Context::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Context))
        return static_cast<void*>(const_cast< Context*>(this));
    return AbstractConsole::qt_metacast(_clname);
}

int Context::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractConsole::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Context::sExecute(Context * _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Context::sFinished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Context::sCancelFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
