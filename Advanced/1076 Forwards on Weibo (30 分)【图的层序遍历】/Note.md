# 1076 Forwards on Weibo (30 分)

Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only *L* levels of indirect followers are counted.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: *N* (≤1000), the number of users; and *L* (≤6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to *N*. Then *N* lines follow, each in the format:

```
M[i] user_list[i]
```

where `M[i]` (≤100) is the total number of people that `user[i]` follows; and `user_list[i]` is a list of the `M[i]` users that followed by `user[i]`. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive *K* is given, followed by *K* `UserID`'s for query.

### Output Specification:

For each `UserID`, you are supposed to print in one line the maximum potential amount of forwards this user can trigger, assuming that everyone who can view the initial post will forward it once, and that only *L* levels of indirect followers are counted.

### Sample Input:

```in
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
```

### Sample Output:

```out
4
5
```

### Analysis

##### 题目大意

有n个用户，现在给出每个用户的粉丝列表，假设粉丝看到每一条post都会转发。询问k个用户，在L层之内，最多有多少转发数。

##### 解析

BFS，记录k层共多少节点数。两个计数器一个res记录转发数，一个cnt记录当前层数。最后res减去1，也就是post者本人。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>

using namespace std;

int n, l, k;

vector<vector<int>> net;



void solve (int r) {
	queue<int> q, tmpq;
	vector<int> used(n+1, 0);
	int res = 0, tmp, cnt = 0;

	q.push(r);

	while(1) {
		if(cnt > l) break;
		tmp = q.front();
		q.pop();
		res++;
		used[tmp]=1;

		for(int i = 0; i < net[tmp].size(); i++) {
			if(!used[net[tmp][i]]) {
				tmpq.push(net[tmp][i]);
				used[net[tmp][i]] = 1;
			}
		}

		if (tmpq.empty() && q.empty()) break;

		if(q.empty() && !tmpq.empty()) {
			cnt++;
			while(!tmpq.empty()) {
				q.push(tmpq.front());
				tmpq.pop();
			}
		}

	}

	printf("%d\n", res-1);
}

int main () {
	scanf("%d%d", &n, &l);
	net.resize(n+1);
	int cnt, tmp;

	for(int i = 1; i <= n; i++) {
		scanf("%d", &cnt);
		for(int j = 0; j < cnt; j++) {
			scanf("%d", &tmp);
			net[tmp].push_back(i);
		}
	}

	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &tmp);
		solve(tmp);
	}

	return 0;
}
```

