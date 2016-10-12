/****************************************************************************
** Meta object code from reading C++ file 'PropertyEditorFactory.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/Views/DataView/PropertyEditorFactory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PropertyEditorFactory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PropertyEditorFactory[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   23,   22,   22, 0x09,
      61,   23,   22,   22, 0x09,
      98,   23,   22,   22, 0x09,
     139,  133,   22,   22, 0x09,
     180,  172,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PropertyEditorFactory[] = {
    "PropertyEditorFactory\0\0newValue\0"
    "slotSpinBoxValueChanged(int)\0"
    "slotFloatSpinBoxValueChanged(double)\0"
    "slotAngleEditorValueChanged(float)\0"
    "index\0slotAngleEditorUnityChanged(int)\0"
    "pObject\0slotEditorDestroyed(QObject*)\0"
};

void PropertyEditorFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PropertyEditorFactory *_t = static_cast<PropertyEditorFactory *>(_o);
        switch (_id) {
        case 0: _t->slotSpinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotFloatSpinBoxValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->slotAngleEditorValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->slotAngleEditorUnityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotEditorDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PropertyEditorFactory::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PropertyEditorFactory::staticMetaObject = {
    { &QtVariantEditorFactory::staticMetaObject, qt_meta_stringdata_PropertyEditorFactory,
      qt_meta_data_PropertyEditorFactory, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PropertyEditorFactory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PropertyEditorFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PropertyEditorFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PropertyEditorFactory))
        return static_cast<void*>(const_cast< PropertyEditorFactory*>(this));
    return QtVariantEditorFactory::qt_metacast(_clname);
}

int PropertyEditorFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtVariantEditorFactory::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_AngleEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      45,   39,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   13,   12,   12, 0x08,
      83,   39,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AngleEditor[] = {
    "AngleEditor\0\0value\0valueChanged(float)\0"
    "index\0unityChanged(int)\0updateValue(double)\0"
    "updateUnity(int)\0"
};

void AngleEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AngleEditor *_t = static_cast<AngleEditor *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->unityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->updateUnity((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AngleEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AngleEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AngleEditor,
      qt_meta_data_AngleEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AngleEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AngleEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AngleEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AngleEditor))
        return static_cast<void*>(const_cast< AngleEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int AngleEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AngleEditor::valueChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AngleEditor::unityChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
