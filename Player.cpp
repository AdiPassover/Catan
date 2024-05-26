// 326627635 | adi.peisach@gmail.com
#include "Player.hpp"

unsigned int Player::playerNum = 0;

Player::Player(string n) {
    name.assign(n);
    wallet.resize(5,0);
    points = 0;
    numKnights = 0;
    id = playerNum;
    if (playerNum == 0)
        color = Constants::BLUE;
    else if (playerNum == 1)
        color = Constants::RED;
    else if (playerNum == 2)
        color = Constants::GREEN;
    else if (playerNum == 3)
        color = Constants::YELLOW;
    else
        throw std::out_of_range("Too many players!");
    playerNum++;
}

bool Player::canAfford(vector<unsigned int> resources) const {
    for (size_t i = 0; i < resources.size(); i++)
        if (wallet[i] < resources[i]) return false;
    return true;
}

void Player::pay(vector<unsigned int> resources) {
    if (!canAfford(resources)) throw std::invalid_argument("Player cannot afford to pay");
    for (size_t i = 0; i < resources.size(); i++)
        wallet[i] -= resources[i];
}

void Player::receiveResources(vector<unsigned int> resources) {
    for (size_t i = 0; i < resources.size(); i++)
        wallet[i] += resources[i];
}
