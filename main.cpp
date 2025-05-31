#include "gamepanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gamepanel w;
    w.show();
    return a.exec();
}
