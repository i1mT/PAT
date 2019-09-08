# 1068 Find More Coins (30 分)

Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: `N` (≤104, the total number of coins) and `M` (≤102, the amount of money Eva has to pay). The second line contains `N` face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the face values *V*1≤*V*2≤⋯≤*V**k* such that *V*1+*V*2+⋯+*V**k*=`M`. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists *k*≥1 such that A[*i*]=B[*i*] for all *i*<*k*, and A[*k*] < B[*k*].

### Sample Input 1:

```in
8 9
5 9 8 7 2 3 4 1
```

### Sample Output 1:

```out
1 3 5
```

### Sample Input 2:

```
4 8
7 2 4 3
```

### Sample Output 2:

```
No Solution
```



### Analysis

##### 题目大意

给你n个硬币，要支付m块钱，问最优支付的硬币组合。

##### 解析

明显是01背包，不过要装满才有Solution，而且知道哪些装了。所以用一个choice数组在背包选择装的时候记录下来。

### Code

```
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
```

