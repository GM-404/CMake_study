#include <gtest/gtest.h>
#include <vector>
#include "matrix.hh" // 包含两种方法的Matrix类声明

// 测试用例：哈希集合法（空间O(m+n)）
TEST(MatrixSetZeroesTest, HashMethod)
{
    // 测试类（使用哈希集合的版本，假设类名为MatrixHash）
    Matrix solver_hash;

    // 用例1：基本场景（中间元素含0）
    {
        std::vector<std::vector<int>> input = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        std::vector<std::vector<int>> expected = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
        solver_hash.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例2：首行首列含0
    {
        std::vector<std::vector<int>> input = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        std::vector<std::vector<int>> expected = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
        solver_hash.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例3：空矩阵
    {
        std::vector<std::vector<int>> input = {};
        std::vector<std::vector<int>> expected = {};
        solver_hash.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例4：单元素矩阵（含0）
    {
        std::vector<std::vector<int>> input = {{0}};
        std::vector<std::vector<int>> expected = {{0}};
        solver_hash.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例5：无0元素（不做修改）
    {
        std::vector<std::vector<int>> input = {{1, 2}, {3, 4}};
        std::vector<std::vector<int>> expected = {{1, 2}, {3, 4}};
        solver_hash.setZeroes(input);
        EXPECT_EQ(input, expected);
    }
}

// 测试用例：原地标记法（空间O(1)）
TEST(MatrixSetZeroesTest, InplaceMethod)
{
    // 测试类（使用原地标记的版本，假设类名为MatrixInplace）
    Matrix solver_inplace;

    // 用例1：基本场景（中间元素含0）
    {
        std::vector<std::vector<int>> input = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        std::vector<std::vector<int>> expected = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
        solver_inplace.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例2：首行首列含0（原地法的关键场景）
    {
        std::vector<std::vector<int>> input = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        std::vector<std::vector<int>> expected = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
        solver_inplace.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例3：首行单独含0
    {
        std::vector<std::vector<int>> input = {{1, 0, 3}, {4, 5, 6}, {7, 8, 9}};
        std::vector<std::vector<int>> expected = {{0, 0, 0}, {4, 0, 6}, {7, 0, 9}};
        solver_inplace.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例4：首列单独含0
    {
        std::vector<std::vector<int>> input = {{1, 2, 3}, {0, 5, 6}, {7, 8, 9}};
        std::vector<std::vector<int>> expected = {{0, 2, 3}, {0, 0, 0}, {0, 8, 9}};
        solver_inplace.setZeroes(input);
        EXPECT_EQ(input, expected);
    }

    // 用例5：全0矩阵
    {
        std::vector<std::vector<int>> input = {{0, 0}, {0, 0}};
        std::vector<std::vector<int>> expected = {{0, 0}, {0, 0}};
        solver_inplace.setZeroes(input);
        EXPECT_EQ(input, expected);
    }
}

// 运行所有测试
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
