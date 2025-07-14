#include "letter_combination.hh"
#include <unordered_map>
#include <algorithm> // 排序函数
#include <iostream>
#include <vector>
#include <string>
#include <functional> // std::function

std::vector<std::vector<std::string>> letter_combination::groupAnagrams(std::vector<std::string> &strs)
{
    // Result vector to store grouped anagrams
    std::vector<std::vector<std::string>> result;
    // Return empty result if input is empty
    if (strs.empty())
    {
        return result;
    }
    // Temporary vector to store current group of anagrams
    std::vector<std::string> temp;
    // Function to check if two strings are anagrams
    for (int i = 0; i < strs.size(); ++i)
    {
        // Add current string to temporary vector
        temp.push_back(strs[i]);
        for (int j = i + 1; j < strs.size(); ++j)
        {
            // std::is_permutation 函数会比较两个范围的元素是否是彼此的排列组合。
            if (std::is_permutation(strs[i].begin(), strs[i].end(), strs[j].begin()))
            {
                temp.push_back(strs[j]);      // Add other string to temporary vector
                strs.erase(strs.begin() + j); // Remove other string from input vector
                --j;                          // Decrement j to account for removed element
            }
        }
        result.push_back(temp); // Add current group of anagrams to result vector
        temp.clear();           // Clear temporary vector
    }
    return result;
}
std::vector<std::vector<std::string>> letter_combination::groupAnagrams1(std::vector<std::string> &strs)
{
    std::vector<std::vector<std::string>> result;
    // Return empty result if input is empty
    if (strs.empty())
    {
        return result;
    }
    // 创建一个哈希表，用于存储字母异位词的分组，其中键是排序后的字符串，值是原始字符串的列表
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;
    for (std::string &str : strs) // 从输入字符串向量中的每个字符串迭代
    {
        std::string sortedStr = str;                   // 将当前字符串复制到 sortedStr
        std::sort(sortedStr.begin(), sortedStr.end()); // 对 sortedStr 进行排序
        anagramMap[sortedStr].push_back(str);          // 将原始字符串添加到对应的排序后的键下
    }
    // for (std::unordered_map<std::string, std::vector<std::string>>::iterator it = anagramMap.begin(); it != anagramMap.end(); ++it)   //类型，迭代器，it
    // {
    //     std::sort(it->second.begin(), it->second.end()); // 对每个分组的字符串进行排序
    // }
    for (const auto &pair : anagramMap) // 遍历哈希表中的每个键值对
    {
        result.push_back(pair.second); // 将每个分组的字符串向量添加到结果向量中
    }
    return result; // 返回结果向量，包含所有字母异位词的分组
}
