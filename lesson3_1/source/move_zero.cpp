#include "move_zero.hh"

void Solution_Move_Zero::Move_Zeroes(std::vector<int> &nums)
{
    // 覆盖填充后补零
    int index = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            nums[index++] = nums[i];
        }
    }
    for (int i = index; i < nums.size(); ++i)
    {
        nums[i] = 0;
    }

    // // 交换非零元素
    // int index = 0;
    // for (int i = 0; i < nums.size(); ++i)
    // {
    //     if (nums[i] != 0)
    //     {
    //         std::swap(nums[index++], nums[i]);
    //     }
    // }

    // // 双指针
    // int j = 0; // 记录非零元素应该存放的位置
    // // 第一次遍历：将所有非零元素移到前面
    // for (int i = 0; i < nums.size(); ++i)
    // {
    //     if (nums[i] != 0)
    //     {
    //         nums[j] = nums[i];
    //         j++;
    //     }
    // }
    // // 第二次遍历：将剩余位置填充为0
    // for (int i = j; i < nums.size(); ++i)
    // {
    //     nums[i] = 0;
    // }
}
