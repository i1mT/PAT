#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

#define INF 999999

using namespace std;


map<string, int> names;
vector<string> sNames;

int N, MAX;
int grid[2010][2010];
vector<int> visit;

struct Record {
	string name;
	int nodes;
};


int DFS (int start, int &head, int &nodes) {
	stack<int> s;
	s.push(start);
	int index, sum = 0;
	int maxConn = -1;
	int sumNode = 0;
	while(!s.empty()) {
		index = s.top();
		s.pop();
		int conn = 0;
		for(int i = 0; i < N; i++) {
			if (grid[index][i] != INF) {
				conn += grid[index][i];
				if(!visit[i]) {
					sum += grid[index][i];
					s.push(i);
				}
			}
		}
		if (maxConn < conn) {
			maxConn = conn;
			head = index;
		}
		if(visit[index] == 1) continue;
		visit[index] = 1;
		sumNode++;
	}
	nodes = sumNode;
	if (sumNode <= 2) return 0;
	return sum;
}

bool cmp (Record a, Record b) {
	return a.name < b.name;
}


int main () {

	scanf("%d%d", &N, &MAX);
	// 初始化grid
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] = INF;
		}
	}
	sNames.resize(2*N + 10);
	string name1, name2;
	name1.resize(3);
	name2.resize(3);
	int id1, id2, id = 0, time;
	for (int i = 0; i < N; i++) {
		scanf("%s%s%d", &name1[0], &name2[0], &time);
			
		if (names.count(name1) != 1) {
			names[name1] = id;
			id++;
		}
		if (names.count(name2) != 1) {
			names[name2] = id;
			id++;
		}
		id1 = names[name1];
		sNames[id1] = name1;
		id2 = names[name2];
		sNames[id2] = name2;

		if (grid[id1][id2] == INF) grid[id1][id2] = time;
		else grid[id1][id2] += time;

		grid[id2][id1] = grid[id1][id2];
	}

	// 统计联通分量
	int start, num, head, nodes;
	visit.assign(2*N + 10, 0);
	vector<Record> res;
	Record r;
	while (1) {
		start = -1;
		for (int i = 0; i < N; i++) {
			if (visit[i] == 0) {
				start = i;
				break;
			}
		}

		if (start < 0) break;
		// DFS
		num = DFS(start, head, nodes);

		// 联通量大于阈值，记录
		if (num > MAX) {
			r.name = sNames[head];
			r.nodes = nodes;

			res.push_back(r);
		}
	}
	sort(res.begin(), res.end(), cmp);
	printf("%d\n", res.size());
	for(int i = 0; i < res.size(); i++) {
		cout << res[i].name;
		printf(" %d\n", res[i].nodes);
	}
	return 0;
}
