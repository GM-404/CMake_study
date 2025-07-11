#include <iostream>
#include <vector>

#include "sum.h"

/*
''' 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。

    你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

        你可以按任意顺序返回答案。
'''
*/

int main()
{
    std::cout << "lesson3_1, temporary_test" << std::endl;
    Solution sol;
    std::vector<int> nums = {1, 2, 4, 10, 15, 7};
    int target = 11;
    std::vector<int> result = sol.twoSum(nums, target);
    if (!result.empty())
    {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
        std::cout << "Values: " << nums[result[0]] << ", " << nums[result[1]] << std::endl;
    }
    else
    {
        std::cout << "No two sum solution found." << std::endl;
    }
    return 0;
}