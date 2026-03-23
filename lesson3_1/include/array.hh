#ifndef _ARRAY_HH_
#define _ARRAY_HH_

#include <vector>
// 关于双指针数组的一些集合
class Array
{
public:
    std::vector<int> data_;
    // 构造函数
    Array(int size) : data_(size) {
        // 无需手动初始化内存，vector会自动初始化
    }
    // 26. 删除有序数组中的重复项
    int removeDuplicates(std::vector<int>& nums);
    // 析构函数
    ~Array()
    {
    }

};

#endif