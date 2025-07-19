#ifndef COLLECT_RAINWATER_HH
#define COLLECT_RAINWATER_HH

#include <vector>
#include <iostream>
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// eg:
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6

class Solution_rainwater
{
public:
    int trap(std::vector<int> &height);
};
#endif

// 测试用例

// int main()
// {
//     Solution_rainwater solution;
//     int restult;
//     std::vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // 测试复杂情况
//     std::vector<int> height2 = {4, 2, 0, 3, 2, 5};
//     restult = solution.trap(height2);
//     std::cout << restult << std::endl;
//     return 0;
// }