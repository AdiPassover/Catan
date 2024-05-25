// 326627635 | adi.peisach@gmail.com
#include "Settlement.hpp"

void Settlement::upgradeToCity() {
    level = 2;
}


void Settlement::buildVillage(Player& p) {
    level = 1;
    player = &p;
}

string Settlement::toString() const {
    string ans = "■";
    if (level == 1)
        ans = player->getColor() + "🏘";
    if (level == 2)
        ans = player->getColor() + "🏙";
    return ans + RESET;
}

void Settlement::receiveProducts(unsigned int product) {
    if (level == 0) return;
    player->receiveProduct(product, level);
}
