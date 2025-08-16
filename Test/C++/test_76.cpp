#include <gtest/gtest.h>
#include <string>
#include "sliding_window.hh" // 假设函数定义在这个头文件中

SlidingWindow sw;
// 测试正常场景：存在唯一最小覆盖子串
TEST(MinWindowTest, NormalCaseWithUniqueResult)
{
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    EXPECT_EQ(sw.minWindow(s, t), "BANC");
}

// 测试场景：存在多个覆盖子串，取最短的
TEST(MinWindowTest, MultipleValidWindows)
{
    std::string s = "aaabbbccc";
    std::string t = "abc";
    EXPECT_EQ(sw.minWindow(s, t), "abbbc"); // 最后三个字符组成的子串
}

// 测试场景：s与t完全相同
TEST(MinWindowTest, SEqualsT)
{
    std::string s = "hello";
    std::string t = "hello";
    EXPECT_EQ(sw.minWindow(s, t), "hello");
}

// 测试场景：t是s的第一个子串
TEST(MinWindowTest, TisPrefixOfS)
{
    std::string s = "abcdefg";
    std::string t = "abc";
    EXPECT_EQ(sw.minWindow(s, t), "abc");
}

// 测试场景：t是s的最后一个子串
TEST(MinWindowTest, TisSuffixOfS)
{
    std::string s = "xyzabc";
    std::string t = "abc";
    EXPECT_EQ(sw.minWindow(s, t), "abc");
}

// 测试场景：s中没有覆盖t的子串
TEST(MinWindowTest, NoValidWindow)
{
    std::string s = "abcdef";
    std::string t = "xyz";
    EXPECT_EQ(sw.minWindow(s, t), "");
}

// 测试场景：t包含重复字符
TEST(MinWindowTest, TWithDuplicateChars)
{
    std::string s = "aabdec";
    std::string t = "abc"; // 需要包含1个a、1个b、1个c
    EXPECT_EQ(sw.minWindow(s, t), "abdec");
}

// 测试场景：t包含多个重复字符，需要精确匹配数量
TEST(MinWindowTest, TWithMultipleDuplicates)
{
    std::string s = "aaabbbcc";
    std::string t = "aabbc"; // 需要2个a、2个b、1个c
    EXPECT_EQ(sw.minWindow(s, t), "aabbbc");
}

// 测试场景：s中存在多个符合条件的子串，取长度最小的
TEST(MinWindowTest, ChooseShortestWindow)
{
    std::string s = "abbbcabc";
    std::string t = "abc";
    // 可能的子串："abbbc" (长度5)、"abc" (长度3)，应取后者
    EXPECT_EQ(sw.minWindow(s, t), "bca");
}

// 测试边界场景：t为空字符串
TEST(MinWindowTest, TisEmpty)
{
    std::string s = "anything";
    std::string t = "";
    EXPECT_EQ(sw.minWindow(s, t), ""); // 按常规约定，返回空串
}

// 测试边界场景：s为空字符串
TEST(MinWindowTest, SisEmpty)
{
    std::string s = "";
    std::string t = "abc";
    EXPECT_EQ(sw.minWindow(s, t), "");
}

// 测试场景：区分大小写（假设函数是大小写敏感的）
TEST(MinWindowTest, CaseSensitive)
{
    std::string s = "AbcAbc";
    std::string t = "ABC";
    EXPECT_EQ(sw.minWindow(s, t), ""); // 小写字母无法匹配大写
}

// 测试场景：s中字符全部相同，t也相同
TEST(MinWindowTest, AllSameChars)
{
    std::string s = "aaaaa";
    std::string t = "aa";
    EXPECT_EQ(sw.minWindow(s, t), "aa");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
