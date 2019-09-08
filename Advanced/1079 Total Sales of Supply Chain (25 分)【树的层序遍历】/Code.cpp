#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>


using namespace std;

struct Node {
	double price;
	int num;
};

int n;
double p, r;
vector<vector<int>> tree;

Node data[100010];

double bfs() {
	int tmp;
	double res = 0.0;
	queue<int> q;

	q.push(0);

	while(!q.empty()) {
		tmp = q.front();
		q.pop();

		for(int i = 0; i < tree[tmp].size(); i++) {
			data[tree[tmp][i]].price = data[tmp].price * (1.0 + r/100);

			q.push(tree[tmp][i]);
		}
	}

	for(int i = 0; i < n; i++) {
		res += data[i].num * data[i].price;
	}

	return res;
}

int main () {
	int tmp, t;
	Node nd;
	nd.num = 0;

	scanf("%d%lf%lf", &n, &p, &r);

	tree.resize(n);
	data[0].price = p;
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			scanf("%d", &tmp);
			data[i].num = tmp;
		} else {
			while(tmp--) {
				scanf("%d", &t);
				
				tree[i].push_back(t);
			}
		}
	}

	double res = bfs();

	printf("%.1f", res);

	return 0;
}
