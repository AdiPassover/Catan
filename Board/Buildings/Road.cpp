// 326627635 | adi.peisach@gmail.com
#include "Road.hpp"

string Road::toString() const {
    string ans = std::to_string((char)orientation);
    if (isBuilt())
        return player->getColor() + ans + RESET;
    return ans;
}
