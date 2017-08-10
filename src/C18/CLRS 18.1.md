# CLRS 18.1

## 18.1-1

**Why don't we allow a minimum degree of t = 1?**

**Answer：**

根据定义，除根结点外其余结点的关键字个数满足：

![](http://latex.codecogs.com/gif.latex?2t-1%20\ge%20x\ge%20t-1)

因此当最小度数为 1 时，结点关键字个数最少为 0，子结点最少个数为 1，显然是不合理的。

## 18.1-2

**For what values of t is the tree of Figure 18.1 a legal B-tree?**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C18/img/t18.1.jpg)

**Answer：**

跟据定义结点关键字个数需满足条件：
![](http://latex.codecogs.com/gif.latex?2%20\ge%20t-1)
![](http://latex.codecogs.com/gif.latex?2t-1%20\ge%203)

因此 t 可取 2 或 3。

## 18.1-3

**Show all legal B-trees of minimum degree 3 that represent {1, 2, 3, 4, 5}**

**Answer：**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C18/img/s18.1-3.png)

## 18.1-4

**As a function of the minimum degree t, what is the maximum number of keys that can be stored in a B-tree of height h?**

**Answer：**


