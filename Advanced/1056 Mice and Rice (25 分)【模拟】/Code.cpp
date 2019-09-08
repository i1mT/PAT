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


struct Node {
	int id;
	int num;
};

int np, ng, max_rk = -1;
vector<int> w;
queue<int> q;
vector<int> rk;
vector< Node > res;

bool cmp(Node a, Node b) {
	return a.num > b.num;
}

void solve () {
	int tmp, mmax = -1, maxI, level = 0;
	int cnt;
	queue<int> qg;
	while(1) {
		while(!qg.empty()) {
			q.push(qg.front());
			qg.pop();
		}
		mmax = -1;
		cnt = 0;
		while(!q.empty()) {
			tmp = q.front();
			q.pop();
			
			cnt++;
			if (w[tmp] > mmax) {
				mmax = w[tmp];
				maxI = tmp;
			}
			if(cnt%ng == 0 || q.empty()) {
				if (mmax != -1) {
					qg.push(maxI);
					rk[maxI] += 1;
					max_rk = max(max_rk, rk[maxI]);
					mmax = -1;
				}
			}
		}
		if(cnt == 1) {
			break;
		}
	}

	Node p;
	for(int i = 0; i < rk.size(); i++) {
		p.id = i;
		p.num = rk[i];
		res.push_back(p);
	}
	sort(res.begin(), res.end(), cmp);

	int order = 0, num;
	for(int i = 0; i < res.size(); i++) {
		if(i == 0) {
			num = res[i].num;
			order++;
			rk[res[i].id] = order;
		}
		if(num > res[i].num) {
			num = res[i].num;
			order = i + 1;
			rk[res[i].id] = order;
		} else {
			rk[res[i].id] = order;
		}
	}

	for(int i = 0; i < rk.size(); i++) {
		if(i != 0) printf(" ");
		printf("%d", rk[i]);
	}
}

int main () {
	
	int tmp;

	scanf("%d%d", &np, &ng);
	rk.assign(np, -1);

	for (int i = 0; i < np; i++) {
		scanf("%d", &tmp);
		w.push_back(tmp);
	}

	for(int i = 0; i < np; i++) {
		scanf("%d", &tmp);
		q.push(tmp);
	}

	solve();
	
	return 0;
}
