#include <iostream>

#include <unordered_map>
#include "subarray.hh"

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    Solution_subarray sol;
    int result = sol.maxSubArray(nums, target);
    std::cout << "Number of subarrays with sum " << target << ": " << result << std::endl;
    return 0;
}