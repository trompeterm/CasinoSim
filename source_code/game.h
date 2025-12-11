#ifndef GAME_H
#define GAME_H

#include <vector>
#include <qpixmap.h>
#include <string>
#include "player.h"

//enums used for slots statuses.
enum class WINTYPE {NONE, X2, X10, X25, X100};
enum class DISPLAY {CHERRY, MELON, BANANA, GRAPE, BELL, SEVEN};

//Base game class. Inherited by Blackjack and Slots
class Game {
public:
    Game(Player& p);
    virtual ~Game() = default;
    virtual void win() {};
    virtual void lose() {};
protected:
    int betAmount = 0;
    Player& player;
};

//Slots game type class
class Slots : public Game {
public:
    Slots(Player& p) : Game(p) {};
    void spin();
    void win() override;
    void lose() override;
    WINTYPE checkWin();
    std::vector<DISPLAY> getSpin();
    void setBetAmount(int val);
private:
    std::vector<DISPLAY> result;
};

//Card class for blackjack
class Card {
public:
    Card(std::string suit, int value);
    Card() : suit(" "), value(0) {};
    std::string getSuit();
    int getValue();
    QPixmap getImg();
private:
    std::string suit;
    int value;
};

//Deck class has a vector of 52 cards, used for Blackjack
class Deck {
public:
    Deck();
    void shuffle();
    Card draw();
private:
    std::vector<Card> deck;
    int drawIndex;
};

//Blackjack game type class
class Blackjack : public Game {
public:
    Blackjack(Player& p);
    void deal();
    Card draw();
    void reset();
    int getTotal();
    void setTotal(int val);
    int getCardValue(Card& card);
    int adjustTotal(const std::vector<int>& cards) const;
    void lose() override;
    void win() override;
    void setBetAmount(int val);
    bool isActive;
    bool canDeal;
    bool playerStanding;
    std::vector<int> playerCards;
    std::vector<int> dealerCards;
private:
    Deck deck;
    int runningTotal;
};

#endif // GAME_H
