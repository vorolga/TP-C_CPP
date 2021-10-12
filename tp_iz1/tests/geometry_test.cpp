#include <gtest/gtest.h>

extern "C" {
#include "../include/geometry.h"
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_345)
{
    EXPECT_NEAR(find_circle_radius(3, 4, 5), 2.5, 0.0000001);
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_456)
{
    EXPECT_NEAR(find_circle_radius(4, 5, 6), 3.0237157, 0.0000001);
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_567)
{
    EXPECT_NEAR(find_circle_radius(5, 6, 7), 3.5721725, 0.0000001);
}

TEST(FIND_CIRCLE_RADIUS_TEST, Assert_678)
{
    EXPECT_NEAR(find_circle_radius(6, 7, 8), 4.1311822, 0.0000001);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}