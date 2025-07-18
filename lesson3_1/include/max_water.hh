#ifndef MAX_WATER_HH
#define MAX_WATER_HH
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子,下面最多能接多少雨水。*/
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是(i, 0) 和(i, height[i]) 。

//     找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

//     返回容器可以储存的最大水量。

//     说明：你不能倾斜容器。

class Solution_max_water
{
public:
    int max_water(std::vector<int> &height);
};

#endif
