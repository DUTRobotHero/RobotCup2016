/****************************************************************************
** Meta object code from reading C++ file 'BHToolBar.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/BHToolBar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BHToolBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BHToolBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      19,   10,   10,   10, 0x08,
      29,   10,   10,   10, 0x08,
      43,   10,   10,   10, 0x08,
      54,   10,   10,   10, 0x08,
      74,   67,   10,   10, 0x08,
      90,   10,   10,   10, 0x08,
     109,   10,   10,   10, 0x08,
     130,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BHToolBar[] = {
    "BHToolBar\0\0stand()\0sitDown()\0setPlayDead()\0"
    "setStand()\0setSitDown()\0active\0"
    "headAngle(bool)\0pressChestButton()\0"
    "releaseChestButton()\0unchangeButtons()\0"
};

void BHToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BHToolBar *_t = static_cast<BHToolBar *>(_o);
        switch (_id) {
        case 0: _t->stand(); break;
        case 1: _t->sitDown(); break;
        case 2: _t->setPlayDead(); break;
        case 3: _t->setStand(); break;
        case 4: _t->setSitDown(); break;
        case 5: _t->headAngle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->pressChestButton(); break;
        case 7: _t->releaseChestButton(); break;
        case 8: _t->unchangeButtons(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BHToolBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BHToolBar::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BHToolBar,
      qt_meta_data_BHToolBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BHToolBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BHToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BHToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BHToolBar))
        return static_cast<void*>(const_cast< BHToolBar*>(this));
    return QObject::qt_metacast(_clname);
}

int BHToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
