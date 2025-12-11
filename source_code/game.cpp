#include <cstdlib>
#include <random>
#include <vector>
#include <map>
#include "game.h"

//Function prototype
bool isFruit(DISPLAY d);

//Game constructor, takes a player.
Game::Game(Player& p) : player(p) {}

//spin method, generates 3 spin results.
void Slots::spin() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 5);
    std::vector<DISPLAY> results;

    int n1 = dist(gen);
    int n2 = dist(gen);
    int n3 = dist(gen);

    std::map<int, DISPLAY> correlation;
    correlation[0] = DISPLAY::BANANA;
    correlation[1] = DISPLAY::CHERRY;
    correlation[2] = DISPLAY::GRAPE;
    correlation[3] = DISPLAY::MELON;
    correlation[4] = DISPLAY::BELL;
    correlation[5] = DISPLAY::SEVEN;

    results.push_back(correlation[n1]);
    results.push_back(correlation[n2]);
    results.push_back(correlation[n3]);

    result = results;
};

//Checks if the spin resulted in a win.
WINTYPE Slots::checkWin() {
    WINTYPE type = WINTYPE::NONE;

    DISPLAY a = result.at(0);
    DISPLAY b = result.at(1);
    DISPLAY c = result.at(2);

    std::map<DISPLAY, int> count;
    count[a]++;
    count[b]++;
    count[c]++;

    if(count[DISPLAY::SEVEN] == 3) {
        type = WINTYPE::X100;
    } else {
        if(count[DISPLAY::BELL] == 3) {
            type = WINTYPE::X25;
        } else {
            bool allFruit = isFruit(a) && isFruit(b) && isFruit(c);
            if(allFruit) {
                if(count[a] == 3) {
                    type = WINTYPE::X10;
                } else {
                    type = WINTYPE::X2;
                }
            }
        }
    }

    return type;
}

//Gets the result from the slots spin.
std::vector<DISPLAY> Slots::getSpin() {
    return result;
}

//Sets the bet amount
void Slots::setBetAmount(int val){
    betAmount = val;
}

//Ran when the user wins
void Slots::win() {
    player.setChips(player.getChips() + betAmount);
}

//Ran when the user loses.
void Slots::lose() {
    player.setChips(player.getChips() - betAmount);
}

//Helper method to check if a spin was a fruit
bool isFruit(DISPLAY d){
    bool fruit = false;
    if(d == DISPLAY::BANANA || d == DISPLAY::MELON || d == DISPLAY::CHERRY || d == DISPLAY::GRAPE) {
        fruit = true;
    }
    return fruit;
}

//Card constructor takes a suit and a value
Card::Card(std::string suit, int value) {
    this->suit = suit;
    this->value = value;
};

//Gets the suit of the card
std::string Card::getSuit() {
    return suit;
};

//Gets the value of the card
int Card::getValue() {
    return value;
};

//Deck constructor, initializes a vector of 52 cards.
Deck::Deck(): deck(52), drawIndex(0) {
    int count = 0;
    for(int i = 1; i < 14; i++) {
        for(int j = 0; j < 4; j++) {
            if(j == 0) {
                deck.at(count) = Card("hearts", i);
            } else if (j == 1) {
                deck.at(count) = Card("clubs", i);
            } else if (j == 2) {
                deck.at(count) = Card("diamonds", i);
            } else {
                deck.at(count) = Card("spades", i);
            }
            count++;
        }
    }
};

//Randomizes the deck vector
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    drawIndex = 0;
}

//Draws from the deck
Card Deck::draw() {
    return deck.at(drawIndex++);
}

//Blackjack constructor
Blackjack::Blackjack(Player& p) : Game(p) {
    deck = Deck();
    deck.shuffle();
    isActive = false;
    canDeal = true;
    playerStanding = false;
    betAmount = 0;
}

//Draws a card from the deck
Card Blackjack::draw() {
    return deck.draw();
}

//Gets the running total for the user
int Blackjack::getTotal() {
    return runningTotal;
}

//Updates running total
void Blackjack::setTotal(int val) {
    runningTotal = val;
}

//Gets the blackjack value of a card
int Blackjack::getCardValue(Card& card) {
    int value = card.getValue();
    if (value >= 11) {
        value = 10;
    } else if (value ==1) {
        value = 11;
    }
    return value;
}

//Adjusts the total based on the updated card values
int Blackjack::adjustTotal(const std::vector<int>& cards) const {
    int total = 0;
    int aces = 0;

    for(int v: cards) {
        total += v;
        if(v == 11) {
            aces++;
        }
    }

    while(total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    return total;
}

//resets the blackjack game
void Blackjack::reset() {
    deck.shuffle();
    betAmount = 0;
}

//ran when user loses blackjack
void Blackjack::lose() {
    player.setChips(player.getChips() - betAmount);
}

//ran when user wins blackjack
void Blackjack::win() {
    player.setChips(player.getChips() + betAmount);
}

//sets the blackjack bet amount
void Blackjack::setBetAmount(int val){
    betAmount = val;
}
