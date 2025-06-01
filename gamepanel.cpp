#include "cardpenal.h"
#include "gamecontrol.h"
#include "gamepanel.h"
#include "robot.h"
#include "ui_gamepanel.h"
#include "userplayer.h"
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QRandomGenerator>

Gamepanel::Gamepanel(QWidget* parent) : QMainWindow(parent), ui(new Ui::Gamepanel)
{
    ui->setupUi(this);

    // 1. 背景图
    int num = QRandomGenerator::global()->bounded(1, 11); //[1,10)
    QString path = QString(":/images/background-%1.png").arg(num);
    m_backgroundImage.load(path);

    // 2. 设置窗口标题，大小，图标
    this->setFixedSize(1000, 650); // 不允许改变窗口大小
    this->setWindowTitle("嘿嘿斗地主");
    this->setWindowIcon(QIcon(":/images/logo.ico"));

    // 3. 实例化游戏控制类对象GameControl
    gameControlInit();

    // 4. 更新玩家得分
    updatePlayerScore();

    // 5. 切割扑克牌图片
    initCardMap();

    // 6. 初始化游戏中的按钮组
    initButtonGroup();

    // 7. 初始化玩家在窗口中的上下文化境
    initPlayerContext();
}

Gamepanel::~Gamepanel()
{
    delete ui;
}

void Gamepanel::gameControlInit()
{
    m_gameCtl = new GameControl(this);
    // 初始化玩家对象
    m_gameCtl->playerInit();
    Robot* left = m_gameCtl->robotLeft();
    Robot* right = m_gameCtl->robotRight();
    UserPlayer* user = m_gameCtl->user();
    // 存储顺序 leftRobot rightRobot User
    m_playerList << left << right << user;
}

void Gamepanel::updatePlayerScore()
{
    ui->scorePanel->setScore(
        m_playerList[0]->score(), m_playerList[1]->score(), m_playerList[2]->score());
}

void Gamepanel::initCardMap()
{
    // 1. 加载大图
    QPixmap pixmap(":/images/card.png"); // 图片按每张扑克牌来切割共有13列5行

    // 2. 计算扑克牌大小
    m_cardSize.setWidth(pixmap.width() / 13);
    m_cardSize.setHeight(pixmap.height() / 5);

    // 3. 扑克牌背面，正常花色牌，大小王
    /*
        ————————x
        |
        |
        |
        y
    */
    // 扑克牌背面
    m_cardBackgroundImage = pixmap.copy(
        m_cardSize.width() * 2, m_cardSize.height() * 4, m_cardSize.width(), m_cardSize.height());

    // 正常花色牌
    for (int y = 0, suit = Card::Suit_Begin; suit < Card::Suit_End; ++y, ++suit)
    {
        for (int x = 0, pt = Card::Card_Begin; pt < Card::Card_End; ++x, ++pt)
        {
            Card c((Card::CardPoint)pt, (Card::CardSuit)suit);
            // 裁剪图片
            cropImage(pixmap, m_cardSize.width() * x, m_cardSize.height() * y, c);
        }
    }

    // 大小王
    Card c(Card::Card_SJ, Card::Suit_Begin); // 小王
    cropImage(pixmap, 0, m_cardSize.height() * 4, c);
    c.setPoint(Card::Card_BJ); // 大王
    cropImage(pixmap, 1, m_cardSize.height() * 4, c);
}

void Gamepanel::cropImage(QPixmap& pix, int x, int y, Card& c)
{
    // 裁剪出对应位置的牌
    QPixmap sub = pix.copy(x, y, m_cardSize.width(), m_cardSize.height());

    // 创建CardPenal对象
    CardPenal* penal = new CardPenal(this);

    // 设置penal对象正面和背面图片
    penal->setImage(sub, m_backgroundImage);

    // 将牌设置到penal对象中
    penal->setCard(c);
    penal->hide();
    m_cardMap.insert(c, penal);
}

void Gamepanel::initButtonGroup()
{
    ui->btnGroup->initButtons();
    ui->btnGroup->selectPanel(ButtonGroup::Start);
    // 后续再处理
    connect(ui->btnGroup, &ButtonGroup::startGame, this, [=]() {});
    connect(ui->btnGroup, &ButtonGroup::playHand, this, [=]() {});
    connect(ui->btnGroup, &ButtonGroup::pass, this, [=]() {});
    connect(ui->btnGroup, &ButtonGroup::betPoint, this, [=]() {});
}

void Gamepanel::initPlayerContext()
{
    // 1. 放置玩家扑克牌的区域
    const QRect cardsRect[] = {
        QRect(90, 130, 100, height() - 200),                    // 左侧机器人
        QRect(rect().right() - 190, 130, 100, height() - 200),  // 右侧机器人
        QRect(250, rect().bottom() - 120, width() - 500, 100)}; // 玩家

    // 2. 玩家出牌的区域
    const QRect playHandRect[] = {
        QRect(260, 150, 100, 100),                              // 左侧机器人
        QRect(rect().right() - 360, 150, 100, 100),             // 右侧机器人
        QRect(150, rect().bottom() - 290, width() - 300, 105)}; // 玩家

    // 3. 玩家头像位置
    const QPoint roleImgPos[] = {
        QPoint(cardsRect[0].left() - 80, cardsRect[0].height() / 2 + 20),  // 左侧机器人
        QPoint(cardsRect[1].right() + 10, cardsRect[1].height() / 2 + 20), // 右侧机器人
        QPoint(cardsRect[2].right() - 10, cardsRect[2].top() - 10)};       // 玩家

    // 4. 逐个遍历m_playerList将其添加到m_contextMap
    int index = m_playerList.indexOf(m_gameCtl->user()); // 记录非机器人玩家在list里的索引
    for (int i = 0; i < m_playerList.size(); ++i)
    {
        PlayContext context;
        context.cardRect = cardsRect[i];
        context.playHandRect = playHandRect[i];
        context.align = i == index ? Horizontal : Vertical;
        context.isFrontSide = i == index ? true : false;

        // 提示信息
        context.info = new QLabel(this);
        context.info->resize(160, 98);
        context.info->hide();
        // 提示信息显示到出牌区域的中间
        QRect rect = playHandRect[i];
        float x = rect.left() + (rect.width() - context.info->width()) / 2;
        float y = rect.top() + (rect.height() - context.info->height()) / 2;
        QPoint pt(x, y);
        context.info->move(pt);

        // 玩家头像
        context.roleImg = new QLabel(this);
        context.roleImg->resize(89, 120);
        context.roleImg->hide();
        context.roleImg->move(roleImgPos[i]);

        m_contextMap.insert(m_playerList[i], context);
    }
}

void Gamepanel::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    p.drawPixmap(this->rect(), m_backgroundImage);
    event->accept();
}
