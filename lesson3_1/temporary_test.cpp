#include <iostream>
#include <vector>
#include <string>

#include "sum.h"
#include "three_sum.hh"
#include "four_sum.hh"
#include "letter_combination.hh"
#include "move_zero.hh"
#include "max_water.hh"
#include "collect_rainwater.hh"
#include "sliding_window.hh"
#include "linked_list.hh"
#include "my_tree.hh"
#include "subarray.hh"
#include "matrix.hh"
int main()
{
    // TreeNode *root = new TreeNode(1);
    // root->left = nullptr;
    // root->right = new TreeNode(3);
    // root->right->left = new TreeNode(2);
    // int depth = root->maxDepth(root);
    // std::cout << "Maximum depth of the tree: " << depth << std::endl;

    std::vector<std::vector<int>> nums = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> nums2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Matrix s;
    std::vector<int> res = s.spiralOrder2(nums2);
    for (const auto &val : res)
    {
        std::cout << val << " ";
    }
    return 0;
}