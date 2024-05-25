#include <iostream>
#include <ctime>
#include "Board/Buildings/Settlement.hpp"
#include "Board/Buildings/Road.hpp"
#include "Board/Board.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    std::srand(std::time(nullptr));
    Board board;
    board.print();
    Player blue("Blue");
    Player red("Red");

    int count = 0;
    while (true) {
        char c;
        cin >> c;
        if (c == '0') break;
        board.placeSettlement(red, c, Direction::North);
        board.upgradeSettlement(c, Direction::North);
        board.placeSettlement(blue, c, Direction::South);
        board.upgradeSettlement(c, Direction::South);
        board.print();
        count++;
    }


    return 0;
}
