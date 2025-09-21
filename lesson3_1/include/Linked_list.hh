#ifndef LINKED_LIST_HH
#define LINKED_LIST_HH

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
/*给你一个链表的头节点 head ，判断链表中是否有环。

    如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

        如果链表中存在环 ，则返回 true 。 否则，返回 false */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Linked_Node
{
public:
    int val;
    Linked_Node *next;
    Linked_Node() : val(0), next(nullptr) {};
    Linked_Node(int x) : val(x), next(nullptr) {};
    Linked_Node(int x, Linked_Node *next) : val(x), next(next) {};
    // 通过数组创建链表
    Linked_Node(std::vector<int> &arr) : val(0), next(nullptr)
    {
        if (arr.empty())
        {
            return;
        }

        // 当前对象作为头节点，初始化第一个值
        this->val = arr[0];
        Linked_Node *cur = this;

        // 循环创建后续节点
        for (size_t i = 1; i < arr.size(); ++i)
        {
            cur->next = new Linked_Node(arr[i]);
            cur = cur->next;
        }
    }
    // 2.两数相加
    Linked_Node *addTwoNumbers(Linked_Node *l1, Linked_Node *l2);
    // 19.删除链表的倒数第N个节点
    static Linked_Node *removeNthFromEnd(Linked_Node *head,
                                         int n); // 需要遍历两次
    static Linked_Node *removeNthFromEnd1(Linked_Node *head,
                                          int n); // 只需要遍历一次
    // 21.合并两个有序链表
    static Linked_Node *mergeTwoLists(Linked_Node *l1, Linked_Node *l2);

    // 23.合并K个升序链表
    Linked_Node *mergeKLists(std::vector<Linked_Node *> &lists);

    // 141.判断链表是否有环
    bool hasCycle(Linked_Node *head);  // 使用快慢指针
    bool hasCycle2(Linked_Node *head); // 使用哈希表

    // 142. 环形链表 II
    Linked_Node *detectCycle(Linked_Node *head);

    // 160.相交链表
    Linked_Node *getIntersectionNode(Linked_Node *headA, Linked_Node *headB);  // 使用哈希表
    Linked_Node *getIntersectionNode1(Linked_Node *headA, Linked_Node *headB); // 使用双指针

    // 206. 反转链表
    Linked_Node *reverseList(Linked_Node *head); // 递归

    // 234. 回文链表
    bool isPalindrome(Linked_Node *head);  // 转化为数组
    bool isPalindrome1(Linked_Node *head); // 递归
};
#endif
// 示例
//  std::vector<int> nums = {3, 2, 0, -4};
//      Linked_Node *cur = new Linked_Node(nums);
//      Linked_Node *head = cur;
//      while (cur != nullptr)
//      {
//          if (cur->next == nullptr)
//          {
//              cur->next = head->next;
//              break;
//          }
//          else
//          {
//              cur = cur->next;
//          }
//      }
//      // for (int i = 0; i < 10; i++)
//      // {
//      //     std::cout << head->val << " ";
//      //     head = head->next;
//      // }
//      bool result = cur->hasCycle(head);
//      std::cout << result << std::endl;
//      return 0;