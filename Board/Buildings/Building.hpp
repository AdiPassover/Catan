// 326627635 | adi.peisach@gmail.com
#include "../../Player.hpp"
#include <string>
#include <utility>

using std::string;

class Building {
protected:
    Player& player;
    string symbol = "-";

    Building(Player& p, string s) : player(p), symbol(std::move(s)) {}

public:
    virtual string toString() { return symbol; }

};
