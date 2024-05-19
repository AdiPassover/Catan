// 326627635 | adi.peisach@gmail.com
#include <vector>
#include <memory>
#include "../Buildings/Village.hpp"

using std::vector, std::unique_ptr;

class Tile {
private:

    vector<vector<unique_ptr<Village>>> settlements;

public:

    Tile();
    virtual ~Tile() = default;

    virtual void addProduct();
};
