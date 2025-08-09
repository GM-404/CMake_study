#ifndef STUDY_TREE_H
#define STUDY_TREE_H

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
    // 二叉树的递归遍历框架
    void traverse(TreeNode *root);
    // 层序遍历框架这种写法最大的优势就是简单。每次把队头元素拿出来，然后把它的左右子节点加入队列，就完事了。
    // 但是这种写法的缺点是，无法知道当前节点在第几层。知道节点的层数是个常见的需求，比方说让你收集每一层的节点，或者计算二叉树的最小深度等等。
    // 所以这种写法虽然简单，但用的不多，
    void levelOrderTraverse1(TreeNode *root);
    // 层序遍历框架这种写法的好处是，能知道当前节点在第几层。
    // 这种写法的缺点是，代码稍微复杂一点。
    // 但是这种写法的好处是，能知道当前节点在第几层。
    void levelOrderTraverse2(TreeNode *root);
    // 让每一层自己维护自己的路径权重和，在下面的代码中，我们定义了一个 State 结构体，里面包含两个成员变量：node 和 depth，分别表示当前节点和从根节点到当前节点的路径权重和。
    void levelOrderTraverse3(TreeNode *root);
    // 题
    // 94.二叉树的中序遍历框架
    std::vector<int> inorderTraversal(TreeNode *root);
};
class State
{
public:
    TreeNode *node;
    int depth;

    State(TreeNode *node, int depth) : node(node), depth(depth) {}
};
// 二叉树的递归遍历框架
void TreeNode::traverse(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    // 前序124356
    std::cout << "前" << root->val << std::endl;
    traverse(root->left);
    // 中序421536
    std::cout << "中" << root->val << std::endl;
    traverse(root->right);
    // 后序425631
    std::cout << "后" << root->val << std::endl;
};
void TreeNode::levelOrderTraverse1(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        // 访问 cur 节点
        std::cout << cur->val << std::endl;

        // 把 cur 的左右子节点加入队列
        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }
}
void TreeNode::levelOrderTraverse2(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    // 记录当前遍历到的层数（根节点视为第 1 层）
    int depth = 1;

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        // while (!q.empty())或者while (sz-- > 0) 都可
        {
            TreeNode *cur = q.front();
            q.pop();
            // 访问 cur 节点，同时知道它所在的层数
            std::cout << "depth = " << depth << ", val = " << cur->val << std::endl;

            // 把 cur 的左右子节点加入队列
            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
        depth++;
    }
};
void TreeNode::levelOrderTraverse3(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<State> q;
    // 根节点的路径权重和是 1
    q.push(State(root, 1));

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        // 访问 cur 节点，同时知道它的路径权重和
        std::cout << "depth = " << cur.depth << ", val = " << cur.node->val << std::endl;

        // 把 cur 的左右子节点加入队列
        if (cur.node->left != nullptr)
        {
            q.push(State(cur.node->left, cur.depth + 1));
        }
        if (cur.node->right != nullptr)
        {
            q.push(State(cur.node->right, cur.depth + 1));
        }
    }
}
#endif // MY_TREE_H
