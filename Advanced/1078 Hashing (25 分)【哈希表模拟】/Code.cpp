#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>

#define maxn 15112

using namespace std;

int m, n;

int prime[maxn], table[maxn];


void getPrime () {
	fill(prime, prime+maxn, 1);
	prime[1] = 0; // 注意这里可能是只有一个元素的hash表 
	for(int i = 2; i <= maxn; i++) {
		if (prime[i]) {
			for(int j = i*i; j < maxn && i < sqrt(double(maxn)); j+=i) {
				prime[j] = 0;
			}
		}
	}
}

int h(int k) {
	int pos = k%m, p;
	int cnt = 1;
	p = pos;

	while(table[p] != 0 && cnt <= m) {
		p = (k + cnt*cnt) % m;
		cnt++;
	}

	if(table[p] == 0) {
		table[p] = k;
		return p;
	}

	return -1;
}

int main () {
	int tmp, res;

	getPrime();

	scanf("%d%d", &m, &n);

	// 找素数
	while(!prime[m]) m++;

	for(int i = 0; i < n; i++) {
 		scanf("%d", &tmp);
		res = h(tmp);

		if(i != 0) printf(" ");

		if (res < 0) printf("-");
		else printf("%d", res);
	}


	return 0;
}
