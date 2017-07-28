# CLRS 10.4

## 10.4.1
**Draw the binary tree rooted at index 6 that is represented by the following fields.**

|index|key|left|right|
|:---:|:---:|:---:|:---:|
|1|12|7|3|
|2|15|8|NIL|
|3|4|10|NIL|
|4|10|5|9|
|5|2|NIL|NIL|
|6|18|1|4|
|7|7|NIL|NIL|
|8|14|6|2|
|9|21|NIL|NIL|
|10|5|NIL|NIL|

**Answer：**

![](https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C10/img/s10.4-1.png)

## 10.4.2
**Write an O(n)-time recursive procedure that, given an n-node binary tree, prints out the key of each node in the tree.**

**Answer：**

中序遍历：
```
MID_ORDER(root):
	if root == NIL
		return
	MID_ORDER(root.left)
	PRINT root.value
	MID_ORDER(root.right)
```
前序遍历：
```
MID_ORDER(root):
	if root == NIL
		return
	PRINT root.value
	MID_ORDER(root.left)
	MID_ORDER(root.right)
```
后序遍历：
```
MID_ORDER(root):
	if root == NIL
		return
	MID_ORDER(root.left)
	MID_ORDER(root.right)
	PRINT root.value
```

## 10.4-3

**Write an O(n)-time nonrecursive procedure that, given an n-node binary tree, prints out the key of each node in the tree. Use a stack as an auxiliary data structure.**

**Answer：**

https://github.com/MurphysL/Introduction-to-Algorithms/blob/master/src/C10/code/s10.4-3.kt


## 10.4-4

**Write an O(n)-time procedure that prints all the keys of an arbitrary rooted tree with n nodes, where the tree is stored using the left-child, right-sibling representation.**

**Answer：**
```
PROCEDURE(root):
	if root == NIL
		return
	PRINT root.value
	PROCEDURE(root.child)
	PROCEDURE(root.sibling)
```

## 10.4-5
**Write an O(n)-time nonrecursive procedure that, given an n-node binary tree, prints out the key of each node. Use no more than constant extra space outside of the tree itself and do not modify the tree, even temporarily, during the procedure.**

**Answer：**
```

```

## 10.4-6
**The left-child, right-sibling representation of an arbitrary rooted tree uses three pointers in each node: left-child, right-sibling, and parent. From any node, its parent can be reached and identified in constant time and all its children can be reached and identified in time linear in the number of children. Show how to use only two pointers and one boolean value in each node so that the parent of a node or all of its children can be reached and identified in time linear in the number of children.**

**Answer：**
```

```




