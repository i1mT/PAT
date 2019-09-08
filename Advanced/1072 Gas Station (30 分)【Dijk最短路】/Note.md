# 1072 Gas Station (30 分)

A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: *N* (≤103), the total number of houses; *M* (≤10), the total number of the candidate locations for the gas stations; *K* (≤104), the number of roads connecting the houses and the gas stations; and *D**S*, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to *N*, and all the candidate locations are numbered from `G`1 to `G`*M*.

Then *K* lines follow, each describes a road in the format

```
P1 P2 Dist
```

where `P1` and `P2` are the two ends of a road which can be either house numbers or gas station numbers, and `Dist` is the integer length of the road.

### Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output `No Solution`.

### Sample Input 1:

```in
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
```

### Sample Output 1:

```out
G1
2.0 3.3
```

### Sample Input 2:

```in
2 1 2 10
1 G1 9
2 G1 20
```

### Sample Output 2:

```out
No Solution
```

### Analysis

##### 题目大意

给你一个图，其中有n个房子和m个加油站的候选点，加油站的服务距离为k。求最优的加油站设置点。

其中最优定义是这样的：

	1. 距离加油站房子最近的距离越大越好。(题目第一句话`as far away as possible`，很容易忽视)
 	2. 条件1相同的，取到加油站平均距离最小的。
 	3. 条件2相同的，取序号大的

其中图的弧是这样给出的：

`a b d`，意为从a到b的距离为d，若a，b为房子，则为序号（1-n）；若为加油站候选点，则为序号（G1-Gm）。

##### 解析

首先要考虑图如何建，先不考虑房子，是`n*n`的图。再加上m个加油站，是`(n+m)*(n+m)`的图。

其次要输入给出的弧，需要自己解析是数字还是`G+数字`,如果是`G+数字`，那么序号就是`n+数字`。

之后以每个加油站点出发，做`Dijkstra`之后讨论得到的d数组，找出最小值与平均值，并且若有房子到加油站距离大于服务距离k了，那么这个加油站不可用。

之后按照排序条件输出最优即可。

注意使用double。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int maxn = 1020;
const int INF = 9999999;

int n, m, k, d;
int grid[maxn][maxn];
int visit[maxn], dist[maxn];

struct Ans {
	double ave;
	double min;
	int index;
}ans[15];

int getInt (string s) {
	int res = 0, duct = 1;

	if (s[0] == 'G') {
		res += n;
		s= s.substr(1);
	}

	for(int i = s.size() - 1; i >= 0; i--) {
		res += int(s[i] - '0') * duct;
		duct*=10;
	}

	return res;
}

void input() {
	string s, e;
	int _d, x, y;
	ios::sync_with_stdio(false);
	cin >> s >> e >> _d;
	
	x = getInt(s), y = getInt(e);

	grid[x][y] = _d;
	grid[y][x] = _d;
}

void Dijkstra (int s) {
	memset(visit, 0, sizeof(visit));
	fill(dist, dist+maxn, INF);

	dist[s] = 0;

	while (1) {
		int v = -1;
		for(int u = 1; u <= n+m; u++) {
			if((v==-1 || dist[u] < dist[v]) && !visit[u]) {
				v = u;
			}
		}

		if(v < 0) break;
		visit[v] = 1;

		for(int i = 1; i <= n+m; i++) {
			dist[i] = min(dist[i], dist[v] + grid[v][i]);
		}
	}
}
 
bool cmp(Ans a, Ans b) {
	if (a.min != b.min) return a.min > b.min;
	if (a.ave != b.ave) return a.ave < b.ave;
	return a.index < b.index;
}

int main () {

	fill(grid[0], grid[0]+(maxn)*(maxn), INF);
	

	scanf("%d%d%d%d", &n, &m, &k, &d);

	for(int i = 0; i < k; i++) {
		input();
	}
	int cnt = 0, hasAns = 0;
	for (int j = 1; j <= m; j++) {
		

		Dijkstra(n+j);

		int flag = 1, minn = INF;
		double sum = 0.0;
		for(int i = 1; i <= n; i++) {
			// 找出该站到各点的距离
			if(dist[i] > d) {
				flag = 0;
				break;
			}
			minn = min(minn, dist[i]);
			sum += dist[i];
		}

		if(flag) {
			ans[cnt].ave = double(sum/n);
			ans[cnt].min = minn;
			ans[cnt].index = j;
			cnt++;
			hasAns = 1;
		}
	}

	

	if (hasAns) {
		sort(ans, ans+cnt, cmp);
		printf("G%d\n%.1f %.1f\n", ans[0].index, ans[0].min, ans[0].ave);
	} else
		printf("No Solution\n");

	return 0;
}
```

