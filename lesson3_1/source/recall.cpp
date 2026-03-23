
#include "recall.hh"
#include <algorithm>
#include <vector>

// 17. 电话号码的字母组合
std::vector<std::string> Recall::letterCombinations(std::string digits){
    std::vector<std::string> res;
    if(digits.empty()) return res;
    std::string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::string cur;
    backtrack17(digits, 0, mapping, cur, res);
    return res;
}
void Recall::backtrack17(std::string digits, int start, std::string mapping[], std::string& cur, std::vector<std::string>& res){
    if(start == digits.size()){
        res.push_back(cur);
        return;
    }
    int digit = digits[start] - '0';
    std::string letters = mapping[digit];
    for(int i = 0; i < letters.size(); i++){
        cur.push_back(letters[i]);
        backtrack17(digits, start + 1, mapping, cur, res);
        cur.pop_back();
    }
}
// 22. 括号生成
std::vector<std::string> Recall::generateParenthesis(int n){
    std::vector<std::string> res;
    std::string cur;
    backtrack22(n, 0, 0, cur, res);
    return res;
}
void Recall::backtrack22(int n, int left, int right, std::string& cur, std::vector<std::string>& res){
    if(left == n && right == n){
        res.push_back(cur);
        return;
    }
    if(left < n){
        cur.push_back('(');
        backtrack22(n, left + 1, right, cur, res);
        cur.pop_back();
    }
    if(right < left){
        cur.push_back(')');
        backtrack22(n, left, right + 1, cur, res);
        cur.pop_back();
    }
}
// 39. 组合总和
std::vector<std::vector<int>> Recall::combinationSum(std::vector<int>& candidates, int target){
    std::vector<std::vector<int>> res;
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> cur;
    backtrack39(candidates, 0, target, cur, res);
    return res;
}
void Recall::backtrack39(std::vector<int>& candidates, int start, int target, std::vector<int>& cur, std::vector<std::vector<int>>& res){
    if(target == 0){
        res.push_back(cur);
        return;
    }
    for(int i = start; i < candidates.size(); i++){
        if(candidates[i] > target){
            break;
        }
        cur.push_back(candidates[i]);
        backtrack39(candidates, i, target - candidates[i], cur, res);
        cur.pop_back();
    }
}
// 46. 全排列
std::vector<std::vector<int>> Recall::permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> res; // 存储所有全排列结果
    backtrack46(nums, 0, res); // 从第0个位置开始回溯
    return res;
}
void Recall::backtrack46(std::vector<int>& nums, int start, std::vector<std::vector<int>>& res) {
    // 终止条件：start到达数组末尾，当前排列已生成
    if (start == nums.size()) {
        res.push_back(nums); // 将当前排列加入结果集
        return;
    }

    // 遍历start及之后的所有位置，交换生成排列
    for (int i = start; i < nums.size(); ++i) {
        std::swap(nums[start], nums[i]); // 交换start和i位置的元素
        backtrack46(nums, start + 1, res); // 递归处理下一个位置
        std::swap(nums[start], nums[i]); // 回溯：恢复原数组（关键！）
    }
}
//78. 子集
std::vector<std::vector<int>> Recall::subsets(std::vector<int>& nums){
    std::vector<std::vector<int>> res;
    std::vector<int> subset;
    backtrack78(nums, 0, subset, res);
    return res; 
}
void Recall::backtrack78(std::vector<int>& nums, int start, std::vector<int>& subset, std::vector<std::vector<int>>& res){
    //先把当前子集加入结果，第一次为空集
    res.push_back(subset);
    //如果start到达数组末尾，结束递归
    if(start == nums.size()){
        return;
    }
    //不选当前元素，递归处理下一个元素
    for(int i = start; i < nums.size(); i++){
        subset.push_back(nums[i]);
        backtrack78(nums, i + 1, subset, res);
        subset.pop_back();  //删除向量最后一个元素，且不会返回该元素
    }
}