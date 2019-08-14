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

关于VIP： 

	1. 如果有vip桌子可用，队里的vip可以直接使用vip桌子
	2. 如果没有vip在队伍里，普通玩家可以使用vip桌子
	3. 如果没有vip桌子可用，vip可以看作普通玩家

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
		// 寻找最先结束的table
		for (int j = 1; j < tables.size(); j++) {
			if (tables[j].end < fastTime) {
				fastIndex = j;
				fastTime = tables[j].end;
			}
		}
		if (fastIndex < 0) break;


		if (qlist[i].arrive >= tables[fastIndex].end) {
			// 如果队伍第一个人来的比最快结束的桌子的结束时间晚，那么他来的时候就可以直接用这个桌子
			if (qlist[i].isVip && !tables[fastIndex].isVip && M > 0) {
				// 来的是vip，但当前不是vip桌子，寻找最早空闲的vip桌子
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
			// 队伍第一个人来的比最快结束的桌子结束时间早，那么他需要等待

			if (tables[fastIndex].isVip) {
				// 是vip桌
				// 循环一遍队列，看是否有vip在这个桌子结束之前到队列中了
				for (int k = i; k < qlist.size(); k++) {
					if (qlist[k].arrive > tables[fastIndex].end) break;
					if (qlist[k].arrive < tables[fastIndex].end && qlist[k].isVip == 1) { // 有vip在排队
						moveP(k, i);
						break;
					}
				}
			}
			else if (qlist[i].isVip == 1) {
				// 不是vip桌子，第一个人是vip，将vip往后挪一位
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
