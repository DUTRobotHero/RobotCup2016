/****************************************************************************
** Meta object code from reading C++ file 'TeamView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Utils/bush/ui/TeamView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TeamView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TeamView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x08,
      45,   38,    9,    9, 0x08,
      73,   64,    9,    9, 0x08,
     105,   98,    9,    9, 0x08,
     138,  132,    9,    9, 0x08,
     173,  166,    9,    9, 0x08,
     199,  192,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TeamView[] = {
    "TeamView\0\0color\0colorChanged(QString)\0"
    "number\0numberChanged(int)\0location\0"
    "locationChanged(QString)\0config\0"
    "wlanConfigChanged(QString)\0build\0"
    "buildConfigChanged(QString)\0volume\0"
    "volumeChanged(int)\0device\0"
    "deployDeviceChanged(QString)\0"
};

void TeamView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TeamView *_t = static_cast<TeamView *>(_o);
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->numberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->locationChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->wlanConfigChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->buildConfigChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->volumeChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->deployDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TeamView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TeamView::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_TeamView,
      qt_meta_data_TeamView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TeamView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TeamView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TeamView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TeamView))
        return static_cast<void*>(const_cast< TeamView*>(this));
    return QFrame::qt_metacast(_clname);
}

int TeamView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
