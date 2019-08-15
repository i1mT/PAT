#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

int N, M, K;
vector<int> checkList;
vector< vector<int> > map;
vector<int> visited;

void dfs(int start) {
	visited[start] = 1;

	for (int i = 1; i <= N; i++) {
		if (map[i][start] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}

int kosaraju(int cid, vector< vector<int> > amap) {
	if (cid > N || cid < 0) return 0;
	int num = 0;

	// kosaraju
	int v;
	visited[cid] = 1; // 这个问题中，需要把这个点先挖掉 
	while (true) {
		// 寻找一个没有使用过的点
		v = -1;

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				v = i;
				break;
			}
		}
		if (v == -1) break;

		dfs(v);
		num++;
	}

	return num - 1;
}

int main() {
	checkList.assign(1001, 0);
	map.assign(1001, checkList);

	scanf("%d%d%d", &N, &M, &K);

	int from, to;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &from, &to);

		map[from][to] = 1;
		map[to][from] = 1;
	}

	int tmp;
	for (int i = 0; i < K; ++i) {
		scanf("%d", &tmp);

		visited.resize(1001);
		visited.assign(1001, 0);
		printf("%d\n", kosaraju(tmp, map));
	}
	return 0;
}

