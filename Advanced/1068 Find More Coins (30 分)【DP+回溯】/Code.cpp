#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxc = 10010, maxn=10010, maxm=110;

int n, m;
int coin[maxc];
int dp[maxm], choice[maxn][maxc];

int main () {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}

	sort(coin+1, coin+n+1, greater<int>());

	for(int i = 1; i <= n; i++) {
		for(int j = m; j >= coin[i]; j--) {
			if (dp[j] <= dp[j - coin[i]] + coin[i]) {
				dp[j] = dp[j - coin[i]] + coin[i];
				choice[i][j] = 1; // 这个选了
			}
		}
	}

	if (dp[m] != m) {
		printf("No Solution");
		return 0;
	}
	
	vector<int> res;
	int w = m, idx = n;
	while(w>0) {
		if(choice[idx][w]==1) {
			res.push_back(coin[idx]);
			w -= coin[idx];
		}
		idx--;
	}

	for(int i = 0; i < res.size(); i++) {
		if (i!=0) printf(" ");
		printf("%d", res[i]);
	}
	
	return 0;
}
