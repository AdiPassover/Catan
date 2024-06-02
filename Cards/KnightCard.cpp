// 326627635 | adi.peisach@gmail.com
#include "KnightCard.hpp"

void KnightCard::play(Player& p, Game& g) {
    p.addKnight();
    if (p.getKnights() == 3) {
        p.addPoints(2);
    }
}

string KnightCard::toString() const {
    return "Knight";
}