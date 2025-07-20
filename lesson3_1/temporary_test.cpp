#include <iostream>
#include <vector>
#include <string>

#include "sum.h"
#include "three_sum.hh"
#include "four_sum.hh"
#include "letter_combination.hh"
#include "move_zero.hh"
#include "max_water.hh"
#include "collect_rainwater.hh"
#include "sliding_window.hh"

int main()
{
    std::string s = "cbaebabacd";
    std::string p = "abc";
    SlidingWindow sw;
    std::vector<int> result = sw.findAnagrams(s, p);
    for (int index : result)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}