#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>

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
    // 98. 验证二叉搜索树
    bool isValidBST(TreeNode *root);
    bool isValidBST1(TreeNode *root);
    bool isValid(TreeNode *root, long long lower, long long upper);
    // 101. 对称二叉树
    bool isSymmetric(TreeNode *root);
    bool isSymmetric1(TreeNode *root);
    // 102. 二叉树的层序遍历
    std::vector<std::vector<int>> levelOrder(TreeNode *root);
    std::vector<std::vector<int>> levelOrder1(TreeNode *root);
    // 104. 二叉树的最大深度
    int maxDepth(TreeNode *root);
    // 105. 从前序与中序遍历序列构造二叉树
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder);
    // 108 将有序数组转换为二叉搜索树
    TreeNode *sortedArrayToBST(std::vector<int> &nums);
    TreeNode *buildBST(std::vector<int> &nums, int left, int right); // 辅助函数
    // 114. 二叉树展开为链表
    void flatten(TreeNode* root);   //从下而上展开
    void flatten1(TreeNode* root);  //从上而下展开
    void flatten2(TreeNode* root);  //从上而下展开
    // 124. 二叉树中的最大路径和
    int maxGain(TreeNode* node, int& maxSum);  //辅助函数
    int maxPathSum(TreeNode* root);
    // 199. 二叉树的右视图
    std::vector<int> rightSideView(TreeNode* root); //深度优先搜索
    // 226. 翻转二叉树
    TreeNode *invertTree(TreeNode *root);
    // 230. 二叉搜索树中第K小的元素
    int kthSmallest(TreeNode *root, int k); //遍历整个数组之后返回第K-1个
    int kthSmallest1(TreeNode *root, int k);//由中序遍历二叉搜索数是递增的，搜到第K个就是所要的
    // 236.二叉树的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q);
    // 437. 路径总和 III
    int pathSum(TreeNode *root, int targetSum);
    int pathSum1(TreeNode *root, int targetSum);
    // 543. 二叉树的直径
    int diameterOfBinaryTree(TreeNode *root);
};
#endif // MY_TREE_H