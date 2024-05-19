#include <iostream>
#include "Board/Buildings/Village.hpp"

using std::cout, std::endl;

int main() {
    Player player1("Adi");
    Village village(player1);
    cout << village.toString() << endl;

    return 0;
}
