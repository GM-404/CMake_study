#ifndef SUBARRAY_HH
#define SUBARRAY_HH
#include <vector>

#include <unordered_map>
/*给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。*/
class Solution_subarray // 解决的是连续子数组
{
public:
  // 53. 最大子数组和
  int maxSubArray(std::vector<int> &nums);
  // 56. 合并区间
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals);
  // 189. 旋转数组
  void rotate(std::vector<int> &nums, int k);
  void rotate1(std::vector<int> &nums, int k);
  // 560. 和为 K 的子数组
  int maxSubArray(std::vector<int> &nums, int &target);
};
#endif
