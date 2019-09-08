# 1079 Total Sales of Supply Chain (25 分)

A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price *P* and sell or distribute them in a price that is *r*% higher than *P*. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the total sales from all the retailers.

### Input Specification:

Each input file contains one test case. For each case, the first line contains three positive numbers: *N* (≤105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to *N*−1, and the root supplier's ID is 0); *P*, the unit price given by the root supplier; and *r*, the percentage rate of price increment for each distributor or retailer. Then *N* lines follow, each describes a distributor or retailer in the following format:

*K**i* ID[1] ID[2] ... ID[*K**i*]

where in the *i*-th line, *K**i* is the total number of distributors or retailers who receive products from supplier *i*, and is then followed by the ID's of these distributors or retailers. *K**j* being 0 means that the *j*-th member is a retailer, then instead the total amount of the product will be given after *K**j*. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 1010.

### Sample Input:

```in
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
```

### Sample Output:

```out
42.4
```

### Analysis

##### 题目大意

给你一个经销商与零售商的树，共n个节点，root假设为节点0，root节点的价格为p，每经过一层就加价r%，问零售商的销售总额。对于每个节点以及子节点的输入格式为:

```
Ki a[1] a[2] ...
```

其中第几行就是第几个节点的子节点，ki为第i个节点的子节点数量，后面跟着ki个子节点a[1]...

若ki为0，说明该节点为零售商，后面跟着一个数字，为该经销商持有的商品数量。

##### 解析

树的层序遍历，即BFS。令数组data[i]表示节点i所持有的商品数量与其价格，零售商之外的节点的商品数量均为0。对树进行广度优先遍历，每次压入队列时先更新该节点的价格。



最后将data循环计算商品数量*价格之和即可。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>


using namespace std;

struct Node {
	double price;
	int num;
};

int n;
double p, r;
vector<vector<int>> tree;

Node data[100010];

double bfs() {
	int tmp;
	double res = 0.0;
	queue<int> q;

	q.push(0);

	while(!q.empty()) {
		tmp = q.front();
		q.pop();

		for(int i = 0; i < tree[tmp].size(); i++) {
			data[tree[tmp][i]].price = data[tmp].price * (1.0 + r/100);

			q.push(tree[tmp][i]);
		}
	}

	for(int i = 0; i < n; i++) {
		res += data[i].num * data[i].price;
	}

	return res;
}

int main () {
	int tmp, t;
	Node nd;
	nd.num = 0;

	scanf("%d%lf%lf", &n, &p, &r);

	tree.resize(n);
	data[0].price = p;
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			scanf("%d", &tmp);
			data[i].num = tmp;
		} else {
			while(tmp--) {
				scanf("%d", &t);
				
				tree[i].push_back(t);
			}
		}
	}

	double res = bfs();

	printf("%.1f", res);

	return 0;
}
```

