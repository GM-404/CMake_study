#include "Linked_list.hh"

// 21.合并两个有序链表
Linked_Node *Linked_Node::mergeTwoLists(Linked_Node *l1, Linked_Node *l2) {
  // 创建一个虚拟头节点，简化操作
  Linked_Node dummy;
  Linked_Node *tail = &dummy;

  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val < l2->val) {
      tail->next = l1;
      l1 = l1->next;
    } else {
      tail->next = l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }

  // 连接剩余的节点
  if (l1 != nullptr) {
    tail->next = l1;
  } else {
    tail->next = l2;
  }

  return dummy.next; // 返回合并后的链表头节点
}
// 141.判断链表是否有环(快慢指针法)
bool Linked_Node::hasCycle(Linked_Node *head)
{
    Linked_Node *fast = head;
    Linked_Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
// 141.判断链表是否有环(哈希表法)
bool Linked_Node::hasCycle2(Linked_Node *head)
{
    std::unordered_map<Linked_Node *, int> map;
    while (head != nullptr)
    {
        if (map.find(head) != map.end())
        {
            return true;
        }
        map[head] = head->val; // 存储节点地址和对应的值
        head = head->next;
    }
    return false;
}
// 142. 环形链表 II
// 根据：

// f=2s （快指针每次2步，路程刚好2倍）

// f = s + nb (相遇时，刚好多走了n圈）

// 推出：s = nb

// 从head结点走到入环点需要走 ： a + nb， 而slow已经走了nb，那么slow再走a步就是入环点了。

// 如何知道slow刚好走了a步？ 从head开始，和slow指针一起走，相遇时刚好就是a步
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
// 160.相交链表
Linked_Node *Linked_Node::getIntersectionNode(Linked_Node *headA, Linked_Node *headB)
{
    std::unordered_map<Linked_Node *, int> map;
    while (headA != nullptr)
    {
        map[headA] = headA->val; // 存储节点地址和对应的值
        headA = headA->next;
    }
    while (headB != nullptr)
    {
        if (map.find(headB) != map.end())
        {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr; // 该函数需要实现具体的逻辑
}
// 160.相交链表(双指针法)
Linked_Node *Linked_Node::getIntersectionNode1(Linked_Node *headA, Linked_Node *headB)
{
    if (headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }
    Linked_Node *a = headA;
    Linked_Node *b = headB;
    while (a != b)
    {
        a = (a == nullptr) ? headB : a->next; // 如果到达尾部，则转到另一个链表的头部
        b = (b == nullptr) ? headA : b->next; // 同上
    }
    return a; // 返回相交节点或nullptr
}
// 206.反转链表
Linked_Node *Linked_Node::reverseList(Linked_Node *head)
{
    // 递归法
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Linked_Node *pre = nullptr;
    Linked_Node *cur = head;
    Linked_Node *a = cur->next;
    while (a != nullptr)
    {
        cur->next = pre;
        pre = cur;
        cur = a;
        a = a->next;
    }
    cur->next = pre;
    return cur;
}
// 234.回文链表(转化为数组)
bool Linked_Node::isPalindrome(Linked_Node *head)
{
    std::vector<int> arr;
    Linked_Node *cur = head;
    while (cur != nullptr)
    {
        arr.push_back(cur->val);
        cur = cur->next;
    }
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
// 234.回文链表()
bool Linked_Node::isPalindrome1(Linked_Node *head)
{
    Linked_Node *cur = head;
    std::stack<int> s;
    while (cur != nullptr)
    {
        s.push(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (!s.empty())
    {
        if (s.top() != cur->val)
        {
            return false;
        }
        s.pop();
        cur = cur->next;
    }
    return true;
}