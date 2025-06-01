#include "gamepanel.h"
#include "ui_gamepanel.h"

Gamepanel::Gamepanel(QWidget* parent) : QMainWindow(parent), ui(new Ui::Gamepanel)
{
    ui->setupUi(this);
    ui->btnGroup->initButtons();
    ui->btnGroup->selectPanel(ButtonGroup::Start);

    // 1. 背景图
    // 2. 窗口标题的大小
    // 3. 实例化游戏控制类对象GameControl
    // 4. 玩家得分
    // 5. 切割扑克牌图片
    // 6. 初始化游戏中的按钮组
    // 7. 初始化玩家在窗口中的上下文化境
}

Gamepanel::~Gamepanel()
{
    delete ui;
}
