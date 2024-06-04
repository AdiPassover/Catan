// 326627635 | adi.peisach@gmail.com
#include "KnightCard.hpp"

void KnightCard::play(Player& p, Game& g) {
    p.addKnight();
}

string KnightCard::toString() const {
    return "Knight";
}