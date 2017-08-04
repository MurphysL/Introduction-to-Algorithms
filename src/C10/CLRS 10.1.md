# CLRS 10.1
## 10.1-1


**Using Figure 10.1 as a model, illustrate the result of each operation in the sequence PUSH(S, 4), PUSH(S, 1), PUSH(S, 3), POP(S), PUSH(S, 8), and POP(S) on an initially C10.code.empty stack S stored in array S[1...6].**

**Answer：**

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 |


| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 | 1 |

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 | 1 | 3|

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 | 1 |

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 | 1| 8

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 | 1| 

## 10.1-2

**Explain how to implement two stacks in one array A[1...n] in such a way that neither stack overflows unless the total number of elements in both stacks together is n. The PUSH and POP operations should run in O(1) time.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C10/code/s10.1-2.kt

使用数组两端分别作为两个栈的起点，向中间扩展。

## 10.1-3


**Using Figure 10.2 as a model, illustrate the result of each operation in the sequence ENQUEUE(Q, 4), ENQUEUE(Q, 1), ENQUEUE(Q, 3), DEQUEUE(Q), ENQUEUE(Q, 8), and DEQUEUE(Q) on an initially C10.code.empty queue Q stored in array Q[1...6].**

**Answer：**

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 |

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 | 1

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 4 | 1 | 3|

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
|  | 1 |3

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
|  | 1| 3|8

| 1 | 2 | 3 | 4  | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|
|  | |3|8

## 10.1-4

**Rewrite ENQUEUE and DEQUEUE to detect underflow and overflow of a queue.**

**Answer：** 

ENQUEUE(Q, x)
```
if Q.head == Q.tail + 1
	error "overflow"
else
	...	
```
DEQUEUE(Q)
```
if Q.head == Q.tail
	error "underflow"
else
	...	
```
## 10.1-5

**Whereas a stack allows insertion and deletion of elements at only one end, and a queue allows insertion at one end and deletion at the other end, a deque (double-ended queue) allows insertion and deletion at both ends. Write four O(1)-time procedures to insert elements into and delete elements from both ends of a deque constructed from an array.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C10/code/s10.1-5.kt

## 10.1-6

**Show how to implement a queue using two stacks. Analyze the running time of the queue operations.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C10/code/s10.1-6.kt

> push：O(1)

> pop：O(n)

## 10.1-7

**Show how to implement a stack using two queues. Analyze the running time of the stack operations.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C10/code/s10.1-7.kt

> push：O(1)

> pop：O(n)




