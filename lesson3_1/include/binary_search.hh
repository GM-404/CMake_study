#ifndef _BINARY_SEARCH_HH_
#define _BINARY_SEARCH_HH_


#include <vector>

class BinarySearch{ 
public:
    //35. 搜索插入位置
    int searchInsert(std::vector<int>& nums, int target);
    //74. 搜索二维矩阵
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
    //34. 在排序数组中查找元素的第一个和最后一个位置
    std::vector<int> searchRange(std::vector<int>&nums,int target);
    
};
#endif