// 326627635 | adi.peisach@gmail.com
#ifndef CATAN_MINE_HPP
#define CATAN_MINE_HPP
#include "Tile.hpp"

class Mine : public Tile {
public:
    Mine(unsigned int n, vector<Settlement*>& set, vector<Road*>& r) : Tile("🧱",n,BRICK,set,r) {}

};

#endif //CATAN_MINE_HPP