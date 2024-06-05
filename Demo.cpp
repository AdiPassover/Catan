// 326627635 | adi.peisach@gmail.com
#include <iostream>
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    vector<string> players = {"Blue", "Red", "Green"};
    Game game(players,true);
    game.start();

    return 0;
}
