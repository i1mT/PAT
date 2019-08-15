#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<algorithm> 

/*

����VIP�� 

	1. �����vip���ӿ��ã������vip����ֱ��ʹ��vip����
	2. ���û��vip�ڶ������ͨ��ҿ���ʹ��vip����
	3. ���û��vip���ӿ��ã�vip���Կ�����ͨ���

*/

using namespace std;

int T8 = 60 * 60 * 8;
int T21 = 60 * 60 * 21;

struct Player {
	int arrive;
	int playtime;
	int isVip;
	int serveTime;
	int waitTime;
	int table;
};

struct Table {
	int end = T8;
	int isVip = 0;
	int served = 0;
};

vector<Table> tables;
vector<Player> qlist;
int N, K, M;

bool cmp(Player a, Player b) {
	return a.arrive < b.arrive;
}

bool cmp1(Player a, Player b) {
	return a.serveTime < b.serveTime;
}

void moveP(int from, int to) {
	if (from <= to) return;
	if (to >= qlist.size() || from >= qlist.size()) return;
	// from > to
	vector<Player>::iterator it = qlist.begin() + from;
	Player p;
	for (int i = 0; i < from - to; i++) {
		p = qlist.at(from);
		qlist.at(from) = qlist.at(from - 1);
		qlist.at(from - 1) = p;
		from--;
	}
}

void input() {
	Player ptmp;
	Table Ttmp;
	int tmp;
	ptmp.isVip = 0;

	qlist.push_back(ptmp);

	scanf("%d", &N);
	int h, m, s;
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d%d%d", &h, &m, &s, &ptmp.playtime, &ptmp.isVip);
		ptmp.arrive = (h * 60 * 60) + (m * 60) + s;
		ptmp.playtime *= 60;
		qlist.push_back(ptmp);
	}
	scanf("%d%d", &K, &M);
	tables.assign(K + 1, Ttmp);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		tables[tmp].isVip = 1;
	}

	sort(qlist.begin(), qlist.end(), cmp);
}

void printfTime(int t) {
	int h = t / (60 * 60);
	t %= (60 * 60);
	int m = t / 60;
	int s = t % 60;

	printf("%02d:%02d:%02d", h, m, s);
}

void solve() {
	
	int fastTime, fastIndex, playerIndex;
	int fastTimeV, fastIndexV;

	for (int i = 1; i < qlist.size(); i++) {
		fastTime = 9999999, fastIndex = -1;
		// Ѱ�����Ƚ�����table
		for (int j = 1; j < tables.size(); j++) {
			if (tables[j].end < fastTime) {
				fastIndex = j;
				fastTime = tables[j].end;
			}
		}
		if (fastIndex < 0) break;


		if (qlist[i].arrive >= tables[fastIndex].end) {
			// ��������һ�������ı������������ӵĽ���ʱ������ô������ʱ��Ϳ���ֱ�����������
			if (qlist[i].isVip && !tables[fastIndex].isVip && M > 0) {
				// ������vip������ǰ����vip���ӣ�Ѱ��������е�vip����
				fastTimeV = 9999999, fastIndexV = -1;
				for (int v = 0; v < tables.size(); v++) {
					if (!tables[v].isVip) continue;
					if (fastTimeV < tables[v].end) {
						fastIndexV = v;
						fastTimeV = tables[v].end;
					}
				}
				fastIndex = fastIndexV;
				if (qlist[i].arrive >= tables[fastIndexV].end) {
					tables[fastIndex].end = qlist[i].arrive + qlist[i].playtime;
					qlist[i].waitTime = 0;
					qlist[i].serveTime = qlist[i].arrive;
				} else {
					qlist[i].serveTime = tables[fastIndex].end;
					qlist[i].waitTime = tables[fastIndex].end - qlist[i].arrive;
					tables[fastIndex].end += qlist[i].playtime;
				}
			}
			else {
				tables[fastIndex].end = qlist[i].arrive + qlist[i].playtime;
				qlist[i].waitTime = 0;
				qlist[i].serveTime = qlist[i].arrive;
			}
		}
		else if (qlist[i].arrive < tables[fastIndex].end) {
			// �����һ�������ı������������ӽ���ʱ���磬��ô����Ҫ�ȴ�

			if (tables[fastIndex].isVip) {
				// ��vip��
				// ѭ��һ����У����Ƿ���vip��������ӽ���֮ǰ����������
				for (int k = i; k < qlist.size(); k++) {
					if (qlist[k].arrive > tables[fastIndex].end) break;
					if (qlist[k].arrive < tables[fastIndex].end && qlist[k].isVip == 1) { // ��vip���Ŷ�
						moveP(k, i);
						break;
					}
				}
			}
			else if (qlist[i].isVip == 1) {
				// ����vip���ӣ���һ������vip����vip����Ųһλ
				moveP(i+1, i);
			}
			qlist[i].serveTime = tables[fastIndex].end;
			qlist[i].waitTime = tables[fastIndex].end - qlist[i].arrive;
			tables[fastIndex].end += qlist[i].playtime;
		}
		if (qlist[i].arrive >= T21) break;
		if (qlist[i].serveTime >= T21) break;
		tables[fastIndex].served++;
	}
	sort(qlist.begin(), qlist.end(), cmp1);

	int h, m, s, wait;
	for (int i = 1; i < qlist.size(); i++) {
		if (qlist[i].arrive >= T21) break;
		if (qlist[i].serveTime >= T21) break;
		printfTime(qlist[i].arrive);
		printf(" ");
		printfTime(qlist[i].serveTime);
		printf(" %.0f\n", round((qlist[i].waitTime / 60.0)));
	}

	for (int i = 1; i < tables.size(); i++) {
		if (i != 1) printf(" ");
		printf("%d", tables[i].served);
	}
}




int main() {
	input();
	solve();
	return 0;
}
