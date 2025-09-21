#include "subarray.hh"
#include <vector>
#include <unordered_map>
// 53. 最大子数组和
int Solution_subarray::maxSubArray(std::vector<int> &nums) {
  // 主体思想为加上当前元素，相对于目前最大子数组和是变小了还是变大了
  int maxSum = nums[0];
  int currentSum = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    currentSum = std::max(nums[i], currentSum + nums[i]);
    maxSum = std::max(maxSum, currentSum);
  }
  return maxSum;
}
// 560. 和为 K 的子数组
int Solution_subarray::maxSubArray(std::vector<int> &nums, int &target)
{
    // 检查输入数组是否为空
    if (nums.empty())
    {
        return 0;
    }
    int count = 0;                               // 计数器，记录满足条件的子数组数量
    int prefix_sum = 0;                          // 前缀和，记录当前子数组的和
    std::unordered_map<int, int> prefix_sum_map; // 哈希表，存储前缀和及其出现次数
    prefix_sum_map[0] = 1;                       // 初始化前缀和为 0 的出现次数为 1，表示空子数组的情况
    for (int num : nums)
    {
        // 计算当前前缀和
        prefix_sum += num;
        // 如果当前前缀和减去目标值等于之前存储的前缀和，说明找到了一个满足条件的子数组，即为将前缀和减去目标值的结果
        if (prefix_sum_map.find(prefix_sum - target) != prefix_sum_map.end())
        {
            count += prefix_sum_map[prefix_sum - target]; // 更新计数器，加上之前存储的前缀和出现次数实际上就是找到了多少个满足条件的子数组，断尾次数
        }
        // 更新当前前缀和的出现次数
        prefix_sum_map[prefix_sum]++; // 对应的前缀和出现次数加 1
        // prefix_sum_map[prefix_sum] = prefix_sum_map.count(prefix_sum) ? prefix_sum_map[prefix_sum] + 1 : 1; // 如果当前前缀和已经存在于哈希表中，则将其出现次数加 1，否则初始化为 1
    }
    return count; // 返回满足条件的子数组数量
}
