实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

**示例 1:**

```
输入: haystack = "hello", needle = "ll"
输出: 2
```

**示例 2:**

```
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```

**说明:**

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

------

```cpp
///自己的解法
//直接用find()函数，一行代码搞定，但运行效率
class Solution {
public:
    int strStr(string haystack, string needle) {
        return (int)haystack.find(needle);
    }
};
//可以对寻找空串的条件加个判断，加快运行效率
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        return (int)haystack.find(needle);
    }
};
```

```cpp
///运行效率和库函数差不多，也可用KMP等算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int n1 = haystack.size(), n2 = needle.size();
        if (n2 > n1) return -1;

        for (int i=0; i< n1 - n2 + 1; ++i) {
            int j;
            for (j = 0; j < n2; ++j) {
                if (haystack[i+j] != needle[j]) break;
            }
            
            if (j == n2) return i;
        }
        
        return -1;
    }
};

```