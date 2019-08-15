#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

struct Customer {
	double arrive;
	int cost; // minutes
	int _cost;
};

int N, M;
int T8 = 8 * 60 * 60, T17 = 17 * 60 * 60;
double ttime = 0;
vector<Customer> list;
vector<int> windows;

bool cmp(Customer a, Customer b) {
	return a.arrive < b.arrive;
}

double getSeconds(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

void input() {
	scanf("%d%d", &N, &M);
	windows.assign(M + 1, T8);
	Customer tmp;
	int h, m, s;
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d", &h, &m, &s, &tmp.cost);

		tmp.arrive = getSeconds(h, m, s);
		// 排除17点之后
		if (tmp.arrive > T17) continue;
		tmp.cost = tmp.cost * 60;
		list.push_back(tmp);
	}
	N = list.size();
}

void solve() {
	sort(list.begin(), list.end(), cmp);
	int curIndex = 0;
	int fast, fastIndex = 0;
	ttime = 0;
	Customer tmp;

	for (int i = 0; i < N; i++) {
		// 寻找最快结束的
		fast = windows[0];
		fastIndex = 0;
		for (int j = 1; j < M; j++) {
			if (windows[j] < fast) {
				fast = windows[j];
				fastIndex = j;
			}
		}

		if (list[i].arrive >= windows[fastIndex]) {
			windows[fastIndex] = list[i].arrive + list[i].cost;
		} else {
			ttime += windows[fastIndex] - list[i].arrive;
			windows[fastIndex] += list[i].cost;
		}
	}
}

int main() {
	input();
	solve();

	if (N == 0) printf("0.0");
	else printf("%.1f", ttime / 60.0 / N);
	return 0;
}

