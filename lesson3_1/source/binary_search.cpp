#include "binary_search.hh"

//35. 搜索插入位置
int BinarySearch::searchInsert(std::vector<int>& nums, int target){

    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}
//74.搜索二维矩阵
bool BinarySearch::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    //判断矩阵为空矩阵
    //错误一：
    //if(matrix.size() == 0 && matrix[0].size() == 0){
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }
    for(int i = 0;i<matrix.size();i++){
        //每一次先看行的末尾，定义两个指针，一个指向行头，一个指向行尾
        int left = 0;
        int right = matrix[i].size()-1;
        //如果这一行最右面的小于目标值，说明目标不在这一行
        if(matrix[i][right]<target){
            continue;
        }
        //能过上一行代表找到了目标所在行
        while(left<=right){
            int mid = left +(right - left)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid]<target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return false;
}
// //34. 在排序数组中查找元素的第一个和最后一个位置
// std::vector<int> searchRange(std::vector<int>&nums,int target){
//     //判断数组是否为空
//     //错误一 ：std::vector<int> res = [-1,-1];  
//     std::vector<int> res(2, -1); // 创建大小为2，初始值都是-1 
//     if(nums.size() == 0){
//         return res;
//     }
//     //如果不为空，跟上面的区别就在于，检测到之后，需要记录一下起始位置
//     int left = 0;
//     int right = nums.size()-1;
//     while(left <= right){
//         int mid = left + (right - left)/2;
//         //如果中间值就算目标，那可能分散在左面和右面
//         if(nums[mid] == targt){
//             //找到左值
//             //错误 2：找到 target 后，mid 直接 --，会越界到 -1！
//             while(nums[mid] == target){
//                 mid--;
//             }
//             res[0] = mid+1;
//             //找到右值
//             while(nums[mid+1] == target){
//                 mid++;
//             }
//             res[1] = mid;
//             return res;
//         }
//         //如果目标在中间值左面
//         else if(nums[mid] > target){
//             right = mid - 1;
//         }
//         //如果目标在中间值右面
//         else{
//             left = mid + 1;
//         }
//     }
//     return res;
// }
std::vector<int> searchRange(std::vector<int>&nums,int target){
    std::vector<int> res{-1,-1};
    if (nums.size()==0){
        return res;
    }

    // 找左边界
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // 最终 left 就是左边界
    if (left >= nums.size() || nums[left] != target){
        return res;
    }
    res[0] = left;

    // 找右边界
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    res[1] = right;

    return res;
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        if (n == 0) return res;

        // 找左边界
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // 最终 l 就是左边界
        if (l >= n || nums[l] != target) return res;
        res[0] = l;

        // 找右边界
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res[1] = r;

        return res;
    }
};