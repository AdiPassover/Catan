// 326627635 | adi.peisach@gmail.com

#ifndef CATAN_GAME_HPP
#define CATAN_GAME_HPP

#include "Board/board.hpp"


class Game {
    vector<Player> players;
    Board board;

private:
    void setupBoard();
    unsigned int rollDice();

public:
    Game();

    void makeTurn();

};


#endif //CATAN_GAME_HPP
