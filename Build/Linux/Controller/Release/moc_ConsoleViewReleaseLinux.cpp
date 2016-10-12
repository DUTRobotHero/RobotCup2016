/****************************************************************************
** Meta object code from reading C++ file 'ConsoleView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/Views/ConsoleView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConsoleView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConsoleWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   15,   14,   14, 0x08,
      66,   15,   14,   14, 0x08,
      86,   15,   14,   14, 0x08,
     106,   14,   14,   14, 0x08,
     112,   14,   14,   14, 0x08,
     119,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConsoleWidget[] = {
    "ConsoleWidget\0\0available\0pasteAvailable(bool)\0"
    "copyAvailable(bool)\0redoAvailable(bool)\0"
    "undoAvailable(bool)\0cut()\0copy()\0"
    "deleteText()\0"
};

void ConsoleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConsoleWidget *_t = static_cast<ConsoleWidget *>(_o);
        switch (_id) {
        case 0: _t->pasteAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->copyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->redoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->undoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->cut(); break;
        case 5: _t->copy(); break;
        case 6: _t->deleteText(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConsoleWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConsoleWidget::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_ConsoleWidget,
      qt_meta_data_ConsoleWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConsoleWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConsoleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConsoleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConsoleWidget))
        return static_cast<void*>(const_cast< ConsoleWidget*>(this));
    if (!strcmp(_clname, "SimRobot::Widget"))
        return static_cast< SimRobot::Widget*>(const_cast< ConsoleWidget*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int ConsoleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ConsoleWidget::pasteAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
