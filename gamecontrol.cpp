#include "gamecontrol.h"
#include "userplayer.h"
#include "robot.h"
#include "player.h"

#include <QRandomGenerator>

GameControl::GameControl(QObject* parent) : QObject{parent}
{
}

void GameControl::playerInit()
{
    m_user = new UserPlayer("自己", this);
    m_robotLeft = new Robot("机器人A", this);
    m_robotRight = new Robot("机器人B", this);

    // 头像显示方位
    m_robotLeft->setDirection(Player::Left);
    m_robotRight->setDirection(Player::Right);
    m_user->setDirection(Player::Right);

    // 性别
    Player::Sex sex;
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotLeft->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotRight->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_user->setSex(sex);

    // 分数
    clearPlayerScore();

    // 出牌顺序 逆时针
    //    机器人A        机器人B
    //            自己

    m_user->setPrevious(m_robotLeft);
    m_user->setNext(m_robotRight);

    m_robotLeft->setPrevious(m_user);
    m_robotLeft->setNext(m_robotRight);

    m_robotRight->setPrevious(m_robotLeft);
    m_robotRight->setNext(m_user);

    // 指定当前玩家为user,游戏初始化时玩家可以先抢地主
    m_curPlayer = m_user;
}

Robot* GameControl::robotLeft() const
{
    return m_robotLeft;
}

Robot* GameControl::robotRight() const
{
    return m_robotRight;
}

UserPlayer* GameControl::user() const
{
    return m_user;
}

Player* GameControl::curPlayer() const
{
    return m_curPlayer;
}

void GameControl::setCurPlayer(Player* newCurPlayer)
{
    m_curPlayer = newCurPlayer;
}

Cards GameControl::pendCards() const
{
    return m_pendCards;
}

Player* GameControl::pendPlayer() const
{
    return m_pendPlayer;
}

void GameControl::initCards()
{
    m_allCards.clear();
    for (int p = Card::Card_Begin + 1; p < Card::Card_SJ; ++p)
    {
        for (int s = Card::Suit_Begin; s < Card::Suit_End; ++s)
        {
            Card c((Card::CardPoint)p, (Card::CardSuit)s);
            m_allCards.add(c);
        }
    }
    m_allCards.add(Card(Card::Card_SJ, Card::Suit_Begin));
    m_allCards.add(Card(Card::Card_BJ, Card::Suit_Begin));
}

Card GameControl::takeOneCard()
{
    return m_allCards.takeRandCard();
}

Cards GameControl::getSurplusCards()
{
    return m_allCards;
}

void GameControl::resetCardData()
{
    // 洗牌
    initCards();
    // 清空玩家手中的牌
    m_user->clearCards();
    m_robotLeft->clearCards();
    m_robotRight->clearCards();
    // 初始化出牌玩家和牌
    m_pendPlayer = nullptr;
    m_pendCards.clear();
}

void GameControl::startLordCard()
{
    m_curPlayer->prepareCallLord();
}

void GameControl::becomeLord(Player* player)
{
    // 设置身份
    player->setRole(Player::Lord);
    player->previous()->setRole(Player::Farmer);
    player->previous()->setRole(Player::Farmer);

    // 获取地主牌
    m_curPlayer = player;
    player->storeDispatchCard(m_allCards);

    // 准备出牌
    m_curPlayer->preparePlayHand();
}

void GameControl::clearPlayerScore()
{
    m_user->setScore(0);
    m_robotLeft->setScore(0);
    m_robotRight->setScore(0);
}
