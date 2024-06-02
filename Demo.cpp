#include <iostream>
#include <ctime>
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    std::srand(std::time(nullptr));
    vector<string> players = {"Blue", "Red"};
    Game game(players,true);

//    unsigned int count = 0;
//    while (true) {
//        string s;
//        std::getline(cin, s);
//        if (s.empty()) break;
//        if (count % 3 == 0) game.pla
//        else
//        count++;
//        board.print();
//    }


    return 0;
}
