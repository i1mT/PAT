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
#include <cstring>

int main () {
	long long a, b, c, res;
	int n, flag;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		res = a+b;
		if(a>0 && b>0 && res<0) flag = 1;
		else if (a < 0 && b < 0 && res >= 0) flag = -1;
		else if (res > c) flag = 1;
		else flag = -1;
		printf("Case #%d: ", i+1);

		if(flag == 1) printf("true\n");
		else printf("false\n");
	}

	return 0;
}
