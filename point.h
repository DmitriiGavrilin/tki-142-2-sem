#pragma once
#include <iostream>

/**
 * @brief Класс Point (точка на плоскости)
 */
class Point {
private:
    int x;
    int y;

public:

    /**
     * @brief Конструктор по умолчанию
     */
    Point();

    /**
     * @brief Конструктор точки
     * @param x абсцисса
     * @param y ордината
     */
    Point(const int x, const int y);

    /**
     * @brief Получение X координаты
     * @return x координата
     */
    int getX() const;

    /**
     * @brief Получение Y координаты
     * @return y координата
     */
    int getY() const;

    /**
     * @brief Оператор сравнения ==
     * @param other другая точка
     * @return true если равны
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор сравнения !=
     * @param other другая точка
     * @return true если не равны
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор сложения точки и числа
     * @param value число
     * @return новая точка
     */
    Point operator+(const int value) const;

    /**
     * @brief Оператор вычитания числа из точки
     * @param value число
     * @return новая точка
     */
    Point operator-(const int value) const;

    /**
     * @brief Перегрузка оператора вывода
     * @param os поток вывода
     * @param p объект Point
     * @return поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * @brief Перегрузка оператора ввода
     * @param is входной поток
     * @param p объект Point
     * @return входной поток
     */
    friend std::istream& operator>>(std::istream& is, Point& p);
};
