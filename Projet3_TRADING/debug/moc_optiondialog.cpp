/****************************************************************************
** Meta object code from reading C++ file 'optiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../optiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OptionDialog_t {
    QByteArrayData data[11];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionDialog_t qt_meta_stringdata_OptionDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "OptionDialog"
QT_MOC_LITERAL(1, 13, 21), // "acceptedOptionDevises"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "restartMyApp"
QT_MOC_LITERAL(4, 49, 15), // "checkboxClicked"
QT_MOC_LITERAL(5, 65, 1), // "i"
QT_MOC_LITERAL(6, 67, 13), // "selectionBase"
QT_MOC_LITERAL(7, 81, 6), // "accept"
QT_MOC_LITERAL(8, 88, 11), // "alertDbName"
QT_MOC_LITERAL(9, 100, 20), // "on_btnCocher_clicked"
QT_MOC_LITERAL(10, 121, 22) // "on_btnDecocher_clicked"

    },
    "OptionDialog\0acceptedOptionDevises\0\0"
    "restartMyApp\0checkboxClicked\0i\0"
    "selectionBase\0accept\0alertDbName\0"
    "on_btnCocher_clicked\0on_btnDecocher_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   56,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionDialog *_t = static_cast<OptionDialog *>(_o);
        switch (_id) {
        case 0: _t->acceptedOptionDevises(); break;
        case 1: _t->restartMyApp(); break;
        case 2: _t->checkboxClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->selectionBase(); break;
        case 4: _t->accept(); break;
        case 5: _t->alertDbName(); break;
        case 6: _t->on_btnCocher_clicked(); break;
        case 7: _t->on_btnDecocher_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OptionDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OptionDialog::acceptedOptionDevises)) {
                *result = 0;
            }
        }
        {
            typedef void (OptionDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OptionDialog::restartMyApp)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject OptionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionDialog.data,
      qt_meta_data_OptionDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OptionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OptionDialog.stringdata))
        return static_cast<void*>(const_cast< OptionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OptionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void OptionDialog::acceptedOptionDevises()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void OptionDialog::restartMyApp()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
