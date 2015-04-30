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
    QByteArrayData data[16];
    char stringdata[249];
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
QT_MOC_LITERAL(8, 88, 13), // "alertDbChange"
QT_MOC_LITERAL(9, 102, 20), // "on_btnCocher_clicked"
QT_MOC_LITERAL(10, 123, 22), // "on_btnDecocher_clicked"
QT_MOC_LITERAL(11, 146, 22), // "on_radioSiteFr_toggled"
QT_MOC_LITERAL(12, 169, 7), // "checked"
QT_MOC_LITERAL(13, 177, 22), // "on_radioSiteEn_toggled"
QT_MOC_LITERAL(14, 200, 24), // "on_radioUrlPerso_toggled"
QT_MOC_LITERAL(15, 225, 23) // "on_radioDistant_toggled"

    },
    "OptionDialog\0acceptedOptionDevises\0\0"
    "restartMyApp\0checkboxClicked\0i\0"
    "selectionBase\0accept\0alertDbChange\0"
    "on_btnCocher_clicked\0on_btnDecocher_clicked\0"
    "on_radioSiteFr_toggled\0checked\0"
    "on_radioSiteEn_toggled\0on_radioUrlPerso_toggled\0"
    "on_radioDistant_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   76,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      13,    1,   87,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,

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
        case 5: _t->alertDbChange(); break;
        case 6: _t->on_btnCocher_clicked(); break;
        case 7: _t->on_btnDecocher_clicked(); break;
        case 8: _t->on_radioSiteFr_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_radioSiteEn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_radioUrlPerso_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_radioDistant_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
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
