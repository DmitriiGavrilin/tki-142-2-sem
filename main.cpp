#include <iostream>
#include "circle.h"

int main() {

    Circle::SetMaxCoord(1920);

    try {

        Circle c1(100, 200, 50);

        std::cout << "Created circle:" << std::endl;
        std::cout << c1 << std::endl;

        Circle c2(0, 0, 1);

        std::cout << "Enter circle data (x y radius):" << std::endl;

        std::cin >> c2;

        std::cout << "Entered circle:" << std::endl;

        c2.Draw();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
