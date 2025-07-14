#include <iostream>
#include <vector>

#include "sum.h"
#include "three_sum.hh"
#include "four_sum.hh"
#include "letter_combination.hh"

int main()
{
    letter_combination lc;
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams(input);
    std::vector<std::vector<std::string>> result1 = lc.groupAnagrams1(input);
    for (const auto &group : result)
    {
        for (const auto &word : group)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    // // 遍历result：外层是std::vector<std::vector<std::string>>，内层是std::vector<std::string>
    // for (int i = 0; i < result.size(); ++i)
    // {                                                      // 外层循环：使用索引遍历
    //     const std::vector<std::string> &group = result[i]; // 显式声明内层向量类型
    //     for (int j = 0; j < group.size(); ++j)
    //     {                                       // 内层循环：使用索引遍历
    //         const std::string &word = group[j]; // 显式声明字符串类型
    //         std::cout << word << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // 显式类型的范围for循环（仍可避免auto）
    // for (const std::vector<std::string> &group : result)
    // {
    //     for (const std::string &word : group)
    //     {
    //         std::cout << word << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}