#include <iostream>
#include <vector>

#include "sum.h"
#include "three_sum.hh"
#include "four_sum.hh"
#include "letter_combination.hh"
#include "move_zero.hh"
#include "max_water.hh"
int main()
{
    Solution_max_water solution;
    int restult;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    restult = solution.max_water(height);
    std::cout << restult << std::endl;
    return 0;
}