#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;

set<int> c;
vector<int> coins;
vector< pair<int, int> > sls;
int n, m, tmp;

int cnt[100001];


int main () {
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);

		c.insert(tmp);
		cnt[tmp]++;
	}

	for(set<int>::iterator it = c.begin(); it != c.end(); it++) {
		coins.push_back(*it);
	}

	sort(coins.begin(), coins.end());

	int start = 0, v1 = -1, v2 = -1, j;
	pair<int, int> p;
	for(int i = 0; i < n; i++) {
		v1 = coins[i];
		if (v1 >= m) break;
		if(cnt[v1] > 1) j = i;
		else j = i + 1;
		for(; j < n; j++) {
			if (v1 + coins[j] == m) {
				p.first = v1;
				v2 = coins[j];
				p.second = coins[j];
				sls.push_back(p);
				break;
			} else if (v1 + coins[j] > m) break;
		}
		if (v2 > 0) break;
	}

	if(v2 < 0) printf("No Solution");
	else printf("%d %d", v1, v2);

	return 0;
}
