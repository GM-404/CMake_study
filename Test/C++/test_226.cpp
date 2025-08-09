#include <gtest/gtest.h>
#include "my_tree.hh"
#include <vector>

// 测试夹具类，复用树的创建、销毁和遍历辅助函数
class TreeNodeInvertTest : public ::testing::Test
{
protected:
    // 辅助函数：创建二叉树（-1表示空节点）
    TreeNode *createTree(const std::vector<int> &values, int index = 0)
    {
        if (index >= values.size() || values[index] == -1)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(values[index]);
        node->left = createTree(values, 2 * index + 1);
        node->right = createTree(values, 2 * index + 2);
        return node;
    }

    // 辅助函数：销毁二叉树
    void destroyTree(TreeNode *root)
    {
        if (root == nullptr)
            return;
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }

    // 辅助函数：前序遍历树（用于验证反转后的结构）
    void preorderTraversal(TreeNode *root, std::vector<int> &result)
    {
        if (root == nullptr)
        {
            result.push_back(-1); // 用-1标记空节点，便于对比结构
            return;
        }
        result.push_back(root->val);
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
    }

    // 测试用的TreeNode实例
    TreeNode testNode;
};

// 测试场景1：空树（反转后仍为空）
TEST_F(TreeNodeInvertTest, EmptyTree)
{
    TreeNode *root = nullptr;
    TreeNode *inverted = testNode.invertTree(root);
    EXPECT_EQ(inverted, nullptr) << "空树反转后应为空";
}

// 测试场景2：单节点树（反转后结构不变）
TEST_F(TreeNodeInvertTest, SingleNode)
{
    TreeNode *root = new TreeNode(5);
    TreeNode *inverted = testNode.invertTree(root);

    // 验证反转后根节点值不变，左右子树仍为空
    EXPECT_EQ(inverted->val, 5);
    EXPECT_EQ(inverted->left, nullptr);
    EXPECT_EQ(inverted->right, nullptr);

    destroyTree(inverted);
}

// 测试场景3：只有左子树的树（反转后变为只有右子树）
TEST_F(TreeNodeInvertTest, OnlyLeftSubtree)
{
    // 原始树结构：
    //     3
    //    /
    //   2
    //  /
    // 1
    TreeNode *root = createTree({3, 2, -1, 1});
    TreeNode *inverted = testNode.invertTree(root);

    // 预期反转后结构：
    //     3
    //      \
    //       2
    //        \
    //         1
    std::vector<int> actual;
    preorderTraversal(inverted, actual);
    std::vector<int> expected = {3, -1, 2, -1, 1, -1, -1}; // 前序遍历：根->右->左（原左变右）
    EXPECT_EQ(actual, expected) << "左子树反转后结构错误";

    destroyTree(inverted);
}

// 测试场景4：只有右子树的树（反转后变为只有左子树）
TEST_F(TreeNodeInvertTest, OnlyRightSubtree)
{
    // 原始树结构：
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode *root = createTree({1, -1, 2, -1, -1, -1, 3});
    TreeNode *inverted = testNode.invertTree(root);

    // 预期反转后结构：
    //     1
    //    /
    //   2
    //  /
    // 3
    std::vector<int> actual;
    preorderTraversal(inverted, actual);
    std::vector<int> expected = {1, 2, 3, -1, -1, -1, -1}; // 前序遍历：根->左->右（原右变左）
    EXPECT_EQ(actual, expected) << "右子树反转后结构错误";

    destroyTree(inverted);
}

// 测试场景5：平衡二叉树（左右子树完整反转）
TEST_F(TreeNodeInvertTest, BalancedTree)
{
    // 原始树结构：
    //       4
    //     /   \
    //    2     6
    //   / \   / \
    //  1   3 5   7
    TreeNode *root = createTree({4, 2, 6, 1, 3, 5, 7});
    TreeNode *inverted = testNode.invertTree(root);

    // 预期反转后结构：
    //       4
    //     /   \
    //    6     2
    //   / \   / \
    //  7   5 3   1
    std::vector<int> actual;
    preorderTraversal(inverted, actual);
    std::vector<int> expected = {4, 6, 7, -1, -1, 5, -1, -1, 2, 3, -1, -1, 1, -1, -1};
    EXPECT_EQ(actual, expected) << "平衡树反转后结构错误";

    destroyTree(inverted);
}

// 测试场景6：非对称二叉树（左右子树不对称反转）
TEST_F(TreeNodeInvertTest, AsymmetricTree)
{
    // 原始树结构：
    //       5
    //      / \
    //     3   8
    //    /   /
    //   2   6
    //  /     \
    // 1       7
    TreeNode *root = createTree({5, 3, 8, 2, -1, 6, -1, 1, -1, -1, -1, -1, 7});
    TreeNode *inverted = testNode.invertTree(root);

    // 预期反转后结构：
    //       5
    //      / \
    //     8   3
    //      \   \
    //       6   2
    //      /     \
    //     7       1
    std::vector<int> actual;
    preorderTraversal(inverted, actual);
    std::vector<int> expected = {5, 8, -1, 6, 7, -1, -1, -1, 3, -1, 2, -1, 1, -1, -1}; // 前序遍历：根->右->左（非对称树反转）};
    EXPECT_EQ(actual, expected) << "非对称树反转后结构错误";

    destroyTree(inverted);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
