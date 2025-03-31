#include <gtest/gtest.h>

#include "add.hh"

TEST(test_add, one)
{
    EXPECT_EQ(add(1, 1), 2);
}
TEST(test_add, two)
{
    EXPECT_EQ(add(-1, 1), 0);
}
