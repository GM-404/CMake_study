#include <gtest/gtest.h>
#include "letter_combination.hh"
#include <algorithm>

// 辅助函数：用于比较两个二维字符串向量是否相等（忽略组内和组间顺序）
bool compareResults(const std::vector<std::vector<std::string>> &expected,
                    const std::vector<std::vector<std::string>> &actual)
{
    // 复制实际结果和预期结果，避免修改原数据
    std::vector<std::vector<std::string>> sortedActual = actual;
    std::vector<std::vector<std::string>> sortedExpected = expected;

    // 对每个组内的字符串排序
    // for (auto &group : sortedActual)
    // {
    //     std::sort(group.begin(), group.end());
    // }
    // for (auto &group : sortedExpected)
    // {
    //     std::sort(group.begin(), group.end());
    // }
    for (std::vector<std::vector<std::string>>::iterator groupIt = sortedActual.begin();
         groupIt != sortedActual.end(); ++groupIt)
    {
        std::sort(groupIt->begin(), groupIt->end());
    }
    for (std::vector<std::vector<std::string>>::iterator groupIt = sortedExpected.begin();
         groupIt != sortedExpected.end(); ++groupIt)
    {
        std::sort(groupIt->begin(), groupIt->end());
    }

    // 对所有组按字典序排序（确保组间顺序不影响比较）这三句代码的核心作用是消除组间顺序对结果比较的影响，确保两个 “字符串分组集合” 在逻辑上相等时能被判定为相等
    std::function<bool(const std::vector<std::string> &, const std::vector<std::string> &)> compareGroups = [](const std::vector<std::string> &a, const std::vector<std::string> &b)
    {
        return a < b; // 利用vector的默认字典序比较
    };
    std::sort(sortedActual.begin(), sortedActual.end(), compareGroups);
    std::sort(sortedExpected.begin(), sortedExpected.end(), compareGroups);

    return sortedActual == sortedExpected;
}

// 测试用例：基本功能
TEST(LetterCombinationTest, BasicFunctionality)
{
    // 测试 groupAnagrams 方法
    letter_combination lc;
    std::vector<std::string> input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> expected = {
        {"eat", "tea", "ate"},
        {"tan", "nat"},
        {"bat"}};

    auto result = lc.groupAnagrams(input1);
    EXPECT_TRUE(compareResults(expected, result));

    // 测试 groupAnagrams1 方法
    std::vector<std::string> input;
    input.push_back("eat");
    input.push_back("tea");
    input.push_back("tan");
    input.push_back("ate");
    input.push_back("nat");
    input.push_back("bat");

    std::vector<std::vector<std::string>> expected1;
    std::vector<std::string> group1;
    group1.push_back("eat");
    group1.push_back("tea");
    group1.push_back("ate");
    expected1.push_back(group1);

    std::vector<std::string> group2;
    group2.push_back("tan");
    group2.push_back("nat");
    expected1.push_back(group2);

    std::vector<std::string> group3;
    group3.push_back("bat");
    expected1.push_back(group3);

    std::vector<std::vector<std::string>> result1 = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected1, result1));
}

// 测试用例：空输入
TEST(LetterCombinationTest, EmptyInput)
{
    letter_combination lc;
    std::vector<std::string> input = {};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(result.empty());
}

// 测试用例：单个字符串
TEST(LetterCombinationTest, SingleString)
{
    letter_combination lc;
    std::vector<std::string> input = {"a"};
    std::vector<std::vector<std::string>> expected = {{"a"}};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected, result));
}

// 测试用例：多个空字符串
TEST(LetterCombinationTest, MultipleEmptyStrings)
{
    letter_combination lc;
    std::vector<std::string> input = {"", "", ""};
    std::vector<std::vector<std::string>> expected = {{"", "", ""}};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected, result));
}

// 测试用例：所有字符串都是异位词
TEST(LetterCombinationTest, AllAnagrams)
{
    letter_combination lc;
    std::vector<std::string> input = {"abc", "cba", "bac"};
    std::vector<std::vector<std::string>> expected = {{"abc", "cba", "bac"}};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected, result));
}

// 测试用例：没有异位词
TEST(LetterCombinationTest, NoAnagrams)
{
    letter_combination lc;
    std::vector<std::string> input = {"abc", "def", "ghi"};
    std::vector<std::vector<std::string>> expected = {{"abc"}, {"def"}, {"ghi"}};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected, result));
}

// 测试用例：大小写敏感
TEST(LetterCombinationTest, CaseSensitivity)
{
    letter_combination lc;
    std::vector<std::string> input = {"a", "A"};
    std::vector<std::vector<std::string>> expected = {{"a"}, {"A"}};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected, result));
}

// 测试用例：包含重复字符串
TEST(LetterCombinationTest, DuplicateStrings)
{
    letter_combination lc;
    std::vector<std::string> input = {"a", "a", "b", "b"};
    std::vector<std::vector<std::string>> expected = {{"a", "a"}, {"b", "b"}};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected, result));
}

// 测试用例：复杂组合
TEST(LetterCombinationTest, ComplexCombination)
{
    letter_combination lc;
    std::vector<std::string> input = {"", "a", "ab", "ba", "cd", "dc", "c"};
    std::vector<std::vector<std::string>> expected = {
        {""},
        {"a"},
        {"ab", "ba"},
        {"cd", "dc"},
        {"c"}};
    std::vector<std::vector<std::string>> result = lc.groupAnagrams1(input);
    EXPECT_TRUE(compareResults(expected, result));
}