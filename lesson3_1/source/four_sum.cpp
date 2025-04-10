
#include <algorithm> // 排序函数
#include "four_sum.hh"

std::vector<std::vector<int>> Solution_four_sum::fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> result;
    int length = nums.size(); // 判断数组长度 ，如果长度小于 4，直接返回空结果
    if (length < 4)
    {
        return result;
    }

    std::sort(nums.begin(), nums.end());             // 排序函数
    for (int first = 0; first < length - 3; ++first) // 第一个指针，遍历到倒数第三个元素
    {
        // if (first > 0 && nums[first] == nums[first - 1])
        // {
        //     continue;
        // }
        for (int second = first + 1; second < length - 2; ++second) // 第二个指针，遍历到倒数第二个元素
        {
            // // 对第二个元素去重
            // if (second > first + 1 && nums[second] == nums[second - 1])
            // {
            //     continue;
            // }
            for (int third = second + 1; third < length - 1; ++third) // 第三个指针，遍历到倒数第一个元素
            {
                // // 对第三个元素去重
                // if (third > second + 1 && nums[third] == nums[third - 1])
                // {
                //     continue;
                // }
                for (int fourth = third + 1; fourth < length; ++fourth) // 第四个指针，遍历到最后一个元素
                {

                    if (nums[first] + nums[second] + nums[third] + nums[fourth] == target) // 如果找到了满足条件的四个元素
                    {
                        result.push_back({nums[first], nums[second], nums[third], nums[fourth]}); // 将这四个元素添加到结果中
                    }
                    // // 去重操作，避免重复的四元组
                    // while (fourth < length - 1 && nums[fourth] == nums[fourth + 1]) // 主要从第四个元素下手，如果当前元素和下一个元素相同，没必要再循环
                    // {
                    //     ++fourth; // 如果当前元素和下一个元素相同，跳过下一个元素
                    // }
                }
            }
        }
    }
    std::sort(result.begin(), result.end());
    // 使用 std::unique 将重复的元素移到向量末尾，并返回指向第一个重复元素的迭代器
    auto last = std::unique(result.begin(), result.end()); // 这个时候是逆向迭代指向最后一个重复元素
    // 移除重复的元素
    result.erase(last, result.end()); // 从最后一个元素一直往前删除
    return result;                    // 返回结果
}
std::vector<std::vector<int>> Solution_four_sum_quick::fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> result;
    int length = nums.size(); // 判断数组长度 ，如果长度小于 4，直接返回空结果
    if (length < 4)
    {
        return result;
    }
    // 对数组进行排序，方便后续去重和使用双指针
    std::sort(nums.begin(), nums.end()); // 排序函数
    for (int first = 0; first < length - 3; ++first)
    {
        // 去重第一个数字
        if (first > 0 && nums[first] == nums[first] - 1)
        {
            continue;
        }
        for (int second = first + 1; second < length - 2; ++second)
        {
            // 去重第二个数字
            if (second > first + 1 && nums[second] == nums[second - 1])
            {
                continue;
            }
            // 使用双指针法降低复杂度
            int left = second + 1;
            int right = length - 1;
            while (left < right)
            {
                long long sum = static_cast<long long>(nums[first] + nums[second] + nums[left] + nums[right]);
                if (sum == target)
                {
                    result.push_back({nums[first], nums[second], nums[left], nums[right]});
                    // 对第三个元素去重
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        ++left;
                    }
                    // 对第四个个元素去重
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        --right;
                    }
                    --right; // 找到一个四元组后，得先看下一个数字是否重合，再继续向内收缩指针
                    ++left;  // 找到一个四元组后，继续向内收缩指针
                }
                else if (sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
    }
    // std::sort(result.begin(), result.end());
    // // 使用 std::unique 将重复的元素移到向量末尾，并返回指向第一个重复元素的迭代器
    // auto last = std::unique(result.begin(), result.end()); // 这个时候是逆向迭代指向最后一个重复元素
    // // 移除重复的元素
    // result.erase(last, result.end()); // 从最后一个元素一直往前删除
    return result; // 返回结果
}
