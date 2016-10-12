/****************************************************************************
** Meta object code from reading C++ file 'PropertyManager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/Views/DataView/PropertyManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PropertyManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PropertyManager[] = {

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
      30,   17,   16,   16, 0x0a,
      76,   61,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PropertyManager[] = {
    "PropertyManager\0\0property,val\0"
    "setValue(QtProperty*,QVariant)\0"
    "property,value\0slotValueChanged(QtProperty*,QVariant)\0"
};

void PropertyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PropertyManager *_t = static_cast<PropertyManager *>(_o);
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 1: _t->slotValueChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PropertyManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PropertyManager::staticMetaObject = {
    { &QtVariantPropertyManager::staticMetaObject, qt_meta_stringdata_PropertyManager,
      qt_meta_data_PropertyManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PropertyManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PropertyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PropertyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PropertyManager))
        return static_cast<void*>(const_cast< PropertyManager*>(this));
    return QtVariantPropertyManager::qt_metacast(_clname);
}

int PropertyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtVariantPropertyManager::qt_metacall(_c, _id, _a);
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
