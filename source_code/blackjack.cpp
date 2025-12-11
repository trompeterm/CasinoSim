#include "blackjack.h"
#include <random>

Card::Card(std::string suit, int value) {
    this->suit = suit;
    this->value = value;
};

std::string Card::getSuit() {
    return suit;
};

int Card::getValue() {
    return value;
};

Deck::Deck(): deck(52), drawIndex(0) {
    int count = 0;
    for(int i = 1; i < 14; i++) {
        for(int j = 0; j < 4; j++) {
            if(j == 0) {
                deck.at(count) = Card("heart", i);
            } else if (j == 1) {
                deck.at(count) = Card("club", i);
            } else if (j == 2) {
                deck.at(count) = Card("diamond", i);
            } else {
                deck.at(count) = Card("spade", i);
            }
            count++;
        }
    }
};

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

Card Deck::draw() {
    return deck.at(drawIndex++);
}

Blackjack::Blackjack() {
    deck = Deck();
    deck.shuffle();
}

Card Blackjack::draw() {
    return deck.draw();
}

int Blackjack::getTotal() {
    return runningTotal;
}

void Blackjack::setTotal(int val) {
    runningTotal = val;
}
