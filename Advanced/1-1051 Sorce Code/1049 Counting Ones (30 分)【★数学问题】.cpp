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
����������

����2348792
�Ӹ�λ����ʼ����
���絽��ǰ״̬ʱ��2348 7 92����ǰλ��aΪ100
left: 2348
now: 7
right: 92
a: 100

��ʱ�ǵõ�1�ĸ���Ϊ��
	now == 0:
		cnt = left * a
	now == 1:
		cnt = left * a + right + 1
	now >= 2: (����)
		cnt = (left + 1) * a

ÿ��λ������ǵõ�1�ĸ����ܺ;���1-�������ܼ�1�ĸ���

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
