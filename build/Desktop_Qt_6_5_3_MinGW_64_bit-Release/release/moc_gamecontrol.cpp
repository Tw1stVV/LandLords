/****************************************************************************
** Meta object code from reading C++ file 'gamecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gamecontrol.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGameControlENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGameControlENDCLASS = QtMocHelpers::stringData(
    "GameControl",
    "playerStatusChanged",
    "",
    "Player*",
    "player",
    "PlayerStatus",
    "status",
    "notifyGrabLordBet",
    "point",
    "firstCallLord",
    "gameStatusChanged",
    "GameStatus",
    "notifyPlayHand",
    "Cards",
    "cards",
    "pendingInfo",
    "notifyUpdateBeatPoint",
    "betScore",
    "onGrabBet",
    "onNotifyPlayHand"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGameControlENDCLASS_t {
    uint offsetsAndSizes[40];
    char stringdata0[12];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[7];
    char stringdata5[13];
    char stringdata6[7];
    char stringdata7[18];
    char stringdata8[6];
    char stringdata9[14];
    char stringdata10[18];
    char stringdata11[11];
    char stringdata12[15];
    char stringdata13[6];
    char stringdata14[6];
    char stringdata15[12];
    char stringdata16[22];
    char stringdata17[9];
    char stringdata18[10];
    char stringdata19[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGameControlENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGameControlENDCLASS_t qt_meta_stringdata_CLASSGameControlENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "GameControl"
        QT_MOC_LITERAL(12, 19),  // "playerStatusChanged"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 7),  // "Player*"
        QT_MOC_LITERAL(41, 6),  // "player"
        QT_MOC_LITERAL(48, 12),  // "PlayerStatus"
        QT_MOC_LITERAL(61, 6),  // "status"
        QT_MOC_LITERAL(68, 17),  // "notifyGrabLordBet"
        QT_MOC_LITERAL(86, 5),  // "point"
        QT_MOC_LITERAL(92, 13),  // "firstCallLord"
        QT_MOC_LITERAL(106, 17),  // "gameStatusChanged"
        QT_MOC_LITERAL(124, 10),  // "GameStatus"
        QT_MOC_LITERAL(135, 14),  // "notifyPlayHand"
        QT_MOC_LITERAL(150, 5),  // "Cards"
        QT_MOC_LITERAL(156, 5),  // "cards"
        QT_MOC_LITERAL(162, 11),  // "pendingInfo"
        QT_MOC_LITERAL(174, 21),  // "notifyUpdateBeatPoint"
        QT_MOC_LITERAL(196, 8),  // "betScore"
        QT_MOC_LITERAL(205, 9),  // "onGrabBet"
        QT_MOC_LITERAL(215, 16)   // "onNotifyPlayHand"
    },
    "GameControl",
    "playerStatusChanged",
    "",
    "Player*",
    "player",
    "PlayerStatus",
    "status",
    "notifyGrabLordBet",
    "point",
    "firstCallLord",
    "gameStatusChanged",
    "GameStatus",
    "notifyPlayHand",
    "Cards",
    "cards",
    "pendingInfo",
    "notifyUpdateBeatPoint",
    "betScore",
    "onGrabBet",
    "onNotifyPlayHand"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGameControlENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       7,    3,   67,    2, 0x06,    4 /* Public */,
      10,    1,   74,    2, 0x06,    8 /* Public */,
      12,    2,   77,    2, 0x06,   10 /* Public */,
      15,    2,   82,    2, 0x06,   13 /* Public */,
      16,    1,   87,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    2,   90,    2, 0x08,   18 /* Private */,
      19,    2,   95,    2, 0x08,   21 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,    4,    8,    9,
    QMetaType::Void, 0x80000000 | 11,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 13,    4,   14,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 13,    4,   14,
    QMetaType::Void, QMetaType::Int,   17,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 13,    4,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSGameControlENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGameControlENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGameControlENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameControl, std::true_type>,
        // method 'playerStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player *, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayerStatus, std::false_type>,
        // method 'notifyGrabLordBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'gameStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GameStatus, std::false_type>,
        // method 'notifyPlayHand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Cards &, std::false_type>,
        // method 'pendingInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Cards &, std::false_type>,
        // method 'notifyUpdateBeatPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onGrabBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onNotifyPlayHand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Cards &, std::false_type>
    >,
    nullptr
} };

void GameControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->playerStatusChanged((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayerStatus>>(_a[2]))); break;
        case 1: _t->notifyGrabLordBet((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 2: _t->gameStatusChanged((*reinterpret_cast< std::add_pointer_t<GameStatus>>(_a[1]))); break;
        case 3: _t->notifyPlayHand((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Cards>>(_a[2]))); break;
        case 4: _t->pendingInfo((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Cards>>(_a[2]))); break;
        case 5: _t->notifyUpdateBeatPoint((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->onGrabBet((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->onNotifyPlayHand((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Cards>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameControl::*)(Player * , PlayerStatus );
            if (_t _q_method = &GameControl::playerStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameControl::*)(Player * , int , bool );
            if (_t _q_method = &GameControl::notifyGrabLordBet; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameControl::*)(GameStatus );
            if (_t _q_method = &GameControl::gameStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameControl::*)(Player * , const Cards & );
            if (_t _q_method = &GameControl::notifyPlayHand; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameControl::*)(Player * , const Cards & );
            if (_t _q_method = &GameControl::pendingInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GameControl::*)(int );
            if (_t _q_method = &GameControl::notifyUpdateBeatPoint; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *GameControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGameControlENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GameControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GameControl::playerStatusChanged(Player * _t1, PlayerStatus _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameControl::notifyGrabLordBet(Player * _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameControl::gameStatusChanged(GameStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameControl::notifyPlayHand(Player * _t1, const Cards & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameControl::pendingInfo(Player * _t1, const Cards & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GameControl::notifyUpdateBeatPoint(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
