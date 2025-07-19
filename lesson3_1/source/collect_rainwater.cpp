#include "collect_rainwater.hh"
#include <vector>
#include <algorithm>

int Solution_rainwater::trap(std::vector<int> &height)
{
    // // Check if the input vector is empty(存在漏洞，见C++测试用例)
    // if (height.empty())
    //     return 0;
    // int n = height.size();
    // int left = 0;
    // int right = left + 1;
    // int Accumulative_number = 0;
    // int res = 0;
    // for (left = 0; left < n - 1; left++)
    // {
    //     if (height[left] != 0)
    //     {
    //         for (right = left + 1; right < n; right++)
    //         {
    //             if (height[left] <= height[right])
    //             {
    //                 Accumulative_number = right - left - 1;
    //                 while (Accumulative_number != 0)
    //                 {
    //                     res += (height[left] - height[left + Accumulative_number]);
    //                     Accumulative_number--;
    //                 }
    //                 left = right;
    //             }
    //         }
    //     }
    // }
    // return res;

    // 双指针两边法
    if (height.empty())
        return 0;
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int res = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= left_max)
            {
                left_max = height[left];
            }
            else
            {
                res += left_max - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= right_max)
            {
                right_max = height[right];
            }
            else
            {
                res += right_max - height[right];
            }
            right--;
        }
    }
    return res;

    // // 第三种方法
    // int ans = 0;
    // int n = height.size();
    // int l = 0, r = n - 1;

    // // 记录左右两侧最大高度
    // int lMax = 0, rMax = 0;

    // while (l < r)
    // {
    //     // 更新左右最大高度
    //     lMax = std::max(lMax, height[l]);
    //     rMax = std::max(rMax, height[r]);

    //     if (height[l] < height[r])
    //     {
    //         // 左低右高，左位置接水量由左最大高度决定
    //         ans += lMax - height[l];
    //         l++;
    //     }
    //     else
    //     {
    //         // 左高右低，右位置接水量由右最大高度决定
    //         ans += rMax - height[r];
    //         r--;
    //     }
    // }
    // return ans;

    // // 最终办法,左面灌满，右面灌满，最后相减
    // int n = height.size();
    // if (n == 0)
    // {
    //     return 0;
    // }
    // std::vector<int> leftMax(n);
    // leftMax[0] = height[0];
    // for (int i = 1; i < n; ++i)
    // {
    //     leftMax[i] = std::max(leftMax[i - 1], height[i]);
    // }

    // std::vector<int> rightMax(n);
    // rightMax[n - 1] = height[n - 1];
    // for (int i = n - 2; i >= 0; --i)
    // {
    //     rightMax[i] = std::max(rightMax[i + 1], height[i]);
    // }

    // int ans = 0;
    // for (int i = 0; i < n; ++i)
    // {
    //     ans += std::min(leftMax[i], rightMax[i]) - height[i];
    // }
    // return ans;
}