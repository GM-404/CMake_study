#include <gtest/gtest.h>
#include "Linked_list.hh" // 包含Linked_Node类的头文件

// 辅助函数：创建新节点
Linked_Node *createNode(int val)
{
    return new Linked_Node(val);
}

// 辅助函数：释放链表内存
void freeList(Linked_Node *head)
{
    while (head != nullptr)
    {
        Linked_Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// 测试用例1：两个链表没有交点
TEST(IntersectionTest, NoIntersection)
{
    // 创建链表A: 1 -> 2 -> 3 -> nullptr
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);

    // 创建链表B: 4 -> 5 -> nullptr
    Linked_Node *headB = createNode(4);
    headB->next = createNode(5);

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode(headA, headB);
    EXPECT_EQ(result, nullptr);

    // 清理内存
    freeList(headA);
    freeList(headB);
}

// 测试用例2：两个链表在中间节点有交点
TEST(IntersectionTest, IntersectionInMiddle)
{
    // 创建公共部分: 5 -> 6 -> nullptr
    Linked_Node *common = createNode(5);
    common->next = createNode(6);

    // 创建链表A: 1 -> 2 -> 3 -> 公共部分
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);
    headA->next->next->next = common;

    // 创建链表B: 4 -> 公共部分
    Linked_Node *headB = createNode(4);
    headB->next = common;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode(headA, headB);
    EXPECT_EQ(result, common);
    EXPECT_EQ(result->val, 5); // 验证交点的值

    // 清理内存（注意只需要释放一次公共部分）
    freeList(headA); // 会释放到common及其之后的节点
    delete headB;    // 只释放headB本身，因为common已经被释放
}

// 测试用例3：链表B是链表A的子集（交点在链表A的头部）
TEST(IntersectionTest, IntersectionAtHeadA)
{
    // 创建链表A: 1 -> 2 -> 3 -> nullptr
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);

    // 链表B直接指向链表A的头部
    Linked_Node *headB = headA;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode(headA, headB);
    EXPECT_EQ(result, headA);
    EXPECT_EQ(result->val, 1);

    // 清理内存（只需要释放一次）
    freeList(headA);
}

// 测试用例4：其中一个链表为空
TEST(IntersectionTest, OneListIsEmpty)
{
    // 创建链表A: 1 -> 2 -> 3 -> nullptr
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);

    // 链表B为空
    Linked_Node *headB = nullptr;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode(headA, headB);
    EXPECT_EQ(result, nullptr);

    // 清理内存
    freeList(headA);
}

// 测试用例5：两个链表都为空
TEST(IntersectionTest, BothListsAreEmpty)
{
    Linked_Node *headA = nullptr;
    Linked_Node *headB = nullptr;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode(headA, headB);
    EXPECT_EQ(result, nullptr);
}
// 测试用例1：两个链表没有交点
TEST(IntersectionTest1, NoIntersection)
{
    // 创建链表A: 1 -> 2 -> 3 -> nullptr
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);

    // 创建链表B: 4 -> 5 -> nullptr
    Linked_Node *headB = createNode(4);
    headB->next = createNode(5);

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode1(headA, headB);
    EXPECT_EQ(result, nullptr);

    // 清理内存
    freeList(headA);
    freeList(headB);
}

// 测试用例2：两个链表在中间节点有交点
TEST(IntersectionTest1, IntersectionInMiddle)
{
    // 创建公共部分: 5 -> 6 -> nullptr
    Linked_Node *common = createNode(5);
    common->next = createNode(6);

    // 创建链表A: 1 -> 2 -> 3 -> 公共部分
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);
    headA->next->next->next = common;

    // 创建链表B: 4 -> 公共部分
    Linked_Node *headB = createNode(4);
    headB->next = common;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode1(headA, headB);
    EXPECT_EQ(result, common);
    EXPECT_EQ(result->val, 5); // 验证交点的值

    // 清理内存（注意只需要释放一次公共部分）
    freeList(headA); // 会释放到common及其之后的节点
    delete headB;    // 只释放headB本身，因为common已经被释放
}

// 测试用例3：链表B是链表A的子集（交点在链表A的头部）
TEST(IntersectionTest1, IntersectionAtHeadA)
{
    // 创建链表A: 1 -> 2 -> 3 -> nullptr
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);

    // 链表B直接指向链表A的头部
    Linked_Node *headB = headA;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode1(headA, headB);
    EXPECT_EQ(result, headA);
    EXPECT_EQ(result->val, 1);

    // 清理内存（只需要释放一次）
    freeList(headA);
}

// 测试用例4：其中一个链表为空
TEST(IntersectionTest1, OneListIsEmpty)
{
    // 创建链表A: 1 -> 2 -> 3 -> nullptr
    Linked_Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);

    // 链表B为空
    Linked_Node *headB = nullptr;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode1(headA, headB);
    EXPECT_EQ(result, nullptr);

    // 清理内存
    freeList(headA);
}

// 测试用例5：两个链表都为空
TEST(IntersectionTest1, BothListsAreEmpty)
{
    Linked_Node *headA = nullptr;
    Linked_Node *headB = nullptr;

    // 测试
    Linked_Node current(0);
    Linked_Node *result = current.getIntersectionNode1(headA, headB);
    EXPECT_EQ(result, nullptr);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}