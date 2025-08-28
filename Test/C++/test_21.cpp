#include "Linked_list.hh"
#include <gtest/gtest.h>

// 辅助函数：根据数组创建链表
Linked_Node *createList(const std::vector<int> &values) {
  Linked_Node dummy;
  Linked_Node *tail = &dummy;
  for (int val : values) {
    tail->next = new Linked_Node(val);
    tail = tail->next;
  }
  return dummy.next;
}

// 辅助函数：销毁链表（避免内存泄漏）
void destroyList(Linked_Node *head) {
  while (head != nullptr) {
    Linked_Node *temp = head;
    head = head->next;
    delete temp;
  }
}

// 辅助函数：将链表转换为数组（便于验证结果）
std::vector<int> listToVector(Linked_Node *head) {
  std::vector<int> result;
  while (head != nullptr) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}

// 测试用例1：两个链表都为空
TEST(MergeTwoListsTest, BothEmpty) {
  Linked_Node *l1 = nullptr;
  Linked_Node *l2 = nullptr;

  Linked_Node *merged = Linked_Node::mergeTwoLists(l1, l2);
  EXPECT_EQ(merged, nullptr);
}

// 测试用例2：l1为空，l2非空
TEST(MergeTwoListsTest, L1Empty) {
  Linked_Node *l1 = nullptr;
  Linked_Node *l2 = createList({1, 2, 3});

  Linked_Node *merged = Linked_Node::mergeTwoLists(l1, l2);
  std::vector<int> result = listToVector(merged);

  EXPECT_EQ(result, std::vector<int>({1, 2, 3}));

  destroyList(merged); // 注意：此时merged指向l2的节点，销毁会释放原l2内存
}

// 测试用例3：l2为空，l1非空
TEST(MergeTwoListsTest, L2Empty) {
  Linked_Node *l1 = createList({4, 5, 6});
  Linked_Node *l2 = nullptr;

  Linked_Node *merged = Linked_Node::mergeTwoLists(l1, l2);
  std::vector<int> result = listToVector(merged);

  EXPECT_EQ(result, std::vector<int>({4, 5, 6}));

  destroyList(merged); // 释放原l1内存
}

// 测试用例4：两个链表长度相同且无重复元素
TEST(MergeTwoListsTest, SameLengthNoDuplicate) {
  Linked_Node *l1 = createList({1, 3, 5});
  Linked_Node *l2 = createList({2, 4, 6});

  Linked_Node *merged = Linked_Node::mergeTwoLists(l1, l2);
  std::vector<int> result = listToVector(merged);

  EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4, 5, 6}));

  destroyList(merged); // 释放合并后的所有节点内存
}

// 测试用例5：两个链表长度不同且有重复元素
TEST(MergeTwoListsTest, DifferentLengthWithDuplicate) {
  Linked_Node *l1 = createList({1, 2, 2, 3});
  Linked_Node *l2 = createList({2, 4, 5});

  Linked_Node *merged = Linked_Node::mergeTwoLists(l1, l2);
  std::vector<int> result = listToVector(merged);

  EXPECT_EQ(result, std::vector<int>({1, 2, 2, 2, 3, 4, 5}));

  destroyList(merged);
}

// 测试用例6：一个链表是另一个链表的前缀
TEST(MergeTwoListsTest, OneIsPrefixOfAnother) {
  Linked_Node *l1 = createList({1, 2, 3});
  Linked_Node *l2 = createList({1, 2, 3, 4, 5});

  Linked_Node *merged = Linked_Node::mergeTwoLists(l1, l2);
  std::vector<int> result = listToVector(merged);

  EXPECT_EQ(result, std::vector<int>({1, 1, 2, 2, 3, 3, 4, 5}));

  destroyList(merged);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
