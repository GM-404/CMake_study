#include "my_tree.hh"
// 94.二叉树的中序遍历框架
std::vector<int> TreeNode::inorderTraversal(TreeNode *root)
{
    std::vector<int> result;
    std::vector<int> result_left;
    std::vector<int> result_right;
    TreeNode *cur = root;
    if (root == nullptr)
    {
        return result;
    }
    result_left = inorderTraversal(cur->left);
    result.insert(result.end(), result_left.begin(), result_left.end());
    result.push_back(cur->val);
    result_right = inorderTraversal(cur->right);
    result.insert(result.end(), result_right.begin(), result_right.end());
    return result;
}
// 104. 二叉树的最大深度
int TreeNode::maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return std::max(leftDepth, rightDepth) + 1;
}
// 226. 翻转二叉树
TreeNode *TreeNode::invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}