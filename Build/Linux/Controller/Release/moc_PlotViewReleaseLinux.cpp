/****************************************************************************
** Meta object code from reading C++ file 'PlotView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/Views/PlotView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlotView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlotWidget[] = {

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
      12,   11,   11,   11, 0x0a,
      35,   11,   11,   11, 0x0a,
      53,   11,   11,   11, 0x0a,
      72,   11,   11,   11, 0x0a,
      93,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PlotWidget[] = {
    "PlotWidget\0\0determineMinMaxValue()\0"
    "toggleDrawUnits()\0toggleDrawLegend()\0"
    "toggleAntialiasing()\0exportAsGnuplot()\0"
};

void PlotWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlotWidget *_t = static_cast<PlotWidget *>(_o);
        switch (_id) {
        case 0: _t->determineMinMaxValue(); break;
        case 1: _t->toggleDrawUnits(); break;
        case 2: _t->toggleDrawLegend(); break;
        case 3: _t->toggleAntialiasing(); break;
        case 4: _t->exportAsGnuplot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PlotWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PlotWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlotWidget,
      qt_meta_data_PlotWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlotWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlotWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlotWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlotWidget))
        return static_cast<void*>(const_cast< PlotWidget*>(this));
    if (!strcmp(_clname, "SimRobot::Widget"))
        return static_cast< SimRobot::Widget*>(const_cast< PlotWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlotWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
