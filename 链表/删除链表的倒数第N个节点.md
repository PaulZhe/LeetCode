1. 给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

   **示例 1:**

   ```
   给定一个链表: 1->2->3->4->5, 和 n = 2.
   
   当删除了倒数第二个节点后，链表变为 1->2->3->5.
   ```

   **说明：**

   给定的 *n* 保证是有效的。

   **进阶:**
   你能尝试使用一趟扫描实现吗？

------

```c++
///自己的题解
//快慢指针法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = NULL, *del = head, *lat = head;
        for (int i = 0; i < n; i++) {
            lat = lat->next;
        }
        while (lat != NULL) {
            pre = del;
            del = del->next;
            lat = lat->next;
        }
        if (pre == NULL) {
            head = head->next;
            return head;
        }
        pre->next = pre->next->next;
        return head;
    }
};
```

```c++
///参考题解的解法
//和自己写的思路和用时相差无几，但逻辑略微清晰一点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *start = pre, *lat = pre;
        for (int i = 0; i < n; i++) {
            lat = lat->next;
        }
        while (lat->next != NULL) {
            start = start->next;
            lat = lat->next;
        }
        start->next = start->next->next;
        return pre->next;
    }
};
```

