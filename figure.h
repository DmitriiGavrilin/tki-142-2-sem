#pragma once
#include <string>
#include <iostream>

/**
 * @brief Абстрактный базовый класс "Фигура"
 */
class Figure {
public:
    /**
     * @brief Сериализация объекта в строку
     * @return Строковое представление объекта
     */
    virtual std::string toString() const = 0;
    /**
     * @brief Метод рисования фигуры
     */
    virtual void Draw() const = 0;
    /**
     * @brief Чтение объекта из потока
     * @param is входной поток
     */
    virtual void Read(std::istream& is) = 0;
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Figure() = default;
    /**
     * @brief Перегрузка оператора вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Figure& f) {
        os << f.toString();
        return os;
    }
    /**
     * @brief Перегрузка оператора ввода
     */
    friend std::istream& operator>>(std::istream& is, Figure& f) {
        f.Read(is);
        return is;
    }
};
