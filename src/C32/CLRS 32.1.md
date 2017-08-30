# CLRS 32.1

## 32.1-1

**Show the comparisons the naive string matcher makes for the pattern P = 0001 in the text T = 000010001010001.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C32/code/s32.1-1.kt

## 32.1-2

**Suppose that all characters in the pattern P are different. Show how to accelerate NAIVE- STRING-MATCHER to run in time O(n) on an n-character text T.**

**Answer：**

只需比较第一个字符即可。

## 32.1-3

**Suppose that pattern P and text T are randomly chosen strings of length m and n, respectively, from the d-ary alphabet Σd = {0, 1, . . . , d - 1}, where d ≥ 2. Show that the expected number of character-to-character comparisons made by the implicit loop in line 4 of the naive algorithm is:**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C32/img/s32.1-3.bmp)

**over all executions of this loop. (Assume that the naive algorithm stops comparing characters for a given shift once a mismatch is found or the entire pattern is matched.) Thus, for randomly chosen strings, the naive algorithm is quite efficient.**

**Answer：**

|a(n)|b(n)|
|:--:|:--:|
|1|1-1/d|
|2|1/d*(1-1/d)|
|3|(1/d)^2*(1-1/d)|
|...|...|
|m|(1/d)^(m-1)*(1-1/d)|

> T(time) = (n-m+1)*[a(1)*b(1)+a(2)*b(2)+,,,+a(m)*b(m)] 

## 32.1-4

**Suppose we allow the pattern P to contain occurrences of a gap character ⋄ that can match an arbitrary string of characters (even one of zero length). For example, the pattern ab⋄ba⋄c occurs in the text cabccbacbacab as**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C32/img/s32.1-4.png)

**Note that the gap character may occur an arbitrary number of times in the pattern but is assumed not to occur at all in the text. Give a polynomial-time algorithm to determine if such a pattern P occurs in a given text T , and analyze the running time of your algorithm.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C32/code/s32.1-4.kt

