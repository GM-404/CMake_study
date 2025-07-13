#include <gtest/gtest.h>
#include "three_sum.hh"

// 测试用例
TEST(ThreeSumTest, one)
{
    Solution_three_sum sol;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

    std::vector<std::vector<int>> result = sol.three_Sum(nums);

    int target = 0;
    // 验证结果（以第一个三元组为例）
    EXPECT_FALSE(result.empty()); // 确保有结果
    if (!result.empty())
    {
        // 检查第一个三元组的和是否为0
        EXPECT_EQ(result[0][0] + result[0][1] + result[0][2], target);
    }
}
// 测试用例
TEST(ThreeSumTest, two)
{
    Solution_three_sum sol;
    std::vector<int> nums = {0, -1, 1, 2, 1, 4};

    std::vector<std::vector<int>> result = sol.three_Sum(nums);

    int target = 0;
    // 验证结果（以第一个三元组为例）
    EXPECT_FALSE(result.empty()); // 确保有结果
    if (!result.empty())
    {
        // 检查第一个三元组的和是否为0
        EXPECT_EQ(result[0][0] + result[0][1] + result[0][2], target);
    }
}
