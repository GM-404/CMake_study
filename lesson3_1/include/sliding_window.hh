#ifndef SLIDING_WINDOW_HH
#define SLIDING_WINDOW_HH
#include <vector>
#include <string>

/*
 * @file
 * @brief Sliding window包含两道题目,
 * 1.无重复字符的最长子串,
 * 2.找到字符串中所有字母异构词
 */
class SlidingWindow
{
public:
    // 1.无重复字符的最长子串
    // The longest substring without duplicate characters
    int lengthOfLongestSubstring(std::string &s);
    // 2.找到字符串中所有字母异构词
    //  std::vector<int> maxSlidingWindow1(std::vector<int> &nums, int k);
};
#endif
// 测试示例1.无重复字符的最长子串
int main()
{
    std::string s = "abcabcb";
    SlidingWindow sw;
    int max_len = sw.lengthOfLongestSubstring(s);
    std::cout << max_len << std::endl;
    return 0;
}
