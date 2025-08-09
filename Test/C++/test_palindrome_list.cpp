#include <gtest/gtest.h>
#include <vector>
#include "Linked_list.hh"

// 测试夹具类：封装共享逻辑
class LinkedListPalindromeTest : public ::testing::Test
{
protected:
    // 共享的Linked_Node实例（用于调用isPalindrome1）
    Linked_Node testNode{0};

    // 辅助函数：创建链表（复用）
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

    // 辅助函数：销毁链表（复用）
    void destroyList(Linked_Node *head)
    {
        while (head != nullptr)
        {
            Linked_Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 每个测试用例结束后自动调用，确保链表被销毁（防泄漏）
    void TearDown() override
    {
        // 这里可以统一处理销毁逻辑（如果链表指针在夹具中维护）
        // 也可以在每个用例中显式调用destroyList，结合TearDown双重保障
    }
};

// 测试用例1：空链表
TEST_F(LinkedListPalindromeTest, EmptyList)
{
    Linked_Node *head = nullptr;
    EXPECT_TRUE(testNode.isPalindrome1(head)); // 直接使用夹具中的testNode
}

// 测试用例2：单节点链表
TEST_F(LinkedListPalindromeTest, SingleNode)
{
    Linked_Node *head = createList({5}); // 直接调用夹具中的createList
    EXPECT_TRUE(testNode.isPalindrome1(head));
    destroyList(head); // 调用夹具中的destroyList
}

// 测试用例3：偶数个节点的回文链表
TEST_F(LinkedListPalindromeTest, EvenLengthPalindrome)
{
    Linked_Node *head = createList({1, 2, 2, 1});
    EXPECT_TRUE(testNode.isPalindrome1(head));
    destroyList(head);
}

// 测试用例4：奇数个节点的回文链表
TEST_F(LinkedListPalindromeTest, OddLengthPalindrome)
{
    Linked_Node *head = createList({1, 2, 3, 2, 1});
    EXPECT_TRUE(testNode.isPalindrome1(head));
    destroyList(head);
}

// 测试用例5：非回文链表
TEST_F(LinkedListPalindromeTest, NotPalindrome)
{
    Linked_Node *head = createList({1, 2, 3, 4});
    EXPECT_FALSE(testNode.isPalindrome1(head));
    destroyList(head);
}

// 测试用例6：所有节点值相同的链表（视为回文）
TEST_F(LinkedListPalindromeTest, AllSameValues)
{
    Linked_Node *head = createList({5, 5, 5, 5});
    EXPECT_TRUE(testNode.isPalindrome1(head));
    destroyList(head);
}

// 测试用例7：两个节点的回文链表
TEST_F(LinkedListPalindromeTest, TwoNodesPalindrome)
{
    Linked_Node *head = createList({3, 3});
    EXPECT_TRUE(testNode.isPalindrome1(head));
    destroyList(head);
}

// 测试用例8：两个节点的非回文链表
TEST_F(LinkedListPalindromeTest, TwoNodesNotPalindrome)
{
    Linked_Node *head = createList({3, 4});
    EXPECT_FALSE(testNode.isPalindrome1(head));
    destroyList(head);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
