#include <gtest/gtest.h>

#include "adds.hh"

TEST(test_add, one)
{
    EXPECT_EQ(adds(1, 1), 2);
}
TEST(test_add, two)
{
    EXPECT_EQ(adds(-1, 1), 0);
}
