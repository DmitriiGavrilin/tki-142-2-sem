#pragma once

#include <string>
#include <initializer_list>
#include <iostream>

class CircularDoublyLinkedList
{
private:

    struct Node
    {
        int data;
        Node* next;
        Node* prev;

        Node(int value);
    };

    Node* head;
    size_t size;

    void clear();

public:

    CircularDoublyLinkedList();
    CircularDoublyLinkedList(const std::initializer_list<int> list);

    CircularDoublyLinkedList(const CircularDoublyLinkedList& other);
    CircularDoublyLinkedList(CircularDoublyLinkedList&& other);

    ~CircularDoublyLinkedList();

    bool isEmpty() const;
    size_t getSize() const;

    std::string toString() const;

    void push(int value);
    void pop(int value);

    bool find(int value) const;
    void replace(int oldValue, int newValue);

    CircularDoublyLinkedList& operator=(const CircularDoublyLinkedList& other);
    CircularDoublyLinkedList& operator=(CircularDoublyLinkedList&& other);

    bool operator==(const CircularDoublyLinkedList& other) const;
    bool operator!=(const CircularDoublyLinkedList& other) const;

    friend std::ostream& operator<<(
        std::ostream& os,
        const CircularDoublyLinkedList& list);

    friend std::istream& operator>>(
        std::istream& is,
        CircularDoublyLinkedList& list);
};
