#ifndef MY_TREE_H
#define MY_TREE_H

#include <iostream>
#include <vector>
#include <queue>
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
};
#endif // MY_TREE_H