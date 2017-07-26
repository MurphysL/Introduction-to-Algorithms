# CLRS 10.2

## 10.2-1
**Can the dynamic-set operation INSERT be implemented on a singly linked list in O(1) time? How about DELETE?**

**Answer：**

头插法插入时间复杂度为 O(1) 。删除运行时间为 O(1)，但查找指定删除的元素时间复杂度为 O(n)。


## 10.2-2
**Implement a stack using a singly linked list L. The operations PUSH and POP should still take O(1) time.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/s10.2-2.kt

头插，并从链表头 POP

## 10.2-3
**Implement a queue by a singly linked list L. The operations ENQUEUE and DEQUEUE should still take O(1) time.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/s10.2-3.kt

尾插，并从链表头 DEQUEUE

## 10.2-4

**As written, each loop iteration in the LIST-SEARC′ procedure requires two tests: one for x ≠ nil[L] and one for key[x] ≠ k. Show how to eliminate the test for x ≠ nil[L] in each iteration.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/s10.2-4.kt

将要查找的值存放于哨兵中，判断返回的节点是否为哨兵。

## 10.2-5

**Implement the dictionary operations INSERT, DELETE, and SEARCH using singly linked, circular lists. What are the running times of your procedures?**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/s10.2-5.kt

## 10.2-6

**Show how to implement a queue using two stacks. Analyze the running time of the queue operations.**

**Answer：**

S1，S2 使用链表实现，改变链表头尾指针即可。

## 10.2-7

**Give a Θ(n)-time nonrecursive procedure that reverses a singly linked list of n elements. The procedure should use no more than constant storage beyond that needed for the list itself.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/s10.2-7.kt


## 10.2-8

**Explain how to implement doubly linked lists using only one pointer value np[x] per item instead of the usual two (next and prev). Assume that all pointer values can be interpreted as k-bit integers, and define np[x] to be np[x] = next[x] XOR prev[x], the k-bit "exclusive-or" of next[x] and prev[x]. (The value NIL is represented by 0.) Be sure to describe what information is needed to access the head of the list. Show how to implement the SEARCH, INSERT, and DELETE operations on such a list. Also show how to reverse such a list in O(1) time.**

**Answer：**





