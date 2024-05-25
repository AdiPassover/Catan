// 326627635 | adi.peisach@gmail.com
#ifndef CATAN_FOREST_HPP
#define CATAN_FOREST_HPP
#include "Tile.hpp"

class Forest : public Tile {
public:
    Forest(unsigned int n, vector<Settlement*>& set, vector<Road*>& r) : Tile("🌲",n,WOOD,set,r) {}

};

#endif //CATAN_FOREST_HPP