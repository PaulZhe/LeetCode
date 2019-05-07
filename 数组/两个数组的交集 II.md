1. 给定两个数组，编写一个函数来计算它们的交集。

    **示例 1:**
    ```
    输入: nums1 = [1,2,2,1], nums2 = [2,2]
    输出: [2,2]
    ```
    **示例 2:**
    
    ```
    输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    输出: [4,9]
    ```

    **说明:**

    - 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
    - 我们可以不考虑输出结果的顺序。
***
```C
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        for(vector<int>::iterator it1 = nums1.begin(); it1 != nums1.end(); it1++) {
            for(vector<int>::iterator it2 = nums2.begin(); it2 != nums2.end(); it2++) {
                if(*it1 == *it2) {
                    ret.push_back(*it1);
                    *it1 = -10086;
                    *it2 = -10085;
                }
            }
        }
        return ret;
    }
};
```
