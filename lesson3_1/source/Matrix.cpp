#include "matrix.hh"

void Matrix::setZeroes(std::vector<std::vector<int>> &matrix)
{
    if (matrix.empty())
    {
        return;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::unordered_set<int> zeroRows; // 用集合去重行号
    std::unordered_set<int> zeroCols; // 用集合去重列号
    // 遍历数组找到所有的0的行号和列号
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroRows.insert(i); // 重复行号不会被多次存储
                zeroCols.insert(j); // 重复列号不会被多次存储
            }
        }
    }
    // 2. 将所有含0的行置零
    for (int row : zeroRows)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[row][j] = 0;
        }
    }

    // 3. 将所有含0的列置零
    for (int col : zeroCols)
    {
        for (int i = 0; i < rows; ++i)
        {
            matrix[i][col] = 0;
        }
    }
    return;
}