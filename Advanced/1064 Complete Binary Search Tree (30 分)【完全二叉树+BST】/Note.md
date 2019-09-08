# 1064 Complete Binary Search Tree (30 分)

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
- Both the left and right subtrees must also be binary search trees.

A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer *N*(≤1000). Then *N* distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

### Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

### Sample Input:

```in
10
1 2 3 4 5 6 7 8 9 0
```

### Sample Output:

```out
6 3 8 1 5 7 9 0 2 4
```

### Analysis

##### 题目大意

给你一个序列，将它构建为完全二叉搜索树，输出此树层次遍历的结果。

##### 解析

完全二叉树可以用根节点在下标1的顺序表存储，对于每个下标为x的节点，左孩子节点下标为`2*x`，,右孩子下标为`2*x+1`。而二叉搜索树的中序遍历为有序序列。将完全二叉树中序遍历，用排序过的序列一一赋值，即可得到完全二叉树数组。输出即可。

### Code

```
#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>

#define maxn 1010

using namespace std;

int n, idx = 0;
int cbt[maxn], num[maxn];


void inorder(int root) {
	if(root > n) return;

	inorder(root*2);
	cbt[root] = num[idx++];
	inorder(root*2+1);
}

int main () {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	inorder(1);

	for(int i = 1; i <= n; i++) {
		if(i!=1) printf(" ");
		printf("%d", cbt[i]);
	}

	return 0;
}
```

