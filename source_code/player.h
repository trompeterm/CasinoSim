#ifndef PLAYER_H
#define PLAYER_H

//Player class. Handles chip amount.
class Player {
public:
    Player() {};
    int getChips();
    void setChips(int x);
private:
    int chips = 100;
};

#endif // PLAYER_H
