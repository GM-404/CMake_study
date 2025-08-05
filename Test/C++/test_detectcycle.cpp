#include <gtest/gtest.h>
#include <iostream>

// 假设Linked_Node的定义如下
struct Linked_Node
{
    int val;
    Linked_Node *next;
    Linked_Node(int x) : val(x), next(nullptr) {}
};

// 待测试的函数
Linked_Node *detectCycle(Linked_Node *head)
{
    // 先判断链表是否为空或者只有一个节点
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr; // 空链表或只有一个节点
    }
    // 使用快慢指针检测环
    Linked_Node *slow = head;
    Linked_Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // 找到环的起始点
            Linked_Node *entry = head;
            while (entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // 返回环的起始点
        }
    }
    return nullptr; // 没有环
}

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

// 辅助函数：创建带环的链表
Linked_Node *createListWithCycle(const std::vector<int> &values, int cycleStartIndex)
{
    if (values.empty() || cycleStartIndex < 0 || cycleStartIndex >= (int)values.size())
    {
        return nullptr;
    }

    Linked_Node *head = createList(values);
    if (!head)
        return nullptr;

    // 找到环的起始节点
    Linked_Node *cycleStart = head;
    for (int i = 0; i < cycleStartIndex; ++i)
    {
        cycleStart = cycleStart->next;
    }

    // 找到链表尾节点，并将其指向环的起始节点
    Linked_Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = cycleStart;

    return head;
}

// 辅助函数：释放链表内存（注意：带环的链表需要特殊处理）
void freeList(Linked_Node *head)
{
    if (!head)
        return;

    // 检测是否有环
    Linked_Node *cycleNode = detectCycle(head);
    if (cycleNode)
    {
        // 有环，先断开环
        Linked_Node *current = cycleNode;
        while (current->next != cycleNode)
        {
            current = current->next;
        }
        current->next = nullptr;
    }

    // 正常释放链表
    while (head != nullptr)
    {
        Linked_Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// 测试用例
TEST(DetectCycleTest, EmptyList)
{
    Linked_Node *head = nullptr;
    EXPECT_EQ(detectCycle(head), nullptr);
}

TEST(DetectCycleTest, SingleNodeNoCycle)
{
    Linked_Node *head = new Linked_Node(1);
    EXPECT_EQ(detectCycle(head), nullptr);
    freeList(head);
}

TEST(DetectCycleTest, MultipleNodesNoCycle)
{
    std::vector<int> values = {1, 2, 3, 4, 5};
    Linked_Node *head = createList(values);
    EXPECT_EQ(detectCycle(head), nullptr);
    freeList(head);
}

TEST(DetectCycleTest, CycleAtStart)
{
    std::vector<int> values = {1, 2, 3, 4, 5};
    Linked_Node *head = createListWithCycle(values, 0); // 环从第一个节点开始
    EXPECT_EQ(detectCycle(head), head);                 // 环的起始点应该是头节点
    freeList(head);
}

TEST(DetectCycleTest, CycleInMiddle)
{
    std::vector<int> values = {1, 2, 3, 4, 5};
    Linked_Node *head = createListWithCycle(values, 2); // 环从第三个节点(值为3)开始

    // 找到预期的环起始节点
    Linked_Node *expected = head;
    expected = expected->next->next; // 移动到第三个节点

    EXPECT_EQ(detectCycle(head), expected);
    freeList(head);
}

TEST(DetectCycleTest, CycleAtEnd)
{
    std::vector<int> values = {1, 2, 3, 4, 5};
    Linked_Node *head = createListWithCycle(values, 4); // 环从最后一个节点开始

    // 找到预期的环起始节点
    Linked_Node *expected = head;
    for (int i = 0; i < 4; ++i)
    {
        expected = expected->next;
    }

    EXPECT_EQ(detectCycle(head), expected);
    freeList(head);
}

TEST(DetectCycleTest, SelfCycle)
{
    Linked_Node *head = new Linked_Node(1);
    head->next = head; // 自环

    EXPECT_EQ(detectCycle(head), head);
    freeList(head);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}