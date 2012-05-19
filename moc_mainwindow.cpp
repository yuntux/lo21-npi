/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat May 19 21:46:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
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
     341,   11,   11,   11, 0x0a,
     369,   11,   11,   11, 0x0a,

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
    "_modComplexeONClicked(bool)\0"
    "_modComplexeOFFClicked(bool)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
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
        switch (_id) {
        case 0: num0Clicked(); break;
        case 1: num1Clicked(); break;
        case 2: num2Clicked(); break;
        case 3: num3Clicked(); break;
        case 4: num4Clicked(); break;
        case 5: num5Clicked(); break;
        case 6: num6Clicked(); break;
        case 7: num7Clicked(); break;
        case 8: num8Clicked(); break;
        case 9: num9Clicked(); break;
        case 10: POINTClicked(); break;
        case 11: ESPACEClicked(); break;
        case 12: FACTORIELClicked(); break;
        case 13: ADDITIONNERClicked(); break;
        case 14: SOUSTRAIREClicked(); break;
        case 15: MULTIPLIERClicked(); break;
        case 16: DIVISERClicked(); break;
        case 17: _clavierBasicStateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _clavierAvanceStateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _modComplexeONClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _modComplexeOFFClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
