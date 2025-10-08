#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>

// 二叉树
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    // 题
    // 94.二叉树的中序遍历框架
    std::vector<int> inorderTraversal(TreeNode *root);
    // 98. 验证二叉搜索树
    bool isValidBST(TreeNode *root);
    bool isValidBST1(TreeNode *root);
    bool isValid(TreeNode *root, long long lower, long long upper);
    // 101. 对称二叉树
    bool isSymmetric(TreeNode *root);
    bool isSymmetric1(TreeNode *root);
    // 102. 二叉树的层序遍历
    std::vector<std::vector<int>> levelOrder(TreeNode *root);
    std::vector<std::vector<int>> levelOrder1(TreeNode *root);
    // 104. 二叉树的最大深度
    int maxDepth(TreeNode *root);
    // 108 将有序数组转换为二叉搜索树
    TreeNode *sortedArrayToBST(std::vector<int> &nums);
    TreeNode *buildBST(std::vector<int> &nums, int left, int right); // 辅助函数
    // 226. 翻转二叉树
    TreeNode *invertTree(TreeNode *root);
    // 543. 二叉树的直径
    int diameterOfBinaryTree(TreeNode *root);
};
#endif // MY_TREE_H