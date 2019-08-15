# 1055 The World's Richest (25 分)

Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of *N* people, you must find the *M* richest people in a given range of their ages.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: *N* (≤105) - the total number of people, and *K* (≤103) - the number of queries. Then *N*lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [−106,106]) of a person. Finally there are *K*lines of queries, each contains three positive integers: *M* (≤100) - the maximum number of outputs, and [`Amin`, `Amax`] which are the range of ages. All the numbers in a line are separated by a space.

### Output Specification:

For each query, first print in a line `Case #X:` where `X` is the query number starting from 1. Then output the *M* richest people with their ages in the range [`Amin`, `Amax`]. Each person's information occupies a line, in the format

```
Name Age Net_Worth
```

The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output `None`.

### Sample Input:

```in
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
```

### Sample Output:

```out
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
```



### Analysis

##### 题目大意

给你一n个人的信息，包含姓名、年龄、资产。有k个查询，每次查询输出年龄在[min, max]的资产从高到低前m个人。若资产相同，按照年龄排序，若年龄也相同，按照名字字母表序排列。

##### 解析

定义结构体，输入，按照先资产再年龄再姓名排好序。然后每次查询输出前m个符合条件的即可。



> 原以为在数据量很大的情况下这样的解法不行，之前尝试先按照年龄数组将同一年龄的放在一个链表中的方法，测试点3过不去，最后使用暴力的方法发现还是可以的。说明PAT有时候可以先暴力试一试。

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

struct Node {
	string name;
	int age;
	int asset;
};

int n, m, num, l, h;
vector<Node> list;

bool cmp (Node a, Node b) {
	if(a.asset != b.asset)
		return a.asset > b.asset;
	if(a.age != b.age)
		return a.age < b.age;
	return a.name < b.name;
}

void solve() {
	int cnt = 0;
	for(int i = 0; cnt < num && i < list.size(); i++) {
		if (list[i].age >= l && list[i].age <= h) {
			cnt++;
			printf("%s %d %d\n", list[i].name.c_str(), list[i].age, list[i].asset);
		}
	}
	if(cnt == 0) {
		printf("None\n");
	}
}

int main () {
	
	scanf("%d%d", &n, &m);
	Node nd;
	nd.name.resize(8);
	int max_page = 100;

	for(int i = 0; i < n; i++) {
		scanf("%s%d%d", &nd.name[0], &nd.age, &nd.asset);

		list.push_back(nd);
	}

	sort(list.begin(), list.end(), cmp);

	for(int i = 0; i < m; i++) {
		printf("Case #%d:\n", i+1);
		scanf("%d%d%d", &num, &l, &h);
		solve();
	}
	return 0;
}
```

