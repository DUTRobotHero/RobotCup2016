/****************************************************************************
** Meta object code from reading C++ file 'RegisteredDockWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Util/SimRobot/Src/SimRobot/RegisteredDockWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RegisteredDockWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegisteredDockWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   22,   21,   21, 0x05,
      51,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   71,   21,   21, 0x08,
     103,   21,   21,   21, 0x08,
     110,   21,   21,   21, 0x08,
     124,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RegisteredDockWidget[] = {
    "RegisteredDockWidget\0\0object\0"
    "closedObject(QString)\0closedContextMenu()\0"
    "visible\0visibilityChanged(bool)\0copy()\0"
    "exportAsSvg()\0exportAsPng()\0"
};

void RegisteredDockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RegisteredDockWidget *_t = static_cast<RegisteredDockWidget *>(_o);
        switch (_id) {
        case 0: _t->closedObject((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->closedContextMenu(); break;
        case 2: _t->visibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->copy(); break;
        case 4: _t->exportAsSvg(); break;
        case 5: _t->exportAsPng(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RegisteredDockWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RegisteredDockWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_RegisteredDockWidget,
      qt_meta_data_RegisteredDockWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegisteredDockWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegisteredDockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegisteredDockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegisteredDockWidget))
        return static_cast<void*>(const_cast< RegisteredDockWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int RegisteredDockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RegisteredDockWidget::closedObject(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RegisteredDockWidget::closedContextMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
