// 326627635 | adi.peisach@gmail.com

#include "../doctest.h"
#include "Board.hpp"

TEST_CASE("Placing settlements") {

    Board board;
    Player red("Red");
    Player blue("Blue");

    board.placeSettlement(red, 'a', Direction::South);
    CHECK(board.getTile('a')->getSettlement(Direction::South)->toString() == "🏘");

}