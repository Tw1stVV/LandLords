#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include "cards.h"
class UserPlayer;
class Robot;
class Player;

class GameControl : public QObject
{
    Q_OBJECT
public:
    explicit GameControl(QObject* parent = nullptr);
    // 游戏状态
    enum GameStatus
    {
        DispatchCord,
        CallingLord,
        PlayingHand
    };

    // 玩家状态
    enum PlayerStatus
    {
        ThkingForCallLorc,
        ThkingForPlayHand,
        Winning
    };

    // 玩家初始化
    void playerInit();

    // 玩家实例对象
    Robot* robotLeft() const;
    Robot* robotRight() const;
    UserPlayer* user() const;
    Player* curPlayer() const;
    void setCurPlayer(Player* newCurPlayer);

    // 出牌玩家和打出的牌
    Cards pendCards() const;
    Player* pendPlayer() const;

    // 扑克牌初始化
    void initCards();

    // 发出一张牌
    Card takeOneCard();

    // 获取剩余的地主牌
    Cards getSurplusCards();

    // 重置卡牌数据
    void resetCardData();

    // 准备叫地主
    void startLordCard();

    // 成为地主
    void becomeLord(Player* player);

    // 清空玩家得分
    void clearPlayerScore();

signals:
private:
    Robot* m_robotLeft;
    Robot* m_robotRight;
    UserPlayer* m_user;
    Player* m_curPlayer;  // 当前的玩家
    Cards m_pendCards;    // 打出的牌
    Player* m_pendPlayer; // 出牌的玩家
    Cards m_allCards;
};

#endif // GAMECONTROL_H
