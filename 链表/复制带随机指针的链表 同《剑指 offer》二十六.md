给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的**深拷贝**。 

 

**示例：**

**![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1470150906153-2yxeznm.png)**

```
输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
```

 

**提示：**

1. 你必须返回**给定头的拷贝**作为对克隆列表的引用。

***

```cpp
///用哈希表去将复制节点与原节点去做一个关联
//第一步先复制所有的节点及其值，用next属性连起来
//第二步通过哈希将随机指针指向的值连起来

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        map<Node*, Node*> mp;
        Node *tmp = head, *pre = NULL;
        while (tmp != NULL) {
            Node *pCloned = new Node(tmp->val, NULL, NULL);
            mp.insert(make_pair(tmp, pCloned));
            if (pre != NULL) { //空指针不能访问结构体变量
                pre->next = pCloned;
            }
            pre = pCloned;
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp != NULL) {
            mp[tmp]->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head];
    }
};

//还有两种做法，暴力法不谈
///空间复杂度为1的做法
//将复制节点接在原节点之后，代替另开辟的哈希表的功能，然后拼接完成后比哈希做法多了一步再拆分链表的操作
```

