#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "move_zero.hh"
using namespace std;

// // 辅助函数：验证结果是否符合预期
// bool verifyResult(const vector<int> &nums)
// {
//     // 检查所有非零元素是否在零元素之前
//     bool foundZero = false;
//     for (int num : nums)
//     {
//         if (num == 0)
//         {
//             foundZero = true;
//         }
//         else if (foundZero)
//         {
//             return false; // 发现非零元素在零元素之后
//         }
//     }
//     // 检查非零元素的相对顺序是否保持不变
//     vector<int> originalNonZero;
//     vector<int> resultNonZero;

//     for (int num : nums)
//     {
//         if (num != 0)
//         {
//             originalNonZero.push_back(num);
//         }
//     }

//     vector<int> numsCopy = nums;
//     Solution_Move_Zero sol;
//     sol.Move_Zeroes(numsCopy);

//     for (int num : numsCopy)
//     {
//         if (num != 0)
//         {
//             resultNonZero.push_back(num);
//         }
//     }

//     return originalNonZero == resultNonZero;
// }

// 测试用例：基本情况
TEST(MoveZeroesTest, BasicCase)
{
    Solution_Move_Zero sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> expected = {1, 3, 12, 0, 0};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：没有零
TEST(MoveZeroesTest, NoZeroes)
{
    Solution_Move_Zero sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：全是零
TEST(MoveZeroesTest, AllZeroes)
{
    Solution_Move_Zero sol;
    vector<int> nums = {0, 0, 0, 0};
    vector<int> expected = {0, 0, 0, 0};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：零在开头
TEST(MoveZeroesTest, ZeroesAtBeginning)
{
    Solution_Move_Zero sol;
    vector<int> nums = {0, 0, 1, 2, 3};
    vector<int> expected = {1, 2, 3, 0, 0};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：零在结尾
TEST(MoveZeroesTest, ZeroesAtEnd)
{
    Solution_Move_Zero sol;
    vector<int> nums = {1, 2, 3, 0, 0};
    vector<int> expected = {1, 2, 3, 0, 0};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：交替出现零
TEST(MoveZeroesTest, AlternatingZeroes)
{
    Solution_Move_Zero sol;
    vector<int> nums = {0, 1, 0, 2, 0, 3};
    vector<int> expected = {1, 2, 3, 0, 0, 0};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：空数组
TEST(MoveZeroesTest, EmptyArray)
{
    Solution_Move_Zero sol;
    vector<int> nums = {};
    vector<int> expected = {};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：只有一个元素
TEST(MoveZeroesTest, SingleElement)
{
    Solution_Move_Zero sol;
    vector<int> nums = {5};
    vector<int> expected = {5};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 测试用例：只有一个零
TEST(MoveZeroesTest, SingleZero)
{
    Solution_Move_Zero sol;
    vector<int> nums = {0};
    vector<int> expected = {0};

    sol.Move_Zeroes(nums);
    EXPECT_EQ(nums, expected);
}

// // 测试用例：验证非零元素相对顺序
// TEST(MoveZeroesTest, MaintainOrder)
// {
//     Solution_Move_Zero sol;
//     vector<int> nums = {1, 2, 0, 3, 0, 4};

//     sol.Move_Zeroes(nums);
//     EXPECT_TRUE(verifyResult(nums));
// }

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}