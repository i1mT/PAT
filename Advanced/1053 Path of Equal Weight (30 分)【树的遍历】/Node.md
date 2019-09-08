# 1053 Path of Equal Weight **(30** 分)

Given a non-empty tree with root *R*, and with weight *W**i* assigned to each tree node *T**i*. The **weight of a path from R to L** is defined to be the sum of the weights of all the nodes along the path from *R* to any leaf node *L*.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in the following figure: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in the figure.

![img](http://upy.iimt.me/2019/08/14/upload_c86909e08525b63f009f030e6f460646.jpg!/watermark/text/aWltdC5tZQ==/font/helvetica/align/southeast//color/ffffff/opacity/80/size/28/border/33333333)

### Input Specification:

Each input file contains one test case. Each case starts with a line containing 0<*N*≤100, the number of nodes in a tree, *M* (<*N*), the number of non-leaf nodes, and 0<*S*<230, the given weight number. The next line contains *N* positive numbers where *W**i* (<1000) corresponds to the tree node *T**i*. Then *M* lines follow, each in the format:

```
ID K ID[1] ID[2] ... ID[K]
```

where `ID` is a two-digit number representing a given non-leaf node, `K` is the number of its children, followed by a sequence of two-digit `ID`'s of its children. For the sake of simplicity, let us fix the root ID to be `00`.

### Output Specification:

For each test case, print all the paths with weight S in **non-increasing** order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

Note: sequence {*A*1,*A*2,⋯,*A**n*} is said to be **greater than** sequence {*B*1,*B*2,⋯,*B**m*} if there exists 1≤*k*<*m**i**n*{*n*,*m*} such that *A**i*=*B**i* for *i*=1,⋯,*k*, and *A**k*+1>*B**k*+1.

### Sample Input:

```in
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
```

### Sample Output:

```out
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
```

### Special thanks to Zhang Yuan and Yang Han for their contribution to the judge's data.

### Analysis

##### 题目大意

给你一个树，如上图所示。每个树Node的上一半是它的ID，下一半是它的weight。给定weight为s，求所有从根节点出发的路径权重之和为s的路径。根节点固定为00。

【注意】：路径要以非叶子节点为结尾。

##### 解法

使用临接链表来存储树。数组存储weight。定义二维向量存储结果。

显然是BFS遍历树。不过BFS函数需要更改一下。需要传入参数root，与target，意为从root开始，寻找权重和为target的路径。定义sum为遍历过程中的权重和。定义遍历过程中的路径path向量。对于每次的bfs：

	1. sum增加root节点的权重。
 	2. root节点的权重push入path中。
 	3. 如果sum等于s，且当前root是非叶子节点。那么将path保存到res中，删除path最后一位，sum减去root的权重返回。
 	4. 如果sum不等于s，而且还是叶子节点。path删除最后一位，sum减去root的权重。返回。
 	5. 循环root节点的所有子节点，做bfs(tree[root, i], target - sum)。
 	6. path删除最后一位，sum减去root的权重。返回。



之后对res排序即可。



### Code

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>

using namespace std;

int n, m, s;
vector< vector<int> > tree;
vector<int> weight;
vector< vector<int> > res;
vector<int> path;
int sum = 0, tmp;

void bfs(int r, int target) {
	sum += weight[r];
	path.push_back(weight[r]);

	if(sum == s) {
		if(tree[r].size() == 0)
			res.push_back(path);
		path.pop_back();
		sum -= weight[r];
		return;
	}

	if(tree[r].size() == 0) {
		path.pop_back();
		sum -= weight[r];
		return;
	}
	
	for(int i = 0; i < tree[r].size(); i++) {
		bfs(tree[r][i], target - sum);
	}

	path.pop_back();
	sum -= weight[r];
	return;
}

bool cmp(vector<int> a, vector<int> b) {
	int n = min(a.size(), b.size());
	int i = 0;
	while(i < n) {
		if (a[i] != b[i])
			return a[i] > b[i];
		i++;
	}

	return a.size() < b.size();
}

int main () {
	
	int index, num;

	scanf("%d %d %d", &n, &m, &s);

	tree.resize(n);
	weight.resize(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}

	for(int i = 0; i < m; i++) {
		scanf("%d %d", &index, &num);
		tree[index].resize(num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &tree[index][j]);
		}
	}

	bfs(0, s);

	sort(res.begin(), res.end(), cmp);

	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			if(j != 0) printf(" ");
			printf("%d", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}
```

