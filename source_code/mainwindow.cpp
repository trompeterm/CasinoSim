#include <QTimer>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game.h"
#include "player.h"

//Casino elements
Player player;
Slots slotMachine(player);
Blackjack blackjack(player);

//Function prototypes
void setMain(Ui::MainWindow* ui, bool status);
void setSlots(Ui::MainWindow* ui, bool status);
void setBlackjack(Ui::MainWindow* ui, bool status);
void updateChips(Ui::MainWindow* ui);
bool isValidCardNumber(const QString& card);

QLabel* dealerHiddenCard = nullptr;
Card dealerHiddenCardValue;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setMain(ui, true);
    setSlots(ui, false);
    setBlackjack(ui, false);
}

MainWindow::~MainWindow() {
    delete ui;
}

//Ran when the spin button is clicked for slots
void MainWindow::on_spinButton_clicked() {
    QPixmap cherryImg("images/cherry.png");
    QPixmap bananaImg("images/banana.png");
    QPixmap grapeImg("images/grape.png");
    QPixmap melonImg("images/melon.png");
    QPixmap bellImg("images/bell.png");
    QPixmap sevenImg("images/seven.png");

    QString input = ui->betAmount->toPlainText();
    bool ok;
    int betAmount = input.toInt(&ok);

    if(ok && betAmount > 0) {
        if (betAmount <= player.getChips()) {
            slotMachine.setBetAmount(betAmount);
            slotMachine.spin();
            WINTYPE win = slotMachine.checkWin();
            std::vector<DISPLAY> result = slotMachine.getSpin();

            DISPLAY s1 = result.at(0);
            DISPLAY s2 = result.at(1);
            DISPLAY s3 = result.at(2);

            if (s1 == DISPLAY::BANANA) {
                ui->slot1->setPixmap(bananaImg);
            } else if (s1 == DISPLAY::CHERRY) {
                ui->slot1->setPixmap(cherryImg);
            } else if (s1 == DISPLAY::MELON) {
                ui->slot1->setPixmap(melonImg);
            } else if (s1 == DISPLAY::GRAPE) {
                ui->slot1->setPixmap(grapeImg);
            } else if (s1 == DISPLAY::BELL) {
                ui->slot1->setPixmap(bellImg);
            } else if (s1 == DISPLAY::SEVEN) {
                ui->slot1->setPixmap(sevenImg);
            }

            if (s2 == DISPLAY::BANANA) {
                ui->slot2->setPixmap(bananaImg);
            } else if (s2 == DISPLAY::CHERRY) {
                ui->slot2->setPixmap(cherryImg);
            } else if (s2 == DISPLAY::MELON) {
                ui->slot2->setPixmap(melonImg);
            } else if (s2 == DISPLAY::GRAPE) {
                ui->slot2->setPixmap(grapeImg);
            } else if (s2 == DISPLAY::BELL) {
                ui->slot2->setPixmap(bellImg);
            } else if (s2 == DISPLAY::SEVEN) {
                ui->slot2->setPixmap(sevenImg);
            }

            if (s3 == DISPLAY::BANANA) {
                ui->slot3->setPixmap(bananaImg);
            } else if (s3 == DISPLAY::CHERRY) {
                ui->slot3->setPixmap(cherryImg);
            } else if (s3 == DISPLAY::MELON) {
                ui->slot3->setPixmap(melonImg);
            } else if (s3 == DISPLAY::GRAPE) {
                ui->slot3->setPixmap(grapeImg);
            } else if (s3 == DISPLAY::BELL) {
                ui->slot3->setPixmap(bellImg);
            } else if (s3 == DISPLAY::SEVEN) {
                ui->slot3->setPixmap(sevenImg);
            }

            if (win == WINTYPE::NONE) {
                ui->winLabel->setText("No win");
                slotMachine.lose();
            } else if (win == WINTYPE::X2) {
                ui->winLabel->setText("2x");
                for(int i = 0; i < 2; i++) {
                    slotMachine.win();
                }
            } else if (win == WINTYPE::X10) {
                ui->winLabel->setText("10x");
                for(int i = 0; i < 10; i++) {
                    slotMachine.win();
                }
            } else if (win == WINTYPE::X25) {
                ui->winLabel->setText("25x");
                for(int i = 0; i < 25; i++) {
                    slotMachine.win();
                }
            } else if (win == WINTYPE::X100) {
                ui->winLabel->setText("100x");
                for(int i = 0; i < 100; i++) {
                    slotMachine.win();
                }
            }
            updateChips(ui);
        } else {
            ui->winLabel->setText("Error - Not enough chips");
        }
    } else {
        ui->winLabel->setText("Error - Invalid bet amount");
    }
}

//Ran when the add chips button is clicked on main menu
void MainWindow::on_addChipsBtn_clicked()
{
    QString cardInput = ui->creditCardEntry->toPlainText();
    bool cardok;
    cardInput.toLongLong(&cardok);

    if(cardok) {
        QString chipAmount = ui->chipAddEntry->toPlainText();
        bool chipok;
        int chipsToAdd = chipAmount.toInt(&chipok);
        if(chipok) {
            if(isValidCardNumber(cardInput) && cardInput.length() == 16){
                player.setChips(player.getChips() + chipsToAdd);
                updateChips(ui);
                ui->addChipsInfo->setText("Chips added");
            } else {
                ui->addChipsInfo->setText("Error - invalid card number");
            }
        } else {
            ui->addChipsInfo->setText("Error reading chip amount");
        }
    } else {
        ui->addChipsInfo->setText("Error reading card number");
    }
}

//Handles menu navigation
void MainWindow::on_navToSlots_triggered() {
    setSlots(ui, true);
    setMain(ui, false);
    setBlackjack(ui, false);
}

void MainWindow::on_navToMenu_triggered() {
    setMain(ui, true);
    setSlots(ui, false);
    setBlackjack(ui, false);
}

void MainWindow::on_navToBlackjack_triggered() {
    setMain(ui, false);
    setSlots(ui, false);
    setBlackjack(ui, true);
}

void setMain(Ui::MainWindow* ui, bool status) {
    if(status) {
        ui->gameLabel->setText("MENU");
    }
    ui->addChipsLabel->setVisible(status);
    ui->creditCardEntry->setVisible(status);
    ui->chipAddEntry->setVisible(status);
    ui->addChipsBtn->setVisible(status);
    ui->addChipsInfo->setVisible(status);
}

void setSlots(Ui::MainWindow* ui, bool status) {
    if(status) {
        ui->gameLabel->setText("SLOTS");
    }
    ui->slot1->setVisible(status);
    ui->slot2->setVisible(status);
    ui->slot3->setVisible(status);
    ui->betLabel->setVisible(status);
    ui->spinButton->setVisible(status);
    ui->winLabel->setVisible(status);
    ui->betAmount->setVisible(status);
    ui->slotsKey->setVisible(status);
    ui->slotsKey_2->setVisible(status);
    ui->slotsKey_3->setVisible(status);
    ui->slotsKey_4->setVisible(status);
}

void setBlackjack(Ui::MainWindow* ui, bool status){
    if(status){
        ui->gameLabel->setText("BLACKJACK");
    }
    ui->dealerLabel->setVisible(status);
    ui->youLabel->setVisible(status);
    ui->blackjackBetAmount->setVisible(status);
    ui->dealButton->setVisible(status);
    ui->totalLabel->setVisible(status);
    ui->hitButton->setVisible(status);
    ui->standButton->setVisible(status);
    ui->blackjackStatusLabel->setVisible(status);
    ui->blackjackInfo1->setVisible(status);
    ui->blackjackInfo2->setVisible(status);

    if(!status) {
        QLayoutItem* item;
        while((item = ui->dealerCards->takeAt(0)) != nullptr) {
            delete item->widget();
        }

        while((item = ui->playerCards->takeAt(0)) != nullptr) {
            delete item->widget();
        }
    }
}

//Updates chip label
void updateChips(Ui::MainWindow* ui) {
    ui->chipCount->setText(QString::number(player.getChips()));
}

//Checks if the credit card is a valid credit card number
bool isValidCardNumber(const QString& number) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = number.length() - 1; i >= 0; i--) {
        QChar c = number[i];

        int digit = c.digitValue();

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

//Resets the blackjack game
void resetBlackjack(Ui::MainWindow* ui) {
    QLayoutItem* item;
    while((item = ui->dealerCards->takeAt(0)) != nullptr) {
        delete item->widget();
    }

    while((item = ui->playerCards->takeAt(0)) != nullptr) {
        delete item->widget();
    }

    blackjack.dealerCards.clear();
    blackjack.playerCards.clear();
    blackjack.setTotal(0);
    blackjack.reset();
}

//Gets the file name for each unique card
QString getFileName(Card& card) {
    int value = card.getValue();
    QString suit = QString::fromStdString(card.getSuit());
    QString valueName;

    switch(value) {
    case 1:
        valueName = "ace";
        break;
    case 2:
        valueName = "two";
        break;
    case 3:
        valueName = "three";
        break;
    case 4:
        valueName = "four";
        break;
    case 5:
        valueName = "five";
        break;
    case 6:
        valueName = "six";
        break;
    case 7:
        valueName = "seven";
        break;
    case 8:
        valueName = "eight";
        break;
    case 9:
        valueName = "nine";
        break;
    case 10:
        valueName = "ten";
        break;
    case 11:
        valueName = "jack";
        break;
    case 12:
        valueName = "queen";
        break;
    case 13:
        valueName = "king";
        break;
    }
    return "images/" + valueName + "_of_" + suit + ".png";
}

//Ran when the deal button is clicked for blackjack
void MainWindow::on_dealButton_clicked() {
    QString betEntry = ui->blackjackBetAmount->toPlainText();
    bool betOk;
    int bet = betEntry.toInt(&betOk);

    if(!(betOk && bet > 0 && bet <= player.getChips())) {
        ui->blackjackStatusLabel->setText("Invalid Bet Amount");
    } else {
        if(!blackjack.canDeal) {
            ui->blackjackStatusLabel->setText("Game already in progress!");
        } else {
            blackjack.canDeal = false;
            blackjack.isActive = true;
            blackjack.playerStanding = false;

            resetBlackjack(ui);
            blackjack.setBetAmount(bet);
            QPixmap cardback("images/cardback_64x96.png");

            Card dealer1 = blackjack.draw();
            Card dealer2 = blackjack.draw();
            Card you1 = blackjack.draw();
            Card you2 = blackjack.draw();

            int dval1 = blackjack.getCardValue(dealer1);
            int dval2 = blackjack.getCardValue(dealer2);
            int pval1 = blackjack.getCardValue(you1);
            int pval2 = blackjack.getCardValue(you2);

            blackjack.playerCards = {pval1, pval2};
            blackjack.dealerCards = {dval1, dval2};

            QLabel* playerCard1 = new QLabel(QString::number(pval1));
            playerCard1->setPixmap(QPixmap(getFileName(you1)));
            ui->playerCards->addWidget(playerCard1);

            QLabel* playerCard2 = new QLabel(QString::number(pval2));
            playerCard2->setPixmap(QPixmap(getFileName(you2)));
            ui->playerCards->addWidget(playerCard2);

            dealerHiddenCard = new QLabel();
            dealerHiddenCard->setPixmap(cardback);
            ui->dealerCards->addWidget(dealerHiddenCard);
            dealerHiddenCardValue = dealer1;

            QLabel* dealerCard2 = new QLabel(QString::number(dval2));
            dealerCard2->setPixmap(QPixmap(getFileName(dealer2)));
            ui->dealerCards->addWidget(dealerCard2);

            int total = blackjack.adjustTotal(blackjack.playerCards);
            blackjack.setTotal(total);
            ui->totalLabel->setText("Total: " + QString::number(total));
            ui->blackjackStatusLabel->setText("Playing...");

            if(total == 21) {
                ui->blackjackStatusLabel->setText("Blackjack - YOU WIN");
                player.setChips(player.getChips() + (int)(1.5 * bet));
                blackjack.isActive = false;
                blackjack.canDeal = true;
                updateChips(ui);
            }
        }
    }
}

//Ran when the hit button is clicked
void MainWindow::on_hitButton_clicked() {

    if(!blackjack.isActive) {
        ui->blackjackStatusLabel->setText("You are not in a game!");
    } else {
        if(blackjack.playerStanding) {
            ui->blackjackStatusLabel->setText("You already stood!");
        } else {
            Card deltCard = blackjack.draw();
            int value = blackjack.getCardValue(deltCard);
            blackjack.playerCards.push_back(value);

            QLabel* label = new QLabel(QString::number(value));
            label->setPixmap(QPixmap(getFileName(deltCard)));
            ui->playerCards->addWidget(label);

            int total = blackjack.adjustTotal(blackjack.playerCards);
            blackjack.setTotal(total);
            ui->totalLabel->setText("Total: " + QString::number(total));

            if(total > 21) {
                ui->blackjackStatusLabel->setText("BUST: YOU LOSE");
                blackjack.lose();
                blackjack.isActive = false;
                blackjack.canDeal = true;
                updateChips(ui);
            }
        }
    }
}

//Ran when the stand button is clicked
void MainWindow::on_standButton_clicked() {

    if(!blackjack.isActive) {
        ui->blackjackStatusLabel->setText("You are not in a game!");
    } else {

        blackjack.playerStanding = true;

        int dealerTotal = blackjack.adjustTotal(blackjack.dealerCards);
        int playerTotal = blackjack.adjustTotal(blackjack.playerCards);

        QString hiddenFileName = getFileName(dealerHiddenCardValue);
        dealerHiddenCard->setPixmap(QPixmap(hiddenFileName));

        while(dealerTotal < 17 || dealerTotal < playerTotal) {
            QEventLoop loop;
            QTimer::singleShot(1000, &loop, SLOT(quit()));
            loop.exec();

            Card drawnCard = blackjack.draw();
            int val = blackjack.getCardValue(drawnCard);
            blackjack.dealerCards.push_back(val);

            QLabel* label = new QLabel(QString::number(val));
            label->setPixmap(QPixmap(getFileName(drawnCard)));
            ui->dealerCards->addWidget(label);

            dealerTotal = blackjack.adjustTotal(blackjack.dealerCards);
        }

        QString result;
        if(dealerTotal > 21) {
            result = "Dealer Busts - You WIN";
            blackjack.win();
        } else if(playerTotal > dealerTotal) {
            result = "YOU WIN";
            blackjack.win();
        } else if(playerTotal < dealerTotal) {
            result = "Dealer wins";
            blackjack.lose();
        } else {
            result = "Push";
        }

        ui->blackjackStatusLabel->setText(result);

        blackjack.isActive = false;
        blackjack.canDeal = true;

        updateChips(ui);
    }
}
