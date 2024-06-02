// 326627635 | adi.peisach@gmail.com

#ifndef CATAN_CONSTANTS_HPP
#define CATAN_CONSTANTS_HPP
#include <string>
#include <vector>

using std::vector;
using std::string;

namespace Constants {

    const unsigned int BRICK = 0;
    const unsigned int WOOD  = 1;
    const unsigned int WOOL  = 2;
    const unsigned int WHEAT = 3;
    const unsigned int STONE = 4;

    const string BRICK_ICON = "🧱";
    const string WOOD_ICON = "🌲";
    const string WOOL_ICON = "🐑";
    const string WHEAT_ICON = "🌾";
    const string STONE_ICON = "🪨";
    const string RESOURCES_ICONS = BRICK_ICON+" "+WOOD_ICON+" "+WOOL_ICON+" "+WHEAT_ICON+" "+STONE_ICON;

    const string ROBBER_ICON = "🥷";
    const string DESERT_ICON = "🏜";
    const string VACANT_ICON = "■";
    const string VILLAGE_ICON = "🏘";
    const string CITY_ICON = "🏙";

    const string RESET = "\033[0m";
    const string BLUE = "\033[34m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const vector<string> COLORS = {BLUE, RED, GREEN, YELLOW};

    const vector<unsigned int> SETTLEMENT_COST = {1, 1, 1, 1, 0};
    const vector<unsigned int> ROAD_COST = {1, 1, 0, 0, 0};
    const vector<unsigned int> CITY_COST = {0, 0, 0, 2, 3};
    const vector<unsigned int> CARD_COST = {0, 0, 1, 1, 1};

}

#endif //CATAN_CONSTANTS_HPP
