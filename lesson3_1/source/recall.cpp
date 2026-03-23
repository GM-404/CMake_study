
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
//51. N皇后
std::vector<std::vector<std::string>> Recall::solveNQueens(int n){
    std::vector<std::vector<std::string>> res;    // 存储所有合法的棋盘方案
    std::vector<std::string> board(n, std::string(n, '.')); // 初始化棋盘，全部为'.'
    // 三个数组记录冲突：列、正对角线(行-列)、反对角线(行+列)
    std::vector<bool> col(n, false);   // col[j] = true 表示第j列已有皇后
    std::vector<bool> diag1(2*n-1, false); // 正对角线：行-列 = 常数，范围[-(n-1), n-1]，映射为行-列 + n-1
    std::vector<bool> diag2(2*n-1, false); // 反对角线：行+列 = 常数，范围[0, 2n-2]

    backtrack51(n, 0, board, col, diag1, diag2, res);
    return res;
}
void Recall::backtrack51(int n, int row, std::vector<std::string>& board, std::vector<bool>& col, std::vector<bool>& diag1, std::vector<bool>& diag2, std::vector<std::vector<std::string>>& res){
    // 终止条件：所有行都放置了皇后，记录当前方案
    if (row == n) {
        res.push_back(board);
        return;
    }

    // 遍历当前行的所有列，尝试放置皇后
    for (int j = 0; j < n; ++j) {
        // 计算对角线索引（避免负数）
        int d1 = row - j + n - 1; // 正对角线映射索引
        int d2 = row + j;         // 反对角线索引

        // 剪枝：列/正对角线/反对角线有冲突，跳过当前列
        if (col[j] || diag1[d1] || diag2[d2]) {
            continue;
        }

        // 选择：在(row,j)放置皇后
        board[row][j] = 'Q';
        col[j] = true;
        diag1[d1] = true;
        diag2[d2] = true;

        // 递归：处理下一行
        backtrack51(n, row + 1, board, col, diag1, diag2, res);

        // 回溯：撤销选择，恢复状态
        board[row][j] = '.';
        col[j] = false;
        diag1[d1] = false;
        diag2[d2] = false;
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
//79. 单词搜索
bool Recall::exist(std::vector<std::vector<char>>& board, std::string word){
    // 遍历棋盘的每个位置作为起始点
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            // 从(i,j)开始DFS搜索，匹配word的第0个字符
            if (backtrack79(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    // 所有起始点都匹配失败
    return false;
}
// DFS回溯函数：board=棋盘，word=目标单词，i/j=当前棋盘位置，idx=当前匹配到word的第几个字符
bool Recall::backtrack79(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int idx) {
    // 终止条件1：匹配完所有字符，成功
    if (idx == word.size()) {
        return true;
    }
    // 终止条件2：越界 或 当前字符不匹配，失败
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
        return false;
    }

    // 标记当前位置已访问（避免重复使用）：临时修改为特殊字符
    char temp = board[i][j];
    board[i][j] = '#';

    // 向上下左右四个方向递归搜索，匹配下一个字符
    bool found = backtrack79(board, word, i - 1, j, idx + 1)   // 上
            || backtrack79(board, word, i + 1, j, idx + 1)   // 下
            || backtrack79(board, word, i, j - 1, idx + 1)   // 左
            || backtrack79(board, word, i, j + 1, idx + 1);  // 右

    // 回溯：恢复当前位置的原始字符（关键！）
    board[i][j] = temp;

    return found;
}
//131. 分割回文串
std::vector<std::vector<std::string>> Recall::partition(std::string s){
    std::vector<std::vector<std::string>> res; // 存储所有分割方案
    std::vector<std::string> path;        // 存储当前分割路径
    backtrack131(s, 0, path, res);
    return res;
}
// 辅助函数：判断s[left..right]是否为回文串（闭区间）
bool isPalindrome(const std::string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) {
            return false;
        }
    }
    return true;
}
void Recall::backtrack131(const std::string& s, int start, std::vector<std::string>& path, std::vector<std::vector<std::string>>& res){
    // 终止条件：分割到字符串末尾，记录当前路径
    if (start == s.size()) {
        res.push_back(path);
        return;
    }

    // 遍历所有可能的分割点（从start到字符串末尾）
    for (int i = start; i < s.size(); ++i) {
        // 剪枝：如果s[start..i]不是回文，跳过该分割点
        if (!isPalindrome(s, start, i)) {
            continue;
        }
        // 选择：将回文子串加入当前路径
        path.push_back(s.substr(start, i - start + 1));
        // 递归：处理剩余子串（从i+1开始分割）
        backtrack131(s, i + 1, path, res);
        // 回溯：撤销选择，移除当前子串
        path.pop_back();
    }
}