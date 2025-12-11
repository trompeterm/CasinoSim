/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *navToMenu;
    QAction *navToSlots;
    QAction *navToBlackjack;
    QWidget *centralwidget;
    QPushButton *spinButton;
    QLabel *gameLabel;
    QLabel *slot1;
    QLabel *slot2;
    QLabel *slot3;
    QLabel *betLabel;
    QLabel *winLabel;
    QLabel *chipsLabel;
    QLabel *chipCount;
    QTextEdit *betAmount;
    QLabel *slotsKey;
    QLabel *slotsKey_2;
    QLabel *slotsKey_3;
    QLabel *slotsKey_4;
    QLabel *addChipsLabel;
    QTextEdit *creditCardEntry;
    QTextEdit *chipAddEntry;
    QPushButton *addChipsBtn;
    QLabel *addChipsInfo;
    QLabel *dealerLabel;
    QLabel *youLabel;
    QTextEdit *blackjackBetAmount;
    QPushButton *dealButton;
    QPushButton *hitButton;
    QPushButton *standButton;
    QLabel *totalLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *dealerCards;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *playerCards;
    QLabel *blackjackStatusLabel;
    QLabel *blackjackInfo1;
    QLabel *blackjackInfo2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *Navigate;
    QMenu *menuGames;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #4e6a54"));
        navToMenu = new QAction(MainWindow);
        navToMenu->setObjectName("navToMenu");
        navToSlots = new QAction(MainWindow);
        navToSlots->setObjectName("navToSlots");
        navToBlackjack = new QAction(MainWindow);
        navToBlackjack->setObjectName("navToBlackjack");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        spinButton = new QPushButton(centralwidget);
        spinButton->setObjectName("spinButton");
        spinButton->setGeometry(QRect(289, 160, 91, 20));
        gameLabel = new QLabel(centralwidget);
        gameLabel->setObjectName("gameLabel");
        gameLabel->setGeometry(QRect(330, 0, 91, 16));
        slot1 = new QLabel(centralwidget);
        slot1->setObjectName("slot1");
        slot1->setGeometry(QRect(220, 50, 71, 51));
        slot2 = new QLabel(centralwidget);
        slot2->setObjectName("slot2");
        slot2->setGeometry(QRect(300, 50, 71, 51));
        slot3 = new QLabel(centralwidget);
        slot3->setObjectName("slot3");
        slot3->setGeometry(QRect(380, 50, 71, 51));
        betLabel = new QLabel(centralwidget);
        betLabel->setObjectName("betLabel");
        betLabel->setGeometry(QRect(260, 130, 37, 12));
        winLabel = new QLabel(centralwidget);
        winLabel->setObjectName("winLabel");
        winLabel->setGeometry(QRect(250, 180, 191, 41));
        chipsLabel = new QLabel(centralwidget);
        chipsLabel->setObjectName("chipsLabel");
        chipsLabel->setGeometry(QRect(10, 10, 37, 12));
        chipCount = new QLabel(centralwidget);
        chipCount->setObjectName("chipCount");
        chipCount->setGeometry(QRect(60, 10, 37, 12));
        betAmount = new QTextEdit(centralwidget);
        betAmount->setObjectName("betAmount");
        betAmount->setGeometry(QRect(290, 120, 91, 31));
        slotsKey = new QLabel(centralwidget);
        slotsKey->setObjectName("slotsKey");
        slotsKey->setGeometry(QRect(590, 0, 71, 20));
        slotsKey_2 = new QLabel(centralwidget);
        slotsKey_2->setObjectName("slotsKey_2");
        slotsKey_2->setGeometry(QRect(550, 20, 181, 20));
        slotsKey_3 = new QLabel(centralwidget);
        slotsKey_3->setObjectName("slotsKey_3");
        slotsKey_3->setGeometry(QRect(590, 40, 71, 20));
        slotsKey_4 = new QLabel(centralwidget);
        slotsKey_4->setObjectName("slotsKey_4");
        slotsKey_4->setGeometry(QRect(600, 60, 71, 20));
        addChipsLabel = new QLabel(centralwidget);
        addChipsLabel->setObjectName("addChipsLabel");
        addChipsLabel->setGeometry(QRect(50, 70, 71, 16));
        creditCardEntry = new QTextEdit(centralwidget);
        creditCardEntry->setObjectName("creditCardEntry");
        creditCardEntry->setGeometry(QRect(10, 90, 131, 31));
        chipAddEntry = new QTextEdit(centralwidget);
        chipAddEntry->setObjectName("chipAddEntry");
        chipAddEntry->setGeometry(QRect(10, 130, 131, 31));
        addChipsBtn = new QPushButton(centralwidget);
        addChipsBtn->setObjectName("addChipsBtn");
        addChipsBtn->setGeometry(QRect(30, 170, 80, 18));
        addChipsInfo = new QLabel(centralwidget);
        addChipsInfo->setObjectName("addChipsInfo");
        addChipsInfo->setGeometry(QRect(20, 190, 181, 41));
        dealerLabel = new QLabel(centralwidget);
        dealerLabel->setObjectName("dealerLabel");
        dealerLabel->setGeometry(QRect(20, 200, 37, 12));
        youLabel = new QLabel(centralwidget);
        youLabel->setObjectName("youLabel");
        youLabel->setGeometry(QRect(20, 370, 37, 12));
        blackjackBetAmount = new QTextEdit(centralwidget);
        blackjackBetAmount->setObjectName("blackjackBetAmount");
        blackjackBetAmount->setGeometry(QRect(620, 410, 91, 31));
        dealButton = new QPushButton(centralwidget);
        dealButton->setObjectName("dealButton");
        dealButton->setGeometry(QRect(620, 450, 91, 20));
        hitButton = new QPushButton(centralwidget);
        hitButton->setObjectName("hitButton");
        hitButton->setGeometry(QRect(460, 420, 80, 18));
        standButton = new QPushButton(centralwidget);
        standButton->setObjectName("standButton");
        standButton->setGeometry(QRect(460, 450, 80, 18));
        totalLabel = new QLabel(centralwidget);
        totalLabel->setObjectName("totalLabel");
        totalLabel->setGeometry(QRect(460, 390, 61, 16));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 220, 431, 111));
        dealerCards = new QHBoxLayout(horizontalLayoutWidget);
        dealerCards->setObjectName("dealerCards");
        dealerCards->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 390, 431, 121));
        playerCards = new QHBoxLayout(horizontalLayoutWidget_2);
        playerCards->setObjectName("playerCards");
        playerCards->setContentsMargins(0, 0, 0, 0);
        blackjackStatusLabel = new QLabel(centralwidget);
        blackjackStatusLabel->setObjectName("blackjackStatusLabel");
        blackjackStatusLabel->setGeometry(QRect(20, 525, 431, 31));
        blackjackInfo1 = new QLabel(centralwidget);
        blackjackInfo1->setObjectName("blackjackInfo1");
        blackjackInfo1->setGeometry(QRect(580, 221, 91, 20));
        blackjackInfo2 = new QLabel(centralwidget);
        blackjackInfo2->setObjectName("blackjackInfo2");
        blackjackInfo2->setGeometry(QRect(580, 250, 121, 16));
        MainWindow->setCentralWidget(centralwidget);
        gameLabel->raise();
        slot1->raise();
        slot2->raise();
        slot3->raise();
        betLabel->raise();
        winLabel->raise();
        chipsLabel->raise();
        chipCount->raise();
        betAmount->raise();
        spinButton->raise();
        slotsKey->raise();
        slotsKey_2->raise();
        slotsKey_3->raise();
        slotsKey_4->raise();
        addChipsLabel->raise();
        creditCardEntry->raise();
        chipAddEntry->raise();
        addChipsBtn->raise();
        addChipsInfo->raise();
        dealerLabel->raise();
        youLabel->raise();
        blackjackBetAmount->raise();
        dealButton->raise();
        hitButton->raise();
        standButton->raise();
        totalLabel->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        blackjackStatusLabel->raise();
        blackjackInfo1->raise();
        blackjackInfo2->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Navigate = new QMenu(menubar);
        Navigate->setObjectName("Navigate");
        Navigate->setAutoFillBackground(false);
        Navigate->setStyleSheet(QString::fromUtf8(""));
        menuGames = new QMenu(Navigate);
        menuGames->setObjectName("menuGames");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(Navigate->menuAction());
        Navigate->addAction(navToMenu);
        Navigate->addAction(menuGames->menuAction());
        menuGames->addAction(navToSlots);
        menuGames->addAction(navToBlackjack);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Casino", nullptr));
        navToMenu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        navToSlots->setText(QCoreApplication::translate("MainWindow", "Slots", nullptr));
        navToBlackjack->setText(QCoreApplication::translate("MainWindow", "Blackjack", nullptr));
        spinButton->setText(QCoreApplication::translate("MainWindow", "SPIN", nullptr));
        gameLabel->setText(QCoreApplication::translate("MainWindow", "MENU", nullptr));
        slot1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        slot2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        slot3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        betLabel->setText(QCoreApplication::translate("MainWindow", "Bet: ", nullptr));
        winLabel->setText(QString());
        chipsLabel->setText(QCoreApplication::translate("MainWindow", "CHIPS:", nullptr));
        chipCount->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        betAmount->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">enter bet</p></body></html>", nullptr));
        slotsKey->setText(QCoreApplication::translate("MainWindow", "3 Fruits = 2x", nullptr));
        slotsKey_2->setText(QCoreApplication::translate("MainWindow", "3 Matching Fruits = 10x", nullptr));
        slotsKey_3->setText(QCoreApplication::translate("MainWindow", "3 Bells = 25x", nullptr));
        slotsKey_4->setText(QCoreApplication::translate("MainWindow", "3 7s = 100x", nullptr));
        addChipsLabel->setText(QCoreApplication::translate("MainWindow", "Add Chips", nullptr));
        creditCardEntry->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Credit Card #</p></body></html>", nullptr));
        chipAddEntry->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">num chips</p></body></html>", nullptr));
        addChipsBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        addChipsInfo->setText(QString());
        dealerLabel->setText(QCoreApplication::translate("MainWindow", "Dealer", nullptr));
        youLabel->setText(QCoreApplication::translate("MainWindow", "You", nullptr));
        blackjackBetAmount->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">enter bet</p></body></html>", nullptr));
        dealButton->setText(QCoreApplication::translate("MainWindow", "DEAL", nullptr));
        hitButton->setText(QCoreApplication::translate("MainWindow", "Hit", nullptr));
        standButton->setText(QCoreApplication::translate("MainWindow", "Stand", nullptr));
        totalLabel->setText(QCoreApplication::translate("MainWindow", "Total: ", nullptr));
        blackjackStatusLabel->setText(QString());
        blackjackInfo1->setText(QCoreApplication::translate("MainWindow", "Win pays 1:1", nullptr));
        blackjackInfo2->setText(QCoreApplication::translate("MainWindow", "Blackjack pays 3:2", nullptr));
        Navigate->setTitle(QCoreApplication::translate("MainWindow", "Navigate", nullptr));
        menuGames->setTitle(QCoreApplication::translate("MainWindow", "Games", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
