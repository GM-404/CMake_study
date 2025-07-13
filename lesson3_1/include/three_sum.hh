#ifndef THREE_SUM_HH
#define THREE_SUM_HH

#include <vector>
#include <unordered_map>
/*给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。*/
class Solution_three_sum
{
public:
    // 接受一个整数向量 nums 返回包含三个整数的向量，这三个整数和等于 0。
    std::vector<std::vector<int>> three_Sum(std::vector<int> &nums);
};

#endif // SOLUTION_HH