// 326627635 | adi.peisach@gmail.com

#ifndef CATAN_GAME_HPP
#define CATAN_GAME_HPP

#include "Board/Board.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

enum class Turn {
    FirstSettlement,
    FirstRoad,

    BuildSettlement,
    BuildRoad,
    UpgradeSettlement,

    TradePlayer,
    TradeBank,

    BuyCard,
    PlayCard,

    EndTurn
};

class Game {
    vector<Player> players;
    Board board;

private:
    unsigned int rollDice();
    vector<unsigned int> namePrice() const;

public:
    Game(vector<Player>& p) : players(p), board() { // TODO: empty constructor with inputs
        srand(time(nullptr));
    }

    Turn chooseTurn();
    void makeTurn(Player&, Turn);

    void placeSettlement(Player&, string, bool first = false);
    void upgradeSettlement(Player&, string);
    void placeRoad(Player&, string, bool first = false);

    void tradePlayer(Player&, string);
    void tradeBank(Player&, string);

    void buyCard(Player&);
    void playCard(Player&, string);

    void print() const { board.print(); };
};


#endif //CATAN_GAME_HPP
