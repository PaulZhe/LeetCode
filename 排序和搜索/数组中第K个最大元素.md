在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

**示例 1:**

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

**示例 2:**

```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

**说明**：

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

------

```cpp
///创建一个最小堆，用优先队列来实现
//将数组所有元素入队，入队后判断队列的大小是否大于K，如果大于就pop一下
//最后返回这个最小堆的堆顶
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (int t : nums) {
            q.push(t);
            if (q.size() > k) {
                q.pop();
            }
        } 
        return q.top();
    }
};
```

