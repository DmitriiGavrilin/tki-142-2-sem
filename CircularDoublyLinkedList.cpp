#include "CircularDoublyLinkedList.h"

#include <sstream>

CircularDoublyLinkedList::Node::Node(int value)
    : data(value), next(nullptr), prev(nullptr)
{
}

CircularDoublyLinkedList::CircularDoublyLinkedList()
    : head(nullptr), size(0)
{
}

CircularDoublyLinkedList::CircularDoublyLinkedList(
    const std::initializer_list<int> list)
    : head(nullptr), size(0)
{
    for (int value : list)
    {
        push(value);
    }
}

CircularDoublyLinkedList::CircularDoublyLinkedList(
    const CircularDoublyLinkedList& other)
    : head(nullptr), size(0)
{
    if (other.head == nullptr)
        return;

    Node* current = other.head;

    do
    {
        push(current->data);
        current = current->next;
    }
    while (current != other.head);
}

CircularDoublyLinkedList::CircularDoublyLinkedList(
    CircularDoublyLinkedList&& other)
    : head(other.head), size(other.size)
{
    other.head = nullptr;
    other.size = 0;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    clear();
}

void CircularDoublyLinkedList::clear()
{
    while (!isEmpty())
    {
        pop(head->data);
    }
}

bool CircularDoublyLinkedList::isEmpty() const
{
    return size == 0;
}

size_t CircularDoublyLinkedList::getSize() const
{
    return size;
}

void CircularDoublyLinkedList::push(int value)
{
    Node* node = new Node(value);

    if (head == nullptr)
    {
        head = node;

        node->next = node;
        node->prev = node;
    }
    else
    {
        Node* tail = head->prev;

        tail->next = node;
        node->prev = tail;

        node->next = head;
        head->prev = node;
    }

    ++size;
}

void CircularDoublyLinkedList::pop(int value)
{
    if (head == nullptr)
        return;

    Node* current = head;

    do
    {
        if (current->data == value)
        {
            if (size == 1)
            {
                delete current;
                head = nullptr;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head)
                    head = current->next;

                delete current;
            }

            --size;
            return;
        }

        current = current->next;
    }
    while (current != head);
}

bool CircularDoublyLinkedList::find(int value) const
{
    if (head == nullptr)
        return false;

    Node* current = head;

    do
    {
        if (current->data == value)
            return true;

        current = current->next;
    }
    while (current != head);

    return false;
}

void CircularDoublyLinkedList::replace(
    int oldValue,
    int newValue)
{
    if (head == nullptr)
        return;

    Node* current = head;

    do
    {
        if (current->data == oldValue)
        {
            current->data = newValue;
            return;
        }

        current = current->next;
    }
    while (current != head);
}

std::string CircularDoublyLinkedList::toString() const
{
    if (isEmpty())
        return "Empty";

    std::stringstream ss;

    Node* current = head;

    do
    {
        ss << current->data;

        current = current->next;

        if (current != head)
            ss << " ";
    }
    while (current != head);

    return ss.str();
}

CircularDoublyLinkedList&
CircularDoublyLinkedList::operator=(
    const CircularDoublyLinkedList& other)
{
    if (this != &other)
    {
        clear();

        Node* current = other.head;

        if (current != nullptr)
        {
            do
            {
                push(current->data);
                current = current->next;
            }
            while (current != other.head);
        }
    }

    return *this;
}

CircularDoublyLinkedList&
CircularDoublyLinkedList::operator=(
    CircularDoublyLinkedList&& other)
{
    if (this != &other)
    {
        clear();

        head = other.head;
        size = other.size;

        other.head = nullptr;
        other.size = 0;
    }

    return *this;
}

bool CircularDoublyLinkedList::operator==(
    const CircularDoublyLinkedList& other) const
{
    if (size != other.size)
        return false;

    if (size == 0)
        return true;

    Node* first = head;
    Node* second = other.head;

    do
    {
        if (first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }
    while (first != head);

    return true;
}

bool CircularDoublyLinkedList::operator!=(
    const CircularDoublyLinkedList& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(
    std::ostream& os,
    const CircularDoublyLinkedList& list)
{
    os << list.toString();
    return os;
}

std::istream& operator>>(
    std::istream& is,
    CircularDoublyLinkedList& list)
{
    int value;

    if (is >> value)
    {
        list.push(value);
    }

    return is;
}
