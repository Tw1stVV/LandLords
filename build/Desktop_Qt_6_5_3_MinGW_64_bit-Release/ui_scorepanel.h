/********************************************************************************
** Form generated from reading UI file 'scorepanel.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREPANEL_H
#define UI_SCOREPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScorePanel
{
public:
    QGridLayout *gridLayout;
    QLabel *myTitle;
    QLabel *myScore;
    QLabel *label_3;
    QLabel *leftTitle;
    QLabel *leftScore;
    QLabel *label_4;
    QLabel *rightTitle;
    QLabel *rightScore;
    QLabel *label_8;
    QLabel *beatLebel;
    QLabel *beatScore;
    QLabel *label_9;

    void setupUi(QWidget *ScorePanel)
    {
        if (ScorePanel->objectName().isEmpty())
            ScorePanel->setObjectName("ScorePanel");
        ScorePanel->resize(262, 138);
        gridLayout = new QGridLayout(ScorePanel);
        gridLayout->setObjectName("gridLayout");
        myTitle = new QLabel(ScorePanel);
        myTitle->setObjectName("myTitle");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(12);
        font.setBold(true);
        myTitle->setFont(font);
        myTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        myTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(myTitle, 0, 0, 1, 1);

        myScore = new QLabel(ScorePanel);
        myScore->setObjectName("myScore");
        myScore->setMinimumSize(QSize(30, 0));
        myScore->setFont(font);
        myScore->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        myScore->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(myScore, 0, 1, 1, 1);

        label_3 = new QLabel(ScorePanel);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        leftTitle = new QLabel(ScorePanel);
        leftTitle->setObjectName("leftTitle");
        leftTitle->setFont(font);
        leftTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        leftTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(leftTitle, 1, 0, 1, 1);

        leftScore = new QLabel(ScorePanel);
        leftScore->setObjectName("leftScore");
        leftScore->setMinimumSize(QSize(30, 0));
        leftScore->setFont(font);
        leftScore->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        leftScore->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(leftScore, 1, 1, 1, 1);

        label_4 = new QLabel(ScorePanel);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        rightTitle = new QLabel(ScorePanel);
        rightTitle->setObjectName("rightTitle");
        rightTitle->setFont(font);
        rightTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        rightTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(rightTitle, 2, 0, 1, 1);

        rightScore = new QLabel(ScorePanel);
        rightScore->setObjectName("rightScore");
        rightScore->setMinimumSize(QSize(30, 0));
        rightScore->setFont(font);
        rightScore->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        rightScore->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(rightScore, 2, 1, 1, 1);

        label_8 = new QLabel(ScorePanel);
        label_8->setObjectName("label_8");
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        beatLebel = new QLabel(ScorePanel);
        beatLebel->setObjectName("beatLebel");
        beatLebel->setFont(font);
        beatLebel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        beatLebel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(beatLebel, 3, 0, 1, 1);

        beatScore = new QLabel(ScorePanel);
        beatScore->setObjectName("beatScore");
        beatScore->setFont(font);
        beatScore->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        beatScore->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(beatScore, 3, 1, 1, 1);

        label_9 = new QLabel(ScorePanel);
        label_9->setObjectName("label_9");
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 3, 2, 1, 1);


        retranslateUi(ScorePanel);

        QMetaObject::connectSlotsByName(ScorePanel);
    } // setupUi

    void retranslateUi(QWidget *ScorePanel)
    {
        ScorePanel->setWindowTitle(QCoreApplication::translate("ScorePanel", "Form", nullptr));
        myTitle->setText(QCoreApplication::translate("ScorePanel", "\346\210\221", nullptr));
        myScore->setText(QString());
        label_3->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        leftTitle->setText(QCoreApplication::translate("ScorePanel", "\345\267\246\344\276\247\346\234\272\345\231\250\344\272\272", nullptr));
        leftScore->setText(QString());
        label_4->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        rightTitle->setText(QCoreApplication::translate("ScorePanel", "\345\217\263\344\276\247\346\234\272\345\231\250\344\272\272", nullptr));
        rightScore->setText(QString());
        label_8->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        beatLebel->setText(QCoreApplication::translate("ScorePanel", "\350\265\214\346\263\250", nullptr));
        beatScore->setText(QString());
        label_9->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScorePanel: public Ui_ScorePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREPANEL_H
