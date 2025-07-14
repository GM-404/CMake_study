#include <iostream>
#include <vector>

#include "sum.h"
#include "three_sum.hh"
#include "four_sum.hh"

int main()
{
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution_four_sum solution;
    std::vector<std::vector<int>> result = solution.four_Sum(nums, target);
    for (const auto &quadruplet : result)
    {
        for (int num : quadruplet)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
