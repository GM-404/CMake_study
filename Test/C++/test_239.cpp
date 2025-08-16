#include <gtest/gtest.h>
#include <vector>
#include <deque>
#include "sliding_window.hh"

// 测试用例类
SlidingWindow sw;
class SlidingWindowTest : public ::testing::Test
{
protected:
    // 辅助函数：打印向量（调试用）
    void printVector(const std::vector<int> &v)
    {
        for (int num : v)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

// 测试场景1：标准窗口（无重复最大值，窗口大小为数组长度一半）
TEST_F(SlidingWindowTest, StandardWindow)
{
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {3, 3, 5, 5, 6, 7};
    EXPECT_EQ(result, expected) << "标准窗口最大值计算错误";
}

// 测试场景2：窗口大小为1（每个元素都是窗口最大值）
TEST_F(SlidingWindowTest, WindowSize1)
{
    std::vector<int> nums = {5, 2, 9, -1};
    int k = 1;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {5, 2, 9, -1};
    EXPECT_EQ(result, expected) << "窗口大小为1时结果错误";
}

// 测试场景3：窗口大小等于数组长度（仅一个窗口，取全局最大值）
TEST_F(SlidingWindowTest, WindowSizeEqualArray)
{
    std::vector<int> nums = {4, 2, 7, 1, 3};
    int k = 5;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {7};
    EXPECT_EQ(result, expected) << "窗口等于数组长度时结果错误";
}

// 测试场景4：数组元素递增（每个窗口最大值为窗口最后一个元素）
TEST_F(SlidingWindowTest, IncreasingArray)
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {3, 4, 5, 6};
    EXPECT_EQ(result, expected) << "递增数组窗口最大值错误";
}

// 测试场景5：数组元素递减（每个窗口最大值为窗口第一个元素）
TEST_F(SlidingWindowTest, DecreasingArray)
{
    std::vector<int> nums = {6, 5, 4, 3, 2, 1};
    int k = 3;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {6, 5, 4, 3};
    EXPECT_EQ(result, expected) << "递减数组窗口最大值错误";
}

// 测试场景6：数组包含重复元素
TEST_F(SlidingWindowTest, ArrayWithDuplicates)
{
    std::vector<int> nums = {2, 2, 2, 2, 2};
    int k = 2;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {2, 2, 2, 2};
    EXPECT_EQ(result, expected) << "重复元素窗口最大值错误";
}

// 测试场景7：数组包含负数
TEST_F(SlidingWindowTest, ArrayWithNegatives)
{
    std::vector<int> nums = {-1, -3, -5, -2, -4};
    int k = 2;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {-1, -3, -2, -2};
    EXPECT_EQ(result, expected) << "含负数的窗口最大值错误";
}

// 测试场景8：空数组
TEST_F(SlidingWindowTest, EmptyArray)
{
    std::vector<int> nums = {};
    int k = 3;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    EXPECT_TRUE(result.empty()) << "空数组应返回空结果";
}

// 测试场景9：窗口大小为0
TEST_F(SlidingWindowTest, WindowSize0)
{
    std::vector<int> nums = {1, 2, 3};
    int k = 0;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    EXPECT_TRUE(result.empty()) << "窗口大小为0应返回空结果";
}

// 测试场景10：窗口滑动中最大值交替变化
TEST_F(SlidingWindowTest, FluctuatingMax)
{
    std::vector<int> nums = {9, 10, 9, -7, -4, -8, 2, -6};
    int k = 5;
    std::vector<int> result = sw.maxSlidingWindow(nums, k);
    std::vector<int> expected = {10, 10, 9, 2};
    EXPECT_EQ(result, expected) << "交替变化的最大值计算错误";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
