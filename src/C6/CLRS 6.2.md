# CLRS 6.2

## 6.2-1
**Using Figure 6.2 as a model, illustrate the operation of MAX-HEAPIFY(A, 3) on the array A = 27,17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0.**

**Answer：**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/img/s6.2-1.1.png)
![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/img/s6.2-1.2.png)
![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C6/img/s6.2-1.3.png)

## 6.2-2

**Starting with the procedure MAX-HEAPIFY, write pseudocode for the procedure MIN- HEAPIFY(A, i), which performs the corresponding manipulation on a min-heap. How does the running time of MIN-HEAPIFY compare to that of MAX-HEAPIFY?**

**Answer：**
```
MIN-HEAPIFY(A，i)：
	l = LEFT(i)
	r = LEFT(i)
	minimum = i
	if l <= A.heap-size and A[l] < A[i]
		minimum = l
	if r <= A.heap-size and A[r] < A[i]
		minimum = r
	if minimum != i
		exchange A[i] with A[minimum ]
		MIN-HEAPIFY(A, minimum)
```
时间复杂度均为 O(h)

## 6.2-3

**What is the effect of calling MAX-HEAPIFY(A, i) when the element A[i] is larger than its children?**

**Answer：**

并没有任何影响

## 6.2-4

**What is the effect of calling MAX-HEAPIFY(A, i) for i > heap-size[A]/2?**

**Answer：**

此情况下均为叶子结点，并没有任何影响

## 6.2-5
**The code for MAX-HEAPIFY is quite efficient in terms of constant factors, except possibly for the recursive call in line 10, which might cause some compilers to produce inefficient code. Write an efficient MAX-HEAPIFY that uses an iterative control construct (a loop) instead of recursion.**

**Answer：**
```
MAX_HEAPIFY(A, i):
	while true :
		largest = i
		left = i * 2
		right = i * 2 + 1
		if left <= A.size && A[largest] < A[left]:
			largest = left
		if right <= A.size && A[largest] < A[right]:
			largest = right
		if i != largest
			exchange i with largest
			i = largest
		else
			break
```

## 6.2-6

**Show that the worst-case running time of MAX-HEAPIFY on a heap of size n is Ω(lg n). (Hint: For a heap with n nodes, give node values that cause MAX-HEAPIFY to be called recursively at every node on a path from the root down to a leaf.)**

**Answer：**

最坏情况，MAX-HEAPIFY 会从根节点递归调用到叶结点，因为 h=lgn 所以最坏运行情况为 Ω(lgn)

