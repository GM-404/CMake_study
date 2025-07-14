
#include <algorithm> // 排序函数
#include "four_sum.hh"

/*
问题叙述:
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
*/
// 方法1：暴力法
std::vector<std::vector<int>> Solution_four_sum::four_Sum(std::vector<int> &nums, int target)
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
// 方法2：双指针法
// 这种方法的时间复杂度是 O(n^3)，比暴力法的 O(n^4) 更高效。我们通过排序数组，然后使用四个指针来找到满足条件的四元组。
// 这种方法的核心思想是先固定前两个指针，然后使用双指针法来查找后两个指针的值。这样可以减少不必要的重复计算，提高效率。
std::vector<std::vector<int>> Solution_four_sum_quick::four_Sum(std::vector<int> &nums, int target)
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
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }
        // 剪枝操作
        if ((long long)nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target)
        {
            break;
        }
        if ((long long)nums[first] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
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
            // 剪枝操作
            if ((long long)nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target)
            {
                break;
            }
            if ((long long)nums[first] + nums[second] + nums[length - 2] + nums[length - 1] < target)
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
// 测试代码，运行时将以下部分复制到temporary_test.cpp中
// int main()
// {
//     std::vector<int> nums = {1, 0, -1, 0, -2, 2};
//     int target = 0;
//     Solution_four_sum solution;
//     std::vector<std::vector<int>> result = solution.four_Sum(nums, target);
//     for (const auto &quadruplet : result)
//     {
//         for (int num : quadruplet)
//         {//             std::cout << num << " ";
// }
// std::cout << std::endl;
// }
// return 0;
