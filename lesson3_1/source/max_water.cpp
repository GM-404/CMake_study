#include "max_water.hh"

int Solution_max_water::max_water(std::vector<int> &height)
{
    // // 暴力法
    // int res = 0;
    // int left = 0;
    // int right = height.size() - 1;

    // for (left = 0; left < height.size() - 1; left++)
    // {
    //     for (right = height.size() - 1; right > left; right--)
    //     {
    //         res = std::max(res, std::min(height[left], height[right]) * (right - left));
    //     }
    // }

    // 双指针
    int res = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right)
    {
        res = std::max(res, std::min(height[left], height[right]) * (right - left));
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    // 查找最大值元素的迭代器
    std::vector<int>::iterator max_it = std::max_element(height.begin(), height.end());
    std::cout << "Max element: " << *max_it << std::endl;

    return res;
}
