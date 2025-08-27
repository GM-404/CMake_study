#include <gtest/gtest.h>
#include <vector>
#include "matrix.hh" // 包含Matrix类和spiralOrder函数声明

// 测试类：封装测试用例
class SpiralOrderTest : public testing::Test
{
protected:
    // 实例化测试对象
    Matrix matrix;
};

// 测试用例1：3x3正方形矩阵（标准螺旋）
TEST_F(SpiralOrderTest, 3x3Matrix)
{
    std::vector<std::vector<int>> input = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例2：2x2正方形矩阵
TEST_F(SpiralOrderTest, 2x2Matrix)
{
    std::vector<std::vector<int>> input = {
        {1, 2},
        {3, 4}};
    std::vector<int> expected = {1, 2, 4, 3};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例3：行数 > 列数的长方形矩阵（3x2）
TEST_F(SpiralOrderTest, RowsGreaterThanCols)
{
    std::vector<std::vector<int>> input = {
        {1, 2},
        {3, 4},
        {5, 6}};
    std::vector<int> expected = {1, 2, 4, 6, 5, 3};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例4：列数 > 行数的长方形矩阵（2x3）
TEST_F(SpiralOrderTest, ColsGreaterThanRows)
{
    std::vector<std::vector<int>> input = {
        {1, 2, 3},
        {4, 5, 6}};
    std::vector<int> expected = {1, 2, 3, 6, 5, 4};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例5：单行矩阵（1x5）
TEST_F(SpiralOrderTest, SingleRow)
{
    std::vector<std::vector<int>> input = {{1, 2, 3, 4, 5}};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例6：单列矩阵（5x1）
TEST_F(SpiralOrderTest, SingleColumn)
{
    std::vector<std::vector<int>> input = {
        {1},
        {2},
        {3},
        {4},
        {5}};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例7：空矩阵
TEST_F(SpiralOrderTest, EmptyMatrix)
{
    std::vector<std::vector<int>> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例8：1x1矩阵（单个元素）
TEST_F(SpiralOrderTest, SingleElement)
{
    std::vector<std::vector<int>> input = {{100}};
    std::vector<int> expected = {100};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

// 测试用例9：4x4矩阵（偶数行偶数列）
TEST_F(SpiralOrderTest, 4x4Matrix)
{
    std::vector<std::vector<int>> input = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    std::vector<int> expected = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
    EXPECT_EQ(matrix.spiralOrder(input), expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
