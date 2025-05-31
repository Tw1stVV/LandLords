#include "card.h"
#include <algorithm>

Card::Card()
{
}

Card::CardPoint Card::getPoint() const
{
    return m_point;
}

void Card::setPoint(CardPoint newPoint)
{
    m_point = newPoint;
}

Card::CardSuit Card::getSuit() const
{
    return m_suit;
}

void Card::setSuit(CardSuit newSuit)
{
    m_suit = newSuit;
}

bool lessSort(const Card &c1, const Card &c2)
{
    if (c1.getPoint() == c2.getPoint())
    {
        return c1.getSuit() < c2.getSuit();
    }
    else
    {
        return c1.getPoint() < c2.getPoint();
    }
}

bool greaterSort(const Card &c1, const Card &c2)
{
    return !lessSort(c1, c2);
}

bool operator==(const Card &left, const Card &right)
{
    return (left.getPoint() == right.getPoint())
           && (left.getSuit() == right.getSuit());
}

uint qHash(const Card &card)
{
    return card.getPoint() * 100 + card.getSuit();
}
