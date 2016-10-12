/****************************************************************************
** Meta object code from reading C++ file 'ColorCalibrationView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Src/Controller/Views/ColorCalibrationView/ColorCalibrationView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorCalibrationView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ColorCalibrationWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x0a,
      52,   23,   23,   23, 0x0a,
      75,   23,   23,   23, 0x0a,
      98,   23,   23,   23, 0x08,
     127,  121,   23,   23, 0x08,
     141,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ColorCalibrationWidget[] = {
    "ColorCalibrationWidget\0\0"
    "currentCalibrationChanged()\0"
    "undoColorCalibration()\0redoColorCalibration()\0"
    "saveColorCalibration()\0color\0colorAct(int)\0"
    "expandColorAct()\0"
};

void ColorCalibrationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorCalibrationWidget *_t = static_cast<ColorCalibrationWidget *>(_o);
        switch (_id) {
        case 0: _t->currentCalibrationChanged(); break;
        case 1: _t->undoColorCalibration(); break;
        case 2: _t->redoColorCalibration(); break;
        case 3: _t->saveColorCalibration(); break;
        case 4: _t->colorAct((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->expandColorAct(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ColorCalibrationWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ColorCalibrationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ColorCalibrationWidget,
      qt_meta_data_ColorCalibrationWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorCalibrationWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorCalibrationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorCalibrationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorCalibrationWidget))
        return static_cast<void*>(const_cast< ColorCalibrationWidget*>(this));
    if (!strcmp(_clname, "SimRobot::Widget"))
        return static_cast< SimRobot::Widget*>(const_cast< ColorCalibrationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ColorCalibrationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
