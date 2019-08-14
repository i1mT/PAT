#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

stack<int> cur, nextL;
vector< stack<int> > tree;
vector<int> result;
int N, M, level_cnt;

void solve() {
	cin >> N >> M;
	tree.resize(N + 1);
	result.assign(N, 0);
	level_cnt = 0;

	int par, temp, k;
	for (int i = 0; i < M; i++) {
		cin >> par >> k;
		
		for (int j = 0; j < k; j++) {
			cin >> temp;
			tree[par].push(temp);
		}
	}

	cur.push(1);
	int cur_pos, tmp;
	while (!cur.empty()) {
		cur_pos = cur.top();
		cur.pop();

		if (tree[cur_pos].empty()) {
			result[level_cnt]++;
		}
		int size = tree[cur_pos].size();
		for (int i = 0; i < size; i++) {
			tmp = tree[cur_pos].top();
			nextL.push(tmp);
			tree[cur_pos].pop();
		}

		// if (nextL.size() == 0) break;

		if (cur.empty()) {
			level_cnt++;

			int size = nextL.size();
			for (int i = 0; i < size; i++) {
				cur.push(nextL.top());
				nextL.pop();
			}
		}
	}

	for (int i = 0; i < level_cnt; i++) {
		if (i != 0) cout << " ";
		cout << result[i];
	}
}




int main() {
	solve();
	return 0;
}
