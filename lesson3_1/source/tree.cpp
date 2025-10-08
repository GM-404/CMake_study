#include "my_tree.hh"

#include <functional>
#include <queue>
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
    TreeNode *right = stack.back();
    stack.pop_back();
    TreeNode *left = stack.back();
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
// 102. 二叉树的层序遍历
std::vector<std::vector<int>> TreeNode::levelOrder(TreeNode *root) {
  std::vector<std::vector<int>> result;
  if (root == nullptr) {
    return result;
  }
  std::vector<TreeNode *> queue;
  queue.push_back(root);
  while (!queue.empty()) {
    int size = queue.size();
    std::vector<int> level;
    for (int i = 0; i < size; i++) {
      TreeNode *node = queue.front(); // 取出队头： 获取队列最前端的节点指针。
      // ❗ 注意： 使用 vector::erase(vector::begin())
      // 来模拟队列的出队操作效率是低下的。因为它要求将所有剩余元素向前移动一位，导致整个算法的时间复杂度可能恶化。
      queue.erase(queue.begin());
      level.push_back(node->val);
      if (node->left != nullptr) {
        queue.push_back(node->left);
      }
      if (node->right != nullptr) {
        queue.push_back(node->right);
      }
    }
    result.push_back(level);
  }
  return result;
}
std::vector<std::vector<int>> TreeNode::levelOrder1(TreeNode *root) {
  std::vector<std::vector<int>> result;
  if (root == nullptr) {
    return result;
  }
  // 申请一个队列
  std::queue<TreeNode *> queue;
  // 将二叉树的根目录放进去，因为前期已经判断过根节点不为空
  queue.push(root);
  // while(!queue.empty)
  while (queue.size() != 0) {
    int size =
        queue.size(); // 先看一下这一层有几个数据，方便后续遍历多少次来取数据
    std::vector<int> level; // 暂存当前层的数据
    for (int i = 0; i < size; i++) {
      TreeNode *index = queue.front(); // 取出当前层的第一个
      level.push_back(index->val);     // 将这个值放进结果中
      queue.pop();                     // 移除队首元素
      // 看一下这个数的左面还有没有子树,有就加进去
      if (index->left != nullptr) {
        queue.push(index->left);
      }
      // 看一下这个数的右面还有没有子树,有就加进去
      if (index->right != nullptr) {
        queue.push(index->right);
      }
    }
    // 将这一层的数加进结果中
    result.push_back(level);
  }
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
// 543. 二叉树的直径
int TreeNode::diameterOfBinaryTree(TreeNode *root) {
  int diameter = 0;
  std::function<int(TreeNode *)> depth = [&](TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    diameter = std::max(diameter, leftDepth + rightDepth);
    return std::max(leftDepth, rightDepth) + 1;
  };
  depth(root);
  return diameter;
}