# 1074 Reversing Linked List (25 分)

Given a constant *K* and a singly linked list *L*, you are supposed to reverse the links of every *K* elements on *L*. For example, given *L* being 1→2→3→4→5→6, if *K*=3, then you must output 3→2→1→6→5→4; if *K*=4, you must output 4→3→2→1→5→6.

### Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive *N* (≤105) which is the total number of nodes, and a positive *K* (≤*N*) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then *N* lines follow, each describes a node in the format:

```
Address Data Next
```

where `Address` is the position of the node, `Data` is an integer, and `Next` is the position of the next node.

### Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

### Sample Input:

```in
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
```

### Sample Output:

```out
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```

### Analysis

##### 题目大意

给你一个链表，与常熟k，要求按照k个一组逆序链表。

##### 解析

输入之后自己重建链表，取出不在链上的节点。之后k个一组逆序即可。逆序函数不要手写，使用reverse即可。



### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

struct Node {
	int id;
	int data;
	int next;
};


Node list[100010];
vector<Node> llist;
int head, n, k;

int main () {
	scanf("%d%d%d", &head, &n, &k);

	Node nd;
	int tmp;

	if(n == 0) return 0;

	for(int j = 0; j < n; j++) {
		scanf("%d%d%d", &tmp, &nd.data, &nd.next);
		nd.id = tmp;
		list[tmp] = nd;
	}

	int p = head;

	while(p >= 0) {
		llist.push_back(list[p]);

		p = list[p].next;
	}

	int cnt = llist.size()/k;

	for(int i = 0; i < cnt; i++) {
		reverse(llist.begin() + i*k, llist.begin()+i*k+k );
	}

	for (int i = 0; i < llist.size(); i++) {
		if(i != 0)
			printf("%05d\n", llist[i].id);

		printf("%05d %d ", llist[i].id, llist[i].data);

		if(i == llist.size() - 1) printf("-1\n");
	}
	return 0;
}
```

