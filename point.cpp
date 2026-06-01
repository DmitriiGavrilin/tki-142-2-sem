#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(const int x, const int y)
    : x(x), y(y) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

Point Point::operator+(const int value) const {
    return Point(x + value, y + value);
}

Point Point::operator-(const int value) const {
    return Point(x - value, y - value);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
