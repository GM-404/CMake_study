#include <gtest/gtest.h>
#include "Linked_list.hh"

// 辅助函数：创建无环链表
Linked_Node *createLinkedList(const std::vector<int> &values)
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

// 辅助函数：创建有环链表（最后一个节点指向第cyclePos个节点，0表示头节点）
Linked_Node *createCyclicLinkedList(const std::vector<int> &values, int cyclePos)
{
    if (values.empty())
        return nullptr;

    Linked_Node *head = createLinkedList(values);
    Linked_Node *current = head;
    Linked_Node *cycleNode = nullptr;
    int pos = 0;

    // 找到要形成环的节点
    while (current->next != nullptr)
    {
        if (pos == cyclePos)
        {
            cycleNode = current;
        }
        current = current->next;
        pos++;
    }

    // 如果cyclePos是最后一个节点，自己形成环
    if (cycleNode == nullptr)
    {
        cycleNode = current;
    }

    // 让尾节点指向环节点
    current->next = cycleNode;

    return head;
}

// 辅助函数：释放链表内存（处理无环情况，有环链表需要特殊处理）
void deleteLinkedList(Linked_Node *head)
{
    if (!head)
        return;

    // 对于有环链表，需要先断开环才能安全释放
    Linked_Node *slow = head;
    Linked_Node *fast = head;
    Linked_Node *cycleNode = nullptr;

    // 检测并找到环的位置
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // 找到环的起始点
            cycleNode = head;
            while (cycleNode != slow)
            {
                cycleNode = cycleNode->next;
                slow = slow->next;
            }
            // 断开环
            Linked_Node *temp = cycleNode;
            while (temp->next != cycleNode)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            break;
        }
    }

    // 正常释放链表
    while (head)
    {
        Linked_Node *temp = head;
        head = head->next;
        delete temp;
    }
}

TEST(HasCycleTest, EmptyList)
{
    Linked_Node *head = nullptr;
    Linked_Node testNode(0); // 创建一个测试对象用于调用成员函数
    EXPECT_FALSE(testNode.hasCycle(head));
}

TEST(HasCycleTest, SingleNodeNoCycle)
{
    Linked_Node *head = new Linked_Node(1);
    Linked_Node testNode(0);
    EXPECT_FALSE(testNode.hasCycle(head));
    delete head;
}

TEST(HasCycleTest, SingleNodeWithCycle)
{
    Linked_Node *head = new Linked_Node(1);
    head->next = head; // 自环
    Linked_Node testNode(0);
    EXPECT_TRUE(testNode.hasCycle(head));

    // 特殊处理自环的释放
    head->next = nullptr;
    delete head;
}

TEST(HasCycleTest, MultipleNodesNoCycle)
{
    Linked_Node *head = createLinkedList({1, 2, 3, 4, 5});
    Linked_Node testNode(0);
    EXPECT_FALSE(testNode.hasCycle(head));
    deleteLinkedList(head);
}

TEST(HasCycleTest, MultipleNodesWithCycleAtHead)
{
    Linked_Node *head = createCyclicLinkedList({1, 2, 3, 4, 5}, 0); // 环在头节点
    Linked_Node testNode(0);
    EXPECT_TRUE(testNode.hasCycle(head));
    deleteLinkedList(head);
}

TEST(HasCycleTest, MultipleNodesWithCycleInMiddle)
{
    Linked_Node *head = createCyclicLinkedList({1, 2, 3, 4, 5}, 2); // 环在第3个节点(值为3)
    Linked_Node testNode(0);
    EXPECT_TRUE(testNode.hasCycle(head));
    deleteLinkedList(head);
}

TEST(HasCycleTest, MultipleNodesWithCycleAtTail)
{
    Linked_Node *head = createCyclicLinkedList({1, 2, 3, 4, 5}, 4); // 环在尾节点(自环)
    Linked_Node testNode(0);
    EXPECT_TRUE(testNode.hasCycle(head));
    deleteLinkedList(head);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
