// 326627635 | adi.peisach@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Game.hpp"

TEST_CASE("Test rolled 7") {
    Game game({"Blue", "Red", "Green"}, false, "TestInputs/inputRoll7.txt");
    Player& green = game.getPlayer(0);
    Player& red = game.getPlayer(1);
    Player& blue = game.getPlayer(2);

    green.receiveResources({2,0,3,0,2});
    red.receiveResources({2,4,2,0,0});
    blue.receiveResources({0,0,0,2,4});

    game.startTurn(green, 7);
    CHECK(green.walletEquals({1,0,2,0,1}));
    CHECK(red.walletEquals({2,0,2,0,0}));
    CHECK(blue.walletEquals({0,0,0,2,4}));

    red.receiveResources({2,4,2,0,0});
    game.startTurn(red, 7);
    CHECK(red.walletEquals({0,2,4,0,0}));
}

//TEST_CASE("Test full game") {
//    Game game({"Blue", "Red", "Green"}, false,"TestInputs/inputGame.txt");
//    CHECK(game.start() == "Blue");
//}