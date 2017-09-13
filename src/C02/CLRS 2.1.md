# CLRS 2.1

## 2.1-1 

**Using Figure 2.2 as a model, illustrate the operation of INSERTION-SORT on the array A = [31, 41, 59, 26, 41, 58].**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C02/code/s2.1-1.py


## 2.1-2

**Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of nondecreasing order.**

**Answer：**

```
DES-INSERTION-SORT(A):
	for j = 2 to A.length:
		key = A[j]
		i = j - 1
		while i > 0 and A[i] > key:
			A[i+1] = A[i]
			i = i - 1
		A[i + 1] = key
```

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C02/code/s2.1-2.py


## 2.1-3

**Consider the searching problem:**

**Input: A sequence of n numbers A = [a1, a2, . . . , an] and a value v.**
**Output: An index i such that v = A[i] or the special value NIL if v does not appear in A.**

**Write pseudocode for linear search, which scans through the sequence, looking for v. Using a loop invariant, prove that your algorithm is correct. Make sure that your loop invariant fulfills the three necessary properties.**

**Answer：**

```
SEARCH(A, v):
	for i = 1 to A.length:
		if A[i] == v:
			return i
	return nil
```

## 2.1-4

**Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in an (n + 1)-element array C. State the problem formally and write pseudocode for adding the two integers.**

**Answer：**

```
ADD(A, B, C):
carry = 0
for i = A.length to 1
    C[i+1] = (A[i] + B[i] + carry) % 2
    carry = (A[i] + B[i] + carry) / 2
C[i-1] = carry
```
