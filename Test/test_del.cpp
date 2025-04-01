#include <gtest/gtest.h>

#include "del.hh"

TEST(TestDel, one)
{
    EXPECT_EQ(1, del(2, 1));
}
