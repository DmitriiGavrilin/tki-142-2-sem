#pragma once
#include <iostream>
/**
 * @brief Класс, представляющий шестиугольник, заданный через окружность.
 */
class Hexagon {
private:
/** @brief радиус шестиугольника **/
    double radius;
/** @brief сторона шестиугольника **/
    double side;
public:
    /**
     * @brief Конструктор класса Hexagon.
     * @param cx Координата X центра окружности
     * @param cy Координата Y центра окружности
     * @param px Координата X точки на окружности
     * @param py Координата Y точки на окружности
     */
    Hexagon(const double cx, const double cy, const double px, const double py);
    /**
     * @brief Получить длину стороны шестиугольника.
     * @return double Длина стороны
     */
    double getSide() const;
    /**
     * @brief Вычислить площадь шестиугольника.
     * @return double Площадь шестиугольника
     */
    double getArea() const;
};
