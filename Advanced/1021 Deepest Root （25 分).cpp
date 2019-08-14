#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

vector< vector<int> > graph;
vector<int> temp;
set<int> res;
vector<int> visited;
int maxLength = 0, maxIndex, N, com = 0;

void dfs(int node, int length) {
	if (length > maxLength) {
		maxLength = length;
		temp.clear();
		temp.push_back(node);
	}
	else if (length == maxLength) {
		temp.push_back(node);
	}

	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]] == 0)
			dfs(graph[node][i], length + 1);
	}
}





int main() {
	int N, from, to, ss;
	scanf("%d", &N);
	graph.resize(N + 1);
	visited.assign(N + 1, 0);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &from, &to);

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			dfs(i, 1);
			com++;
			if (i = 1) {
				if (temp.size() > 0) ss = temp[0];
				for (int j = 0; j < temp.size(); j++) {
					res.insert(temp[j]);
				}
			}
		}
	}

	if (com > 1) {
		printf("Error: %d components", com);
		return 0;
	}
	visited.assign(N + 1, 0);
	temp.clear();
	dfs(ss, 1);
	maxLength = 0;
	for (int i = 0; i < temp.size(); i++) {
		res.insert(temp[i]);
	}
	for (auto it = res.begin(); it != res.end(); it++) {
		printf("%d\n", *it);
	}
	return 0;
}

