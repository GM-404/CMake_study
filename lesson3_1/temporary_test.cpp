#include <iostream>
#include <vector>

#include "sum.h"
#include "three_sum.hh"
#include "four_sum.hh"
#include "letter_combination.hh"
#include "move_zero.hh"
#include "max_water.hh"
#include "collect_rainwater.hh"
int main()
{
    Solution_rainwater solution;
    int restult;
    std::vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // 测试复杂情况
    std::vector<int> height2 = {3, 1, 2, 1, 4, 2, 3};
    restult = solution.trap(height2);
    std::cout << restult << std::endl;
    return 0;
}