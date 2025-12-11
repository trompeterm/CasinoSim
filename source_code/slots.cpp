#include <cstdlib>
#include <random>
#include <vector>
#include <map>
#include "slots.h"

bool isFruit(DISPLAY d);

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

std::vector<DISPLAY> Slots::getSpin() {
    return result;
}

bool isFruit(DISPLAY d){
    bool fruit = false;
    if(d == DISPLAY::BANANA || d == DISPLAY::MELON || d == DISPLAY::CHERRY || d == DISPLAY::GRAPE) {
        fruit = true;
    }
    return fruit;
}
