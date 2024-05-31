// 326627635 | adi.peisach@gmail.com
#include "Game.hpp"

unsigned int Game::rollDice() {
    return (unsigned int)(rand()%6 + rand()%6 + 2);
}

void Game::placeSettlement(Player& p, string line, bool first) {
    char tile = line[0];
    if (tile < 'a' || tile > 's') throw std::invalid_argument("Invalid tile letter");
    Direction dire = Directions::stringToDirection(line.substr(2));

    if (!p.canAfford(Constants::SETTLEMENT_COST))
        throw std::invalid_argument("Player cannot afford to place settlement");
    p.pay(Constants::SETTLEMENT_COST);


    if (!first && board.canPlaceSettlement(p, tile, dire))
        board.placeSettlement(p, tile, dire);
    else if (first && board.canPlaceFirstSettlement(tile, dire))
        board.placeSettlement(p, tile, dire);
    else throw std::invalid_argument("Cannot place settlement");
}

void Game::upgradeSettlement(Player& p, string line) {
    char tile = line[0];
    if (tile < 'a' || tile > 's') throw std::invalid_argument("Invalid tile letter");
    Direction dire = Directions::stringToDirection(line.substr(2));

    if (!p.canAfford(Constants::CITY_COST))
        throw std::invalid_argument("Player cannot afford to upgrade settlement");
    p.pay(Constants::CITY_COST);

    if (board.canUpgradeSettlement(p, tile, dire))
        board.upgradeSettlement(tile, dire);
    else throw std::invalid_argument("Cannot upgrade settlement");
}

void Game::placeRoad(Player& p, string line) {
    char tile = line[0];
    if (tile < 'a' || tile > 's') throw std::invalid_argument("Invalid tile letter");
    Direction dire = Directions::stringToDirection(line.substr(2));

    if (!p.canAfford(Constants::ROAD_COST))
        throw std::invalid_argument("Player cannot afford to place road");
    p.pay(Constants::ROAD_COST);

    if (board.canPlaceRoad(p, tile, dire))
        board.placeRoad(p, tile, dire);
    else throw std::invalid_argument("Cannot place road");
}

vector<unsigned int> Game::namePrice() const {
    cout << "Enter price" << endl;
    cout << Constants::RESOURCES_ICONS << endl;
    vector<unsigned int> price(5,0);
    cin >> price[0] >> price[1] >> price[2] >> price[3] >> price[4];
    return price;
}

void Game::tradePlayer(Player& p, string line) {
    // TODO
}

void Game::tradeBank(Player &, std::string) {
    // TODO
}

void Game::buyCard(Player& p) {
    if (!p.canAfford(Constants::CARD_COST))
        throw std::invalid_argument("Player cannot afford to buy card");
    p.pay(Constants::CARD_COST);
    // TODO
}

void Game::playCard(Player& p, string line) {
    // TODO
}

Turn Game::chooseTurn() {
    string line = "";
    cout << line << endl;
    cin >> line;

    while (true) {
        cin >> line;
        if (line == "build") {
            cin >> line;
            if (line == "settlement") return Turn::BuildSettlement;
            if (line == "road") return Turn::BuildRoad;
            if (line == "city") return Turn::UpgradeSettlement;
        } else if (line == "trade") {
            cin >> line;
            if (line == "player") return Turn::TradePlayer;
            if (line == "bank") return Turn::TradeBank;
        } else if (line == "card") {
            cin >> line;
            if (line == "buy") return Turn::BuyCard;
            if (line == "play") return Turn::PlayCard;
        } else if (line == "end") {
            return Turn::EndTurn;
        }
    }
}

void Game::makeTurn(Player& p, Turn t) {
    string line = "";
    std::getline(cin, line);
    switch (t) {
        case Turn::FirstSettlement:
            placeSettlement(p, line,true);
            break;
        case Turn::BuildSettlement:
            placeSettlement(p, line);
            break;
        case Turn::BuildRoad:
            placeRoad(p, line);
            break;
        case Turn::UpgradeSettlement:
            upgradeSettlement(p, line);
            break;
        case Turn::TradePlayer:
            tradePlayer(p, line);
            break;
        case Turn::TradeBank:
            tradeBank(p, line);
            break;
        case Turn::BuyCard:
            buyCard(p);
            break;
        case Turn::PlayCard:
            playCard(p, line);
            break;
        case Turn::EndTurn:
            break;
    }
}
