# 题目描述

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

------

```cpp
///解题思路：先遍历一遍字符串，这样就能统计出字符串中空格的总数，由此计算出替换之后字符串的总长度
//从字符串的后面开始复制和替换。
//首先准备两个指针，P1和P2，P1指向原始字符串的末尾，而P2指向替换之后的字符串的末尾
//依次复制字符串的内容，直到第一个指针碰到第一个空格，然后替换，指针前移（分别移1和3格）
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (length <= 0 || str == NULL) {
            return;
        }
        int blankNum = 0, originLength = 0, i = 0;
        while (str[i] != '\0') {
            originLength++;
            if (str[i] == ' ') {
                blankNum++;
            }
            i++;
        }
        int finalLength = originLength + blankNum * 2;
        int pNew = finalLength;
        while (originLength >= 0 && pNew > originLength) {
            if (str[originLength] == ' ') {
                str[pNew--] = '0';
                str[pNew--] = '2';
                str[pNew--] = '%';
            } else {
                str[pNew--] = str[originLength];
            }
            --originLength;
        }
	}
};
```

