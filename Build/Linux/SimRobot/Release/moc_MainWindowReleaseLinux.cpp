/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Util/SimRobot/Src/SimRobot/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   12,   11,   11, 0x0a,
      39,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      71,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     157,  152,   11,   11, 0x08,
     179,   11,   11,   11, 0x08,
     191,   11,  186,   11, 0x08,
     203,   11,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     223,  218,   11,   11, 0x08,
     271,  242,   11,   11, 0x08,
     346,  337,   11,   11, 0x08,
     367,  337,   11,   11, 0x08,
     397,  389,   11,   11, 0x08,
     429,  421,   11,   11, 0x08,
     461,   11,   11,   11, 0x0a,
     472,   11,   11,   11, 0x0a,
     483,   11,   11,   11, 0x0a,
     493,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0fileName\0openFile(QString)\0"
    "unlockLayout()\0updateFileMenu()\0"
    "updateRecentFileMenu()\0updateViewMenu()\0"
    "updateAddonMenu()\0updateMenuAndToolBar()\0"
    "rate\0setGuiUpdateRate(int)\0open()\0"
    "bool\0closeFile()\0help()\0about()\0name\0"
    "loadAddon(QString)\0fullName,module,object,flags\0"
    "openObject(QString,const SimRobot::Module*,SimRobot::Object*,int)\0"
    "fullName\0closeObject(QString)\0"
    "closedObject(QString)\0visible\0"
    "visibilityChanged(bool)\0old,now\0"
    "focusChanged(QWidget*,QWidget*)\0"
    "simReset()\0simStart()\0simStep()\0"
    "simStop()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->unlockLayout(); break;
        case 2: _t->updateFileMenu(); break;
        case 3: _t->updateRecentFileMenu(); break;
        case 4: _t->updateViewMenu(); break;
        case 5: _t->updateAddonMenu(); break;
        case 6: _t->updateMenuAndToolBar(); break;
        case 7: _t->setGuiUpdateRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->open(); break;
        case 9: { bool _r = _t->closeFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: _t->help(); break;
        case 11: _t->about(); break;
        case 12: _t->loadAddon((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->openObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const SimRobot::Module*(*)>(_a[2])),(*reinterpret_cast< SimRobot::Object*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 14: _t->closeObject((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->closedObject((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->visibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->focusChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 18: _t->simReset(); break;
        case 19: _t->simStart(); break;
        case 20: _t->simStep(); break;
        case 21: _t->simStop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "SimRobot::Application"))
        return static_cast< SimRobot::Application*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
