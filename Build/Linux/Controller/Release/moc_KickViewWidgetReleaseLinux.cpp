/****************************************************************************
** Meta object code from reading C++ file 'KickViewWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/Views/KickView/KickViewWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KickViewWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KickViewWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x08,
      40,   16,   15,   15, 0x08,
      63,   16,   15,   15, 0x08,
      87,   16,   15,   15, 0x08,
     103,   16,   15,   15, 0x08,
     118,   16,   15,   15, 0x08,
     133,   16,   15,   15, 0x08,
     151,   16,   15,   15, 0x08,
     166,   16,   15,   15, 0x08,
     186,   15,   15,   15, 0x08,
     200,   15,   15,   15, 0x08,
     222,   15,   15,   15, 0x08,
     240,   15,   15,   15, 0x08,
     262,   15,   15,   15, 0x08,
     275,   15,   15,   15, 0x08,
     294,  288,   15,   15, 0x08,
     311,   15,   15,   15, 0x08,
     329,  324,   15,   15, 0x08,
     349,  347,   15,   15, 0x08,
     379,  374,   15,   15, 0x08,
     418,  374,   15,   15, 0x08,
     474,  456,   15,   15, 0x08,
     493,   15,   15,   15, 0x08,
     526,  520,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KickViewWidget[] = {
    "KickViewWidget\0\0value\0setDrawings(bool)\0"
    "setSingleDrawing(bool)\0setReachedDrawing(bool)\0"
    "setEditor(bool)\0setTra2d(bool)\0"
    "setTra1d(bool)\0setVelocity(bool)\0"
    "setAccel(bool)\0setFollowMode(bool)\0"
    "removePhase()\0addPhaseAfterActual()\0"
    "playWholeMotion()\0playMotionTilActive()\0"
    "resetRobot()\0standRobot()\0state\0"
    "setMirrored(int)\0recordPose()\0limb\0"
    "setStiffness(int)\0i\0transparencyChanged(int)\0"
    "item\0updateCommonParameters(QStandardItem*)\0"
    "updatePhaseParameters(QStandardItem*)\0"
    "fromIndex,toIndex\0movePhase(int,int)\0"
    "setSelectedFromEditor(int)\0plane\0"
    "setDragPlane(int)\0"
};

void KickViewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KickViewWidget *_t = static_cast<KickViewWidget *>(_o);
        switch (_id) {
        case 0: _t->setDrawings((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setSingleDrawing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setReachedDrawing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setEditor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setTra2d((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setTra1d((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setVelocity((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setAccel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setFollowMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->removePhase(); break;
        case 10: _t->addPhaseAfterActual(); break;
        case 11: _t->playWholeMotion(); break;
        case 12: _t->playMotionTilActive(); break;
        case 13: _t->resetRobot(); break;
        case 14: _t->standRobot(); break;
        case 15: _t->setMirrored((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->recordPose(); break;
        case 17: _t->setStiffness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->transparencyChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 19: _t->updateCommonParameters((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 20: _t->updatePhaseParameters((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 21: _t->movePhase((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->setSelectedFromEditor((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 23: _t->setDragPlane((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KickViewWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KickViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_KickViewWidget,
      qt_meta_data_KickViewWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KickViewWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KickViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KickViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KickViewWidget))
        return static_cast<void*>(const_cast< KickViewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int KickViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
