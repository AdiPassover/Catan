#include <iostream>
#include <ctime>
#include "Board/Buildings/Settlement.hpp"
#include "Board/Buildings/Road.hpp"
#include "Board/Board.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    std::srand(std::time(nullptr));

    Board board;
    board.print();
    Player blue("Blue",Constants::BLUE);
    Player red("Red",Constants::RED);

//    unsigned int count = 0;
//    while (true) {
//        string s;
//        std::getline(cin, s);
//        if (s.empty()) break;
//        char tile = s[0];
//        if (tile < 'a' || tile > 's') throw std::invalid_argument("Invalid tile letter");
//        Direction dire = Directions::stringToDirection(s.substr(2));
//        if (count % 2 == 1) board.placeRoad(red,tile,dire);
//        else board.placeRoad(blue, tile, dire);
//        count++;
//        board.print();
//    }

    vector<Direction> dirs = {Direction::NorthEast, Direction::East, Direction::SouthEast, Direction::SouthWest, Direction::West, Direction::NorthWest};
    for (char tile = 'a'; tile <= 's'; tile++) {
        for (Direction dir : dirs) {
            try {
                board.placeRoad(red, tile, dir);
            } catch (std::invalid_argument& e) {
                //cout << e.what() << endl;
            }
        }
    }
    board.print();

    return 0;
}
