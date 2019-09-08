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
