// 326627635 | adi.peisach@gmail.com

#ifndef CATAN_PLAYER_HPP
#define CATAN_PLAYER_HPP
#include <string>
#include <vector>
#include <stdexcept>
#include "Constants.hpp"
#include "Cards/Card.hpp"

using std::string;
using std::vector;

class Player {
private:
    string name;
    unsigned int id;
    vector<unsigned int> wallet;
    vector<Card> cards;
    string color;
    unsigned int points;
    unsigned int numKnights;

    static unsigned int playerNum;

public:
    Player(string n);

    string getName() const { return name; }
    unsigned int getId() const { return id; }
    string getColor() const { return color; }
    unsigned int getPoints() const { return points; }
    unsigned int getKnights() const { return numKnights; }

    void addPoints(unsigned int p) { points += p; }

    bool canAfford(vector<unsigned int> resources) const;
    void pay(vector<unsigned int> resources);

    unsigned int numProducts(unsigned int product) const { return wallet[product]; }
    void receiveProduct(unsigned int product, unsigned int num) { wallet[product] += num; }
    void receiveResources(vector<unsigned int> resources);

};

#endif