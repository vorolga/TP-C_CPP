#include <gtest/gtest.h>

extern "C" {
#include "geometry.h"
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_345)
{
    struct Triangle *triangle = new struct Triangle;
    ASSERT_TRUE(triangle);
    triangle->a = 3;
    triangle->b = 4;
    triangle->c = 5;
    EXPECT_NEAR(find_circle_radius(triangle), 2.5, 0.0000001);
    delete [] triangle;
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_456)
{
    struct Triangle *triangle = new struct Triangle;
    ASSERT_TRUE(triangle);
    triangle->a = 4;
    triangle->b = 5;
    triangle->c = 6;
    EXPECT_NEAR(find_circle_radius(triangle), 3.0237157, 0.0000001);
    delete [] triangle;
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_567)
{
    struct Triangle *triangle = new struct Triangle;
    ASSERT_TRUE(triangle);
    triangle->a = 5;
    triangle->b = 6;
    triangle->c = 7;
    EXPECT_NEAR(find_circle_radius(triangle), 3.5721725, 0.0000001);
    delete [] triangle;
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_678)
{
    struct Triangle *triangle = new struct Triangle;
    ASSERT_TRUE(triangle);
    triangle->a = 6;
    triangle->b = 7;
    triangle->c = 8;
    EXPECT_NEAR(find_circle_radius(triangle), 4.1311822, 0.0000001);
    delete [] triangle;
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}