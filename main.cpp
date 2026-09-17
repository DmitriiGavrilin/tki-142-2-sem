#include <iostream>
#include "CircularDoublyLinkedList.h"

int main()
{
    CircularDoublyLinkedList list = { 10, 20, 30, 40 };

    std::cout << "List: "
              << list
              << std::endl;

    list.push(50);

    std::cout << "After push: "
              << list
              << std::endl;

    list.pop(20);

    std::cout << "After pop(20): "
              << list
              << std::endl;

    list.replace(30, 300);

    std::cout << "After replace: "
              << list
              << std::endl;

    std::cout << "Find 300: "
              << (list.find(300) ? "Found" : "Not found")
              << std::endl;

    CircularDoublyLinkedList copy;

    copy = list;

    std::cout << "Copy: "
              << copy
              << std::endl;

    return 0;
}
