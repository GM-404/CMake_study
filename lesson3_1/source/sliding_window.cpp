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
// 找到字符串中所有字母异构词
std::vector<int> SlidingWindow::findAnagrams(std::string &s, std::string &p)
{
    std::vector<int> result;
    int len1 = s.length(), len2 = p.length();
    if (len1 < len2)
        return result;
    // 构建初始滑动窗口
    std::unordered_map<char, int> map1, map2;
    for (int i = 0; i < len2; ++i)
    {
        map1[s[i]]++;
        map2[p[i]]++;
    }
    if (map1 == map2)
        result.push_back(0);
    // 滑动窗口
    for (int i = len2; i < len1; ++i)
    {
        map1[s[i]]++;
        map1[s[i - len2]]--;
        // 如果某个字符的计数变为0，删除它
        if (map1[s[i - len2]] == 0)
            map1.erase(s[i - len2]);
        // 比较两个哈希表
        if (map1 == map2)
            result.push_back(i - len2 + 1);
    }
    return result;
}
