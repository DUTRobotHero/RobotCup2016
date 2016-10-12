/****************************************************************************
** Meta object code from reading C++ file 'RobotView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Utils/bush/ui/RobotView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RobotView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RobotView[] = {

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
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   26,   10,   10, 0x0a,
      67,   53,   10,   10, 0x08,
     122,  116,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RobotView[] = {
    "RobotView\0\0robotChanged()\0selected\0"
    "setSelected(bool)\0network,pings\0"
    "setPings(ENetwork,std::map<std::string,double>*)\0"
    "power\0setPower(std::map<std::string,Power>*)\0"
};

void RobotView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RobotView *_t = static_cast<RobotView *>(_o);
        switch (_id) {
        case 0: _t->robotChanged(); break;
        case 1: _t->setSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setPings((*reinterpret_cast< ENetwork(*)>(_a[1])),(*reinterpret_cast< std::map<std::string,double>*(*)>(_a[2]))); break;
        case 3: _t->setPower((*reinterpret_cast< std::map<std::string,Power>*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RobotView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RobotView::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_RobotView,
      qt_meta_data_RobotView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RobotView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RobotView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RobotView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RobotView))
        return static_cast<void*>(const_cast< RobotView*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int RobotView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
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
void RobotView::robotChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
