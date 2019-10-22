## 题目描述

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

***

```cpp
///解法：将链表中所有元素存入容器中，最后再逆置容器就OK
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        if (head == NULL) {
            return ans;
        }
        ListNode *temp = head;
        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

