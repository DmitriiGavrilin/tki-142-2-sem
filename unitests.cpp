#include <gtest/gtest.h>
#include "CircularDoublyLinkedList.h"
#include <sstream>

TEST(ListTests, DefaultConstructor)
{
    CircularDoublyLinkedList list;

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(0, list.getSize());
    EXPECT_EQ("Empty", list.toString());
}

TEST(ListTests, InitializerListConstructor)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(3, list.getSize());
    EXPECT_EQ("1 2 3", list.toString());
}

TEST(ListTests, Push)
{
    CircularDoublyLinkedList list;

    list.push(10);
    EXPECT_EQ(1, list.getSize());
    EXPECT_EQ("10", list.toString());

    list.push(20);
    EXPECT_EQ(2, list.getSize());
    EXPECT_EQ("10 20", list.toString());
}

TEST(ListTests, Pop)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    // Удаление из середины
    list.pop(2);
    EXPECT_EQ("1 3", list.toString());
    EXPECT_EQ(2, list.getSize());

    // Удаление головы (head должен сместиться на элемент 3)
    list.pop(1);
    EXPECT_EQ("3", list.toString());
    EXPECT_EQ(1, list.getSize());

    // Удаление единственного оставшегося элемента (head должен стать nullptr)
    list.pop(3);
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ("Empty", list.toString());
}

TEST(ListTests, PopEdgeCases)
{
    CircularDoublyLinkedList list;
    
    // Попытка удаления из пустого списка (не должно приводить к ошибкам памяти)
    list.pop(5); 
    EXPECT_TRUE(list.isEmpty());

    CircularDoublyLinkedList list2 = {1, 2, 3};
    
    // Попытка удаления несуществующего элемента
    list2.pop(100); 
    EXPECT_EQ("1 2 3", list2.toString());
    EXPECT_EQ(3, list2.getSize());
}

TEST(ListTests, Find)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    EXPECT_TRUE(list.find(2));
    EXPECT_FALSE(list.find(10));

    // Поиск в пустом списке
    CircularDoublyLinkedList emptyList;
    EXPECT_FALSE(emptyList.find(5));
}

TEST(ListTests, Replace)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    // Обычная замена первого вхождения
    list.replace(2, 20);
    EXPECT_EQ("1 20 3", list.toString());

    // Попытка замены несуществующего элемента (список не должен измениться)
    list.replace(99, 100);
    EXPECT_EQ("1 20 3", list.toString());

    // Замена в пустом списке
    CircularDoublyLinkedList emptyList;
    emptyList.replace(1, 2);
    EXPECT_TRUE(emptyList.isEmpty());
}

TEST(ListTests, CopyConstructor)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};
    CircularDoublyLinkedList list2(list1);

    EXPECT_EQ(list1, list2);
    
    // Проверка глубокого копирования: изменение list2 не ломает list1
    list2.push(4);
    EXPECT_EQ("1 2 3", list1.toString());
    EXPECT_EQ("1 2 3 4", list2.toString());
}

TEST(ListTests, CopyAssignment)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};
    CircularDoublyLinkedList list2;

    list2 = list1;
    EXPECT_EQ(list1, list2);

    // Тест на самоприсваивание (защита от очистки самого себя)
    list2 = *&list2; 
    EXPECT_EQ("1 2 3", list2.toString());
}

TEST(ListTests, MoveConstructor)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};
    CircularDoublyLinkedList list2(std::move(list1));

    EXPECT_EQ("1 2 3", list2.toString());
    
    // Перемещенный список должен корректно обнулиться
    EXPECT_TRUE(list1.isEmpty());
    EXPECT_EQ(0, list1.getSize());
}

TEST(ListTests, MoveAssignment)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};
    CircularDoublyLinkedList list2;

    list2 = std::move(list1);

    EXPECT_EQ("1 2 3", list2.toString());
    
    // Перемещенный список должен корректно обнулиться
    EXPECT_TRUE(list1.isEmpty());
    EXPECT_EQ(0, list1.getSize());
}

TEST(ListTests, OperatorsEqualNotEqual)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};
    CircularDoublyLinkedList list2 = {1, 2, 3};
    CircularDoublyLinkedList list3 = {1, 2, 4};
    CircularDoublyLinkedList list4 = {1, 2};

    // Полное совпадение
    EXPECT_TRUE(list1 == list2);
    
    // Различаются данные в узлах
    EXPECT_FALSE(list1 == list3); 
    EXPECT_TRUE(list1 != list3);

    // Различаются размеры списков
    EXPECT_FALSE(list1 == list4);
    EXPECT_TRUE(list1 != list4);

    // Два пустых списка равны между собой
    CircularDoublyLinkedList empty1, empty2;
    EXPECT_TRUE(empty1 == empty2);
}

TEST(ListTests, StreamOutputOperator)
{
    CircularDoublyLinkedList list = {5, 10, 15};
    std::stringstream ss;

    // Проверяем оператор <<
    ss << list;
    EXPECT_EQ("5 10 15", ss.str());
}

TEST(ListTests, StreamInputOperator)
{
    CircularDoublyLinkedList list = {1, 2};
    std::stringstream ss("3");

    // Проверяем оператор >>
    ss >> list;
    EXPECT_EQ("1 2 3", list.toString());
    EXPECT_EQ(3, list.getSize());
}
