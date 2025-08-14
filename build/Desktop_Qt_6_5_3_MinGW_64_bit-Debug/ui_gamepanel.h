/********************************************************************************
** Form generated from reading UI file 'gamepanel.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPANEL_H
#define UI_GAMEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "buttongroup.h"
#include "scorepanel.h"

QT_BEGIN_NAMESPACE

class Ui_Gamepanel
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    ScorePanel *scorePanel;
    QSpacerItem *verticalSpacer;
    ButtonGroup *btnGroup;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gamepanel)
    {
        if (Gamepanel->objectName().isEmpty())
            Gamepanel->setObjectName("Gamepanel");
        Gamepanel->resize(800, 600);
        centralwidget = new QWidget(Gamepanel);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(736, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scorePanel = new ScorePanel(widget);
        scorePanel->setObjectName("scorePanel");

        horizontalLayout->addWidget(scorePanel);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnGroup = new ButtonGroup(centralwidget);
        btnGroup->setObjectName("btnGroup");

        verticalLayout->addWidget(btnGroup);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        Gamepanel->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Gamepanel);
        statusbar->setObjectName("statusbar");
        Gamepanel->setStatusBar(statusbar);

        retranslateUi(Gamepanel);

        QMetaObject::connectSlotsByName(Gamepanel);
    } // setupUi

    void retranslateUi(QMainWindow *Gamepanel)
    {
        Gamepanel->setWindowTitle(QCoreApplication::translate("Gamepanel", "Gamepanel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gamepanel: public Ui_Gamepanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPANEL_H
