#ifndef SIM_MAP_H
#define SIM_MAP_H

#include <vector>
#include <string>
#include "Point.h"

namespace sim {

class Map {
private:
    int rows, cols;
    std::vector<Point> deliveryPoints;
    std::vector<Point> truckStations;
    std::vector<Point> noTruckZones;
    std::vector<std::vector<char>> grid;

public:
    Map(int r = 0, int c = 0);

    bool loadFromFile(const std::string& filename);
    void print() const;
    bool isBlocked(const Point& p) const;
    int getRows() const;
    int getCols() const;
};

} // namespace sim

#endif
