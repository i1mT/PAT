#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;



int dp[10002];
int orders[10002];
int colors[10002];


int main () {

	int n, m, l, tmp, num = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		scanf("%d", &tmp);

		orders[tmp] = i;
	}

	scanf("%d", &l);

	for(int i = 0; i < l; i++) {
		scanf("%d", &tmp);
		if (orders[tmp] > 0) {
			colors[num++] = tmp;
		}
	}
	

	// DP[i] 为第i个序列位置的颜色结尾的最长序列
	int maxn = 0;
	for (int i = 0; i < num; i++) {
		dp[i] = 1;

		for(int j = 0; j < i; j++) {
			// 要是在i的位置之前有在序列之前的颜色，比较取最大
			if (orders[colors[j]] <= orders[colors[i]]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxn = max(maxn, dp[i]);
	}

	printf("%d", maxn);

	return 0;
}
