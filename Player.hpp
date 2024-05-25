// 326627635 | adi.peisach@gmail.com

#ifndef CATAN_PLAYER_HPP
#define CATAN_PLAYER_HPP
#include <string>
#include <vector>
#include <stdexcept>

using std::string;
using std::vector;

static const unsigned int BRICK = 0; // TODO: move these
static const unsigned int WOOD  = 1;
static const unsigned int STONE = 2;
static const unsigned int WHEAT = 3;
static const unsigned int WOOL  = 4;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";

class Player {
private:
    string name;
    vector<unsigned int> wallet;
    string color;

    static unsigned int playerNum;

public:
    Player(string n);

    string getName() const { return name; }
    string getColor() const { return color; }

    unsigned int numProducts(unsigned int product) const { return wallet[product]; }
    void receiveProduct(unsigned int product, unsigned int num) { wallet[product] += num; }

};

#endif