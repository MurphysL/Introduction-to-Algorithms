# CLRS 32.2

## 32.2-1

**Working modulo q = 11, how many spurious hits does the Rabin-Karp matcher encounter in the text T = 3141592653589793 when looking for the pattern P = 26?**

**Answer：**

15、59、92

## 32.2-2

**How would you extend the Rabin-Karp method to the problem of searching a text string for an occurrence of any one of a given set of k patterns? Start by assuming that all k patterns have the same length. Then generalize your solution to allow the patterns to have different lengths.**

**Answer：**

模式等长时，先计算模式P，再依次比较。不等长时，先计算各长度模式的模P，再依次比较。

## 32.2-3

**Show how to extend the Rabin-Karp method to handle the problem of looking for a given m × m pattern in an n × n array of characters. (The pattern may be shifted vertically and horizontally, but it may not be rotated.)**

**Answer：**

先对二维字符数组的每一列根据 Rabin-Karp 算法计算 (n - m + 1) 个值，再对每一行使用 Rabin-Karp 算法。

## 32.2-4

**Alice has a copy of a long n-bit file A = <an-1, an-2, . . . , a0>, and Bob similarly has an n-bit file B = <bn-1, bn-2, . . . , b0>. Alice and Bob wish to know if their files are identical. To avoid transmitting all of A or B, they use the following fast probabilistic check. Together, they select a prime q > 1000n and randomly select an integer x from {0, 1, . . . , q - 1}. Then, Alice evaluates**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C32/img/s32.2-4.png)

**and Bob similarly evaluates B(x). Prove that if A ≠ B, there is at most one chance in 1000 that A(x) = B(x), whereas if the two files are the same, A(x) is necessarily the same as B(x). (Hint: See Exercise 31.4-4.)**

**Answer：**
