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

int n, m, s;
vector< vector<int> > tree;
vector<int> weight;
vector< vector<int> > res;
vector<int> path;
int sum = 0, tmp;

void bfs(int r, int target) {
	sum += weight[r];
	path.push_back(weight[r]);

	if(sum == s) {
		if(tree[r].size() == 0)
			res.push_back(path);
		path.pop_back();
		sum -= weight[r];
		return;
	}

	if(tree[r].size() == 0) {
		path.pop_back();
		sum -= weight[r];
		return;
	}
	
	for(int i = 0; i < tree[r].size(); i++) {
		bfs(tree[r][i], target - sum);
	}

	path.pop_back();
	sum -= weight[r];
	return;
}

bool cmp(vector<int> a, vector<int> b) {
	int n = min(a.size(), b.size());
	int i = 0;
	while(i < n) {
		if (a[i] != b[i])
			return a[i] > b[i];
		i++;
	}

	return a.size() < b.size();
}

int main () {
	
	int index, num;

	scanf("%d %d %d", &n, &m, &s);

	tree.resize(n);
	weight.resize(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}

	for(int i = 0; i < m; i++) {
		scanf("%d %d", &index, &num);
		tree[index].resize(num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &tree[index][j]);
		}
	}

	bfs(0, s);

	sort(res.begin(), res.end(), cmp);

	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			if(j != 0) printf(" ");
			printf("%d", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}
