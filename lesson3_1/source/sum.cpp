#include <vector>
#include <unordered_map>
#include <iostream>
#include <vector>
class Solution
{
public:
    // 接受一个整数向量 nums 和一个整数 target 作为参数，返回一个包含两个整数的向量，这两个整数表示数组中两个数的索引，这两个数的和等于 target。
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // 定义一个无序映射（哈希表），用于存储数组中的数字及其对应的索引（见知识点）

        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            printf("nums[i]:%d\n", nums[i]);
            int complement = target - nums[i];
            // 如果补数存在于哈希表中，说明找到了满足条件的两个数
            // 返回这两个数的索引，第一个是补数在哈希表中对应的索引，第二个是当前数字的索引
            if (num_map.find(complement) != num_map.end()) // 没有找到就指向最后
            {
                return {num_map[complement], i};
            }
            // 如果补数不存在于哈希表中，将当前数字及其索引存入哈希表
            num_map[nums[i]] = i;
        }
        // 如果没有找到满足条件的两个数，返回空向量
        return {};
    }
};
// std::unordered_map 是 C++ 标准库中的一个容器，它位于 <unordered_map> 头文件中，用于存储键值对。
// 它基于哈希表实现，这意味着它通过哈希函数将键映射到存储桶，从而实现快速的查找、插入和删除操作。
// 其平均时间复杂度为 \(O(1)\)，但在最坏情况下可能达到 \(O(n)\)。

// 上面实现的 Solution 类
int main()
{
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    std::vector<int> result = sol.twoSum(nums, target);
    if (!result.empty())
    {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    }
    else
    {
        std::cout << "No two sum solution found." << std::endl;
    }
    // 定义一个 std::unordered_map<int, int> 对象
    std::unordered_map<int, int> num_map;

    // 插入元素
    num_map[1] = 100;
    num_map[2] = 200;
    num_map[3] = 300;

    // 查找元素
    auto it = num_map.find(2);
    if (it != num_map.end())
    {
        std::cout << "Key 2 found, value is: " << it->second << std::endl;
    }
    else
    {
        std::cout << "Key 2 not found." << std::endl;
    }

    // 删除元素
    num_map.erase(3);

    // 遍历元素
    for (const auto &pair : num_map)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    return 0;
}
// find找的是键值
