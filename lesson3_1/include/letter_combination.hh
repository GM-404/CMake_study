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

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

时间:2025.4.17
作者: GM-404
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
//     // // 遍历result：外层是std::vector<std::vector<std::string>>，内层是std::vector<std::string>
//     // for (int i = 0; i < result.size(); ++i)
//     // {                                                      // 外层循环：使用索引遍历
//     //     const std::vector<std::string> &group = result[i]; // 显式声明内层向量类型
//     //     for (int j = 0; j < group.size(); ++j)
//     //     {                                       // 内层循环：使用索引遍历
//     //         const std::string &word = group[j]; // 显式声明字符串类型
//     //         std::cout << word << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }
//     // 显式类型的范围for循环（仍可避免auto）
//     // for (const std::vector<std::string> &group : result)
//     // {
//     //     for (const std::string &word : group)
//     //     {
//     //         std::cout << word << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }

//     return 0;
// }