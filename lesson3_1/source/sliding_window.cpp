#include "sliding_window.hh"
#include <unordered_map>
// 最长无重复子串
int SlidingWindow::lengthOfLongestSubstring(std::string &s)
{
    std::unordered_map<char, int> charMap;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); ++right)
    {
        // 记录重复字符的最后面的位置
        if (charMap.find(s[right]) != charMap.end() && charMap[s[right]] >= left)
        {
            left = charMap[s[right]] + 1;
        }
        charMap[s[right]] = right;
        maxLen = std::max(maxLen, right - left + 1);
    }

    return maxLen;
}
