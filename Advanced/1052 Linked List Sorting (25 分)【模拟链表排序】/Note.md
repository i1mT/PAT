# **1052** **Linked List Sorting** **(25** 分)

A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer `key` and a `Next` pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive *N* (<105) and an address of the head node, where *N* is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by −1.

Then *N* lines follow, each describes a node in the format:

```
Address Key Next
```

where `Address` is the address of the node in memory, `Key` is an integer in [−105,105], and `Next` is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

### Output Specification:

For each test case, the output format is the same as that of the input, where *N* is the total number of nodes in the list and all the nodes must be sorted order.

### Sample Input:

```in
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
```

### Sample Output:

```out
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
```

### Analysis

##### 题目大意

给你一堆链表的Node，每个Node包含所在地址add，存储的key，后继Node的地址。然后告诉你链表表头所在地址，让你将链表按key升序排列后输出。



##### 解法

>  这里借鉴的是柳婼的思路。

​	

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node {
	int add;
	int key;
	int next;
	bool flag;
};

vector<int> ll;
vector<Node> list;
vector<Node> docker(100000);

bool cmp(Node a, Node b) {
	return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}

bool cmp1(int a, int b) {
	return docker[a].key < docker[b].key;
}


int main () {
	int n, head, cnt = 0;
	Node nd;

	scanf("%d%d", &n, &head);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &nd.add, &nd.key, &nd.next);
		nd.flag = false;
		docker[nd.add] = nd;
	}

	// 记录表
	for(int i = head; i != -1; i = docker[i].next) {
		docker[i].flag = true;
		cnt++;
	}

	if(cnt == 0) {
		printf("0 -1");
		return 0;
	}

	sort(docker.begin(), docker.end(), cmp);

	printf("%d", cnt);
	for(int i = 0; i < cnt; i++) {
		printf(" %05d\n%05d %d", docker[i].add, docker[i].add, docker[i].key);

		if(i == cnt-1) {
			printf(" -1");
		}
	}

	return 0;
}
```

