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
    std::string s = "abcabcb";
    SlidingWindow sw;
    int max_len = sw.lengthOfLongestSubstring(s);
    std::cout << max_len << std::endl;
    return 0;
}