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