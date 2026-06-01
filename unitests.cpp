#include <gtest/gtest.h>
#include "CircularDoublyLinkedList.h"

TEST(ListTests, DefaultConstructor)
{
    CircularDoublyLinkedList list;

    EXPECT_TRUE(list.isEmpty());
}

TEST(ListTests, InitializerListConstructor)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    EXPECT_EQ("1 2 3", list.toString());
}

TEST(ListTests, Push)
{
    CircularDoublyLinkedList list;

    list.push(10);
    list.push(20);

    EXPECT_EQ("10 20", list.toString());
}

TEST(ListTests, Pop)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    list.pop(2);

    EXPECT_EQ("1 3", list.toString());
}

TEST(ListTests, Find)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    EXPECT_TRUE(list.find(2));
    EXPECT_FALSE(list.find(10));
}

TEST(ListTests, Replace)
{
    CircularDoublyLinkedList list = {1, 2, 3};

    list.replace(2, 20);

    EXPECT_EQ("1 20 3", list.toString());
}

TEST(ListTests, CopyConstructor)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};

    CircularDoublyLinkedList list2(list1);

    EXPECT_EQ(list1, list2);
}

TEST(ListTests, CopyAssignment)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};
    CircularDoublyLinkedList list2;

    list2 = list1;

    EXPECT_EQ(list1, list2);
}

TEST(ListTests, MoveConstructor)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};

    CircularDoublyLinkedList list2(std::move(list1));

    EXPECT_EQ("1 2 3", list2.toString());
    EXPECT_TRUE(list1.isEmpty());
}

TEST(ListTests, MoveAssignment)
{
    CircularDoublyLinkedList list1 = {1, 2, 3};
    CircularDoublyLinkedList list2;

    list2 = std::move(list1);

    EXPECT_EQ("1 2 3", list2.toString());
    EXPECT_TRUE(list1.isEmpty());
}
