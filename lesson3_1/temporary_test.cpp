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
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    std::vector<int> result = root->inorderTraversal(root);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
    return 0;
}