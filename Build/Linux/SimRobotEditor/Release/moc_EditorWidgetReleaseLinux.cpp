/****************************************************************************
** Meta object code from reading C++ file 'EditorWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Util/SimRobot/Src/SimRobotEditor/EditorWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditorWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditorWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   13,   13,   13, 0x08,
      62,   14,   13,   13, 0x08,
      82,   14,   13,   13, 0x08,
     102,   14,   13,   13, 0x08,
     122,   13,   13,   13, 0x08,
     129,   13,   13,   13, 0x08,
     135,   13,   13,   13, 0x08,
     142,   13,   13,   13, 0x08,
     164,  155,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditorWidget[] = {
    "EditorWidget\0\0available\0pasteAvailable(bool)\0"
    "updateEditMenu()\0copyAvailable(bool)\0"
    "redoAvailable(bool)\0undoAvailable(bool)\0"
    "save()\0cut()\0copy()\0deleteText()\0"
    "fileName\0openFile(QString)\0"
};

void EditorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditorWidget *_t = static_cast<EditorWidget *>(_o);
        switch (_id) {
        case 0: _t->pasteAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateEditMenu(); break;
        case 2: _t->copyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->redoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->undoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->save(); break;
        case 6: _t->cut(); break;
        case 7: _t->copy(); break;
        case 8: _t->deleteText(); break;
        case 9: _t->openFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditorWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditorWidget::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_EditorWidget,
      qt_meta_data_EditorWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditorWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditorWidget))
        return static_cast<void*>(const_cast< EditorWidget*>(this));
    if (!strcmp(_clname, "SimRobot::Widget"))
        return static_cast< SimRobot::Widget*>(const_cast< EditorWidget*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int EditorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void EditorWidget::pasteAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
