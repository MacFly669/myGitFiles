/****************************************************************************
** Meta object code from reading C++ file 'cotationsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cotationsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cotationsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CotationsView_t {
    QByteArrayData data[10];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CotationsView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CotationsView_t qt_meta_stringdata_CotationsView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CotationsView"
QT_MOC_LITERAL(1, 14, 9), // "dataSaved"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "erreurConDb"
QT_MOC_LITERAL(4, 37, 15), // "emitReloadCombo"
QT_MOC_LITERAL(5, 53, 6), // "reload"
QT_MOC_LITERAL(6, 60, 9), // "updateUrl"
QT_MOC_LITERAL(7, 70, 8), // "loadData"
QT_MOC_LITERAL(8, 79, 17), // "afficheProprietes"
QT_MOC_LITERAL(9, 97, 21) // "on_pushButton_clicked"

    },
    "CotationsView\0dataSaved\0\0erreurConDb\0"
    "emitReloadCombo\0reload\0updateUrl\0"
    "loadData\0afficheProprietes\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CotationsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CotationsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CotationsView *_t = static_cast<CotationsView *>(_o);
        switch (_id) {
        case 0: _t->dataSaved(); break;
        case 1: _t->erreurConDb(); break;
        case 2: _t->emitReloadCombo(); break;
        case 3: _t->reload(); break;
        case 4: _t->updateUrl(); break;
        case 5: _t->loadData(); break;
        case 6: _t->afficheProprietes(); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CotationsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CotationsView::dataSaved)) {
                *result = 0;
            }
        }
        {
            typedef void (CotationsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CotationsView::erreurConDb)) {
                *result = 1;
            }
        }
        {
            typedef void (CotationsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CotationsView::emitReloadCombo)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CotationsView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CotationsView.data,
      qt_meta_data_CotationsView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CotationsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CotationsView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CotationsView.stringdata))
        return static_cast<void*>(const_cast< CotationsView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CotationsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CotationsView::dataSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CotationsView::erreurConDb()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CotationsView::emitReloadCombo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
