# CLRS 2.2

## 2.2-1

**Express the function **
![](http://latex.codecogs.com/gif.latex?n^3/1000 - 100n^2-100n+3)
**in terms of Θ-notation.**

**Answer：**

Θ(n^3)

## 2.2-2

**Consider sorting n numbers stored in array A by first finding the smallest element of A and exchanging it with the element in A[1]. Then find the second smallest element of A, and exchange it with A[2]. Continue in this manner for the first n - 1 elements of A. Write pseudocode for this algorithm, which is known as selection sort. What loop invariant does this algorithm maintain? Why does it need to run for only the first n - 1 elements, rather than for all n elements? Give the best-case and worst-case running times of selection sort in Θ- notation.**

**Answer：**

```
SELECTION_SORT(A):
	for i = 0 to A.length-1:
		min = i
		for j = i+1 to A.length:
		if A[min] > A[j]:
			min = j
		exchange(arr[i], arr[max])
```

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C02/code/s2.2-2.py

best-case and worst-case running times both are **Θ(n^2)**

## 2.2-3

**Consider linear search again (see Exercise 2.1-3). How many elements of the input sequence need to be checked on the average, assuming that the element being searched for is equally likely to be any element in the array? How about in the worst case? What are the average-case and worst-case running times of linear search in Θ-notation? Justify your answers.**

**Answer：**

average elements which need to be checked is 1/n * (1 + 2 + ... +n) = **(n+1)/2**. average running time : **Θ(n)**

worst running time : **Θ(n)**


## 2.2-4

**How can we modify almost any algorithm to have a good best-case running time?**