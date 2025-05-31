#ifndef USERPLAYER_H
#define USERPLAYER_H

#include <QObject>
#include "player.h"

class UserPlayer : public Player
{
    Q_OBJECT
public:
    explicit UserPlayer(QObject* parent = nullptr);

    // 使用父类构造函数
    using Player::Player;



    // Player interface
public:
    virtual void prepareCallLord() override;
    virtual void preparePlayHand() override;
};

#endif // USERPLAYER_H
