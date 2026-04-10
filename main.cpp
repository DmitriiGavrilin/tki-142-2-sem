#include <iostream>
#include "Hexagon.h"
/**
 * @brief Запрашивает у пользователя ввод координаты.
 * Функция выводит сообщение-подсказку, считывает значение с клавиатуры
 * и проверяет корректность ввода.
 * @param report Текст подсказки для пользователя (например, "cx: ")
 * @return double Введённое числовое значение
 * @warning При некорректном вводе программа завершается с кодом ошибки 1
 */
double getCoord(const std::string &report);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() {
    std::cout << "Enter center coordinates (cx cy):\n";
    double cx = getCoord("cx: ");
    double cy = getCoord("cy: ");
    std::cout << "Enter point on circle (px py):\n";
    double px = getCoord("px: ");
    double py = getCoord("py: ");
    Hexagon myHex(cx, cy, px, py);
    std::cout << "Side: " << myHex.getSide() << std::endl;
    std::cout << "Area: " << myHex.getArea() << std::endl;
    return 0;
}
double getCoord(const std::string &report) {
    std::cout << report;
    double val;
    std::cin >> val;
    if (std::cin.fail()) {
        std::cout << "Error: invalid input\n";
        exit(1);
    }
    return val;
}
