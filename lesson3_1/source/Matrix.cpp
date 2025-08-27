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
// 73暂时性测试
//   std::vector<std::vector<int>> nums = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//      std::vector<std::vector<int>> nums2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//      Matrix s;
//      s.setZeroes(nums);
//      s.setZeroes(nums2);
//      for (const auto &row : nums)
//      {
//          for (const auto &val : row)
//          {
//              std::cout << val << " ";
//          }
//          std::cout << std::endl;
//      }

//  54. 螺旋矩阵
std::vector<int> Matrix::spiralOrder(const std::vector<std::vector<int>> &matrix)
{
    std::vector<int> res;
    if (matrix.empty())
        return res; // 空矩阵直接返回
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            res.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]);
        right--;
        if (top <= bottom)
        { // 关键检查：避免只剩一行时重复遍历
            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right)
        { // 关键检查：避免只剩一列时重复遍历
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
};
std::vector<int> Matrix::spiralOrder2(const std::vector<std::vector<int>> &matrix)
{
    std::vector<int> res;
    if (matrix.empty())
        return res;

    int m = matrix.size(), n = matrix[0].size();
    // 定义4个方向：右、下、左、上（dx为行偏移，dy为列偏移）
    std::vector<std::pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0; // 当前方向索引（0:右, 1:下, 2:左, 3:上）

    // 边界：left=左边界, right=右边界, top=上边界, bottom=下边界
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    int x = 0, y = 0; // 当前位置

    for (int i = 0; i < m * n; ++i)
    {
        res.push_back(matrix[x][y]); // 加入当前元素

        // 计算下一个位置
        int nx = x + dirs[dir].first;
        int ny = y + dirs[dir].second;

        // 若下一个位置越界或超出当前边界，则切换方向并收缩边界
        if (nx < top || nx > bottom || ny < left || ny > right)
        {
            // 收缩边界（根据当前方向）
            if (dir == 0)
                top++; // 右移完，上边界下移
            else if (dir == 1)
                right--; // 下移完，右边界左移
            else if (dir == 2)
                bottom--; // 左移完，下边界上移
            else if (dir == 3)
                left++; // 上移完，左边界右移

            dir = (dir + 1) % 4; // 切换到下一个方向
            // 更新下一个位置（按新方向）
            nx = x + dirs[dir].first;
            ny = y + dirs[dir].second;
        }

        // 移动到下一个位置
        x = nx;
        y = ny;
    }

    return res;
}
// 54暂时性测试
//   std::vector<std::vector<int>> nums = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//     std::vector<std::vector<int>> nums2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//     Matrix s;
//     std::vector<int> res = s.spiralOrder(nums2);
//     for (const auto &val : res)
//     {
//         std::cout << val << " ";
//     }
//     return 0;
