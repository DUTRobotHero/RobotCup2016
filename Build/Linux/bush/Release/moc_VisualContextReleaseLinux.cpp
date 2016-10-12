/****************************************************************************
** Meta object code from reading C++ file 'VisualContext.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Utils/bush/ui/VisualContext.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VisualContext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VisualContext[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x05,
      42,   14,   14,   14, 0x05,
      54,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   64,   14,   14, 0x0a,
     127,  111,   14,   14, 0x0a,
     161,   15,   14,   14, 0x0a,
     183,   14,   14,   14, 0x0a,
     201,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VisualContext[] = {
    "VisualContext\0\0status\0statusChanged(bool)\0"
    "sCanceled()\0sCancel()\0target,msg\0"
    "doPrint(ConsolePrintTarget,QString)\0"
    "context,cmdLine\0commandExecuted(Context*,QString)\0"
    "commandFinished(bool)\0commandCanceled()\0"
    "cancel()\0"
};

void VisualContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VisualContext *_t = static_cast<VisualContext *>(_o);
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sCanceled(); break;
        case 2: _t->sCancel(); break;
        case 3: _t->doPrint((*reinterpret_cast< ConsolePrintTarget(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->commandExecuted((*reinterpret_cast< Context*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->commandFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->commandCanceled(); break;
        case 7: _t->cancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VisualContext::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VisualContext::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_VisualContext,
      qt_meta_data_VisualContext, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VisualContext::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VisualContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VisualContext::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VisualContext))
        return static_cast<void*>(const_cast< VisualContext*>(this));
    return QFrame::qt_metacast(_clname);
}

int VisualContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void VisualContext::statusChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VisualContext::sCanceled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void VisualContext::sCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
static const uint qt_meta_data_VisualContextDecoration[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   25,   24,   24, 0x0a,
      51,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VisualContextDecoration[] = {
    "VisualContextDecoration\0\0status\0"
    "updateStatus(bool)\0canceled()\0"
};

void VisualContextDecoration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VisualContextDecoration *_t = static_cast<VisualContextDecoration *>(_o);
        switch (_id) {
        case 0: _t->updateStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->canceled(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VisualContextDecoration::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VisualContextDecoration::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_VisualContextDecoration,
      qt_meta_data_VisualContextDecoration, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VisualContextDecoration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VisualContextDecoration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VisualContextDecoration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VisualContextDecoration))
        return static_cast<void*>(const_cast< VisualContextDecoration*>(this));
    return QFrame::qt_metacast(_clname);
}

int VisualContextDecoration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
