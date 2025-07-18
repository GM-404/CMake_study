#include <iostream>
#include <vector>

#include "sum.h"
#include "three_sum.hh"
#include "four_sum.hh"
#include "letter_combination.hh"
#include "move_zero.hh"

int main()
{
    Solution_Move_Zero solution;
    std::vector<int> nums = {0, 1, 0, 3, 12};
    solution.Move_Zeroes(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << std::endl;
    }
    return 0;
}