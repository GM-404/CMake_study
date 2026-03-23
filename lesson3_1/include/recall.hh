#ifndef _RECALL_HH_
#define _RECALL_HH_

#include <vector>
#include <string>

class Recall{

    public:
    // 17. 电话号码的字母组合
    std::vector<std::string> letterCombinations(std::string digits);
    void backtrack17(std::string digits, int start, std::string mapping[], std::string& cur, std::vector<std::string>& res);
    // 22. 括号生成
    std::vector<std::string> generateParenthesis(int n);
    void backtrack22(int n, int left, int right, std::string& cur, std::vector<std::string>& res);
    // 39. 组合总和
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
    void backtrack39(std::vector<int>& candidates, int start, int target, std::vector<int>& cur, std::vector<std::vector<int>>& res);
    // 46. 全排列
    std::vector<std::vector<int>> permute(std::vector<int>& nums);
    void backtrack46(std::vector<int>& nums, int start, std::vector<std::vector<int>>& res);
    // 51. N 皇后
    std::vector<std::vector<std::string>> solveNQueens(int n);
    void backtrack51(int n, int row, std::vector<std::string>& board, std::vector<bool>& col, std::vector<bool>& diag1, std::vector<bool>& diag2, std::vector<std::vector<std::string>>& res);
    // 78. 子集
    void backtrack78(std::vector<int>& nums, int start, std::vector<int>& subset, std::vector<std::vector<int>>& res);
    std::vector<std::vector<int>> subsets(std::vector<int>& nums);
    // 79. 单词搜索
    bool exist(std::vector<std::vector<char>>& board, std::string word);
    bool backtrack79(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int idx);
    //131. 分割回文串
    std::vector<std::vector<std::string>> partition(std::string s);
    void backtrack131(const std::string& s, int start, std::vector<std::string>& path, std::vector<std::vector<std::string>>& res);
};

















#endif // _RECALL_HH_
