// 326627635 | adi.peisach@gmail.com
#ifndef CATAN_SETTLEMENT_HPP
#define CATAN_SETTLEMENT_HPP
#include "../../Player.hpp"
#include "Road.hpp"

class Settlement {
private:
    unsigned int level;
    vector<Road> roads;
    Player* player = nullptr;

public:
    Settlement() { level = 0; }

    unsigned int getLevel() const { return level; }
    void receiveProducts(unsigned int product);
    bool isBuilt() const { return level > 0; }

    void buildVillage(Player& p);
    void upgradeToCity();
    string toString() const;

};

#endif
