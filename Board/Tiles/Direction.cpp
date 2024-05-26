// 326627635 | adi.peisach@gmail.com
#include "Direction.hpp"

Direction Directions::stringToDirection(string s) {
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') c = c + 'a' - 'A';
    }
    if (s == "north") return Direction::North;
    else if (s == "northeast") return Direction::NorthEast;
    else if (s == "east") return Direction::East;
    else if (s == "southeast") return Direction::SouthEast;
    else if (s == "south") return Direction::South;
    else if (s == "southwest") return Direction::SouthWest;
    else if (s == "west") return Direction::West;
    else if (s == "northwest") return Direction::NorthWest;
    throw std::invalid_argument("Invalid direction string");
}

Direction Directions::sum(Direction d, int i) {
    return static_cast<Direction>((static_cast<int>(d) + i) % 8);
}

Direction Directions::opposite(Direction d) {
    return sum(d, 4);
}
