#include <gtest/gtest.h>

#include "four_sum.hh"

TEST(Test_four_sum, one)
{
    std::vector<std::vector<int>> result;
    Solution_four_sum_quick sol;
    std::vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 10;
    result = sol.four_Sum(nums, target);

    std::cout << "The four numbers that sum to " << target << " have:" << result.size() << std::endl;
    // 打印结果
    if (!result.empty())
    {
        for (const auto &triplet : result)
        {
            for (int num : triplet)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "no result" << std::endl;
    }
    // 验证结果是否正确
    EXPECT_EQ(result.size(), 5); // 验证结果数量
    for (int i = 0; i < result.size(); i++)
    {
        // 验证每个结果的大小
        EXPECT_EQ(result[i].size(), 4);
        // 验证每个结果是否等于目标值
        EXPECT_EQ(result[i][0] + result[i][1] + result[i][2] + result[i][3], target);
    }
}
TEST(Test_four_sum, two)
{
    std::vector<std::vector<int>> result;
    Solution_four_sum_quick sol;
    std::vector<int> nums = {1, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};
    int target = 12;
    result = sol.four_Sum(nums, target);
    std::cout << "The four numbers that sum to " << target << " have:" << result.size() << std::endl;
    // 打印结果
    if (!result.empty())
    {
        for (const auto &triplet : result)
        {
            for (int num : triplet)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "no result" << std::endl;
    }
    // 验证结果是否正确
    EXPECT_EQ(result.size(), 5); // 验证结果数量
    for (int i = 0; i < result.size(); i++)
    {
        // 验证每个结果的大小
        EXPECT_EQ(result[i].size(), 4);
        // 验证每个结果是否等于目标值
        EXPECT_EQ(result[i][0] + result[i][1] + result[i][2] + result[i][3], target);
    }
}
TEST(Test_four_sum, third)
{
    std::vector<std::vector<int>> result;
    Solution_four_sum_quick sol;
    std::vector<int> nums = {2, 2, 2, 2, 2};
    int target = 8;
    result = sol.four_Sum(nums, target);
    std::cout << "The four numbers that sum to " << target << " have:" << result.size() << std::endl;
    // 打印结果
    if (!result.empty())
    {
        for (const auto &triplet : result)
        {
            for (int num : triplet)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "no result" << std::endl;
    }
    // 验证结果是否正确
    EXPECT_EQ(result.size(), 1); // 验证结果数量
    for (int i = 0; i < result.size(); i++)
    {
        // 验证每个结果的大小
        EXPECT_EQ(result[i].size(), 4);
        // 验证每个结果是否等于目标值
        EXPECT_EQ(result[i][0] + result[i][1] + result[i][2] + result[i][3], target);
    }
}