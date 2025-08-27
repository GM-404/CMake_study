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
// 原地标记法：核心思路是利用矩阵自身的第一行和第一列作为标记位，避免使用额外的集合或数组存储行 / 列信息。
void Matrix::setZeroes1(std::vector<std::vector<int>> &matrix)
{
    if (matrix.empty())
        return;

    int rows = matrix.size();
    int cols = matrix[0].size();

    // 步骤1：标记首行和首列是否需要置零
    bool row0HasZero = false; // 首行是否有0
    bool col0HasZero = false; // 首列是否有0

    // 检查首行
    for (int j = 0; j < cols; ++j)
    {
        if (matrix[0][j] == 0)
        {
            row0HasZero = true;
            break;
        }
    }

    // 检查首列
    for (int i = 0; i < rows; ++i)
    {
        if (matrix[i][0] == 0)
        {
            col0HasZero = true;
            break;
        }
    }

    // 步骤2：用首行和首列标记其他行/列是否需要置零
    for (int i = 1; i < rows; ++i)
    {
        for (int j = 1; j < cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // 标记第i行需要置零
                matrix[0][j] = 0; // 标记第j列需要置零
            }
        }
    }

    // 步骤3：根据首列标记置零行（从第二行开始）
    for (int i = 1; i < rows; ++i)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 1; j < cols; ++j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // 步骤4：根据首行标记置零列（从第二列开始）
    for (int j = 1; j < cols; ++j)
    {
        if (matrix[0][j] == 0)
        {
            for (int i = 1; i < rows; ++i)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // 步骤5：处理首行和首列
    if (row0HasZero)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0HasZero)
    {
        for (int i = 0; i < rows; ++i)
        {
            matrix[i][0] = 0;
        }
    }
}