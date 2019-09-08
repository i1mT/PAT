# 1063 Set Similarity (25 分)

Given two sets of integers, the similarity of the sets is defined to be *N**c*/*N**t*×100%, where *N**c*is the number of distinct common numbers shared by the two sets, and *N**t* is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

### Input Specification:

Each input file contains one test case. Each case first gives a positive integer *N* (≤50) which is the total number of sets. Then *N* lines follow, each gives a set with a positive *M* (≤104) and followed by *M* integers in the range [0,109]. After the input of sets, a positive integer *K*(≤2000) is given, followed by *K* lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to *N*). All the numbers in a line are separated by a space.

### Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

### Sample Input:

```in
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
```

### Sample Output:

```out
50.0%
33.3%
```

### Analysis

##### 题目大意

给你共N个set，询问K对set的相似值。两个set的相似值是这样定义的：

	1. 相似值 = Nc/Nt
 	2. Nc为这两个set公共的但两两不同数个数。([1,2]为两个不同数，[1,2,2] 还是两个不同数。)
 	3. Nt位两个序列总共的但两两不同数个数。([134]与[1 2 3 3]的公共数字不同数是1 2 3 4共四个。[134]与[1 2 3 3]的公共不同数为1 3 两个)

##### 解析

使用map/set存储，可以直接得到每个set的不同数个数。对于一对查询a，b，设Nc = q。则相似值等于

	> Nc / (a.size() + b.size() - Nc)

如此，只需求得两个set公共两两不同个数即可。使用a与b较短的循环询问另一个是否存在即可。

详见代码。

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

using namespace std;

vector<map<int, int>> data;
vector<pair<int, int>> query;
int n, m, k;

void cal (int a, int b) {
	map<int, int> ma = data[a-1];
	map<int, int> mb = data[b-1];
	float sum = ma.size() + mb.size();
	float comSum = 0;

	if (ma.size() > mb.size()) swap(ma, mb);

	map<int, int>::iterator it = ma.begin();
	for(;it != ma.end(); it++) {
		int a = it->first;
		if (mb.find(a) != mb.end()) comSum++;
	}

	printf("%.1f%%\n", (comSum*100.0)/(sum - comSum));
}

int main () {
	int tmp, f, s;
	map<int, int> mp;
	pair<int, int> pr;

	scanf("%d", &n);

	
	data.assign(n, mp);

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for(int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			data[i][tmp] = 1;
		}
	}

	scanf("%d", &k);
	
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &f, &s);
		cal(f, s);
	}

	return 0;
}
```

