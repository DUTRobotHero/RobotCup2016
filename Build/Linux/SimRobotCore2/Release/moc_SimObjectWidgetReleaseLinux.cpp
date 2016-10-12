/****************************************************************************
** Meta object code from reading C++ file 'SimObjectWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Util/SimRobot/Src/SimRobotCore2/SimObjectWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimObjectWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimObjectWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      30,   24,   16,   16, 0x08,
      55,   24,   16,   16, 0x08,
      80,   24,   16,   16, 0x08,
     111,  106,   16,   16, 0x08,
     142,  137,   16,   16, 0x08,
     166,  161,   16,   16, 0x08,
     185,  179,   16,   16, 0x08,
     203,  137,   16,   16, 0x08,
     220,   16,   16,   16, 0x08,
     234,   16,   16,   16, 0x08,
     253,   16,   16,   16, 0x08,
     265,  106,   16,   16, 0x08,
     298,  287,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimObjectWidget[] = {
    "SimObjectWidget\0\0copy()\0style\0"
    "setSurfaceShadeMode(int)\0"
    "setPhysicsShadeMode(int)\0"
    "setDrawingsShadeMode(int)\0flag\0"
    "setDrawingsOcclusion(int)\0mode\0"
    "setCameraMode(int)\0fovy\0setFovY(int)\0"
    "plane\0setDragPlane(int)\0setDragMode(int)\0"
    "resetCamera()\0toggleCameraMode()\0"
    "fitCamera()\0toggleRenderFlag(int)\0"
    "resolution\0exportAsImage(int)\0"
};

void SimObjectWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimObjectWidget *_t = static_cast<SimObjectWidget *>(_o);
        switch (_id) {
        case 0: _t->copy(); break;
        case 1: _t->setSurfaceShadeMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setPhysicsShadeMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setDrawingsShadeMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setDrawingsOcclusion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setCameraMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setFovY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setDragPlane((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setDragMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->resetCamera(); break;
        case 10: _t->toggleCameraMode(); break;
        case 11: _t->fitCamera(); break;
        case 12: _t->toggleRenderFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->exportAsImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SimObjectWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimObjectWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_SimObjectWidget,
      qt_meta_data_SimObjectWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimObjectWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimObjectWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimObjectWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimObjectWidget))
        return static_cast<void*>(const_cast< SimObjectWidget*>(this));
    if (!strcmp(_clname, "SimRobot::Widget"))
        return static_cast< SimRobot::Widget*>(const_cast< SimObjectWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int SimObjectWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
