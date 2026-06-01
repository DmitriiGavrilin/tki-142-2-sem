#include <gtest/gtest.h>
#include "circle.h"
#include "point.h"
#include <string>
#include <sstream>

/**
 * @brief Создание корректного круга для тестов
 * @return объект Circle
 */
Circle CreateValidCircle() {
    Circle::SetMaxCoord(2000);
    return Circle(100, 200, 50);
}

/**
 * для круга
 */

TEST(CircleTest, Constructors) {

    Circle c1 = CreateValidCircle();

    EXPECT_FALSE(c1.toString().empty());

    Point p(300, 400);

    Circle c2(p, 70);

    EXPECT_FALSE(c2.toString().empty());
}

TEST(CircleTest, ToStringMethod) {

    Circle c = CreateValidCircle();

    std::string out = c.toString();

    EXPECT_FALSE(out.empty());

    EXPECT_TRUE(
        out.find("Circle") != std::string::npos ||
        out.find("Круг") != std::string::npos
    );
}

TEST(CircleTest, StreamOutputOperator) {

    Circle c = CreateValidCircle();

    std::stringstream ss;

    ss << c;

    EXPECT_EQ(ss.str(), c.toString());
}

TEST(CircleTest, ReadMethod) {

    Circle::SetMaxCoord(2000);

    Circle c(1, 1, 1);

    std::stringstream ss("500 600 80");

    ASSERT_NO_THROW(c.Read(ss));

    EXPECT_FALSE(c.toString().empty());
}

TEST(CircleTest, InvalidRadiusException) {

    EXPECT_THROW({
        Circle c(100, 100, 0);
    }, std::invalid_argument);
}

TEST(CircleTest, OutOfRangeException) {

    Circle::SetMaxCoord(1000);

    EXPECT_THROW({
        Circle c(5000, 100, 10);
    }, std::out_of_range);

    EXPECT_THROW({
        Circle c(100, 5000, 10);
    }, std::out_of_range);
}

/**
 * для точек
 */

TEST(PointTest, Constructors) {

    Point p(10, 20);

    EXPECT_EQ(p.x, 10);
    EXPECT_EQ(p.y, 20);
}

TEST(PointTest, EqualityOperators) {

    Point p1(10, 20);
    Point p2(10, 20);
    Point p3(1, 2);

    EXPECT_TRUE(p1 == p2);

    EXPECT_TRUE(p1 != p3);
}

TEST(PointTest, AdditionOperator) {

    Point p(10, 20);

    Point result = p + 5;

    EXPECT_EQ(result.x, 15);
    EXPECT_EQ(result.y, 25);
}

TEST(PointTest, SubtractionOperator) {

    Point p(10, 20);

    Point result = p - 5;

    EXPECT_EQ(result.x, 5);
    EXPECT_EQ(result.y, 15);
}

TEST(PointTest, StreamOperators) {

    Point p;

    std::stringstream ss("100 200");

    ss >> p;

    EXPECT_EQ(p.x, 100);
    EXPECT_EQ(p.y, 200);

    std::stringstream out;

    out << p;

    EXPECT_FALSE(out.str().empty());

    EXPECT_TRUE(
        out.str().find("100") != std::string::npos
    );
}
