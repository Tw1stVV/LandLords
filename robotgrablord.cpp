#include "robotgrablord.h"
#include "robot.h"
RobotGrabLord::RobotGrabLord(Robot* robot, QObject* parent) : m_robot(robot), QThread(parent)
{
}

void RobotGrabLord::run()
{
    msleep(2000);
    m_robot->thinkingCallLord();
}
