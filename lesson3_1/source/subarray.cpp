#include "subarray.hh"
#include <algorithm> // std::sort
#include <unordered_map>
#include <vector>

// 41. 缺失的第一个正数
int Solution_subarray::firstMissingPositive(std::vector<int> &nums) {
  int n = nums.size();
  // 如果数组中包含 x∈[1,N]，那么恢复后，数组的第 x−1 个元素为 x
  for (int i = 0; i < n; i++) {
    while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
      std::swap(nums[i], nums[nums[i] - 1]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (nums[i] != i + 1)
      return i + 1;
  }
  return n + 1;
}
// 哈希表
int Solution_subarray::firstMissingPositive1(std::vector<int> &nums) {
  int n = nums.size();
  std::unordered_map<int, int> map;
  for (int i = 0; i < n; i++) {
    map[nums[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (map.find(i) == map.end())
      return i;
  }
  return n + 1;
}
// 53. 最大子数组和
int Solution_subarray::bestMaxSubArray(std::vector<int> &nums) {
  // 主体思想为加上当前元素，相对于目前最大子数组和是变小了还是变大了
  int maxSum = nums[0];
  int currentSum = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    currentSum = std::max(nums[i], currentSum + nums[i]);
    maxSum = std::max(maxSum, currentSum);
  }
  return maxSum;
}
// 56. 合并区间
std::vector<std::vector<int>>
Solution_subarray::merge(std::vector<std::vector<int>> &intervals) {
  // 检查输入是否为空
  if (size(intervals) == 0)
    return {};
  // 对区间进行排序
  std::sort(
      intervals.begin(), intervals.end(),
      [](std::vector<int> &a, std::vector<int> &b) { return a[0] < b[0]; });
  // 先定义一个区间把第一个区间放进去
  std::vector<std::vector<int>> merged;
  merged.push_back(intervals[0]);
  // 合并区间
  for (int i = 1; i < intervals.size(); i++) {
    // merged.back()[1] 表示结果数组中最后一个区间的右端点。
    if (merged.back()[1] >= intervals[i][0]) {
      merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
    } else {
      merged.push_back(intervals[i]);
    }
  }
  return merged;
}
// 189. 旋转数组
void Solution_subarray::rotate(std::vector<int> &nums, int k) {
  int n = nums.size();
  k = k % n;
  // 逆序
  std::reverse(nums.begin(), nums.end());
  std::reverse(nums.begin(), nums.begin() + k);
  std::reverse(nums.begin() + k, nums.end());
}
void Solution_subarray::rotate1(std::vector<int> &nums, int k) {
  int n = nums.size();
  std::vector<int> newArr(n);
  for (int i = 0; i < n; ++i) {
    newArr[(i + k) % n] = nums[i];
  }
  // 用新的元素替换容器中现有的所有元素。
  nums.assign(newArr.begin(), newArr.end());
}
// 238. 除自身以外数组的乘积
std::vector<int> Solution_subarray::productExceptSelf(std::vector<int> &nums) {
  int length = nums.size();
  std::vector<int> leftProduct(length, 1);
  std::vector<int> rightProduct(length, 1);
  for (int i = 1; i < length; i++) {
    leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
  }
  for (int i = length - 2; i >= 0; i--) {
    rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
  }
  std::vector<int> result(length);
  for (int i = 0; i < length; i++) {
    result[i] = leftProduct[i] * rightProduct[i];
  }
  return result;
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
