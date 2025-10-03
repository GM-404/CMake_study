#ifndef LINKED_LIST_HH
#define LINKED_LIST_HH

#include <unordered_map>
#include <vector>


class Linked_Node
{
public:
    int val;
    Linked_Node *next;
    Linked_Node *random; // 用于138中的随机指针
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

    // 24.两两交换链表中的节点
    Linked_Node *swapPairs(Linked_Node *head);
    Linked_Node *swapPairs1(Linked_Node *head);

    // 25. K 个一组翻转链表
    Linked_Node *reverseKGroup(Linked_Node *head, int k);
    Linked_Node *reverseKGroup1(Linked_Node *head, int k);

    // 138.复制带随机指针的链表
    Linked_Node *copyRandomList(Linked_Node *head);

    // 141.判断链表是否有环
    bool hasCycle(Linked_Node *head);  // 使用快慢指针
    bool hasCycle2(Linked_Node *head); // 使用哈希表

    // 142. 环形链表 II
    Linked_Node *detectCycle(Linked_Node *head);

    // 148.排序链表
    Linked_Node *sortList(Linked_Node *head);
    // 160.相交链表
    Linked_Node *getIntersectionNode(Linked_Node *headA, Linked_Node *headB);  // 使用哈希表
    Linked_Node *getIntersectionNode1(Linked_Node *headA, Linked_Node *headB); // 使用双指针

    // 206. 反转链表
    Linked_Node *reverseList(Linked_Node *head); // 递归

    // 234. 回文链表
    bool isPalindrome(Linked_Node *head);  // 转化为数组
    bool isPalindrome1(Linked_Node *head); // 递归
};
// 146. LRU缓存机制
class LRUCache {
private:
  struct DLinkedNode {
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode(int k = 0, int v = 0)
        : key(k), value(v), prev(nullptr), next(nullptr) {}
  };

  std::unordered_map<int, DLinkedNode *> cache; // 哈希表：key -> 节点指针
  DLinkedNode *head;                            // 虚拟头节点
  DLinkedNode *tail;                            // 虚拟尾节点
  int capacity;
  int size;

  // 辅助函数：将节点添加到头部
  void addToHead(DLinkedNode *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  // 辅助函数：删除节点
  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  // 辅助函数：将节点移动到头部（先删除再添加）
  void moveToHead(DLinkedNode *node) {
    removeNode(node);
    addToHead(node);
  }

  // 辅助函数：移除尾部节点（最久未使用）
  DLinkedNode *removeTail() {
    DLinkedNode *removed = tail->prev;
    removeNode(removed);
    return removed;
  }

public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
  }

  // 析构函数：释放所有动态分配的节点内存
  ~LRUCache() {
    DLinkedNode *curr = head;
    while (curr != nullptr) {
      DLinkedNode *temp = curr;
      curr = curr->next;
      delete temp;
    }
  }

  int get(int key) {
    // 1. 查找是否存在
    if (cache.find(key) == cache.end()) {
      return -1;
    }

    // 2. 存在：获取节点，并将其移到头部
    DLinkedNode *node = cache[key];
    moveToHead(node);

    // 3. 返回值
    return node->value;
  }

  void put(int key, int value) {
    // 1. 查找 key 是否已存在
    if (cache.find(key) != cache.end()) {
      // A. 存在：更新值，并移到头部
      DLinkedNode *node = cache[key];
      node->value = value;
      moveToHead(node);
    } else {
      // B. 不存在：创建新节点
      DLinkedNode *newNode = new DLinkedNode(key, value);

      // 2. 添加到哈希表和链表头部
      cache[key] = newNode;
      addToHead(newNode);
      size++;

      // 3. 检查是否超出容量
      if (size > capacity) {
        // 超出：移除尾部最久未使用的节点
        DLinkedNode *removed = removeTail();

        // 从哈希表中删除该记录
        cache.erase(removed->key);

        // 释放节点内存
        delete removed;

        size--;
      }
    }
  }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
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