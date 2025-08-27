#ifndef _MATRIX_HH_
#define _MATRIX_HH_

#include <vector>
#include <stdexcept>
#include <stack>

#include <unordered_set> // 用于去重行号和列号
class Matrix
{
public:
    // 默认构造函数（无需初始化任何内部状态）
    Matrix() = default;
    // 54. 螺旋矩阵
    std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix);
    std::vector<int> spiralOrder2(const std::vector<std::vector<int>> &matrix);
    // 73. 矩阵置零
    void setZeroes(std::vector<std::vector<int>> &matrix);
    void setZeroes1(std::vector<std::vector<int>> &matrix);

    // 析构函数
    ~Matrix()
    {
        // 无需手动释放内存，vector的析构函数会自动被调用
    }
};

#endif