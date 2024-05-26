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
    Player blue("Blue");
    Player red("Red");
    vector<Player> players = {blue, red};
    Game game(players);
    blue.receiveResources({999,999,999,999,999});
    red.receiveResources({999,999,999,999,999});

    unsigned int count = 0;
    while (true) {
        string s;
        std::getline(cin, s);
        if (s.empty()) break;
        if (count % 2 == 1) game.placeSettlement(red, s);
        else game.placeSettlement(blue, s);
        count++;
    }


    return 0;
}
