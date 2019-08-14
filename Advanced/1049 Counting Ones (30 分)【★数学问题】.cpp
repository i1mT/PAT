#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

/*
左右数分离

对于2348792
从个位数开始分离
例如到当前状态时：2348 7 92，当前位数a为100
left: 2348
now: 7
right: 92
a: 100

此时记得的1的个数为：
	now == 0:
		cnt = left * a
	now == 1:
		cnt = left * a + right + 1
	now >= 2: (其他)
		cnt = (left + 1) * a

每个位数分离记得的1的个数总和就是1-该数字总计1的个数

*/



int main () {

	int n, l, r, now, a = 1, cnt = 0;

	scanf("%d", &n);

	while (n / a) {
		l = n / (a * 10);
		now = n / a % 10;
		r = n % a;

		if (now == 0) cnt += l * a;
		else if (now == 1) cnt += l * a + r + 1;
		else cnt += (l + 1) * a;

		a *= 10;
	}

	printf("%d", cnt);

	return 0;
}
