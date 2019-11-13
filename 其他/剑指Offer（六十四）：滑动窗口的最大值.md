## 题目描述

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

------

```cpp
///用双端队列做
//队列更新的规则：
//（1）新元素依次与队尾元素比较，如果队尾元素小于新元素，则删除队尾元素，直至队列中没有小于新元素的值。
//（2）更新队首元素，如果队首元素不在新滑动窗口中，则删除队首元素。
//（3）把每次滑动的数字的下标压入队列
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> returnVector;
        deque<int> doubleQueue;
        for (int i = 0; i < num.size(); i++) {
            while(1) {
                if(doubleQueue.empty() || num[doubleQueue.back()] > num[i]) {
                    doubleQueue.push_back(i);
                    break;
            }
            doubleQueue.pop_back();
            }
            if(i - doubleQueue[0] >= size) {
                doubleQueue.pop_front();
            }
            if (i >= size - 1) {
                returnVector.push_back(num[doubleQueue[0]]);
            }  
        }
        return returnVector;
    }
};
```

