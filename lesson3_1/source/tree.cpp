#include "my_tree.hh"

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