// 326627635 | adi.peisach@gmail.com
#include "Player.hpp"

unsigned int Player::playerNum = 0;

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

unsigned int Player::numResources() const {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < wallet.size(); i++) sum += wallet[i];
    return sum;
}
