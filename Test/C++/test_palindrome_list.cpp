#include <gtest/gtest.h>
#include <vector>
#include "Linked_list.hh" // 包含Linked_Node类的头文件

// 辅助函数：创建链表
Linked_Node *createList(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;

    Linked_Node *head = new Linked_Node(values[0]);
    Linked_Node *current = head;

    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new Linked_Node(values[i]);
        current = current->next;
    }

    return head;
}

// 辅助函数：销毁链表（防止内存泄漏）
void destroyList(Linked_Node *head)
{
    while (head != nullptr)
    {
        Linked_Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// 测试用例1：空链表（视为回文）
TEST(IsPalindromeTest, EmptyList)
{
    Linked_Node *head = nullptr;
    Linked_Node a(0);
    EXPECT_TRUE(a.isPalindrome1(head));
}

// // 测试用例2：单节点链表（视为回文）
// TEST(IsPalindromeTest, SingleNode)
// {
//     Linked_Node *head = createList({5});
//     Linked_Node a(0);
//     EXPECT_TRUE(a.isPalindrome1(head));
//     destroyList(head);
// }

// // 测试用例3：偶数个节点的回文链表
// TEST(IsPalindromeTest, EvenLengthPalindrome)
// {
//     Linked_Node *head = createList({1, 2, 2, 1});
//     Linked_Node a(0);
//     EXPECT_TRUE(a.isPalindrome1(head));
//     destroyList(head);
// }

// // 测试用例4：奇数个节点的回文链表
// TEST(IsPalindromeTest, OddLengthPalindrome)
// {
//     Linked_Node *head = createList({1, 2, 3, 2, 1});
//     Linked_Node a(0);
//     EXPECT_TRUE(a.isPalindrome1(head));
//     destroyList(head);
// }

// // 测试用例5：非回文链表
// TEST(IsPalindromeTest, NotPalindrome)
// {
//     Linked_Node *head = createList({1, 2, 3, 4});
//     Linked_Node a(0);
//     EXPECT_TRUE(a.isPalindrome1(head));
//     destroyList(head);
// }

// // 测试用例6：所有节点值相同的链表（视为回文）
// TEST(IsPalindromeTest, AllSameValues)
// {
//     Linked_Node *head = createList({5, 5, 5, 5});
//     Linked_Node a(0);
//     EXPECT_TRUE(a.isPalindrome1(head));
//     destroyList(head);
// }

// // 测试用例7：两个节点的回文链表
// TEST(IsPalindromeTest, TwoNodesPalindrome)
// {
//     Linked_Node *head = createList({3, 3});
//     Linked_Node a(0);
//     EXPECT_TRUE(a.isPalindrome1(head));
//     destroyList(head);
// }

// // 测试用例8：两个节点的非回文链表
// TEST(IsPalindromeTest, TwoNodesNotPalindrome)
// {
//     Linked_Node *head = createList({3, 4});
//     Linked_Node a(0);
//     EXPECT_TRUE(a.isPalindrome1(head));
//     destroyList(head);
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
