#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>


using namespace std;


struct Stu {
	int id;
	int ge, gi, index;
	double sum;
	int rank;
	int prefer[6];
};

int n, m, k;
vector<vector<int>> res;
int quota[110];
vector<Stu> apps;

bool cmp (Stu a, Stu b) {
	if (a.sum != b.sum) return a.sum > b.sum;
	return a.ge > b.ge;
}
bool cmp1(int a, int b) {
	return apps[a].id < apps[b].id;
}


int main () {
	int tmp;

	scanf("%d%d%d", &n, &m, &k);

	res.resize(m);

	for(int i = 0; i < m; i++) {
		scanf("%d", &quota[i]);
	}

	Stu s;

	for(int i = 0; i < n; i++) {
		scanf("%d%d", &s.ge, &s.gi);
		s.sum = double((s.ge + s.gi) / 2);
		s.id = i;

		for(int j = 0; j < k; j++) {
			scanf("%d", &s.prefer[j]);
		}

		apps.push_back(s);
	}

	sort(apps.begin(), apps.end(), cmp);

	int cnt = 1;
	apps[0].rank = 1;
	for(int i = 1; i < apps.size(); i++) {

		if (apps[i].sum == apps[i-1].sum && apps[i].ge == apps[i-1].ge) apps[i].rank = apps[i-1].rank;
		else apps[i].rank = i+1;
	}
	int sc;
	for(int i = 0; i < apps.size(); i++) {
		for(int j = 0; j < k; j++) {
			sc = apps[i].prefer[j];

			if (quota[sc] != 0 || apps[ res[sc][ res[sc].size()-1 ] ].rank == apps[i].rank ) {
				res[sc].push_back(i);
				apps[i].index = j;
				if (quota[sc]!=0) quota[sc]--;

				break;
			}
		}
	}

	for(int i = 0; i < res.size(); i++) {
		sort(res[i].begin(), res[i].end(), cmp1);
		for(int j = 0; j < res[i].size(); j++) {
			if (j != 0) printf(" ");
			printf("%d", apps[res[i][j]].id);
		}

		printf("\n");
	}

	return 0;
}
