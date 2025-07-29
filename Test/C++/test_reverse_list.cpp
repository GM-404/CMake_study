#include <gtest/gtest.h>
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

// 辅助函数：销毁链表
void destroyList(Linked_Node *head)
{
    while (head != nullptr)
    {
        Linked_Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// 辅助函数：将链表转换为向量以便验证
std::vector<int> listToVector(Linked_Node *head)
{
    std::vector<int> result;
    while (head != nullptr)
    {
        result.push_back(head->val); // 假设节点值存储在val成员中
        head = head->next;
    }
    return result;
}

TEST(ReverseListTest, EmptyList)
{
    // 测试空链表
    Linked_Node *head = nullptr;
    Linked_Node a(0);
    Linked_Node *reversed = a.reverseList(head);
    EXPECT_EQ(reversed, nullptr);
}

TEST(ReverseListTest, SingleNode)
{
    // 测试只有一个节点的链表
    Linked_Node *head = createList({5});
    Linked_Node a(0);
    Linked_Node *reversed = a.reverseList(head);

    std::vector<int> result = listToVector(reversed);
    EXPECT_EQ(result, std::vector<int>({5}));

    destroyList(reversed);
}

TEST(ReverseListTest, MultipleNodes)
{
    // 测试多个节点的链表
    Linked_Node *head = createList({1, 2, 3, 4, 5});
    Linked_Node a(0);
    Linked_Node *reversed = a.reverseList(head);

    std::vector<int> result = listToVector(reversed);
    EXPECT_EQ(result, std::vector<int>({5, 4, 3, 2, 1}));

    destroyList(reversed);
}

TEST(ReverseListTest, TwoNodes)
{
    // 测试两个节点的链表
    Linked_Node *head = createList({10, 20});
    Linked_Node a(0);
    Linked_Node *reversed = a.reverseList(head);

    std::vector<int> result = listToVector(reversed);
    EXPECT_EQ(result, std::vector<int>({20, 10}));

    destroyList(reversed);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}