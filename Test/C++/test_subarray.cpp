#include <gtest/gtest.h>
#include "subarray.hh"
#include <vector>

// 测试类：继承自 ::testing::Test
// 这样可以使用 Google Test 的测试框架功能
class SolutionSubarrayTest : public ::testing::Test
{
protected:
    Solution_subarray sol;
};

// 测试用例：空数组
TEST_F(SolutionSubarrayTest, EmptyArray)
{
    std::vector<int> nums;
    int target = 5;
    EXPECT_EQ(sol.maxSubArray(nums, target), 0);
}

// 测试用例：单元素数组
TEST_F(SolutionSubarrayTest, SingleElement)
{
    std::vector<int> nums = {5};
    int target = 5;
    EXPECT_EQ(sol.maxSubArray(nums, target), 1);

    target = 3;
    EXPECT_EQ(sol.maxSubArray(nums, target), 0);
}

// 测试用例：基本场景
TEST_F(SolutionSubarrayTest, BasicCase)
{
    std::vector<int> nums = {1, 2, 3};
    int target = 3;
    EXPECT_EQ(sol.maxSubArray(nums, target), 2); // [1,2], [3]
}

// 测试用例：包含负数
TEST_F(SolutionSubarrayTest, WithNegatives)
{
    std::vector<int> nums = {1, -1, 2, -2};
    int target = 0;
    EXPECT_EQ(sol.maxSubArray(nums, target), 3); // [1,-1], [1,-1,2,-2], [2,-2]
}

// 测试用例：多个不连续子数组
TEST_F(SolutionSubarrayTest, MultipleNonContiguous)
{
    std::vector<int> nums = {0, 0, 0};
    int target = 0;
    EXPECT_EQ(sol.maxSubArray(nums, target), 6); // [0], [0], [0], [0,0], [0,0], [0,0,0]
}

// 测试用例：无匹配子数组
TEST_F(SolutionSubarrayTest, NoMatch)
{
    std::vector<int> nums = {1, 2, 3};
    int target = 10;
    EXPECT_EQ(sol.maxSubArray(nums, target), 0);
}

// 测试用例：需要断尾多次的场景
TEST_F(SolutionSubarrayTest, MultipleTails)
{
    std::vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int target = 7;
    EXPECT_EQ(sol.maxSubArray(nums, target), 4); // [7], [3,4], [7,2,-3,1], [1,4,2]
}

// 测试用例：负数目标
TEST_F(SolutionSubarrayTest, NegativeTarget)
{
    std::vector<int> nums = {2, -3, 1};
    int target = -1;
    EXPECT_EQ(sol.maxSubArray(nums, target), 1); // [2,-3],
}

// 测试用例：单元素多次出现
TEST_F(SolutionSubarrayTest, SingleElementMultipleTimes)
{
    std::vector<int> nums = {1, 1, 1, 1};
    int target = 2;
    EXPECT_EQ(sol.maxSubArray(nums, target), 3); // [1,1], [1,1], [1,1]
}

// 测试用例：包含零的复杂场景
TEST_F(SolutionSubarrayTest, ComplexWithZero)
{
    std::vector<int> nums = {0, 1, 0, -1, 0};
    int target = 0;
    EXPECT_EQ(sol.maxSubArray(nums, target), 7); // [0], [0], [0], [0,1,0,-1], [1,0,-1], [0,-1,0], [-1,0]
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}