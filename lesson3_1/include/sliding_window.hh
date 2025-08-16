#ifndef SLIDING_WINDOW_HH
#define SLIDING_WINDOW_HH
#include <vector>
#include <string>

/*
 * @file
 * @brief Sliding window包含两道题目,
 * 1.无重复字符的最长子串,：给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 * 2.找到字符串中所有字母异构词：给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 */
class SlidingWindow
{
public:
    // 1.无重复字符的最长子串
    // The longest substring without duplicate characters
    int lengthOfLongestSubstring(std::string &s);
    // 2.找到字符串中所有字母异构词
    std::vector<int> findAnagrams(std::string &s, std::string &p);
    // 239.滑动窗口最大值
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k);
    // 76.最小覆盖子串
    std::string minWindow(std::string &s, std::string &t);
};
#endif
// 测试示例1.无重复字符的最长子串
//  int main()
//  {
//      std::string s = "abcabcb";
//      SlidingWindow sw;
//      int max_len = sw.lengthOfLongestSubstring(s);
//      std::cout << max_len << std::endl;
//      return 0;
//  }

//  测试示例2.找到字符串中所有字母异构词
// int main()
// {
//     std::string s = "cbaebabacd";
//     std::string p = "abc";
//     SlidingWindow sw;
//     std::vector<int> result = sw.findAnagrams(s, p);
//     for (int index : result)
//     {
//         std::cout << index << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }
