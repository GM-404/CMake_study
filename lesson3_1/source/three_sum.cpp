#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> triples;
        int length = nums.size();
        // 如果数组元素少于 3 个，无法构成三元组，直接返回空结果
        if (length < 3)
        {
            return triples;
        }
        // 对数组进行排序，方便后续去重和使用双指针
        std::sort(nums.begin(), nums.end()); // 排序函数

        for (int first = 0; first < length; ++first)
        {
            // 跳过重复的第一个元素
            if (first > 0 && nums[first] == nums[first - 1]) // 去重，如果第一个元素和前一个元素相等,会找到相同的元素数组,加前面是为了保证后面不为负
            {
                continue;
            }
            int target = -nums[first]; // 目标为找到第一个数字的负数
            int third = length - 1;    // 对于每一个固定的第一个元素，使用两个指针 second 和 third 分别从第一个元素的下一个位置和数组末尾开始向中间移动。
            for (int second = first + 1; second < length; ++second)
            {
                // 跳过重复的第二个元素
                if (second > first + 1 && nums[second] == nums[second - 1]) // 加前面是为了保证后面不为负
                {
                    continue;
                }
                // 确保第二个指针在第三个指针左侧
                while (second < third && nums[second] + nums[third] > target) // 如果大了就把第三个元素往前移动
                {
                    --third;
                }
                // 如果两个指针相遇，说明没有合适的三元组了，跳出循环
                if (second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target)
                {
                    triples.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return triples;
    }
};
int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution;
    std::vector<std::vector<int>> result = solution.threeSum(nums);
    for (const auto &triplet : result)
    {
        for (int num : triplet)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}