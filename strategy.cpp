#include "strategy.h"

Strategy::Strategy(Player* player, const Cards& cards)
{
    m_player = player;
    m_cards = cards;
}

Cards Strategy::findSamePointCards(Card::CardPoint point, int count)
{
    if (count < 1 || count > 4)
        return Cards();

    // 大小王
    if (point == Card::Card_SJ || point == Card::Card_BJ)
    {
        // 大小王只有一张
        if (count > 1)
        {
            return Cards();
        }

        Card card(point, Card::Suit_Begin);
        if (m_cards.contains(card))
        {
            Cards cards(card);
            return cards;
        }
    }

    // 不是大小王的牌有四个花色，根据point在m_cards遍历四个花色，结果等于count表示找到count个point点数的牌
    int findCount = 0;
    Cards findCards;
    for (int suit = Card::Suit_Begin + 1; suit < Card::Suit_End; ++suit)
    {
        Card card(point, (Card::CardSuit)suit);
        if (m_cards.contains(card))
        {
            findCards.add(card);
            findCount++;
            if (findCount == count)
                return findCards;
        }
    }

    return Cards();
}

QList<Cards> Strategy::findCardsByCount(int count)
{
    if (count < 1 || count > 4)
        return QList<Cards>();

    QList<Cards> cardsArray;
    for (int point = Card::Card_3; point < Card::Card_End; ++point)
    {
        if (m_cards.pointCount((Card::CardPoint)point) == count)
        {
            cardsArray << findSamePointCards((Card::CardPoint)point, count);
        }
    }
    return cardsArray;
}

Cards Strategy::getRangeCards(Card::CardPoint begin, Card::CardPoint end)
{
    Cards cardsRange;
    for (int point = begin; point < end; ++point)
    {
        int count = m_cards.pointCount((Card::CardPoint)point);
        cardsRange << findSamePointCards((Card::CardPoint)point, count);
    }
    return cardsRange;
}

QList<Cards> Strategy::findCardType(PlayHand hand, bool beat)
{
    PlayHand::HandType type = hand.type();
    Card::CardPoint point = hand.point();
    int extra = hand.extra();

    // 确定起始点数
    Card::CardPoint begin = beat ? (Card::CardPoint)(point + 1) : Card::Card_3;

    switch (type)
    {
        case PlayHand::Hand_Single:
            return getCards(begin, 1);
        case PlayHand::Hand_Pair:
            return getCards(begin, 2);
        case PlayHand::Hand_Triple:
            return getCards(begin, 3);
        case PlayHand::Hand_Triple_Single:
            return getTripleSingleOrPair(begin, PlayHand::Hand_Single);
        case PlayHand::Hand_Triple_Pair:
            return getTripleSingleOrPair(begin, PlayHand::Hand_Pair);
        case PlayHand::Hand_Plane:
            return getPlane(begin);
        case PlayHand::Hand_Plane_Two_Single:
            return getPlaneTwoSingleOrTwoPair(begin, PlayHand::Hand_Single);
        case PlayHand::Hand_Plane_Two_pair:
            return getPlaneTwoSingleOrTwoPair(begin, PlayHand::Hand_Pair);
        case PlayHand::Hand_Seq_Pair:
        {
            CardInfo info;
            info.begin = begin;
            info.end = Card::Card_Q;
            info.extra = extra;
            info.beat = beat;
            info.number = 2;
            info.base = 3;
            info.getSeq = &Strategy::getSeqPair;
            return getSeqSingleOrSeqPair(info);
        }
        case PlayHand::Hand_Seq_Single:
        {
            CardInfo info;
            info.begin = begin;
            info.end = Card::Card_10;
            info.extra = extra;
            info.beat = beat;
            info.number = 1;
            info.base = 5;
            info.getSeq = &Strategy::getSeqSingle;
            return getSeqSingleOrSeqPair(info);
        }
        case PlayHand::Hand_Bomb:
            return getBomb(begin);
        default:
            return QList<Cards>();
    }
    return QList<Cards>();
}

QList<Cards> Strategy::getCards(Card::CardPoint point, int number)
{
    QList<Cards> findCardsList;
    for (int pt = point; pt < Card::Card_End; pt++)
    {
        Cards cs = findSamePointCards((Card::CardPoint)pt, number);
        if (!cs.isEmpty())
        {
            findCardsList << cs;
        }
    }

    return findCardsList;
}

QList<Cards> Strategy::getTripleSingleOrPair(Card::CardPoint begin, PlayHand::HandType type)
{
    // 获取三张点数相同的牌的集合
    QList<Cards> findCardsArray = getCards(begin, 3);
    if (!findCardsArray.isEmpty())
    {
        // 在副本中删除这些集合
        Cards remainCard = m_cards;
        remainCard.remove(findCardsArray);

        // 在剩余的牌中选择后面带的单牌或对牌
        Strategy st(m_player, remainCard);
        // 因为三带一或三带二不对后面带的牌有大小要求，所有PlayHand(type, Card::Card_Begin,
        // 0)从最小的开始找
        QList<Cards> cardArray = st.findCardType(PlayHand(type, Card::Card_Begin, 0), false);
        if (!cardArray.isEmpty())
        {
            // 找到后和前面的三张牌组合起来
            for (int i = 0; i < findCardsArray.size(); ++i)
            {
                findCardsArray[i].add(cardArray.at(i));
            }
        }
        else
        {
            // 找不到返回空的容器
            findCardsArray.clear();
        }
    }
    return findCardsArray;
}

QList<Cards> Strategy::getPlane(Card::CardPoint begin)
{
    QList<Cards> findCardsArray;
    for (Card::CardPoint point = begin; point <= Card::Card_K; point = (Card::CardPoint)(point + 1))
    {
        // 根据点数和数量搜索飞机
        Cards previousCards = findSamePointCards(point, 3);
        Cards nextCards = findSamePointCards((Card::CardPoint)(point + 1), 3);
        if (!previousCards.isEmpty() && !nextCards.isEmpty())
        {
            Cards tmp;
            tmp << previousCards << nextCards;
            findCardsArray << tmp;
        }
    }
    return findCardsArray;
}

QList<Cards> Strategy::getPlaneTwoSingleOrTwoPair(Card::CardPoint begin, PlayHand::HandType type)
{
    // 获取飞机
    QList<Cards> findCarsdArray = getPlane(begin);
    if (!findCarsdArray.isEmpty())
    {
        // 在副本中删除这些集合
        Cards remainCard = m_cards;
        remainCard.remove(findCarsdArray);

        // 在剩余的牌中选择后面带的单牌或对牌
        Strategy st(m_player, remainCard);
        // 因为飞机不对后面带的牌有大小要求，所有PlayHand(type, Card::Card_Begin,
        // 0)从最小的开始找
        QList<Cards> cardArray = st.findCardType(PlayHand(type, Card::Card_Begin, 0), false);
        if (cardArray.size() >= 2)
        {
            // 找到后和前面的飞机组合起来
            for (int i = 0; i < findCarsdArray.size(); ++i)
            {
                Cards temp;
                temp << cardArray[0] << cardArray[1];
                findCarsdArray[i].add(temp);
            }
        }
        else
        {
            // 找不到返回空的容器
            findCarsdArray.clear();
        }
    }
    return findCarsdArray;
}

QList<Cards> Strategy::getSeqSingleOrSeqPair(CardInfo info)
{
    QList<Cards> findCarsdArray;
    // 受到extra这个数值的连对长度限制
    if (info.beat)
    {
        // 连对最小需要三个，最多可以连到A
        // 只搜索满足条件的最小连对
        for (Card::CardPoint point = info.begin; point <= info.end;
             point = (Card::CardPoint)(point + 1))
        {
            bool found = true;
            Cards seqCards;

            // 里层循环搜索point开始往后extra张牌是否是连续的对子
            for (int i = 0; i < info.extra; ++i)
            {
                Cards cards = findSamePointCards((Card::CardPoint)(point + i), info.number);
                if (cards.isEmpty() || (Card::CardPoint)(point + info.extra) >= Card::Card_2)
                {
                    found = false;
                    seqCards.clear();
                    break;
                }
                else
                    seqCards << cards;
            }
            if (found)
            {
                findCarsdArray << seqCards;
                return findCarsdArray;
            }
        }
    }
    // 不受到extra这个数值的连对长度限制
    else
    {
        for (Card::CardPoint point = info.begin; point <= info.end;
             point = (Card::CardPoint)(point + 1))
        {
            // 将这个最基础的连对存储起来
            Cards baseSeq = (this->*info.getSeq)(point);
            if (baseSeq.isEmpty())
                continue;

            findCarsdArray << baseSeq;

            int followed = info.base;
            Cards alreadyFollowedCards; // 累加存储后续找到的连对
            /*
             *while循环找到了满足调整的对,将新的对子添加到alreadyFollowedCards
             *在将baseSeq和alreadyFollowedCards组合起来添加到findCarsdArray
             *findCarsdArray会是33,44,55  33,44,55,66     33,44,55,66,77.....这样的组合
             */
            while (true)
            {
                Card::CardPoint followedPoint = (Card::CardPoint)(point + followed);
                // 是否超出连对上限
                if (followedPoint >= Card::Card_2)
                    break;

                // 判断是否是对子
                Cards followedCards = findSamePointCards(followedPoint, info.number);
                if (followedCards.isEmpty())
                    break;
                else
                {
                    // 与基础连对组合起来加入findCarsdArray
                    alreadyFollowedCards << followedCards;
                    Cards newCards = baseSeq;
                    newCards << alreadyFollowedCards;
                    // findCarsdArray是存储所有连对的数组
                    // 如：33,44,55    33,44,55,66     44,55,66,77
                    findCarsdArray << newCards;
                    followed++;
                }
            }
        }
    }
    return findCarsdArray;
}

QList<Cards> Strategy::getBomb(Card::CardPoint begin)
{
    QList<Cards> findCarsdArray;
    for (Card::CardPoint point = begin; point < Card::Card_End;
         point = (Card::CardPoint)(point + 1))
    {
        Cards cs = findSamePointCards(point, 4);
        if (!cs.isEmpty())
            findCarsdArray << cs;
    }
    return findCarsdArray;
}

Cards Strategy::getSeqSingle(Card::CardPoint point)
{
    Cards c0 = findSamePointCards(point, 1);
    Cards c1 = findSamePointCards((Card::CardPoint)(point + 1), 1);
    Cards c2 = findSamePointCards((Card::CardPoint)(point + 2), 1);
    Cards c3 = findSamePointCards((Card::CardPoint)(point + 3), 1);
    Cards c4 = findSamePointCards((Card::CardPoint)(point + 4), 1);
    Cards seq;
    if (!c0.isEmpty() && !c1.isEmpty() && !c2.isEmpty() && !c3.isEmpty() && !c4.isEmpty())
        seq << c0 << c1 << c2 << c3 << c4;
    return seq;
}

Cards Strategy::getSeqPair(Card::CardPoint point)
{
    Cards c0 = findSamePointCards(point, 2);
    Cards c1 = findSamePointCards((Card::CardPoint)(point + 1), 2);
    Cards c2 = findSamePointCards((Card::CardPoint)(point + 2), 2);
    Cards seq;
    if (!c0.isEmpty() && !c1.isEmpty() && !c2.isEmpty())
        seq << c0 << c1 << c2;
    return seq;
}
