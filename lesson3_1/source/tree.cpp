#include "my_tree.hh"

#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <vector>
#include <stack>
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
// 98. 验证二叉搜索树
bool TreeNode::isValidBST(TreeNode *root) {
  std::function<bool(TreeNode *, long, long)> validate =
      [&](TreeNode *node, long min, long max) {
        if (node == nullptr) {
          return true;
        }
        if (node->val <= min || node->val >= max) {
          return false;
        }
        return validate(node->left, min, node->val) &&
               validate(node->right, node->val, max);
      };
  return validate(root, LONG_MIN, LONG_MAX);
}
// 98. 验证二叉搜索树
//  使用辅助函数
bool TreeNode::isValidBST1(TreeNode *root) {
  // 初始范围：负无穷到正无穷（用long long避免int溢出）
  return isValid(root, LLONG_MIN, LLONG_MAX);
}
// 辅助函数：验证以root为根的树是否在[lower, upper]范围内
bool TreeNode::isValid(TreeNode *root, long long lower, long long upper) {
  if (root == nullptr) {
    return true; // 空树是BST
  }
  // 当前节点值必须在[lower, upper]范围内
  if (root->val <= lower || root->val >= upper) {
    return false;
  }
  // 左子树的范围：[lower, 当前节点值)
  // 右子树的范围：(当前节点值, upper]
  return isValid(root->left, lower, root->val) &&
         isValid(root->right, root->val, upper);
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
/**
 * 108. 将有序升序数组转换为二叉搜索树
 *
 * 核心思路：递归地选取当前子数组的中点作为根节点，确保树是高度平衡的。
 * 特性：先看一下数组的大小，平衡二叉树的特性为高度平衡二叉树，说到它的高度为O(logN)，确定所构建的树是平衡的
 * @param nums 有序升序数组
 * @return 构建完成的二叉搜索树的根节点
 */
TreeNode *TreeNode::sortedArrayToBST(std::vector<int> &nums) {
  // 启动递归过程，使用整个数组的索引范围 [0, nums.size() - 1]
  return buildBST(nums, 0, nums.size() - 1);
}
// 辅助递归函数：在数组的指定区间 [left, right] 内构建 BST
TreeNode *TreeNode::buildBST(std::vector<int> &nums, int left, int right) {
  // 1. 递归终止条件
  // 如果左边界大于右边界，说明当前子数组为空，返回空指针
    if (left > right) {
    return nullptr;
    }
  // 2. 找到当前子数组的中间元素作为根节点
  // 选取中间元素是为了保证左右子树的节点数相差最小，从而保证树的高度平衡。
  int mid = left + (right - left) / 2; // 安全计算中点，防止溢出

  // 3. 创建根节点
  TreeNode *root = new TreeNode(nums[mid]);

  // 4. 递归构建左子树
  // 左子树的节点来自数组的左半部分 [left, mid - 1]
    root->left = buildBST(nums, left, mid - 1);

  // 5. 递归构建右子树
  // 右子树的节点来自数组的右半部分 [mid + 1, right]
    root->right = buildBST(nums, mid + 1, right);

  // 6. 返回当前子树的根节点
    return root;
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
// 230. 二叉搜索树中第K小的元素。使用递归中序遍历将整个二叉搜索树（BST）的所有元素存储在一个 std::vector 中，然后直接返回第 K 个元素（elements[k - 1]）。
int TreeNode::kthSmallest(TreeNode *root, int k) {
    std::vector<int> elements;
  std::function<void(TreeNode *)> inorder = [&](TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    // 中序遍历
    // 二叉搜索树使用中序遍历得到的结果是递增的
    inorder(node->left);
    elements.push_back(node->val);
    inorder(node->right);
    };
    inorder(root);
  return elements[k - 1]; // k 是从 1 开始的索引
}
// 230. 二叉搜索树中第K小的元素。由中序遍历二叉搜索数是递增的，搜到第K个就是所要的
int TreeNode::kthSmallest1(TreeNode *root, int k) 
{
    std::stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty()) {
        // 1. 递归下降到最左子节点 (中序遍历的第一步)
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        // 2. 弹出并访问节点 (中序遍历的第二步)
        curr = s.top();
        s.pop();
        // 3. 检查 K
        k--;
        if (k == 0) {
            return curr->val; // 找到第 K 小元素，立即返回
        }
        // 4. 转向右子树 (中序遍历的第三步)
        curr = curr->right;
    }
    // 理论上不会执行到这里，因为 K 保证有效
    return -1; 
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
