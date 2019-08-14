#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 
#include<sstream>

using namespace std;

struct Customer {
	int cost;
	int total;
	int start;
	bool finished;
};

vector<Customer> customers;
vector<queue<int> > windows;
int N, M, K, Q;

void getTime(int minutes, int &h, int &m) {
	int addHour = minutes / 60;
	m = minutes % 60;

	h = 8 + addHour;
}



void calTime() {
	int start = 0;
	int past = 0;
	int curIndex = 0;
	int qSize;
	int shortestIndex;
	int firstNeed;
	int firstIndex;
	int tmpIndex;
	Customer tmp;


	while (1) {

		// enter in
		while (1) {
			if (curIndex == K) break;
			qSize = M;
			shortestIndex = -1;
			for (int i = 0; i < N; i++) {
				if (windows[i].size() < qSize) {
					qSize = windows[i].size();
					shortestIndex = i;
				}
			}
			// enter yellow line
			if (shortestIndex < 0) break;
			windows[shortestIndex].push(curIndex);
			curIndex++;
		}

		// cal time
		firstNeed = 999999;
		firstIndex = -1;
		for (int i = 0; i < N; i++) {
			if (windows[i].size() == 0) continue;

			tmp = customers[windows[i].front()];

			if (firstNeed > tmp.cost) {
				firstNeed = tmp.cost;
				firstIndex = i;
			}
		}

		if (firstIndex < 0) break;
		tmpIndex = windows[firstIndex].front();
		windows[firstIndex].pop();
		tmp = customers[tmpIndex];
		start += tmp.cost;
		if (windows[firstIndex].size() > 0) {
			customers[windows[firstIndex].front()].start = start;
		}
		customers[tmpIndex].total = start;
		past = tmp.cost;

		// 减去重叠时间
		for (int i = 0; i < N; i++) {
			if (i == firstIndex) continue;
			if (windows[i].size() > 0) {
				customers[windows[i].front()].cost -= past;
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	Customer tmp;
	queue<int> q;
	windows.assign(N, q);

	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp.cost);
		tmp.finished = false;
		tmp.start = 0;
		customers.push_back(tmp);
	}
	calTime();
	int temp, h, m, sh, sm;
	for (int i = 0; i < Q; i++) {
		cin >> temp;
		tmp = customers[temp - 1];
		getTime(tmp.total, h, m);
		getTime(tmp.start, sh, sm);
		if (sh >= 17) printf("Sorry\n");
		//if (h >= 17 && m != 0) printf("Sorry\n");
		else {
			if (h < 10) printf("0%d:", h);
			else printf("%d:", h);

			if (m < 10) printf("0%d\n", m);
			else printf("%d\n", m);
		}
	}

	return 0;
}

