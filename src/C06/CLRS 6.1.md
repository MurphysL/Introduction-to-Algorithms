# CLRS 6.1

## 6.1-1
**What are the minimum and maximum numbers of elements in a heap of height h?**

**Answer：**

maximum :
![](http://latex.codecogs.com/gif.latex?2^{h+1}%20-%201)

minimum :
![](http://latex.codecogs.com/gif.latex?2^h)


## 6.1-2

**Show that an n-element heap has height ⌞lg n⌟**

**Answer：**

![](http://latex.codecogs.com/gif.latex?2^{h%20+1}-1\ge%20x\ge2^h=%3E%20lgx%20\ge%20h%20\ge%20lg\(x+1\)-1)

## 6.1-3

**Show that in any subtree of a max-heap, the root of the subtree contains the largest value occurring anywhere in that subtree.**

**Answer：**

最大堆性质：
> A[ PARENT(i) ] >= A[i]

## 6.1-4

**Where in a max-heap might the smallest element reside, assuming that all elements are distinct?**

**Answer：**

叶结点

## 6.1-5

**Is an array that is in sorted order a min-heap?**

**Answer：**

不一定，递减数组不是

## 6.1-6

**Is the sequence [23, 17, 14, 6, 13, 10, 1, 5, 7, 12] a max-heap?**

**Answer：**

不是
![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C06/img/s6.1-6.png)

## 6.1-7

**Show that, with the array representation for storing an n-element heap, the leaves are the nodes indexed by ⌞n/2⌟ + 1, ⌞n/2⌟ + 2, ... , n.**

**Answer：**

最后一个叶结点序号为 n ， 因此其父结点序号为 n/2，其之后的节点均为子结点

