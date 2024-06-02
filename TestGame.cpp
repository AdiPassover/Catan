// 326627635 | adi.peisach@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Game.hpp"

TEST_CASE("test game") {
    Game game({"Blue", "Red", "Green"}, false, "input1.txt");
}