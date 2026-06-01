#pragma once
#include "figure.h"
#include "point.h"

/**
 * @brief Класс Circle (круг)
 */
class Circle : public Figure {
private:
    Point center;
    int radius;

    static int maxCoord;

public:

    /**
     * @brief Конструктор круга через Point
     * @param c центр
     * @param r радиус
     */
    Circle(const Point c, const int r);

    /**
     * @brief Конструктор круга через координаты
     * @param x x координата центра
     * @param y y координата центра
     * @param r радиус
     */
    Circle(const int x, const int y, const int r);

    /**
     * @brief Метод сериализации в строку
     * @return строка
     */
    std::string toString() const override;

    /**
     * @brief Метод вывода круга
     */
    void Draw() const override;

    /**
     * @brief Метод чтения круга
     * @param is входной поток
     */
    void Read(std::istream& is) override;

    /**
     * @brief Установка максимальной координаты
     * @param value максимальное значение
     */
    static void SetMaxCoord(const int value);
};
