// 326627635 | adi.peisach@gmail.com
#include "Player.hpp"

unsigned int Player::playerNum = 0;

Player::Player(string n) {
    name.assign(n);
    wallet.resize(5,0);

    if (playerNum == 0)
        color = BLUE;
    else if (playerNum == 1)
        color = RED;
    else if (playerNum == 2)
        color = GREEN;
    else if (playerNum == 3)
        color = YELLOW;
    else
        throw std::out_of_range("Too many players!");
    playerNum++;
}