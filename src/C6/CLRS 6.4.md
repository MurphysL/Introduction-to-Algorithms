#	 CLRS 6.4

## 6.4-1

**Using Figure 6.4 as a model, illustrate the operation of HEAPSORT on the array A = [5, 13, 2, 25, 7, 17, 20, 8, 4].**

**Anwser：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/code/s6.4-1.kt

## 6.4-2

**Argue the correctness of HEAPSORT using the following loop invariant:**
> At the start of each iteration of the for loop of lines 2-5, the subarray A[1...i] is a max-heap containing the i smallest elements of A[1...n], and the subarray A[i + 1...n] contains the n - i largest elements of A[1...n], sorted.

**Answer：**

**初始化：**第一次循环之前，此时为最大堆，子数组为空。

**保持：**每次迭代，最大堆堆顶元素被交换，交换后调用 MAX-HEAPIFY( A,  1)保持最大堆性质。经 i 此迭代后，子数组为 A[i+1..n]，为从小到大排序的数组。

**终止：**i = 1 时过程终止。


## 6.4-3

**What is the running time of heapsort on an array A of length n that is already sorted in increasing order? What about decreasing order?**

**Answer：**




