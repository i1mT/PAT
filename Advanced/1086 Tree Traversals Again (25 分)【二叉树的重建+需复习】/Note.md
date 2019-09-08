# 1086 Tree Traversals Again (25 分)

An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.

![img](https://images.ptausercontent.com/30)
Figure 1

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer *N*(≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to *N*). Then 2*N* lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

### Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

### Sample Input:

```in
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
```

### Sample Output:

```out
3 4 2 6 5 1
```

### Analysis

##### 题目大意

对一个有序的二叉树进行中序遍历时，可以使用非递归遍历。这时需要用到栈，现在给你一个压栈与出栈序列，让你将这个二叉树重建起来，并输出其后序遍历序列。

##### 解析

数字先后压入的序列是二叉树的先序序列，数字出栈的序列是中序序列。根据两个序列就可以重建二叉树。

可以看我之前的这篇文章：[重建二叉树](http://www.iimt.me/article/52)。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <sstream>

using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;

	Node () {
		lchild = NULL;
		rchild = NULL;
	}
};

int n, cnt = 0, cur = 0;
vector<int> pre, mid;
stack<int> stk;

Node *root = new Node;

int findRootIndex(int num) {
	for(int i = 0; i < n; i++) {
		if (mid[i] == num) return i;
	}

	return -1;
}

// 使用先序序列与中序序列重建二叉树到根root上
Node* createTree(int left, int right) {
	if (left > right) return NULL;

	int rt = pre[cur];
	cur++;

	int rtIndex = findRootIndex(rt);

	Node *t = new Node;
	t->data = rt;

	if(left != right) {
		t->lchild = createTree(left, rtIndex - 1);
		t->rchild = createTree(rtIndex+1, right);
	}

	return t;
}

void postPrint(Node *r) {
	if (r == NULL) return;

	postPrint(r->lchild);

	postPrint(r->rchild);

	if (cnt != 0) printf(" ");
	if (cnt == 0) cnt = 1;

	printf("%d", r->data);
}

int main () {
	scanf("%d", &n);

	string s;
	int tmp;
	ios::sync_with_stdio(false);

	for(int i = 0; i < n*2; i++) {
		cin >> s;
		if (s[1] == 'u') {
			cin >> tmp;
			// push
			stk.push(tmp);
			pre.push_back(tmp);
		} else {
			// pop
			mid.push_back(stk.top());
			stk.pop();
		}
	}

	root = createTree(0, n-1);
	postPrint(root);
	return 0;
}
```

