/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat 19. May 16:24:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      26,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      54,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
      82,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     110,   11,   11,   11, 0x0a,
     124,   11,   11,   11, 0x0a,
     138,   11,   11,   11, 0x0a,
     152,   11,   11,   11, 0x0a,
     167,   11,   11,   11, 0x0a,
     183,   11,   11,   11, 0x0a,
     202,   11,   11,   11, 0x0a,
     223,   11,   11,   11, 0x0a,
     243,   11,   11,   11, 0x0a,
     263,   11,   11,   11, 0x0a,
     280,   11,   11,   11, 0x0a,
     310,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0num0Clicked()\0num1Clicked()\0"
    "num2Clicked()\0num3Clicked()\0num4Clicked()\0"
    "num5Clicked()\0num6Clicked()\0num7Clicked()\0"
    "num8Clicked()\0num9Clicked()\0POINTClicked()\0"
    "ESPACEClicked()\0FACTORIELClicked()\0"
    "ADDITIONNERClicked()\0SOUSTRAIREClicked()\0"
    "MULTIPLIERClicked()\0DIVISERClicked()\0"
    "_clavierBasicStateChange(int)\0"
    "_clavierAvanceStateChange(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->num0Clicked(); break;
        case 1: _t->num1Clicked(); break;
        case 2: _t->num2Clicked(); break;
        case 3: _t->num3Clicked(); break;
        case 4: _t->num4Clicked(); break;
        case 5: _t->num5Clicked(); break;
        case 6: _t->num6Clicked(); break;
        case 7: _t->num7Clicked(); break;
        case 8: _t->num8Clicked(); break;
        case 9: _t->num9Clicked(); break;
        case 10: _t->POINTClicked(); break;
        case 11: _t->ESPACEClicked(); break;
        case 12: _t->FACTORIELClicked(); break;
        case 13: _t->ADDITIONNERClicked(); break;
        case 14: _t->SOUSTRAIREClicked(); break;
        case 15: _t->MULTIPLIERClicked(); break;
        case 16: _t->DIVISERClicked(); break;
        case 17: _t->_clavierBasicStateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->_clavierAvanceStateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
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
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
