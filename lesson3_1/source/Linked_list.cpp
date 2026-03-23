#include "Linked_list.hh"
#include <algorithm>

#include <stack>
#include <unordered_map>
// 2.两数相加
Linked_Node *Linked_Node::addTwoNumbers(Linked_Node *l1, Linked_Node *l2) {
  // 创建一个虚拟头节点，简化操作
  Linked_Node *dummy = new Linked_Node(0);
  Linked_Node *curr = dummy; // 当前操作的节点指针
  // 进位标志
  int carry = 0;
  // 如果两个链表都为空，返回空
  if (!l1 && !l2)
    return nullptr;

  while (l1 != nullptr || l2 != nullptr|| carry != 0) {
    // 计算当前位的和（处理空指针情况）
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    carry = sum / 10;     // 新的进位（sum >= 10时carry=1，否则0）
    int digit = sum % 10; // 当前位的数字

    // 创建新节点并连接到结果链表
    curr->next = new Linked_Node(digit);
    curr = curr->next;

    // 移动原链表指针
    if (l1 != nullptr)
      l1 = l1->next;
    if (l2 != nullptr)
      l2 = l2->next;
  }
  return dummy->next;
}
// 19.删除链表的倒数第N个节点
Linked_Node *Linked_Node::removeNthFromEnd(Linked_Node *head, int n) {

  int length = 0;
  int target = 0;
  Linked_Node *current = head;
  // 计算链表长度
  while (current != nullptr) {
    length++;
    current = current->next;
  }
  // 如果n大于链表长度，删除头节点
  if (n > length || length == 0 || n <= 0) {
    return head; // n超过链表长度，返回原链表
  } else if (n == length) {
    Linked_Node *newHead = head->next;
    delete head; // 释放原头节点内存
    return newHead;
  } else {
    target = length - n; // 计算需要删除的节点位置（从0开始）
    current = head;
    for (int i = 1; i < target; i++) {
      current = current->next; // 移动到目标节点的前一个节点
    }
    Linked_Node *nodeToDelete = current->next;
    current->next = current->next->next; // 删除目标节点
    delete nodeToDelete;                 // 释放目标节点内存
    return head;                         // 返回修改后的链表头节点
  }
}
Linked_Node *Linked_Node::removeNthFromEnd1(Linked_Node *head, int n) {
  Linked_Node *fast = head;
  Linked_Node *slow = head;
  // 让快指针先走n步
  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }
  // 如果快指针到达尾部，说明链表长度小于n，删除头节点
  if (fast == nullptr) {
    return head->next;
  }
  while (fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return head;
}
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
// 23.合并K个升序链表(暴力求解法)
Linked_Node *Linked_Node::mergeKLists(std::vector<Linked_Node *> &lists) {
  std::vector<int> values;

  // 遍历所有链表，将节点值存入数组
  for (Linked_Node *list : lists) {
    Linked_Node *current = list;
    while (current != nullptr) {
      values.push_back(current->val);
      current = current->next;
    }
  }

  // 如果没有节点，返回空
  if (values.empty()) {
    return nullptr;
  }

  // 对数组进行排序
  std::sort(values.begin(), values.end());

  // 根据排序后的数组创建新的链表
  Linked_Node *dummy = new Linked_Node(0);
  Linked_Node *current = dummy;

  for (int val : values) {
    current->next = new Linked_Node(val);
    current = current->next;
  }

  return dummy->next;
}
// 23.合并K个升序链表（优化法）
Linked_Node* merge(std::vector<Linked_Node*>& lists, int left, int right) {
    if (left == right) return lists[left];
    if (left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    Linked_Node* l1 = merge(lists, left, mid);
    Linked_Node* l2 = merge(lists, mid + 1, right);
    return Linked_Node::mergeTwoLists(l1, l2);
}
Linked_Node* mergeKLists(std::vector<Linked_Node*>& lists) {
    if (lists.empty()) return nullptr;
    return merge(lists, 0, lists.size() - 1);
}

// 24.两两交换链表中的节点
Linked_Node *Linked_Node::swapPairs(Linked_Node *head) {
  Linked_Node *dummy = new Linked_Node(0);
  dummy->next = head;
  Linked_Node *prev = dummy;
  while (head != nullptr && head->next != nullptr) {
    Linked_Node *node1 = head;
    Linked_Node *node2 = head->next;
    prev->next = node2;
    node1->next = node2->next;
    node2->next = node1;
    prev = node1;
    head = node1->next;
  }
  return dummy->next;
}
Linked_Node *Linked_Node::swapPairs1(Linked_Node *head) {
  // 递归终止条件：当前节点为空或只有一个节点，无需交换
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  // 标记要交换的两个节点
  Linked_Node *node1 = head;
  Linked_Node *node2 = head->next;

  // 递归处理剩余节点，并将结果连接到node1后面
  node1->next = swapPairs(node2->next);
  // 交换node1和node2
  node2->next = node1;

  // node2成为新的头节点
  return node2;
}
/*
核心思路：通用分组翻转
无论是迭代还是递归，都需要完成三个步骤：

1.分组检查： 确定当前组（k 个节点）是否存在。如果不存在（不足
k个），则停止操作。 2.翻转： 对这 k 个节点进行原地翻转。
3. 连接： 将翻转后的组与前一个片段和后一个片段正确连接起来。*/

// 25. K 个一组翻转链表(递归法)
Linked_Node *Linked_Node::reverseKGroup(Linked_Node *head, int k) {
  // 1. 检查是否存在 k 个节点
  Linked_Node *check = head;
  for (int i = 0; i < k; ++i) {
    if (check == nullptr) {
      return head; // 不足 k 个，不翻转，直接返回
    }
    check = check->next;
  }

  // 2. 存储下一组的起始节点 (check 现在是下一组的 head)
  Linked_Node *next_group_start = check;

  // 3. 递归处理下一组
  Linked_Node *new_next_group_head = reverseKGroup(next_group_start, k);

  // 4. 翻转当前 k 个节点 (head 到 next_group_start 之前的节点)
  // 标准的三指针原地翻转法
  Linked_Node *prev = nullptr;
  Linked_Node *curr = head;

  // 翻转 k 个节点
  while (curr != next_group_start) {
    Linked_Node *next_node = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next_node;
  }

  // 5. 连接
  // 翻转后，原 head 变成了尾部，将它连接到递归返回的下一组新头部
  head->next = new_next_group_head;

  // 6. 返回翻转后的新头部 (即翻转前的第 k 个节点，现在是 prev)
  return prev;
}
// 25. K 个一组翻转链表(迭代法)
Linked_Node *Linked_Node::reverseKGroup1(Linked_Node *head, int k) {

  if (!head || k == 1)
    return head; // 空链表或k=1直接返回

  // 创建哑节点，简化头节点处理
  Linked_Node *dummy = new Linked_Node(0);
  dummy->next = head;

  // pre是当前组的前一个节点，用于连接翻转后的子链表
  Linked_Node *pre = dummy;
  // end用于定位当前组的最后一个节点
  Linked_Node *end = dummy;

  while (end->next != nullptr) {
    // 检查剩余节点是否有k个，移动end到当前组的最后一个节点
    for (int i = 0; i < k && end != nullptr; ++i) {
      end = end->next;
    }
    if (end == nullptr)
      break; // 剩余节点不足k个，停止处理

    // 记录当前组的第一个节点和下一组的第一个节点
    Linked_Node *start = pre->next;
    Linked_Node *nextGroup = end->next;

    // 断开当前组与下一组的连接，便于翻转
    end->next = nullptr;

    // 翻转当前组，并将翻转后的头节点与pre连接
    pre->next = reverseList(start);

    // 将翻转后的尾节点（原start）与下一组连接
    start->next = nextGroup;

    // 更新pre和end，准备处理下一组
    pre = start;
    end = pre;
  }

  Linked_Node *result = dummy->next;
  delete dummy; // 释放哑节点内存
  return result;
}
//86. 分隔链表
//思路：使用两个虚拟头节点，一个存放小于x的节点，一个存放大于等于x的节点
Linked_Node* Linked_Node::partition(Linked_Node *head, int x){
    if(head == nullptr){
        return nullptr;
    }
    Linked_Node *p1 = head;
    Linked_Node *p2 = head;
    Linked_Node *dummy1 = new Linked_Node(0);
    Linked_Node *dummy2 = new Linked_Node(0);
    Linked_Node *tail1 = dummy1;
    Linked_Node *tail2 = dummy2;
    while(p1!=nullptr){
        if(p1->val >= x){
            tail2->next = p1;
            tail2 = tail2->next;
        }
        else{
            tail1->next = p1;
            tail1 = tail1->next;
        }
        p1 = p1->next;
        p2->next = nullptr;
        p2 = p1;
    }
    tail1->next = dummy2->next;
    delete dummy1;
    delete dummy2;
    return dummy1->next;
}

// 141.判断链表是否有环(快慢指针法)
bool Linked_Node::hasCycle(Linked_Node *head) {
  Linked_Node *fast = head;
  Linked_Node *slow = head;
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      return true;
    }
  }
  return false;
}
// 141.判断链表是否有环(哈希表法)
bool Linked_Node::hasCycle2(Linked_Node *head) {
  std::unordered_map<Linked_Node *, int> map;
  while (head != nullptr) {
    if (map.find(head) != map.end()) {
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
Linked_Node *Linked_Node::copyRandomList(Linked_Node *head) {
  if (!head) {
    return nullptr;
  }
  // 第一次遍历：在每个原节点后插入复制节点
  Linked_Node *curr = head;
  while (curr != nullptr) {
    Linked_Node *copy = new Linked_Node(curr->val); // 创建复制节点
    copy->next = curr->next; // 复制节点指向原节点的下一个
    curr->next = copy;       // 原节点指向复制节点
    curr = copy->next;       // 移动到下一个原节点
  }

  // 第二次遍历：设置复制节点的random指针
  curr = head;
  while (curr) {
    Linked_Node *copy = curr->next;
    // 若原节点random不为空，复制节点的random指向原random的复制节点
    if (curr->random != nullptr) {
      copy->random = curr->random->next;
    } else {
      copy->random = nullptr;
    }
    curr = copy->next; // 移动到下一个原节点
  }

  // 第三次遍历：拆分原链表和复制链表
  curr = head;
  Linked_Node *dummy = new Linked_Node(0);
  Linked_Node *copyCurr = dummy;

  while (curr) {
    Linked_Node *copy = curr->next;
    Linked_Node *nextOrig = copy->next; // 保存下一个原节点

    // 构建复制链表的next关系
    copyCurr->next = copy;
    copyCurr = copy;

    // 恢复原链表的next关系
    curr->next = nextOrig;
    curr = nextOrig;
  }

  Linked_Node *result = dummy->next;
  delete dummy; // 释放哑节点
  return result;
}
// 148.排序链表(递归)
Linked_Node *Linked_Node::sortList(Linked_Node *head) {
  // 当为空数组或只有一个节点时，直接返回
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  // 1. 分割（Divide）：寻找中点
  Linked_Node *slow = head;
  Linked_Node *fast = head;
  Linked_Node *prev = nullptr; // 用于断开链表

  while (fast != nullptr && fast->next != nullptr) {
    prev = slow;
    slow = slow->next; // 慢指针指向后半部分的头
    fast = fast->next->next;
  }

  // 断开链表：将前半部分的尾部 next 指向 nullptr
  if (prev != nullptr) {
    prev->next = nullptr;
  }

  // 此时：
  // left_half_head = head
  // right_half_head = slow

  // 2. 递归（Conquer）：排序左右两部分
  Linked_Node *sorted_left = sortList(head);  // 排序前半部分
  Linked_Node *sorted_right = sortList(slow); // 排序后半部分

  // 3. 合并（Combine）：将排好序的两部分合并
  Linked_Node *result = mergeTwoLists(sorted_left, sorted_right);
  return result;
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
    return nullptr; 
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
// 876.链表的中间节点

Linked_Node *Linked_Node::middleNode(Linked_Node *head) {
    
    //先进行帧头判断
    if(head == nullptr){
      return nullptr;

    }
    //快慢指针法
    Linked_Node * slow = head;
    Linked_Node * fast = head;
    while(fast != nullptr && fast->next != nullptr){   //判断快指针和快指针的下一个，这样如果下下一个是空的，慢指针就会停留在中间第二个

      slow = slow->next;        //先让慢指针先走
      fast = fast->next->next;  //再让快指针走两步

    }
    return slow;
}