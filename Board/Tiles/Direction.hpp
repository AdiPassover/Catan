// 326627635 | adi.peisach@gmail.com

#ifndef CATAN_DIRECTION_HPP
#define CATAN_DIRECTION_HPP
#include <string>
#include <stdexcept>

using std::string;

enum class Direction : int {
    North = 0,
    NorthEast = 1,
    East = 2,
    SouthEast = 3,
    South = 4,
    SouthWest= 5,
    West = 6,
    NorthWest = 7
};

namespace Directions {
    Direction stringToDirection(string s);

    Direction sum(Direction d, int i);

    Direction opposite(Direction d);
}

#endif //CATAN_DIRECTION_HPP
