#include "array.hh"


//26 删除有序数组中的重复项
int Array::removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 1) {
        return nums.size();
    }
    int slow = 0;
    int fast = 1;
    while (fast < nums.size()) {
        if (nums[slow] != nums[fast]) {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}


