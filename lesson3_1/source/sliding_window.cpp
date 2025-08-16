#include "sliding_window.hh"
#include <unordered_map>
#include <algorithm>
#include <deque> // 用于滑动窗口最大值的双端队列
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
// 239.滑动窗口最大值
std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> results = {};
    std::deque<int> dq; // 存储索引，队列中元素对应的数值保持递减
    if (nums.size() == 0 || k == 0)
        return results;
    for (int i = 0; i < nums.size(); ++i)
    {
        // 移除队列中超出当前窗口范围的元素
        if (!dq.empty() && dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        // 移除队列中比当前元素小的所有元素
        // 因为它们不可能成为后续窗口的最大值
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // 将当前元素索引加入队列
        dq.push_back(i);

        // 当窗口完全进入数组后，开始记录结果
        if (i >= k - 1)
        {
            results.push_back(nums[dq.front()]);
        }
    }

    return results;
}
