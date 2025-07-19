#include <gtest/gtest.h>
#include "collect_rainwater.hh" // 假设这是你的代码头文件

class SolutionRainwaterTest : public ::testing::Test
{
protected:
    Solution_rainwater solution;
};

// 测试空数组
TEST_F(SolutionRainwaterTest, HandlesEmptyInput)
{
    std::vector<int> height;
    EXPECT_EQ(solution.trap(height), 0);
}

// 测试只有一个元素
TEST_F(SolutionRainwaterTest, HandlesSingleElement)
{
    std::vector<int> height = {5};
    EXPECT_EQ(solution.trap(height), 0);
}

// 测试所有元素都相同
TEST_F(SolutionRainwaterTest, HandlesSameHeight)
{
    std::vector<int> height = {3, 3, 3, 3};
    EXPECT_EQ(solution.trap(height), 0);
}

// 测试单调递增数组
TEST_F(SolutionRainwaterTest, HandlesIncreasingHeights)
{
    std::vector<int> height = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.trap(height), 0);
}

// 测试单调递减数组
TEST_F(SolutionRainwaterTest, HandlesDecreasingHeights)
{
    std::vector<int> height = {5, 4, 3, 2, 1};
    EXPECT_EQ(solution.trap(height), 0);
}

// 测试中间高两边低的情况
TEST_F(SolutionRainwaterTest, HandlesPeakInMiddle)
{
    std::vector<int> height = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    EXPECT_EQ(solution.trap(height), 0);
}

// 测试两边高中间低的典型情况
TEST_F(SolutionRainwaterTest, HandlesTrapInMiddle)
{
    std::vector<int> height = {3, 0, 3};
    EXPECT_EQ(solution.trap(height), 3);
}

// 测试示例输入1
TEST_F(SolutionRainwaterTest, HandlesExample1)
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(solution.trap(height), 6);
}

// 测试示例输入2
TEST_F(SolutionRainwaterTest, HandlesExample2)
{
    std::vector<int> height = {4, 2, 0, 3, 2, 5};
    EXPECT_EQ(solution.trap(height), 9);
}

// 测试非对称容器
TEST_F(SolutionRainwaterTest, HandlesAsymmetricContainer)
{
    std::vector<int> height = {5, 2, 1, 2, 1, 5};
    EXPECT_EQ(solution.trap(height), 14);
}

// 测试多个峰值
TEST_F(SolutionRainwaterTest, HandlesMultiplePeaks)
{
    std::vector<int> height = {3, 1, 2, 1, 4, 2, 3};
    EXPECT_EQ(solution.trap(height), 6);
}

// 测试间隔峰值
TEST_F(SolutionRainwaterTest, HandlesSpacedPeaks)
{
    std::vector<int> height = {2, 0, 1, 0, 3, 0, 2};
    EXPECT_EQ(solution.trap(height), 7);
}

// 测试包含0的情况
TEST_F(SolutionRainwaterTest, HandlesZeros)
{
    std::vector<int> height = {0, 2, 0, 3, 0, 2, 0};
    EXPECT_EQ(solution.trap(height), 4);
}

// 测试边缘高的情况
TEST_F(SolutionRainwaterTest, HandlesHighEdges)
{
    std::vector<int> height = {5, 0, 0, 0, 5};
    EXPECT_EQ(solution.trap(height), 15);
}

// 测试中间有高柱的情况
TEST_F(SolutionRainwaterTest, HandlesTallBarInMiddle)
{
    std::vector<int> height = {3, 0, 0, 4, 0, 0, 3};
    EXPECT_EQ(solution.trap(height), 12);
}

// 测试W形状
TEST_F(SolutionRainwaterTest, HandlesWShape)
{
    std::vector<int> height = {2, 1, 2, 1, 2};
    EXPECT_EQ(solution.trap(height), 2);
}

// 测试复杂形状
TEST_F(SolutionRainwaterTest, HandlesComplexShape)
{
    std::vector<int> height = {1, 3, 2, 4, 1, 3, 1, 4, 5, 2, 2, 1, 4, 2, 2};
    EXPECT_EQ(solution.trap(height), 15);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}