#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include "card.h"
#include "cards.h"
#include <QMainWindow>
class CardPenal;
class GameControl;
class Player;
class QLabel;
QT_BEGIN_NAMESPACE
namespace Ui
{
    class Gamepanel;
}
QT_END_NAMESPACE

class Gamepanel : public QMainWindow
{
    Q_OBJECT

public:
    Gamepanel(QWidget* parent = nullptr);
    ~Gamepanel();

private:
    // 初始化游戏控制类
    void gameControlInit();

    // 更新分数面板分数
    void updatePlayerScore();

    // 初始化图片
    void initCardMap();
    // 将对应位置的牌切割并保存到卡牌窗口并添加到m_cardMap
    void cropImage(QPixmap& pix, int x, int y, Card& c);

    // 初始化按钮组
    void initButtonGroup();

    // 初始化玩家在窗口中的上下文环境
    void initPlayerContext();

private:
    enum CardAlign
    {
        Horizontal,
        Vertical
    };
    struct PlayContext
    {
        // 1. 玩家扑克牌显示的区域
        QRect cardRect;

        // 2. 出牌的区域
        QRect playHandRect;

        // 3. 扑克牌对齐方式
        CardAlign align;

        // 4. 扑克牌显示正面or背面
        bool isFrontSide;

        // 5. 游戏过程中的提升信息，如：不要
        QLabel* info;

        // 6. 玩家头像
        QLabel* roleImg;

        // 7. 玩家刚打出的牌
        Cards lastCards;
    };

private:
    Ui::Gamepanel* ui;
    QPixmap m_backgroundImage;
    GameControl* m_gameCtl;
    QList<Player*> m_playerList;             // 保存玩家类
    QMap<Card, CardPenal*> m_cardMap;        // 保存卡牌和对应的卡牌窗口
    QSize m_cardSize;                        // 每张扑克牌的大小
    QPixmap m_cardBackgroundImage;           // 扑克牌背面图片
    QMap<Player*, PlayContext> m_contextMap; // 存储玩家上下文信息

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent* event) override;
};
#endif // GAMEPANEL_H
