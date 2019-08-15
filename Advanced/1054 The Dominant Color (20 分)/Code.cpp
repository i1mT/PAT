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



int main () {
	int m, n, half, tmp;

	map<int, int> cnt;

	scanf("%d%d", &n, &m);


	half = m*n / 2;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &tmp);

			if(cnt.count(tmp) == 0) {
				cnt[tmp] = 1;
			} else {
				cnt[tmp]++;
			}

			if(cnt[tmp] > half) {
				printf("%d", tmp);
			}
		}
	}

	return 0;
}
