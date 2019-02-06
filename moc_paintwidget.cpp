/****************************************************************************
** Meta object code from reading C++ file 'paintwidget.h'
**
** Created: Fri Nov 6 21:46:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "paintwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PaintWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      29,   12,   12,   12, 0x08,
      42,   12,   12,   12, 0x08,
      63,   55,   12,   12, 0x08,
      93,   87,   12,   12, 0x08,
     109,   87,   12,   12, 0x08,
     137,  128,   12,   12, 0x08,
     168,  157,   12,   12, 0x08,
     200,  190,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PaintWidget[] = {
    "PaintWidget\0\0drawRectangle()\0drawSquare()\0"
    "drawCircle()\0newArea\0changeAreaValue(double)\0"
    "value\0drawFilled(int)\0enableEffects(int)\0"
    "redValue\0changeRedColor(int)\0GreenValue\0"
    "changeGreenColor(int)\0blueValue\0"
    "changeBlueColor(int)\0"
};

const QMetaObject PaintWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PaintWidget,
      qt_meta_data_PaintWidget, 0 }
};

const QMetaObject *PaintWidget::metaObject() const
{
    return &staticMetaObject;
}

void *PaintWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PaintWidget))
        return static_cast<void*>(const_cast< PaintWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PaintWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: drawRectangle(); break;
        case 1: drawSquare(); break;
        case 2: drawCircle(); break;
        case 3: changeAreaValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: drawFilled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: enableEffects((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: changeRedColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: changeGreenColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: changeBlueColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
