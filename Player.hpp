// 326627635 | adi.peisach@gmail.com

#include <string>
#include <vector>

using std::string, std::vector;

static const unsigned int BRICK = 0;
static const unsigned int WOOD  = 1;
static const unsigned int STONE = 2;
static const unsigned int WHEAT = 3;
static const unsigned int WOOL  = 4;

class Player {
private:
    string name;
    vector<unsigned int> wallet;

public:
    Player(string n) { name.assign(n); wallet.resize(5,0); }

    unsigned int numBricks() const { return wallet[BRICK]; }
    unsigned int numWood() const { return wallet[WOOD]; }
    unsigned int numStone() const { return wallet[STONE]; }
    unsigned int numWheat() const { return wallet[WHEAT]; }
    unsigned int numWool() const { return wallet[WOOL]; }

};
