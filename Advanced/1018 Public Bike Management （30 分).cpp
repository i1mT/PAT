#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

#define INF 99999

vector< vector<int> > grid;
vector< vector<int> > pre;
vector <int> capacity;
vector <int> visit;
vector <int> dist;
vector <int> path;
vector <int> temppath;
int C, N, S, M, needmin, backmin, PERFECT;


void input() {
	vector <int> tmp;
	scanf("%d%d%d%d", &C, &N, &S, &M);
	pre.assign(N + 1, tmp);
	capacity.assign(N + 1, 0);
	tmp.assign(N + 1, INF);
	grid.assign(N + 1, tmp);
	visit.assign(N + 1, 0);
	dist.assign(N + 1, INF);
	PERFECT = C / 2;
	needmin = INF, backmin = INF;

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &capacity[i]);
		capacity[i] -= PERFECT;
	}
	int tmpx, tmpy, cost;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &tmpx, &tmpy, &cost);

		grid[tmpx][tmpy] = cost;
		grid[tmpy][tmpx] = cost;
	}
}

void dfs(int v) {
	temppath.push_back(v);
	if (v == 0) {
		int need = 0, back = 0, id, weight, _weight, tmp;
		for (int i = temppath.size() - 1; i >= 0; i--) {
			id = temppath[i];
			if (capacity[id] > 0) {
				// ÓÐÊ£ÏÂµÄ
				back += capacity[id];
			}
			else {
				if (back > -capacity[id]) {
					back += capacity[id];
				} else {
					need += (0-capacity[id]) - back;
					back = 0;
				}
			}
		}
		if (need < needmin) {
			needmin = need;
			backmin = back;
			path = temppath;
		} else if (need == needmin && back < backmin) {
			backmin = back;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}


void solve() {
	int v;
	dist[0] = 0;

	while (1) {
		v = -1;
		for (int i = 0; i < N + 1; i++) {
			if ((v < 0 || dist[v] > dist[i]) && !visit[i])
				v = i;
		}

		if (v < 0) break;
		visit[v] = 1;
		for (int i = 0; i < N + 1; i++) {
			if (i == v) continue;
			if (dist[i] > dist[v] + grid[v][i]) {
				dist[i] = dist[v] + grid[v][i];
				pre[i].clear();
				pre[i].push_back(v);
			}
			else if (dist[i] == dist[v] + grid[v][i]) {
				pre[i].push_back(v);
			}
		}
	}
}

int main() {
	input();
	solve();
	dfs(S);

	printf("%d 0", needmin);
	for (int i = path.size() - 2; i >= 0; i--) {
		printf("->%d", path[i]);
	}
	printf(" %d", backmin);
	return 0;
}


