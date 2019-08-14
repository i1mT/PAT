#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<algorithm> 

using namespace std;

#define INF 999999

struct Way {
	int length = INF;
	int cost = INF;
};

vector< vector<Way> > map;
vector<int> d;
vector<int> c;
vector< vector<int> > path;
int N, M, S, D;


void dijk(int s) {
	vector<int> visited;
	visited.assign(N, 0);
	int v;
	d[s] = 0;
	c[s] = 0;
	path[s].push_back(s);

	while (1) {
		v = -1;
		for (int i = 0; i < N; i++) {
			if (visited[i] != 1 && (v == -1 || d[i] < d[v]))
				v = i;
		}

		if (v < 0) break;
		visited[v] = 1;

		for (int i = 0; i < N; i++) {
			if (d[i] > d[v] + map[v][i].length) {
				d[i] = d[v] + map[v][i].length;
				c[i] = c[v] + map[v][i].cost;
				path[i].clear();
				path[i] = path[v];
				path[i].push_back(i);
			}
			else if (d[i] == d[v] + map[v][i].length) {
				if (c[i] > c[v] + map[v][i].cost) {
					c[i] = c[v] + map[v][i].cost;
					path[i].clear();
					path[i] = path[v];
					path[i].push_back(i);
				}
			}
		}
	}
}

int main() {
	int from, to, length, cost;
	vector<Way> tempways;
	vector<int> p;
	Way way;
	scanf("%d%d%d%d", &N, &M, &S, &D);
	
	tempways.assign(N, way);

	map.assign(N, tempways);
	path.assign(N, p);
	d.assign(N, INF);
	c.assign(N, INF);

	tempways.clear();
	p.clear();

	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &from, &to, &way.length, &way.cost);

		map[from][to] = way;
		map[to][from] = way;
	}

	dijk(S);
	for (int i = 0; i < path[D].size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", path[D][i]);
	}
	printf(" %d %d", d[D], c[D]);
	return 0;
}

