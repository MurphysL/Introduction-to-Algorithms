# CLRS 6.5

## 6.6-1

**Illustrate the operation of HEAP-EXTRACT-MAX on the heap A = [15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1].**

**Answer：**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/img/s6.5-1.png)

## 6.5-2

**Illustrate the operation of MAX-HEAP-INSERT(A, 10) on the heap A = [15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1]. Use the heap of Figure 6.5 as a model for the HEAP-INCREASE-KEY call.**

**Answer：**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/img/s6.5-2.png)

## 6.5-3

**Write pseudocode for the procedures HEAP-MINIMUM, HEAP-EXTRACT-MIN, HEAP- DECREASE-KEY, and MIN-HEAP-INSERT that implement a min-priority queue with a min-heap.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/code/s6.5-3.kt

## 6.5-4

**Why do we bother setting the key of the inserted node to -∞ in line 2 of MAX-HEAP- INSERT when the next thing we do is increase its key to the desired value?**

**Answer：**

确保 key 的值小于 A[heap.size]

## 6.5-5

**Argue the correctness of HEAP-INCREASE-KEY using the following loop invariant:**
> At the start of each iteration of the while loop of lines 4-6, the array A[1...heap- size[A]] satisfies the max-heap property, except that there may be one violation: A[i] may be larger than A[PARENT(i)].

**Answer：**

**初始化：** 第一次循环迭代开始之前，除 A[heap.size] 外，其他元素均满足最大堆的性质。
**保持：** 循环过程中，不断交换 key 与 其父结点的值使其满足最大堆性质。
**终止：** 当 i = 1 时，所有元素已按最大堆的性质排好。

## 6.5-6

**Each exchange operation on line 5 of HEAP-INCREASE-KEY typically requires three asignments. Show how to use the idea of the inner loop of INSERTION-SORT to reduce the three assignments down to just one assignment.**

**Answer：**
```
HEAP-INCREASE-KEY(A, I, key):
	if key < A[i]
		error "new key is smaller than current key"
	A[i] = key
	while i > 1 and A[PARENT(i)] < key:
		A[i] = A[PARENT]
		i = PARENT(i)
	A[i] = key 
```

## 6.5-7

**Show how to implement a first-in, first-out queue with a priority queue. Show how to implement a stack with a priority queue. (Queues and stacks are defined in Section 10.1.)**

**Answer：**
* **队列：** 将新插入的值赋予更低的优先级
* **栈：** 将新插入的值赋予更高的优先级

## 6.5-8

**The operation HEAP-DELETE(A, i) deletes the item in node i from heap A. Give an implementation of HEAP-DELETE that runs in O(lg n) time for an n-element max-heap.**

**Answer：**

* 当 **A[A.heap-size] == A[i]** 时，时间复杂度为 O(1)
* 当 **A[A.heap-size] > A[i]** 时，时间复杂度为 O(lgn)
* 当 **A[A.heap-size] < A[i]** 时，时间复杂度为 O(lgn)，例：

```
      10
    /    \
   5      9
  / \    / \
 2   3  7   8
```

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/code/s6.5-8.kt

