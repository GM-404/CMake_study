#include <gtest/gtest.h>
#include "my_tree.hh" // 包含你的TreeNode类定义

// 测试用例类，用于复用树的创建和销毁逻辑
class TreeNodeInorderTest : public ::testing::Test
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
        node->left = createTree(values, 2 * index + 1);  // 左孩子索引：2i+1
        node->right = createTree(values, 2 * index + 2); // 右孩子索引：2i+2
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

// 测试场景1：空树
TEST_F(TreeNodeInorderTest, EmptyTree)
{
    TreeNode *root = nullptr;
    std::vector<int> result = testNode.inorderTraversal(root);
    EXPECT_TRUE(result.empty()) << "空树应返回空向量";
}

// 测试场景2：仅包含根节点的树
TEST_F(TreeNodeInorderTest, SingleRootNode)
{
    TreeNode *root = new TreeNode(5); // 根节点值为5
    std::vector<int> result = testNode.inorderTraversal(root);
    std::vector<int> expected = {5};
    EXPECT_EQ(result, expected) << "仅根节点的中序遍历应为[5]";
    destroyTree(root);
}

// 测试场景3：只有左子树的树
TEST_F(TreeNodeInorderTest, OnlyLeftSubtree)
{
    // 树结构：
    //      3
    //     /
    //    2
    //   /
    //  1
    TreeNode *root = createTree({3, 2, -1, 1}); // 数组表示树结构
    std::vector<int> result = testNode.inorderTraversal(root);
    std::vector<int> expected = {1, 2, 3}; // 左->根
    EXPECT_EQ(result, expected) << "左子树遍历结果错误";
    destroyTree(root);
}

// 测试场景4：只有右子树的树
TEST_F(TreeNodeInorderTest, OnlyRightSubtree)
{
    // 树结构：
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode *root = createTree({1, -1, 2, -1, -1, -1, 3});
    std::vector<int> result = testNode.inorderTraversal(root);
    std::vector<int> expected = {1, 2, 3}; // 根->右
    EXPECT_EQ(result, expected) << "右子树遍历结果错误";
    destroyTree(root);
}

// 测试场景5：完整二叉树（左右子树均完整）
TEST_F(TreeNodeInorderTest, CompleteBinaryTree)
{
    // 树结构：
    //       4
    //     /   \
    //    2     6
    //   / \   / \
    //  1   3 5   7
    TreeNode *root = createTree({4, 2, 6, 1, 3, 5, 7});
    std::vector<int> result = testNode.inorderTraversal(root);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7}; // 左->根->右
    EXPECT_EQ(result, expected) << "完整二叉树遍历结果错误";
    destroyTree(root);
}

// 测试场景6：非对称二叉树（左右子树结构不同）
TEST_F(TreeNodeInorderTest, AsymmetricTree)
{
    // 树结构：
    //       10
    //      /  \
    //     5    15
    //    /    /
    //   3    12
    //  / \    \
    // 2   4    13
    TreeNode *root = createTree({10, 5, 15, 3, -1, 12, -1, 2, 4, -1, -1, -1, 13});
    std::vector<int> result = testNode.inorderTraversal(root);
    std::vector<int> expected = {2, 3, 4, 5, 10, 12, 13, 15};
    EXPECT_EQ(result, expected) << "非对称树遍历结果错误";
    destroyTree(root);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
