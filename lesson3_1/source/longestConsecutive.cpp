
#include <unordered_map>
#include <algorithm> // 排序函数
#include <iostream>
#include <vector>
#include "longestConsecutive.hh"

int Solution_longestConsecutive::longestConsecutive(std::vector<int> &nums)
{
    int longest = 1;
    int currentLength = 1;
    std::sort(nums.begin(), nums.end());
    int longest = 1;
    int currentLength = 1;
    if (nums.empty())
        return 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            currentLength++;
        }
        else if (nums[i] == nums[i - 1])
        {
            continue;
        }
        else
        {
            currentLength = 1;
        }
        longest = std::max(longest, currentLength);
    }
    return longest;

    // std::unordered_map<int, int> numMap;
    // for (int num : nums)
    // {
    //     numMap[num] = 1;
    // }
    // int longest = 0;
    // for (int num : nums)
    // {
    //     if (numMap.find(num - 1) == numMap.end())
    //     {
    //         int currentNum = num;
    //         int currentLength = 1;
    //         while (numMap.find(currentNum + 1) != numMap.end())
    //         {
    //             currentNum += 1;
    //             currentLength += 1;
    //         }
    //         longest = std::max(longest, currentLength);
    //     }
    // }
    // return longest;
}
