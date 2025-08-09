#include <gtest/gtest.h>
#include "my_tree.hh" // 包含TreeNode类定义

// 复用之前的测试夹具类，共享树的创建和销毁逻辑
class TreeNodeMaxDepthTest : public ::testing::Test
{
protected:
    // 辅助函数：根据数组创建二叉树（-1表示空节点）
    TreeNode *createTree(const std::vector<int> &values, int index = 0)
    {
        if (index >= values.size() || values[index] == -1)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(values[index]);
        node->left = createTree(values, 2 * index + 1);  // 左孩子：2i+1
        node->right = createTree(values, 2 * index + 2); // 右孩子：2i+2
        return node;
    }

    // 辅助函数：销毁二叉树，避免内存泄漏
    void destroyTree(TreeNode *root)
    {
        if (root == nullptr)
            return;
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }

    // 测试用的TreeNode实例（用于调用成员函数）
    TreeNode testNode;
};

// 测试场景1：空树（深度为0）
TEST_F(TreeNodeMaxDepthTest, EmptyTree)
{
    TreeNode *root = nullptr;
    int depth = testNode.maxDepth(root);
    EXPECT_EQ(depth, 0) << "空树的最大深度应为0";
}

// 测试场景2：单节点树（深度为1）
TEST_F(TreeNodeMaxDepthTest, SingleNode)
{
    TreeNode *root = new TreeNode(10); // 仅根节点
    int depth = testNode.maxDepth(root);
    EXPECT_EQ(depth, 1) << "单节点树的最大深度应为1";
    destroyTree(root);
}

// 测试场景3：只有左子树的树（深度为左子树深度+1）
TEST_F(TreeNodeMaxDepthTest, OnlyLeftSubtree)
{
    // 树结构：
    //       3
    //      /
    //     2
    //    /
    //   1
    // 深度：3（从根到叶子1的路径长度）
    TreeNode *root = createTree({3, 2, -1, 1});
    int depth = testNode.maxDepth(root);
    EXPECT_EQ(depth, 3) << "左斜树的最大深度计算错误";
    destroyTree(root);
}

// 测试场景4：只有右子树的树（深度为右子树深度+1）
TEST_F(TreeNodeMaxDepthTest, OnlyRightSubtree)
{
    // 树结构：
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    // 深度：4（从根到叶子4的路径长度）
    TreeNode *root = createTree({1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4});
    int depth = testNode.maxDepth(root);
    EXPECT_EQ(depth, 4) << "右斜树的最大深度计算错误";
    destroyTree(root);
}

// 测试场景5：平衡二叉树（左右子树深度相同）
TEST_F(TreeNodeMaxDepthTest, BalancedTree)
{
    // 树结构：
    //       4
    //     /   \
    //    2     6
    //   / \   / \
    //  1   3 5   7
    // 深度：3（左右子树深度均为2，根+2=3）
    TreeNode *root = createTree({4, 2, 6, 1, 3, 5, 7});
    int depth = testNode.maxDepth(root);
    EXPECT_EQ(depth, 3) << "平衡二叉树的最大深度计算错误";
    destroyTree(root);
}

// 测试场景6：非平衡二叉树（左右子树深度不同）
TEST_F(TreeNodeMaxDepthTest, UnbalancedTree)
{
    // 树结构：
    //       5
    //      / \
    //     3   8
    //    /   /
    //   2   6
    //  /     \
    // 1       7
    // 深度：4（左子树深度3，右子树深度3，根+3=4）
    TreeNode *root = createTree({5, 3, 8, 2, -1, 6, -1, 1});
    int depth = testNode.maxDepth(root);
    EXPECT_EQ(depth, 4) << "非平衡二叉树的最大深度计算错误";
    destroyTree(root);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
