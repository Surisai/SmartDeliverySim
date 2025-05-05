#include "Map.h"
#include <fstream>
#include <iostream>

namespace sim {

Map::Map(int r, int c) : rows(r), cols(c), grid(r, std::vector<char>(c, '.')) {}

bool Map::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;

    std::string line;
    for (int i = 0; i < rows && std::getline(file, line); ++i) {
        for (int j = 0; j < cols && j < static_cast<int>(line.length()); ++j) {
            grid[i][j] = line[j];
        }
    }

    return true;
}

void Map::print() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}

bool Map::isBlocked(const Point& p) const {
    return grid[p.row][p.col] == '#';
}

int Map::getRows() const { return rows; }

int Map::getCols() const { return cols; }

} // namespace sim
