#ifndef ANIMATIONWINDOW_H
#define ANIMATIONWINDOW_H

#include <QWidget>

class AnimationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AnimationWindow(QWidget* parent = nullptr);
    void showBetScore(int bet);

    enum AnimationType
    {
        Pair_Seq,    // 连对
        Sequent,     // 顺子
        Plane,       // 飞机
        Bomb,        // 炸弹
        Bomb_Jokers, // 王炸
        Bet,         // 下注展示点数
    };

signals:

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent* event) override;

private:
    QPixmap m_image;
};

#endif // ANIMATIONWINDOW_H
