// Test letter combination
// Created by 高明 on 2025/4/17
#include <gtest/gtest.h>
#include "letter.hh"

// 辅助函数：用于打印分组结果
void printGroupAnagrams(const std::vector<std::vector<std::string>> &groups)
{
    for (const auto &group : groups)
    {
        for (const auto &word : group)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}
TEST(LetterCombination_groupAnagrams, one)
{
    letter_combination lc;
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams(input);
    std::cout << "one result:" << std::endl;
    EXPECT_EQ(result.size(), 3); // 验证结果数量
    printGroupAnagrams(result);
}
TEST(LetterCombination_groupAnagrams, two)
{
    letter_combination lc;
    std::vector<std::string> input = {"", ""};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams(input);
    std::cout << "two result:" << std::endl;
    EXPECT_EQ(result.size(), 1); // 验证结果数量
    printGroupAnagrams(result);
}
TEST(LetterCombination_groupAnagrams, three)
{
    letter_combination lc;
    std::vector<std::string> input = {"a"};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams(input);
    std::cout << "three result:" << std::endl;
    EXPECT_EQ(result.size(), 1); // 验证结果数量
    printGroupAnagrams(result);
}
TEST(LetterCombination_groupAnagrams, four)
{
    letter_combination lc;
    std::vector<std::string> input = {};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams(input);
    std::cout << "four result:" << std::endl;
    EXPECT_EQ(result.size(), 0); // 验证结果数量
    printGroupAnagrams(result);
}
// 测试 groupAnagrams1 函数
TEST(LetterCombination_groupAnagrams1, one)
{
    letter_combination lc;
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    std::cout << "one result:" << std::endl;
    EXPECT_EQ(result.size(), 3); // 验证结果数量
    printGroupAnagrams(result);
}
TEST(LetterCombination_groupAnagrams1, two)
{
    letter_combination lc;
    std::vector<std::string> input = {"", ""};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    std::cout << "two result:" << std::endl;
    EXPECT_EQ(result.size(), 1); // 验证结果数量
    printGroupAnagrams(result);
}
TEST(LetterCombination_groupAnagrams1, three)
{
    letter_combination lc;
    std::vector<std::string> input = {"a"};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    std::cout << "three result:" << std::endl;
    EXPECT_EQ(result.size(), 1); // 验证结果数量
    printGroupAnagrams(result);
}
TEST(LetterCombination_groupAnagrams1, four)
{
    letter_combination lc;
    std::vector<std::string> input = {};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    std::cout << "four result:" << std::endl;
    EXPECT_EQ(result.size(), 0); // 验证结果数量
    printGroupAnagrams(result);
}
