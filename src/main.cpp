#include <iostream>
#include "Map.h"

int main() {
    sim::Map map(10, 10);

    if (map.loadFromFile("data/simple_map.txt")) {
        std::cout << "Map loaded successfully!\n";
        map.print();
    } else {
        std::cerr << "Failed to load map.\n";
    }

    return 0;
}
