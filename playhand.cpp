#include "playhand.h"

PlayHand::PlayHand()
{
}

PlayHand::PlayHand(Cards& cards)
{
    // 1. 对扑克牌进行分类：1张的，2张的，3张的，4张的有多少种
    classify(cards);

    // 2. 对牌型进行分类
    judgeCardType();
}

PlayHand::PlayHand(HandType type, Card::CardPoint point, int extra)
{
    m_type = type;
    m_point = point;
    m_extra = extra;
}

Card::CardPoint PlayHand::point() const
{
    return m_point;
}

PlayHand::HandType PlayHand::type() const
{
    return m_type;
}

int PlayHand::extra() const
{
    return m_extra;
}

bool PlayHand::canbeat(const PlayHand& other)
{
    // 我的牌型未知
    if (m_type == Hand_UnKnow)
        return false;

    // 对方不出牌
    if (m_type == Hand_Pass)
        return true;

    // 我是王炸，最大
    if (m_type == Hand_Bomb_Jokers)
        return true;

    // 我是炸弹 从单张到到顺子都没炸弹大
    if (m_type == Hand_Bomb && other.type() >= Hand_Single && other.type() < Hand_Seq_Single)
        return true;

    // 双方牌型一致
    if (m_type == other.type())
    {
        // 连对或顺子双方扑克牌数量要一致
        if (m_type == Hand_Seq_Pair || m_type == Hand_Seq_Single)
        {
            return m_point > other.point() && m_extra == other.extra();
        }
        // 其余的只比较点数
        else
        {
            return m_point > other.point();
        }
    }
    return false;
}

void PlayHand::classify(Cards& cards)
{
    CardList list = cards.toCardList();

    // cardRecord存储cards里相同点数扑克牌数量
    /*
    Card_point  Card_Begin  3  4  5  6  7  8  9  .... Card_End
    cardRecord[]      0     1  2  3  4  5  6  7  ....   16
    cardRecord的下标映射到Card_Point的值，每有一张相同点数的牌就在对应的位置+1
*/
    int cardRecord[Card::Card_End];
    memset(cardRecord, 0, sizeof(int) * Card::Card_End);
    for (int i = 0; i < list.size(); ++i)
    {
        Card c = list.at(i);
        cardRecord[c.getPoint()]++;
    }

    m_oneCard.clear();
    m_twoCard.clear();
    m_threeCard.clear();
    m_fourCard.clear();

    for (int i = 0; i < Card::Card_End; ++i)
    {
        if (cardRecord[i] == 0)
            continue;

        if (cardRecord[i] == 1) // 表示有一张CardPoint(i)这个点数的牌
            m_oneCard.push_back((Card::CardPoint)i);
        else if (cardRecord[i] == 2) // 表示有两张CardPoint(i)这个点数的牌
            m_twoCard.push_back((Card::CardPoint)i);
        else if (cardRecord[i] == 3) // 表示有三张CardPoint(i)这个点数的牌
            m_threeCard.push_back((Card::CardPoint)i);
        else if (cardRecord[i] == 4) // 表示有四张CardPoint(i)这个点数的牌
            m_fourCard.push_back((Card::CardPoint)i);
    }
}

void PlayHand::judgeCardType()
{
    m_type = Hand_UnKnow;
    m_point = Card::Card_Begin;
    m_extra = 0;

    if (isPass())
    {
        m_type = Hand_Pass;
    }

    if (isSingle())
    {
        m_type = Hand_Single;
        m_point = m_oneCard[0];
    }
    else if (isPair())
    {
        m_type = Hand_Pair;
        m_point = m_twoCard[0];
    }
    else if (isTriple())
    {
        m_type = Hand_Triple;
        m_point = m_threeCard[0];
    }
    else if (isTriple())
    {
        m_type = Hand_Triple_Single;
        m_point = m_threeCard[0];
    }
    else if (isTriplePair())
    {
        m_type = Hand_Triple_Pair;
        m_point = m_threeCard[0];
    }
    else if (isPlane())
    {
        m_type = Hand_Plane;
        // 记录飞机里小牌的点数
        m_point = m_threeCard[0];
    }
    else if (isPlaneTwoSingle())
    {
        m_type = Hand_Plane_Two_Single;
        m_point = m_threeCard[0];
    }
    else if (isPlaneTwoPair())
    {
        m_type = Hand_Plane_Two_pair;
        m_point = m_threeCard[0];
    }
    else if (isSeqSingle())
    {
        m_type = Hand_Seq_Single;
        m_point = m_oneCard[0];
        m_extra = m_oneCard.size();
    }
    else if (isSeqPair())
    {
        m_type = Hand_Seq_Pair;
        m_point = m_twoCard[0];
        m_extra = m_twoCard.size();
    }
    else if (isBomb())
    {
        m_type = Hand_Bomb;
        m_point = m_fourCard[0];
    }
    else if (isBombSingle())
    {
        m_type = Hand_Bomb_Single;
        m_point = m_fourCard[0];
    }
    else if (isBombPair())
    {
        m_type = Hand_Bomb_Pair;
        m_point = m_fourCard[0];
    }
    else if (isBombTwoSingle())
    {
        m_type = Hand_Bomb_Two_Single;
        m_point = m_fourCard[0];
    }
    else if (isBombJokers())
    {
        // 王炸是唯一的，不记录点数
        m_type = Hand_Bomb_Jokers;
    }
    else if (isBombJokersSingle())
    {
        m_type = Hand_Bomb_Jokers_Single;
    }
    else if (isBombJokersPair())
    {
        m_type = Hand_Bomb_Jokers_Pair;
    }
    else if (isBombJokersTwoSingle())
    {
        m_type = Hand_Bomb_Jokers_Two_Single;
    }
}

bool PlayHand::isPass()
{
    if (m_oneCard.isEmpty() && m_twoCard.isEmpty() && m_threeCard.isEmpty() && m_fourCard.isEmpty())
        return true;
    return false;
}

bool PlayHand::isSingle()
{
    if (m_oneCard.size() == 1 && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
        return true;
    return false;
}

bool PlayHand::isPair()
{
    if (m_oneCard.isEmpty() && m_twoCard.size() == 1 && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
        return true;
    return false;
}

bool PlayHand::isTriple()
{
    if (m_oneCard.isEmpty() && m_twoCard.isEmpty() && m_threeCard.size() == 1
        && m_fourCard.isEmpty())
        return true;
    return false;
}

bool PlayHand::isTripleSingle()
{
    if (m_oneCard.size() == 1 && m_twoCard.isEmpty() && m_threeCard.size() == 1
        && m_fourCard.isEmpty())
        return true;
    return false;
}

bool PlayHand::isTriplePair()
{
    if (m_oneCard.isEmpty() && m_twoCard.size() == 1 && m_threeCard.size() == 1
        && m_fourCard.isEmpty())
        return true;
    return false;
}

bool PlayHand::isPlane()
{
    if (m_oneCard.isEmpty() && m_twoCard.isEmpty() && m_threeCard.size() == 2
        && m_fourCard.isEmpty())
    {
        // 飞机必须是相邻的两张牌并且不能带有2
        std::sort(m_threeCard.begin(), m_threeCard.end());
        if (m_threeCard[1] - m_threeCard[0] == 1 && m_threeCard[1] != Card::Card_2)
            return true;
    }
    return false;
}

bool PlayHand::isPlaneTwoSingle()
{
    if (m_oneCard.size() == 2 && m_twoCard.isEmpty() && m_threeCard.size() == 2
        && m_fourCard.isEmpty())
    {
        // 飞机必须是相邻的两张牌并且不能是2
        // 两张单排不能是王炸
        std::sort(m_threeCard.begin(), m_threeCard.end());
        std::sort(m_oneCard.begin(), m_oneCard.end());
        if ((m_threeCard[1] - m_threeCard[0] == 1 && m_threeCard[1] != Card::Card_2)
            && (m_oneCard[0] != Card::Card_SJ && m_oneCard[1] != Card::Card_BJ))
            return true;
    }
    return false;
}

bool PlayHand::isPlaneTwoPair()
{
    if (m_oneCard.isEmpty() && m_twoCard.size() == 2 && m_threeCard.size() == 2
        && m_fourCard.isEmpty())
    {
        // 飞机必须是相邻的两张牌并且不能是2
        std::sort(m_threeCard.begin(), m_threeCard.end());
        if (m_threeCard[1] - m_threeCard[0] == 1 && m_threeCard[1] != Card::Card_2)
            return true;
    }
    return false;
}

bool PlayHand::isSeqPair()
{
    if (m_oneCard.isEmpty() && m_twoCard.size() >= 2 && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
    {
        // 只允许相邻的几张牌
        std::sort(m_twoCard.begin(), m_twoCard.end());
        if (m_twoCard.last() - m_twoCard.first() == (m_twoCard.size() - 1)
            && m_twoCard.first() > Card::Card_3 && m_twoCard.last() < Card::Card_2)
            return true;
    }
    return false;
}

bool PlayHand::isSeqSingle()
{
    if (m_oneCard.size() >= 5 && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
    {
        // 只允许相邻的几张牌
        std::sort(m_oneCard.begin(), m_oneCard.end());
        if (m_oneCard.last() - m_oneCard.first() == (m_oneCard.size() - 1)
            && m_oneCard.first() > Card::Card_3 && m_oneCard.last() < Card::Card_2)
            return true;
    }
    return false;
}

bool PlayHand::isBomb()
{
    if (m_oneCard.isEmpty() && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.size() == 1)
        return true;
    return false;
}

bool PlayHand::isBombSingle()
{
    if (m_oneCard.size() == 1 && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.size() == 1)
        return true;
    return false;
}

bool PlayHand::isBombPair()
{
    if (m_oneCard.isEmpty() && m_twoCard.size() == 1 && m_threeCard.isEmpty()
        && m_fourCard.size() == 1)
        return true;
    return false;
}

bool PlayHand::isBombTwoSingle()
{
    if (m_oneCard.size() == 2 && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.size() == 1)
    {
        // 炸弹不能带王炸
        std::sort(m_oneCard.begin(), m_oneCard.end());
        if (m_oneCard.first() != Card::Card_SJ && m_oneCard.last() != Card::Card_BJ)
            return true;
    }
    return false;
}

bool PlayHand::isBombJokers()
{
    if (m_oneCard.size() == 2 && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
    {
        std::sort(m_oneCard.begin(), m_oneCard.end());
        if (m_oneCard.first() == Card::Card_SJ && m_oneCard.last() == Card::Card_BJ)
            return true;
    }
    return false;
}

bool PlayHand::isBombJokersSingle()
{
    if (m_oneCard.size() == 3 && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
    {
        std::sort(m_oneCard.begin(), m_oneCard.end());
        if (m_oneCard[1] == Card::Card_SJ && m_oneCard[2] == Card::Card_BJ)
            return true;
    }
    return false;
}

bool PlayHand::isBombJokersPair()
{
    if (m_oneCard.size() == 2 && m_twoCard.size() == 1 && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
    {
        std::sort(m_oneCard.begin(), m_oneCard.end());
        if (m_oneCard.first() == Card::Card_SJ && m_oneCard.last() == Card::Card_BJ)
            return true;
    }
    return false;
}

bool PlayHand::isBombJokersTwoSingle()
{
    if (m_oneCard.size() == 4 && m_twoCard.isEmpty() && m_threeCard.isEmpty()
        && m_fourCard.isEmpty())
    {
        std::sort(m_oneCard.begin(), m_oneCard.end());
        if (m_oneCard[2] == Card::Card_SJ && m_oneCard[3] == Card::Card_BJ)
            return true;
    }
    return false;
}
