/****************************************************************************
** Meta object code from reading C++ file 'TeamSelector.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Utils/bush/ui/TeamSelector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TeamSelector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TeamSelector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      29,   13,   13,   13, 0x08,
      42,   13,   13,   13, 0x08,
      55,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TeamSelector[] = {
    "TeamSelector\0\0selectPlayer()\0selectNext()\0"
    "selectPrev()\0saveTeams()\0"
};

void TeamSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TeamSelector *_t = static_cast<TeamSelector *>(_o);
        switch (_id) {
        case 0: _t->selectPlayer(); break;
        case 1: _t->selectNext(); break;
        case 2: _t->selectPrev(); break;
        case 3: _t->saveTeams(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TeamSelector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TeamSelector::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_TeamSelector,
      qt_meta_data_TeamSelector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TeamSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TeamSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TeamSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TeamSelector))
        return static_cast<void*>(const_cast< TeamSelector*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int TeamSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
