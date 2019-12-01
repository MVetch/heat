/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "stopped"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "finished"
QT_MOC_LITERAL(4, 29, 7), // "onClick"
QT_MOC_LITERAL(5, 37, 25), // "on_openSettings_triggered"
QT_MOC_LITERAL(6, 63, 25), // "on_loadSettings_triggered"
QT_MOC_LITERAL(7, 89, 7), // "aboutQt"
QT_MOC_LITERAL(8, 97, 8), // "callHelp"
QT_MOC_LITERAL(9, 106, 5), // "clear"
QT_MOC_LITERAL(10, 112, 6), // "output"
QT_MOC_LITERAL(11, 119, 9), // "showError"
QT_MOC_LITERAL(12, 129, 15), // "updateEveryStep"
QT_MOC_LITERAL(13, 145, 25), // "updateProgressBarMaxValue"
QT_MOC_LITERAL(14, 171, 26), // "on_sliderDeep_valueChanged"
QT_MOC_LITERAL(15, 198, 5), // "value"
QT_MOC_LITERAL(16, 204, 25), // "on_sliderDeep_sliderMoved"
QT_MOC_LITERAL(17, 230, 8), // "position"
QT_MOC_LITERAL(18, 239, 26) // "on_pushButton_stop_clicked"

    },
    "MainWindow\0stopped\0\0finished\0onClick\0"
    "on_openSettings_triggered\0"
    "on_loadSettings_triggered\0aboutQt\0"
    "callHelp\0clear\0output\0showError\0"
    "updateEveryStep\0updateProgressBarMaxValue\0"
    "on_sliderDeep_valueChanged\0value\0"
    "on_sliderDeep_sliderMoved\0position\0"
    "on_pushButton_stop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    1,   98,    2, 0x08 /* Private */,
      12,    1,  101,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x08 /* Private */,
      16,    1,  110,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int,
    QMetaType::Int,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->stopped();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->finished();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->onClick(); break;
        case 3: _t->on_openSettings_triggered(); break;
        case 4: _t->on_loadSettings_triggered(); break;
        case 5: _t->aboutQt(); break;
        case 6: _t->callHelp(); break;
        case 7: _t->clear(); break;
        case 8: _t->output(); break;
        case 9: _t->showError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->updateEveryStep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateProgressBarMaxValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_sliderDeep_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_sliderDeep_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_stop_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef int (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::stopped)) {
                *result = 0;
                return;
            }
        }
        {
            typedef int (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::finished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
int MainWindow::stopped()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int MainWindow::finished()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
