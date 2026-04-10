#include <iostream>
#include <cmath>
#include "Hexagon.h"
Hexagon::Hexagon(const double cx, const double cy, const double px, const double py) {
    radius = sqrt(pow(px - cx, 2) + pow(py - cy, 2));
    if (radius <= 0) {
        std::cout << "Error: radius must be positive\n";
        exit(1);
    }
    side = radius;
}
double Hexagon::getSide() const {
    return side;
}
double Hexagon::getArea() const {
    return (3 * sqrt(3) / 2) * side * side;
}
