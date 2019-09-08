# 1060 Are They Equal (25 分)

If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123×105 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

### Input Specification:

Each input file contains one test case which gives three numbers *N*, *A* and *B*, where *N* (<100) is the number of significant digits, and *A* and *B* are the two float numbers to be compared. Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.

### Output Specification:

For each test case, print in a line `YES` if the two numbers are treated equal, and then the number in the standard form `0.d[1]...d[N]*10^k` (`d[1]`>0 unless the number is 0); or `NO` if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

### Sample Input 1:

```in
3 12300 12358.9
```

### Sample Output 1:

```out
YES 0.123*10^5
```

### Sample Input 2:

```in
3 120 128
```

### Sample Output 2:

```out
NO 0.120*10^3 0.128*10^3
```

### Analysis

##### 题目大意

给你两个不超过一百位有效数的数字a，b，将它们使用k位有效数的科学计数法表示出来。并判断在此计数法下两数是否相等，并分别输出。

##### 解析

> ~~厚颜无耻地~~又~~照抄~~学习了[柳婼](https://www.liuchuo.net/)的解法。

1. cnta，cntb分别记录该数字小数点的位置（即数字有几位，即最终科学计数法10的指数）。初始化为字符串长度(处理输入为整数的情况)，然后在寻找效数点在字符串中的位置，如果找到重新赋值cnta。
2. p，q标记该数字第一个非0有效数的位置(防止前面无效0)。
3. 若p>cnta，说明小数点在第一个有效数后面，cnta=cnta - p (这时候计算出的是10的指数); 否则，cnta=cnta-p+1; b同理。
4. 如果p或q与字符串同长，那么说明输入的数字是0，将cnta或cntb置为0；否则，回因为指数不等而判不同。
5. 使用indexa与indexb为有效数字A赋值，从a下标p开始，赋值n位不为小数点的数字。若p>a的长度，就赋0。b同理。
6. AB相等且cnta与cntb相等，那么说明两数字在该科学计数法下是相等的。



### Code

```
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

using namespace std;

int main () {
	int n;
	char a[10000], b[10000], A[10000], B[10000];

	scanf("%d%s%s", &n, a, b);
	
	int cnta = strlen(a), cntb = strlen(b);

	for(int i = 0; i < strlen(a); i++) {
		if(a[i] == '.') {
			cnta = i;
			break;
		}
	}

	for(int i = 0; i < strlen(b); i++) {
		if(b[i] == '.') {
			cntb = i;
			break;
		}
	}

	int indexa = 0, indexb = 0, p = 0, q = 0;
	while(a[p] == '0' || a[p] == '.') p++;
	while(b[q] == '0' || b[q] == '.') q++;

	if (cnta >= p)
		cnta = cnta - p;
	else
		cnta = cnta - p + 1;
	if(cntb >= q)
		cntb = cntb - q;
	else
		cntb = cntb - q + 1;

	if(p == strlen(a))
		cnta = 0;
	if(q == strlen(b))
		cntb = 0;

	while(indexa < n) {
		if(a[p] != '.' && p < strlen(a)) {
			A[indexa++] = a[p];
		} else if (p >= strlen(a)) {
			A[indexa++] = '0';
		}
		p++;
	}
	A[indexa] = '\0';

	while(indexb < n) {
		if(b[q] != '.' && q < strlen(b)) {
			B[indexb++] = b[q];
		} else if (q >= strlen(b)) {
			B[indexb++] = '0';
		}
		q++;
	}
	B
	[indexb] = '\0';

	if(strcmp(A, B) == 0 && cnta == cntb) {
		printf("YES 0.%s*10^%d", A, cnta);
	} else {
		printf("NO 0.%s*10^%d 0.%s*10^%d", A, cnta, B, cntb);
	}
	
	

	return 0;
}
```

