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
    // 101. 对称二叉树
    bool isSymmetric(TreeNode *root);
    bool isSymmetric1(TreeNode *root);
    // 104. 二叉树的最大深度
    int maxDepth(TreeNode *root);
    // 226. 翻转二叉树
    TreeNode *invertTree(TreeNode *root);
};
#endif // MY_TREE_H