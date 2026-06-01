#include "circle.h"
#include <stdexcept>

int Circle::maxCoord = 1000;

Circle::Circle(const Point c, const int r)
    : center(c), radius(r) {

    if (r <= 0)
        throw std::invalid_argument("Radius must be positive");

    if (c.getX() > maxCoord || c.getY() > maxCoord)
        throw std::out_of_range("Coordinates out of range");
}

Circle::Circle(const int x, const int y, const int r)
    : Circle(Point(x, y), r) {}

std::string Circle::toString() const {

    return "Circle: center=(" +
        std::to_string(center.getX()) + ", " +
        std::to_string(center.getY()) +
        "), radius=" +
        std::to_string(radius);
}

void Circle::Draw() const {
    std::cout << toString() << std::endl;
}

void Circle::Read(std::istream& is) {
    is >> center >> radius;
}

void Circle::SetMaxCoord(const int value) {
    maxCoord = value;
}
