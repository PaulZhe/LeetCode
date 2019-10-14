# 题目描述

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

***

```cpp
///解题思路：首先选取数组中右上角的数字，因为这个数字是该行最大，该列最小
//如果该数字等于要查找的数字，查找过程结束
//如果该数字大于要查找的数字，剔除这个数字所在列
//如果这个数字小于要查找的数字，则提出这个数字所在行
//直到行或列越出边界，结束查找，未找到
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        if (rows == 0) {
            return false;
        }
        int columns = array[0].size();
        int row = 0, col = columns - 1;
        while (col >= 0 && row < rows) {
            if (array[row][col] == target) {
                return true;
            } else if (array[row][col] > target) {
                col--;
                continue;
            } else {
                row++;
                continue;
            }
        }
        return false;
    }
};
```

