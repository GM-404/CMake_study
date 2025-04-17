#ifndef LETTER_HH
#define LETTER_HH

#include <iostream>
#include <vector>
#include <string>
/*
解决问题: 49 字母异位词分组
问题描述给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
例如，"acdc" 和 "cdca" 是字母异位词。

时间:2025.4.17
作者: 高明
*/

class letter_combination
{
public:
    // 版本一: std::is_permutation 函数来判断两个字符串是否为字母异位词。时间复杂度为 \(O(n^2 * k)\)
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs);
    // 版本二:用哈希表来优化算法的时间复杂度。具体做法是，将每个字符串排序后作为键，将所有字母异位词作为值存储在哈希表中。这样，算法的时间复杂度可以降低到 \(O(n * k log k)\)，
    std::vector<std::vector<std::string>> groupAnagrams1(std::vector<std::string> &strs);
};
#endif

// 调用示例：
// int main()
// {
//     letter_combination lc;
//     std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
//     std::vector<std::vector<std::string>> result = lc.groupAnagrams(input);
//     std::vector<std::vector<std::string>> result1 = lc.groupAnagrams1(input);
//     for (const auto &group : result)
//     {
//         for (const auto &word : group)
//         {
//             std::cout << word << " ";
//         }
//         std::cout << std::endl;
//     }

//     for (const auto &group : result1)
//     {
//         for (const auto &word : group)
//         {
//             std::cout << word << " ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }