#include "cardpenal.h"

#include "player.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

CardPenal::CardPenal(QWidget* parent)
    : QWidget{parent}
{
    m_isfront = true;
}

void CardPenal::setImage(QPixmap& front, QPixmap& back)
{
    m_front = front;
    m_back  = back;
}

QPixmap CardPenal::getImage()
{
    return m_front;
}

void CardPenal::setFrontSide(bool flag)
{
    m_isfront = flag;
}

bool CardPenal::isFrontSide()
{
    return m_isfront;
}

void CardPenal::setSelected(bool flag)
{
    m_selected = flag;
}

bool CardPenal::isSelecetd()
{
    return m_selected;
}

void CardPenal::setCard(Card& card)
{
    m_card = card;
}

Card CardPenal::getCard()
{
    return m_card;
}

void CardPenal::setOwner(Player* player)
{
    m_owner = player;
}

Player* CardPenal::getOwner()
{
    return m_owner;
}

void CardPenal::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    if (m_isfront)
        painter.drawPixmap(this->rect(), m_front);
    else
        painter.drawPixmap(this->rect(), m_back);
    event->accept();
}


void CardPenal::mousePressEvent(QMouseEvent* event) {}
