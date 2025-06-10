#include "animationwindow.h"

#include <QPainter>
#include <QTimer>
#include <QPaintEvent>

AnimationWindow::AnimationWindow(QWidget* parent) : QWidget{parent}
{
}

void AnimationWindow::showBetScore(int bet)
{
    if (bet == 1)
    {
        m_image.load(":/images/score1.png");
    }
    else if (bet == 2)
    {
        m_image.load(":/images/score2.png");
    }
    else if (bet == 3)
    {
        m_image.load(":/images/score3.png");
    }
    this->update();
    QTimer::singleShot(1500, this, &AnimationWindow::hide);
}

void AnimationWindow::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, m_image.width(), m_image.height(), m_image);
    event->accept();
}
