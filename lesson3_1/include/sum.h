#ifndef SUM_H
#define SUM_H

#include <vector>
#include <unordered_map>

class Solution
{
public:
    // 接受一个整数向量 nums 和一个整数 target 作为参数，返回一个包含两个整数的向量，这两个整数表示数组中两个数的索引，这两个数的和等于 target。
    std::vector<int> twoSum(std::vector<int> &nums, int target);
};

#endif // SOLUTION_H
