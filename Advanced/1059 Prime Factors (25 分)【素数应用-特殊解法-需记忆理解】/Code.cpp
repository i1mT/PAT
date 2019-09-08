#include <iostream>
#include <strstream>
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

#define MAX 500000

vector<int> prime(MAX, 1);

int main () {
	long int a;

	// ÇóËØÊý±í
	for(int i = 2; i * i < MAX; i++) {
		for(int j = 2; i * j < MAX; j++)
			prime[i*j] = 0;
	}

	scanf("%ld", &a);
	printf("%ld=", a);
	if(a == 1) printf("1");
	int cnt, flag, state = 0;
	for (int i = 2; a >= 2; i++) {
		cnt = 0;
		flag = 0;
		while(prime[i] == 1 && a%i == 0) {
			// i is prime facter
			cnt++;
			a = a/i;
			flag = 1;
		}

		if (flag == 1) {
			if (state) printf("*");
			printf("%d", i);
			state = 1;
		}
		if(cnt >= 2) {
			printf("^%d", cnt);
		}
	}
	
	return 0;
}
