#include "my_tree.hh"

#include <functional>
#include <vector>

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
// 101. 对称二叉树（递归）
bool TreeNode::isSymmetric(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  std::function<bool(TreeNode *, TreeNode *)> isMirror = [&](TreeNode *t1,
                                                             TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr) {
      return true;
    }
    if (t1 == nullptr || t2 == nullptr) {
      return false;
    }
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
  };
  return isMirror(root->left, root->right);
}
// 101. 对称二叉树（迭代）
bool TreeNode::isSymmetric1(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  std::vector<TreeNode *> stack;
  stack.push_back(root->left);
  stack.push_back(root->right);
  while (!stack.empty()) {
    TreeNode *left = stack.back();
    stack.pop_back();
    TreeNode *right = stack.back();
    stack.pop_back();
    if (left == nullptr && right == nullptr) {
      continue;
    }
    if (left == nullptr || right == nullptr || left->val != right->val) {
      return false;
    }
    stack.push_back(left->left);
    stack.push_back(right->right);
    stack.push_back(left->right);
    stack.push_back(right->left);
  }
  return true;
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