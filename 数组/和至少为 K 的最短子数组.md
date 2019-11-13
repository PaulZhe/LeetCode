返回 `A` 的最短的非空连续子数组的**长度**，该子数组的和至少为 `K` 。

如果没有和至少为 `K` 的非空子数组，返回 `-1` 。

 **示例 1:**

```
输入：A = [1], K = 1
输出：1
```

 **示例 2:**

```
输入：A = [1,2], K = 4
输出：-1
```

 **示例 3:**

```
输入：A = [2,-1,2], K = 3
输出：3
```

***

# 参考题解

# [[LeetCode\] 862. Shortest Subarray with Sum at Least K 和至少为K的最短子数组](https://www.cnblogs.com/grandyang/p/11300071.html)

------

```c++
///自己的解法:
//有数据量特别大的样例没通过，还不清楚原因
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int next = 0, length = A.size(), pos = 0, neg = 0, count = 0, min = 400000000, flag = 0;
        long sum = 0;
        deque<int> dq;
        for (int i = 0; i < length; i++) {
            if (A[i] <= 0 && dq.empty()) {
                continue;
            }
            dq.push_back(A[i]);
            count++;
            if (A[i] > 0) {
                if (pos != 0 && next == 0) {
                    next = i;
                }
                pos += A[i];
            } else {
                neg += A[i];
                if (neg >= pos) {
                    dq.clear();
                    count = 0;
                    pos = 0;
                    neg = 0;
                    sum = 0;
                    next = 0;
                    continue;
                }
            }
            sum += A[i];
            if (sum >= K) {
                if (count == 1) {
                    return 1;
                }
                flag = 1;
                if (min > count) {
                    min = count;
                }
                count = 0;
                pos = 0;
                neg = 0;
                sum = 0;
                i = next - 1;
                next = 0;
                dq.clear();
                continue;
            }
        }
        if (flag == 1) {
            return min;
        } else {
            return -1;
        }
    }
};
```

```cpp
///参考题解以后的解答
//对于子数组之和的问题，十有八九是要建立累加和数组的，因为其可以快速的计算任意区间和，但即便是有了累加和数组，遍历所有区间和还是会超时。
//我们是按照数组原顺序将数字下标加入双向队列的。在建立好累加和数组之和，遍历其每个累加和，然后用一个 while 循环，从双向队列的开头开始遍历，假如区间和之差大于等于K，就移除队首元素并更新结果 res。之后这个 while 循环非常重要，能有这么高的击败率，全要靠这个循环，这个是从双向队列的末尾开始往前遍历，假如当前区间和 sums[i] 小于等于队列末尾的区间和，则移除队列末尾元素。这是为啥呢？因为若数组都是正数，那么长度越长，区间和一定越大，则 sums[i] 一定大于所有双向队列中的区间和，但由于可能存在负数，从而使得长度变长，区间总和反而减少了，之前的区间和之差都没有大于等于K，现在的更不可能大于等于K，这个结束位置可以直接淘汰，不用进行计算。循环结束后将当前位置加入双向数组即可，
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int length = A.size(), ans = INT_MAX;
        deque<int> dq;
        vector<int> sums(length + 1);
        for (int i = 1; i <= length; i++) {
          sums[i] = sums[i - 1] + A[i - 1];
        }
        for (int i = 0; i <= length; i++) {
          while (!dq.empty() && sums[i] - sums[dq.front()] >= K) {
            ans = min(ans, i - dq.front());
            dq.pop_front();
          }
          while (!dq.empty() && sums[i] <= sums[dq.back()]) {
            dq.pop_back();
          }
          dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    } 
};
```

