#include <gtest/gtest.h>
#include "sum.h"

// 测试用例
TEST(TwoSumTest, one)
{
    Solution sol;
    std::vector<int> nums = {2, 7};
    int target = 9;
    std::vector<int> result = sol.twoSum(nums, target);

    // 验证结果是否正确
    EXPECT_EQ(result.size(), 2);
    if (result.size() == 2)
    {
        EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
    }
}
// 测试用例
TEST(TwoSumTest, two)
{
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    std::vector<int> result = sol.twoSum(nums, target);

    // 验证结果是否正确
    EXPECT_EQ(result.size(), 2);
    if (result.size() == 2)
    {
        EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
    }
}
TEST(TwoSumTest, three)
{
    Solution sol;
    std::vector<int> nums = {1, 2, 4, 10, 15, 7};
    int target = 11;
    std::vector<int> result = sol.twoSum(nums, target);

    // 验证结果是否正确
    EXPECT_EQ(result.size(), 2);
    if (result.size() == 2)
    {
        EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
    }
}
TEST(TwoSumTest, four)
{
    Solution sol;
    std::vector<int> nums = {0, 1, 2, 3, 4, 5};
    int target = 6;
    std::vector<int> result = sol.twoSum(nums, target);

    // 验证结果是否正确
    EXPECT_EQ(result.size(), 2);
    if (result.size() == 2)
    {
        EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
    }
}
