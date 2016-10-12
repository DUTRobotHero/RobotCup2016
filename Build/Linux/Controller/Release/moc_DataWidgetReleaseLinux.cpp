/****************************************************************************
** Meta object code from reading C++ file 'DataWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/Views/DataView/DataWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      33,   25,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DataWidget[] = {
    "DataWidget\0\0setPressed()\0checked\0"
    "autoSetToggled(bool)\0unchangedPressed()\0"
};

void DataWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DataWidget *_t = static_cast<DataWidget *>(_o);
        switch (_id) {
        case 0: _t->setPressed(); break;
        case 1: _t->autoSetToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->unchangedPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DataWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DataWidget::staticMetaObject = {
    { &QtTreePropertyBrowser::staticMetaObject, qt_meta_stringdata_DataWidget,
      qt_meta_data_DataWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataWidget))
        return static_cast<void*>(const_cast< DataWidget*>(this));
    if (!strcmp(_clname, "SimRobot::Widget"))
        return static_cast< SimRobot::Widget*>(const_cast< DataWidget*>(this));
    return QtTreePropertyBrowser::qt_metacast(_clname);
}

int DataWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtTreePropertyBrowser::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
