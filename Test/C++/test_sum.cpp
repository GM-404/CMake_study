#include <gtest/gtest.h>
#include "sum.h"

// 测试用例
TEST(SolutionTest, TwoSumTest)
{
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = sol.twoSum(nums, target);

    // 验证结果是否正确
    EXPECT_EQ(result.size(), 2);
    if (result.size() == 2)
    {
        EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}