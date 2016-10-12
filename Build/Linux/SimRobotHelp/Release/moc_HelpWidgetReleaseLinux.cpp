/****************************************************************************
** Meta object code from reading C++ file 'HelpWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Util/SimRobot/Src/SimRobotHelp/HelpWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HelpWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HelpWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     131,  126,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HelpWidget[] = {
    "HelpWidget\0\0tabIndex\0tabChangeRequested(int)\0"
    "navigateHome()\0locatePage()\0"
    "navigateBackward()\0navigateForward()\0"
    "searchInvoked()\0hits\0searchFinished(int)\0"
};

void HelpWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HelpWidget *_t = static_cast<HelpWidget *>(_o);
        switch (_id) {
        case 0: _t->tabChangeRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->navigateHome(); break;
        case 2: _t->locatePage(); break;
        case 3: _t->navigateBackward(); break;
        case 4: _t->navigateForward(); break;
        case 5: _t->searchInvoked(); break;
        case 6: _t->searchFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HelpWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HelpWidget::staticMetaObject = {
    { &QSplitter::staticMetaObject, qt_meta_stringdata_HelpWidget,
      qt_meta_data_HelpWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HelpWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HelpWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HelpWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HelpWidget))
        return static_cast<void*>(const_cast< HelpWidget*>(this));
    if (!strcmp(_clname, "SimRobot::Widget"))
        return static_cast< SimRobot::Widget*>(const_cast< HelpWidget*>(this));
    return QSplitter::qt_metacast(_clname);
}

int HelpWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void HelpWidget::tabChangeRequested(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
