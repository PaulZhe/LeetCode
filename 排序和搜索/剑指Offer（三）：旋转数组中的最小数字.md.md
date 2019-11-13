# 题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

------

```cpp
//二分查找法做更快
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if (length <= 0) {
            return -1;
        }
        int l = 0, r = length - 1, mid = l;
        while (rotateArray[l] >= rotateArray[r]) {
            if (r - l == 1) {
                mid = r;
                break;
            }
            mid = l + (r - l) / 2;
            //如果l、r、mid指向的三个数字相等，则只能顺序查找
            if (rotateArray[l] == rotateArray[r] && rotateArray[mid] == rotateArray[l]) {
                return minInOrder(rotateArray, length);
            }
            
            if (rotateArray[mid] >= rotateArray[l]) {
                l = mid;
            } else if (rotateArray[mid] <= rotateArray[r]) {
                r = mid;
            }
        }
        return rotateArray[mid];
    }
    int minInOrder(vector<int> rotateArray, int length) {
        int first = rotateArray[0];
        for (int i = 0; i < length; i++) {
            if (rotateArray[i] < first) {
                return rotateArray[i];
            }
        }
        return first;
    }
};
```

