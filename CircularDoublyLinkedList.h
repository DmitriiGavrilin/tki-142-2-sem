#pragma once

#include <string>
#include <initializer_list>
#include <iostream>

/**
 * @brief Класс циклического двусвязного списка.
 * 
 * Поддерживает хранение элементов типа int, операции добавления, 
 * удаления, поиска, замены, а также глубокое копирование и перемещение.
 */
class CircularDoublyLinkedList
{
private:

    /**
     * @brief Структура узла списка.
     */
    struct Node
    {
        int data;     ///< Данные, хранящиеся в узле.
        Node* next;   ///< Указатель на следующий узел.
        Node* prev;   ///< Указатель на предыдущий узел.

        /**
         * @brief Конструктор узла.
         * @param value Значение для инициализации данных.
         */
        Node(int value);
    };

    Node* head;       ///< Указатель на первый элемент списка (голову).
    size_t size;      ///< Текущее количество элементов в списке.

    /**
     * @brief Вспомогательный метод для очистки списка и освобождения памяти.
     */
    void clear();

public:

    /**
     * @brief Конструктор по умолчанию. Создает пустой список.
     */
    CircularDoublyLinkedList();

    /**
     * @brief Конструктор со списком инициализации.
     * @param list Список элементов для добавления (например, {1, 2, 3}).
     */
    CircularDoublyLinkedList(const std::initializer_list<int> list);

    /**
     * @brief Конструктор копирования (глубокое копирование).
     * @param other Другой список для копирования.
     */
    CircularDoublyLinkedList(const CircularDoublyLinkedList& other);

    /**
     * @brief Конструктор перемещения.
     * @param other Другой список, у которого забираются ресурсы.
     */
    CircularDoublyLinkedList(CircularDoublyLinkedList&& other);

    /**
     * @brief Деструктор. Освобождает всю выделенную память.
     */
    ~CircularDoublyLinkedList();

    /**
     * @brief Проверяет, пуст ли список.
     * @return true, если список пуст, иначе false.
     */
    bool isEmpty() const;

    /**
     * @brief Возвращает текущее количество элементов в списке.
     * @return Количество элементов.
     */
    size_t getSize() const;

    /**
     * @brief Преобразует содержимое списка в строковое представление.
     * @return Строка со всеми элементами списка.
     */
    std::string toString() const;

    /**
     * @brief Добавляет новый элемент в конец списка.
     * @param value Значение для добавления.
     */
    void push(const int& value);

    /**
     * @brief Удаляет первое вхождение элемента с указанным значением.
     * @param value Значение элемента, который нужно удалить.
     */
    void pop(const int& value);

    /**
     * @brief Ищет элемент в списке.
     * @param value Значение для поиска.
     * @return true, если элемент найден, иначе false.
     */
    bool find(const int& value) const;

    /**
     * @brief Заменяет старое значение элемента на новое (первое вхождение).
     * @param oldValue Значение, которое нужно заменить.
     * @param newValue Новое значение.
     */
    void replace(const int& oldValue, const int& newValue);

    /**
     * @brief Оператор копирующего присваивания.
     * @param other Другой список для копирования.
     * @return Ссылка на текущий объект.
     */
    CircularDoublyLinkedList& operator=(const CircularDoublyLinkedList& other);

    /**
     * @brief Оператор перемещающего присваивания.
     * @param other Другой список, ресурсы которого перемещаются.
     * @return Ссылка на текущий объект.
     */
    CircularDoublyLinkedList& operator=(CircularDoublyLinkedList&& other);

    /**
     * @brief Оператор проверки на равенство двух списков.
     * @param other Список для сравнения.
     * @return true, если списки одинаковой длины и содержат равные элементы.
     */
    bool operator==(const CircularDoublyLinkedList& other) const;

    /**
     * @brief Оператор проверки на неравенство двух списков.
     * @param other Список для сравнения.
     * @return true, если списки отличаются.
     */
    bool operator!=(const CircularDoublyLinkedList& other) const;

    /**
     * @brief Перегрузка оператора вывода в поток.
     * @param os Поток вывода.
     * @param list Список для вывода.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(
        std::ostream& os,
        const CircularDoublyLinkedList& list);

    /**
     * @brief Перегрузка оператора ввода из потока.
     * @param is Поток ввода.
     * @param list Список, в который считываются данные.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(
        std::istream& is,
        CircularDoublyLinkedList& list);
};
