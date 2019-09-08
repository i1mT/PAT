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
