给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

**说明**：不允许修改给定的链表。

**示例 1:**

```
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

**示例 2:**

```
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

**示例 2:**

```
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

- **进阶：**

  你是否可以不用额外空间解决此题？

------

```C
///自己的解答
//用一个set集合记录之前走过的节点，判断如果有相同的点，则该点就是成环的入口点
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *now = head;
        set<ListNode *> nodes;
        while (now) {
            if (nodes.count(now)) {
                return now;
            } else {
                nodes.insert(now);
                now = now->next;
            }
        }
        return NULL;
    }
};
```

不用额外空间的做法：Floyd 算法，[环形链表2 题解](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

先用判断是否有环的双指针法找出相遇点，如何再用两个指针，一个从链表头，一个从相遇点同时遍历，相遇点就是入口点。原因如下：

![image.png](https://pic.leetcode-cn.com/99987d4e679fdfbcfd206a4429d9b076b46ad09bd2670f886703fb35ef130635-image.png)

我们利用已知的条件：慢指针移动 1 步，快指针移动 2 步，来说明它们相遇在环的入口处。（下面证明中的 tortoise 表示慢指针，hare 表示快指针）

2⋅distance(tortoise) = distance(hare)
						2(F+a) = F+a+b+a
						2F+2a = F+2a+b
								F = b

因为 F=b，指针从 相遇点出发和从链表的头出发，最后会遍历相同数目的节点后在环的入口处相遇。

