/********************************************************************************
** Form generated from reading UI file 'buttongroup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONGROUP_H
#define UI_BUTTONGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_ButtonGroup
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *startPage;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    MyButton *btnStart;
    QSpacerItem *horizontalSpacer_2;
    QWidget *playCardPage;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    MyButton *btnPlayCard;
    QSpacerItem *horizontalSpacer_4;
    QWidget *passOrPlayPage;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    MyButton *btnPass;
    QSpacerItem *horizontalSpacer_6;
    MyButton *btnPlayCard_2;
    QSpacerItem *horizontalSpacer_7;
    QWidget *callLordPage;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    MyButton *btnGiveUp;
    QSpacerItem *horizontalSpacer_10;
    MyButton *btnOneScore;
    QSpacerItem *horizontalSpacer_11;
    MyButton *btnTwoScore;
    QSpacerItem *horizontalSpacer_12;
    MyButton *btnThreeScore;
    QSpacerItem *horizontalSpacer_8;
    QWidget *nullPage;

    void setupUi(QWidget *ButtonGroup)
    {
        if (ButtonGroup->objectName().isEmpty())
            ButtonGroup->setObjectName("ButtonGroup");
        ButtonGroup->resize(570, 50);
        verticalLayout = new QVBoxLayout(ButtonGroup);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(ButtonGroup);
        stackedWidget->setObjectName("stackedWidget");
        startPage = new QWidget();
        startPage->setObjectName("startPage");
        horizontalLayout = new QHBoxLayout(startPage);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnStart = new MyButton(startPage);
        btnStart->setObjectName("btnStart");

        horizontalLayout->addWidget(btnStart);

        horizontalSpacer_2 = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(startPage);
        playCardPage = new QWidget();
        playCardPage->setObjectName("playCardPage");
        horizontalLayout_2 = new QHBoxLayout(playCardPage);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnPlayCard = new MyButton(playCardPage);
        btnPlayCard->setObjectName("btnPlayCard");

        horizontalLayout_2->addWidget(btnPlayCard);

        horizontalSpacer_4 = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        stackedWidget->addWidget(playCardPage);
        passOrPlayPage = new QWidget();
        passOrPlayPage->setObjectName("passOrPlayPage");
        horizontalLayout_3 = new QHBoxLayout(passOrPlayPage);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btnPass = new MyButton(passOrPlayPage);
        btnPass->setObjectName("btnPass");

        horizontalLayout_3->addWidget(btnPass);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        btnPlayCard_2 = new MyButton(passOrPlayPage);
        btnPlayCard_2->setObjectName("btnPlayCard_2");

        horizontalLayout_3->addWidget(btnPlayCard_2);

        horizontalSpacer_7 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(passOrPlayPage);
        callLordPage = new QWidget();
        callLordPage->setObjectName("callLordPage");
        horizontalLayout_4 = new QHBoxLayout(callLordPage);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_9 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        btnGiveUp = new MyButton(callLordPage);
        btnGiveUp->setObjectName("btnGiveUp");

        horizontalLayout_4->addWidget(btnGiveUp);

        horizontalSpacer_10 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        btnOneScore = new MyButton(callLordPage);
        btnOneScore->setObjectName("btnOneScore");

        horizontalLayout_4->addWidget(btnOneScore);

        horizontalSpacer_11 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        btnTwoScore = new MyButton(callLordPage);
        btnTwoScore->setObjectName("btnTwoScore");

        horizontalLayout_4->addWidget(btnTwoScore);

        horizontalSpacer_12 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        btnThreeScore = new MyButton(callLordPage);
        btnThreeScore->setObjectName("btnThreeScore");

        horizontalLayout_4->addWidget(btnThreeScore);

        horizontalSpacer_8 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        stackedWidget->addWidget(callLordPage);
        nullPage = new QWidget();
        nullPage->setObjectName("nullPage");
        stackedWidget->addWidget(nullPage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(ButtonGroup);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ButtonGroup);
    } // setupUi

    void retranslateUi(QWidget *ButtonGroup)
    {
        ButtonGroup->setWindowTitle(QCoreApplication::translate("ButtonGroup", "Form", nullptr));
        btnStart->setText(QCoreApplication::translate("ButtonGroup", "\345\274\200\345\247\213", nullptr));
        btnPlayCard->setText(QCoreApplication::translate("ButtonGroup", "\345\207\272\347\211\214", nullptr));
        btnPass->setText(QCoreApplication::translate("ButtonGroup", "\350\267\263\350\277\207", nullptr));
        btnPlayCard_2->setText(QCoreApplication::translate("ButtonGroup", "\345\207\272\347\211\214", nullptr));
        btnGiveUp->setText(QCoreApplication::translate("ButtonGroup", "\344\270\215\345\217\253", nullptr));
        btnOneScore->setText(QCoreApplication::translate("ButtonGroup", "\344\270\200\345\210\206", nullptr));
        btnTwoScore->setText(QCoreApplication::translate("ButtonGroup", "\344\270\244\345\210\206", nullptr));
        btnThreeScore->setText(QCoreApplication::translate("ButtonGroup", "\344\270\211\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ButtonGroup: public Ui_ButtonGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONGROUP_H
